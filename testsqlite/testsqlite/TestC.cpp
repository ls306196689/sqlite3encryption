//
//  TestC.cpp
//  testsqlite
//
//  Created by afei on 13-10-15.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#include "TestC.h"
#include "sqlite3.h"
#include <iostream>
using namespace std;
const char* tablename = "table0";
void testSqlite3(const char* dbfilename)
{
    sqlite3 * db = NULL;
//    sqlite3_os_init();
    int res = sqlite3_open(dbfilename, &db);
    res = sqlite3_threadsafe();
    if (res == SQLITE_OK) {
        res = sqlite3_key(db, "ass", 3);
        cout<<"res:"<<res<<endl;
        char sqlchar[1024] = {0};
        
        sprintf(sqlchar, "CREATE TABLE %s ([id] text)",tablename);
        
        sprintf(sqlchar, "INSERT INTO [test3] VALUES(100);");
        res = sqlite3_exec(db, sqlchar, 0, 0, 0);
        char **azRes;
        int row,col;
        sprintf(sqlchar, "SELECT * FROM [test3]");
        char* message;
        res = sqlite3_get_table(db, sqlchar, &azRes, &row, &col, &message);
        if (SQLITE_OK == res) {
            for (int i = 1; i < row; i ++) {
                for (int j = 0; j < col; j ++) {
                    cout << azRes[i][j]<<endl;
                }
            }
            cout<<"ok\n";
        }
    }
    sqlite3_close(db);
}
void creatTable(const char* tablename, const char* idname, const char* func)
{
    char sqlchar[1024] = {0};
    sprintf(sqlchar, "CREATE TABLE [test3] ([id] text)");
}
void insetRow(const char* tablename, const char* idname, const char* func)
{
    
}