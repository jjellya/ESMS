#ifndef GLOBAL_H
#define GLOBAL_H
/*全局头文件,避免重复编写*/
#include <string>
#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef struct date{
    int year;
    int month;
    int day;
}DATE, *Date;
#define ARRARY_MAXSIZE 255
#endif // GLOBAL_H
