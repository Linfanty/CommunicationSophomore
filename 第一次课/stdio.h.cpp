#include <stdio.h>

头文件
提供跨工程公共代码
stdio : “standard input & output"（标准输入输出）



C源代码中如用到标准输入输出函数时，就要包含这个头文件


int getchar()//从标准输入设备读入一个字符
int putchar()//向标准输出设备写出一个字符
int scanf(char*format[,argument…])//从标准输入设备读入格式化后的数据
int printf(char*format[,argument…])//向标准输出设备输出格式化字符串
char gets(char*string)//从标准输入设备读入一个字符串
int puts(char*string)//向标准输出设备输出一个字符串
int sprintf(char*string,char*format[,…])//把格式化的数据写入某个字符串缓冲区

