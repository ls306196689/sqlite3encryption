//
//  CDataBaseSqlite3.h
//  testsqlite
//
//  Created by afei on 13-10-16.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#ifndef __testsqlite__CDataBaseSqlite3__
#define __testsqlite__CDataBaseSqlite3__
struct sqlite3;
class CDataBaseSqlite3 {
    
    
public:
    CDataBaseSqlite3();
    ~CDataBaseSqlite3();
    static CDataBaseSqlite3* shareDataBase();
    /**
     *  加载数据库文件，初始化数据库
     *
     *  @param filepath 数据库文件的全路径：路径中的所有文件夹都必须事先创建；若文件存在则会被打开，若文件不存在则会被创建
     *
     *  @since 13-10-16
     */
    void loadDataFromFile(const char* filepath);
    
    /**
     *  在表"table_user_data_2"中设置 col_0_key列为key的行的col_2_data为data；如果不存在key行则插入，如果存在，则删除再插入
     *
     *  @param data 保存的数据长度不能超过256
     *  @param key  长度不能超过256
     *
     *  @since 13-10-16
     */
    void setDataForKey(const char* data, const char* key);
    
    /**
     *  插入一行
     *
     *  @param data 保存的数据长度不能超过256
     *  @param key  长度不能超过256
     *
     *  @since 13-10-16
     */
    void insertDataForKey(const char* data, const char* key);
    
    /**
     *  更新key行的数据为data
     *
     *  @param data 保存的数据长度不能超过256
     *  @param key  长度不能超过256
     *
     *  @since 13-10-16
     */
    void updateDataForKey(const char* data, const char* key);
    
    /**
     *  返回key对应的数据，需调用 getDataOver();
     *
     *  @param key 若表中不存在则报错
     *
     *  @return key 对应的数据
     *
     *  @since 13-10-16
     */
    const char* getDataForKey(const char* key);
    
    
    void setDataForKey(float data, const char* key);
    void removeDataForKey(const char* key);
    void getDataOver();
private:
    bool isTableExsit(const char *tablename);
    void initCol2Table();
    void initCol3Table();
private:
    sqlite3*    m_db;
    char**      m_result;
private:
    const char* g_usertablename_col_2 = "table_user_data_2";
    const char* g_usertablename_col_3 = "table_user_data_3";
    const char* g_key_0 = "col_0_key";
    const char* g_key_1 = "col_1_key";
    const char* g_data =  "col_2_data";
    const char* keycode = "~!##$sdr$w";
};

#endif /* defined(__testsqlite__CDataBaseSqlite3__) */
