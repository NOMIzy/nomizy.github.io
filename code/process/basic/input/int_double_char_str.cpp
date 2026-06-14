#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <string>
using namespace std;

//c风格的输入输出

void c_input(){
        //基本输入
    int x_int;
    double x_double;
    char c,str[10];
    //注意输入要用变量地址，而输入不用
    scanf("%d %lf %c %s",&x_int,&x_double,&c,&str);
    printf("%d \n",x_int);
    printf("%lf \n",x_double);
    printf("%c \n",c);
    printf("%s \n",str);
    
    //正则表达式提取日期 输入2003-1-4
    int year, month, day;
    scanf("%d-%d-%d", &year, &month, &day);
    printf("%d %d %d\n", year, month, day);

    //正则表达式提取时间 输入20:30:40 (注意冒号符号)
    int hour, minute, second;
    scanf("%d:%d:%d", &hour, &minute, &second);
    printf("%d %d %d\n", hour, minute, second);
}

int main(){

    //输出进制转换
    int a = 10;//默认十进制
    printf("%x\n", a);//小写十六进制输出 答案 a
    printf("%X\n", a);//大写十六进制输出 答案 A
    printf("%o\n", a);//八进制输出 答案 12

    //输出增加前置0
    a = 5;
    printf("%02d\n", a);//其中 2 代表宽度 不足的地方用 0 补充
    printf("%04d\n", a);//宽度为4

    //输出保留小数位数
    double b = 3.6;
    printf("%.2lf\n", b);//2 表示保留两位小数
}