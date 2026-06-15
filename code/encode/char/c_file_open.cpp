#include <iostream>
#include <fstream>
#include <string>



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
// 读取一个文件的最前面n个字节，并以十六进制形式输出每个字节的值
void  readNBytes( char  *fileName,  int  n)
{
     FILE  *fp =  fopen (fileName,  "r" );
     unsigned  char  *buf = (unsigned  char *) malloc ( sizeof (unsigned  char )*n);
     int  i;
     if (fp == NULL)
     {
         printf ( "open file [%s] failed.\n" , fileName);
         return ;
     }
     fread (buf,  sizeof (unsigned  char ), n, fp);
     fclose (fp);
     printf ( "%s:\t" , fileName);
     for (i = 0; i < n; i++)
     {
         printf ( "%x\t" , buf[i]);
     }
     printf ( "\n" );
     free (buf);
}
 


int main() {
    std::string file_path = "test.txt";

    //官方库默认，不能指定编码格式
    std::ifstream file(file_path);
    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::cout << content << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }




    char  fileName[][50] = { "ansi.txt" ,  "utf8.txt" ,  "utf8bom.txt" ,  "utf16le.txt","utf16be.txt" };
     int  i;
     for (i = 0; i < 5; i++)
     {        
         readNBytes(fileName[i], 3);
     }

    return 0;
}
