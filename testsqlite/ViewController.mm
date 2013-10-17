//
//  ViewController.m
//  testsqlite
//
//  Created by afei on 13-10-15.
//  Copyright (c) 2013年 apple. All rights reserved.
//

#import "ViewController.h"
#include "TestC.h"
#include "CDataBaseSqlite3.h"

@interface ViewController ()

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
	// Do any additional setup after loading the view, typically from a nib.
    NSArray* array = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString* doc = [array[0] stringByAppendingString:@"/tttt5.db"];
    CDataBaseSqlite3::shareDataBase()->loadDataFromFile([doc UTF8String]);
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}
-(IBAction) OnPress:(id)sender
{

    CDataBaseSqlite3::shareDataBase()->updateDataForKey("nofucking2", "key2");
    NSLog(@"start");
    for (int i = 0; i < 1000; i ++) {
        
//        CDataBaseSqlite3::shareDataBase()->setDataForKey("nofucking2", "key2");//11.4s //10s
        CDataBaseSqlite3::shareDataBase()->updateDataForKey("nofucking2", "key2"); //5.7s //5s
    }
    NSLog(@"over");
    
}
-(IBAction) query:(id)sender
{
    const char* data = NULL;
    NSLog(@"start");
    for (int i = 0; i < 10000; i ++) {//4.95s
        
        data = CDataBaseSqlite3::shareDataBase()->getDataForKey("key2");
        CDataBaseSqlite3::shareDataBase()->getDataOver();
    }
    NSLog(@"over:%s",data);
}
@end
