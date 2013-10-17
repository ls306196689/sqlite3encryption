//
//  CDataBaseSqlite3.cpp
//  testsqlite
//
//  Created by afei on 13-10-16.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#include "CDataBaseSqlite3.h"
#include "sqlite3.h"
#include <iostream>
#include <assert.h>

static CDataBaseSqlite3* g_database = nullptr;
CDataBaseSqlite3* CDataBaseSqlite3::shareDataBase()
{
    if (g_database == NULL) {
        g_database = new CDataBaseSqlite3();
    }
    return g_database;
}
CDataBaseSqlite3::CDataBaseSqlite3():
m_db(NULL),
m_result(NULL)
{
    
}
CDataBaseSqlite3::~CDataBaseSqlite3()
{
    
}

void CDataBaseSqlite3::loadDataFromFile(const char* filepath)
{
    if (m_db != NULL) {
        sqlite3_close(m_db);
        m_db = NULL;
    }
    int ress = sqlite3_open(filepath, &m_db);
    if (SQLITE_OK != ress) {
        std::cout<<filepath<<" is not able to opened as sqlite3 database. check out wheare the directory exsits."<<std::endl;
        assert(SQLITE_OK != ress);
    }
    ress = sqlite3_key(m_db, keycode, std::strlen(keycode));
    if (SQLITE_OK != ress) {
        std::cout<<"Maybe the keycode is wrong"<<std::endl;
        assert(SQLITE_OK != ress);
    }

    this->initCol2Table();
}

void CDataBaseSqlite3::setDataForKey(const char* data, const char* key)
{
    removeDataForKey(key);
    insertDataForKey(data, key);
}
void CDataBaseSqlite3::insertDataForKey(const char* data, const char* key)
{
    char sql[256] = {0};
    sprintf(sql,"INSERT INTO %s VALUES('%s','%s')", g_usertablename_col_2, key, data);
    int ress = sqlite3_exec(m_db, sql, 0, 0, 0);
    if (SQLITE_OK != ress) {
        std::cout<<"error code:"<<ress<<":"<<sql<<std::endl;
    }
}
void CDataBaseSqlite3::updateDataForKey(const char* data, const char* key)
{
    char sql[256] = {0};
    sprintf(sql,"UPDATE %s SET %s='%s' WHERE %s='%s'", g_usertablename_col_2, g_data, data,g_key_0,key);
    int ress = sqlite3_exec(m_db, sql, 0, 0, 0);
    if (SQLITE_OK != ress) {
        std::cout<<"error code:"<<ress<<":"<<sql<<std::endl;
    }
}
const char* CDataBaseSqlite3::getDataForKey(const char* key)
{
    int nrow = 0;
    int ncol = 0;
    char sql[256] = {0};
    sprintf(sql,"SELECT * FROM %s WHERE %s='%s'", g_usertablename_col_2, g_key_0, key);
    
    int ress = sqlite3_get_table(m_db, sql, &m_result, &nrow, &ncol, NULL);
    if (m_result != NULL && nrow >= 1) {

        return m_result[ 2*ncol - 1 ];
    }
    else
    {
        if (SQLITE_OK != ress) {
            std::cout<<"error code:"<<ress<<":"<<sql<<std::endl;
        }
        return NULL;
    }
}
void CDataBaseSqlite3::getDataOver()
{
    if (m_result != NULL) {
        sqlite3_free_table(m_result);
        m_result = NULL;
    }
}
void CDataBaseSqlite3::setDataForKey(float data, const char* key)
{
    
}
void CDataBaseSqlite3::removeDataForKey(const char* key)
{
    char sql[256] = {0};
    sprintf(sql,"DELETE FROM %s WHERE %s='%s'", g_usertablename_col_2,g_key_0, key);
    int ress = sqlite3_exec(m_db, sql, 0, 0, 0);
    if (SQLITE_OK != ress) {
        std::cout<<"error code:"<<ress<<":"<<sql<<std::endl;
    }
}

void CDataBaseSqlite3::initCol2Table()
{
    char sql[256] = {0};
    sprintf(sql,"CREATE TABLE IF NOT EXISTS %s (%s varchar,%s varchar)", g_usertablename_col_2, g_key_0, g_data);
    int ress = sqlite3_exec(m_db, sql, 0, 0, 0);
    if (SQLITE_OK != ress) {
        std::cout<<"error code:"<<ress<<":"<<sql<<std::endl;
    }
}
void CDataBaseSqlite3::initCol3Table()
{
    
}