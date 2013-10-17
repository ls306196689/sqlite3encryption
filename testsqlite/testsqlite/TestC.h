//
//  TestC.h
//  testsqlite
//
//  Created by afei on 13-10-15.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#ifndef __testsqlite__TestC__
#define __testsqlite__TestC__

void testSqlite3(const char* dbfilename);
void creatTable(const char* tablename, const char* idname, const char* func);
void insetRow(const char* tablename, const char* idname, const char* func);

#endif /* defined(__testsqlite__TestC__) */
