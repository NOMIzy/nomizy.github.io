#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
using namespace std;

void StringInit(){
    char c;
    char c_array[12]="hello world";//需要一开始就赋值，或者使用strcpy()方法，直接c_array="hello world";是不可以的
    string s1;//默认空字符串
    s1="hello world"; //赋值

    //c风格基本使用
    strcpy(c_array,"hi!");
    cout<<c_array<<endl;
    cout<<strcmp(c_array,"hi!")<<" "<<strcmp(c_array,"hi")<<" "<<strcmp(c_array,"hi!!")<<" "<<endl;

    //string对象基本使用
    cout<<s1<<endl;
    cout<<s1[0]<<endl;//下标从0开始到长度-1，返回该位置字符
    cout<<s1.size()<<endl;//字符个数统计
    cout<<s1.empty()<<endl;//字符串为空时返回1,不为空返回0


    string s2(s1);
    string s3=s1;
    string s4(10,'h');//长度为10的全是h的字符串
    cout<<s2<<" "<<s3<<' '<<s4<<" "<<endl;

}

void StringInput(){
//从键盘输入中读取
    
    //获取一个字符,可以读取空格，\n ,\0
    char c;
    cin.get(c);
    cout<<c<<endl;

    char c1[10];
    cin.getline(c1,10);
    cout<<c1<<endl;
    cout<<c1[9]<<endl;


    //读取一个字符串，以\n结尾,字符串中间可以有空格
    string s1;
    getline(cin,s1);
    cout<<s1<<endl;
    cout<<s1[s1.size()-1]<<endl;

    //读取一个字符串 由\n 空格分隔
    string s2;
    cin>>s1>>s2;
    cout<<s1<<endl;
    cout<<s2<<endl;


}

void StringInputFile(){
    // 打开文件
    ifstream inputFile("string_test.txt"); //文件目录

    // 检查文件是否成功打开
    if (!inputFile.is_open()) {
        cout << "Failed to open the file." << endl;
    }

    // 逐个读取字符直到文件结尾
    cout<<"single char"<<endl;
    char c;
    while (inputFile.get(c)) {
        cout << c; // 输出读取的字符
    }

    // 关闭文件
    inputFile.close();

    // 打开文件
    ifstream inputFile_1("string_test.txt"); //文件目录

    // 检查文件是否成功打开
    if (!inputFile_1.is_open()) {
        cout << "Failed to open the file." << endl;
    }

    //按行读取
    cout<<"getline"<<endl;
    string s1;
    while(getline(inputFile_1,s1)){
        cout<<s1<<endl;
    }

    // 关闭文件
    inputFile_1.close();

}

int main(){
    StringInit();
    //StringInput();
    //StringInputFile();

}