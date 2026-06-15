# 字符的编码
[字符、字符集、字符编码的概念，字符编码发展沿革与常用的UTF系列和GB系列各种编码的区别](https://zhuanlan.zhihu.com/p/260192496)

1. 字符

字符（Character）：在计算机和电信技术中，一个字符是一个单位的字形、类字形单位或符号的基本信息。说的简单点字符是各种文字和符号的总称。一个字符可以是一个中文汉字、一个英文字母、一个阿拉伯数字、一个标点符号、一个图形符号或者控制符号等。

2. 字符集

字符集（Character Set）：是指多个字符的集合。不同的字符集包含的字符个数不一样、包含的字符不一样、对字符的编码方式也不一样。例如GB2312是中国国家标准的简体中文字符集，GB2312收录简化汉字（6763个）及一般符号、序号、数字、拉丁字母、日文假名、希腊字母、俄文字母、汉语拼音符号、汉语注音字母，共 7445 个图形字符。而ASCII字符集只包含了128字符，这个字符集收录的主要字符是英文字母、阿拉伯字母和一些简单的控制字符。

另外，还有其他常用的字符集有 GBK字符集、GB18030字符集、Big5字符集、Unicode字符集等。

3. 字符编码

字符编码（Character Encoding）：字符编码是指一种映射规则，根据这个映射规则可以将某个字符映射成其他形式的数据以便在计算机中存储和传输。例如ASCII字符编码规定使用单字节中低位的7个比特去编码所有的字符，在这个编码规则下字母A的编号是65（ASCII码），用单字节表示就是0x41，因此写入存储设备的时候就是二进制的 01000001。每种字符集都有自己的字符编码规则，常用的字符集编码规则还有 UTF-8编码、GBK编码、Big5编码等。

4. 码点

码点（Code Point）：有些地方翻译为码值或内码。是指在某个字符集中，根据某种编码规则将字符编码后得到的值。比如在ASCII字符集中，字母A经过ASCII编码得到的值是65，那么65就是字符A在ASCII字符集中的码点。

- 总结：通俗解释字符集就是把字符放到一起的一个集合。而这个集合的每一个字符都对应一个数字，叫做码点。那么，这样就建立起来数字和字符之间的索引关系。那么，某个字符在计算机中怎么表示，具体占用几个字节等等，这些就需要编码规则来解决了。这个就是字符编码，他来解决根据某个规则来将字符映射到相应的码点上面。

# 沿革过程
- 需要建立字符到数的映射来让计算机打印字符，处理字符 -> **ASCII**
> ASCII编码一共规定了128个字符的编码规则，这128个字符形成的集合就叫做ASCII字符集。在ASCII编码中，每个字符占用一个字节的后面7位，最前面的1位统一规定为0。在ASCII编码中，0~31 是控制字符如换行回车删除等，32~126 是可打印字符

- 需要为所在地区扩展字符集 -> **ISO-8859系列**
> ISO8859-1 字符集，也就是 Latin-1，是西欧常用字符，包括德法两国的字母。
> ISO8859-2 字符集，也称为 Latin-2，收集了东欧字符。
> ISO8859-3 字符集，也称为 Latin-3，收集了南欧字符。

- 需要统一不同地区字符集 -> **Unicode**
> Unicode 字符编码标准是固定长度字符编码方案，它包含了世界上几乎所有现用语言的字符。
> 有关 Unicode 的信息可在 The Unicode Standard以及 Unicode Consortium Web 站点 ( www.unicode.org) 中找到。
> Unicode 使用两种编码格式: 8-bit 和 16-bit ，基于正在编码的数据的数据类型。 缺省编码格式为 16 位，其中每个字符宽为 16 位 (2 字节)。 16 位编码格式通常显示为 U + hhhh ，其中 hhhh 是字符的十六进制代码点。 这种编码形式产生了超过 65000 个代码元素，这足以编码世界主要语言的大部分字符。 Unicode 标准还提供了一种扩展机制，允许对多达 1,000,000 个额外字符进行编码。 扩展机制使用一对高位和低位代用字符来对扩展字符或补充字符进行编码。 第一个 (或高) 代理字符的代码值介于 U+D800 和 U + DBFF 之间。 第二个 (或低) 替代字符具有介于 U+DC00 和 U + DFFF 之间的代码值。

- 需要控制文件存储尺寸 -> **UTF**
> Unicode符号范围 | UTF-8编码方式
> UTF字节数 (十六进制) | （二进制）
> 一个字节 0000 0000-0000 007F | 0xxxxxxx
> 两个字节 0000 0080-0000 07FF | 110xxxxx 10xxxxxx
> 三个字节 0000 0800-0000 FFFF | 1110xxxx 10xxxxxx 10xxxxxx
> 四个字节 0001 0000-0010 FFFF | 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

# 实际问题
- 了解一个字符的编码
例如，C++和Python都提供了方法来获取字符的编码，但它们的实现和返回值并不相同，这主要是由它们的设计和处理字符编码的方式所决定的：
1. C++的字符编码：C++中的char类型通常使用的是**本地编码**，例如ASCII编码或者UTF-8编码（取决于环境设置）。在C++中，char类型被设计成存储一个字节，其范围通常是0到255，代表了不同的字符或符号。因此，当你将一个字符赋值给char类型变量时，它实际上是以底层的编码方式（如ASCII）存储的。

2. Python的字符编码：Python在设计上更倾向于处理**Unicode**字符，因此它的str类型实际上是一个Unicode字符串。在Python中，使用ord()函数获取一个字符的编码时，它返回的是该字符在Unicode编码表中的代码点，而不是底层的字节表示。这意味着Python更加抽象地处理字符，而不依赖于特定的底层编码方式。

在c++中，使用类型转换获得字符的整数编码
~~~C++
#include <iostream>

int main() {
    char character = 'A'; // 要查看的字符
    int charCode = static_cast<int>(character); // 转换为整数编码
    std::cout << "Character: " << character << ", Encoding: " << charCode << std::endl;
    return 0;
}
~~~

在python中，使用内置的ord（）方法
~~~python
character = 'A'  # 你要查看的字符
char_code = ord(character)  # 获取Unicode编码
print("Character:", character, ", Encoding:", char_code)
~~~

- 正确解码一个文本文件
当一个文本文件使用了某种编码格式存储以后，再解读这个文件就需要按照其使用的编码格式解码。当两者不同时，就会出现乱码。

~~~C++
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::string file_path = "path/to/your/file.txt";
    std::string encoding = "utf-8"; // 指定解码的编码格式

    std::ifstream file(file_path);
    if (file.is_open()) {
        std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
        std::cout << content << std::endl;
        file.close();
    } else {
        std::cerr << "Unable to open file" << std::endl;
    }

    return 0;
}

~~~

~~~python
file_path = "path/to/your/file.txt"
encoding = "utf-8"  # 指定解码的编码格式

with open(file_path, 'r', encoding=encoding) as file:
    content = file.read()
    print(content)

~~~

文件编码格式的检测有两种思路，一是根据文件开头的BOM指示符，二是根据统计学原理推测文件可能的编码格式（字符的分布与特殊字符）

第一种方法，通过一个文件的最前面三个字节，可以判断出该的编码类型：
     ANSI：　　　　　　　　无格式定义；(第一个字节开始就是文件内容)
     Unicode： 　　　　　　前两个字节为FFFE；
     Unicode big endian：　前两字节为FEFF；　 
     UTF-8：　 　　　　　　前两字节为EFBB，第三字节为BF
例如实际测试
~~~c++

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

    char  fileName[][50] = { "ansi.txt" ,  "utf8.txt" ,  "utf8bom.txt" ,  "utf16le.txt","utf16be.txt" };
     int  i;
     for (i = 0; i < 5; i++)
     {        
         readNBytes(fileName[i], 3);
     }

    return 0;
}

~~~
有

        ansi.txt:       e0      cb      20    即 1110 0000  1100 1011  0010 0000

        utf8.txt:       e5      97      a8    即 1110 0101  1001 0111  1010 1000

        utf8bom.txt:    ef      bb      bf    即 1110 1111  1011 1011  1011 1111

        utf16le.txt:    ff      fe      e8    即 1111 1111  1111 1110  1110 1000

        utf16be.txt:    fe      ff      55    即 1111 1110  1111 1111  0101 0101

明确有BOM的可以辨别（）

第二种方法，例如python的chardet库可以帮助推测文件编码，chardet库通过分析文件内容的字符分布模式来猜测文件的编码格式。不同的文件内容可能会导致不同的猜测结果，例如：
~~~python
import chardet
file_path = "test.txt"
# 读取文件内容，并使用 chardet.detect() 函数检测编码格式
with open(file_path, 'rb') as file:
    content = file.read()
    result = chardet.detect(content)

print("文件编码格式检测结果为:", result)
~~~

~~~shell
PS D:\NOMIsWiki\code\encode\char> python -u "d:\NOMIsWiki\code\encode\char\python_file_open.py"
文件内容为： "hello!"

文件编码格式检测结果为: {'encoding': 'ascii', 'confidence': 1.0, 'language': ''}
PS D:\NOMIsWiki\code\encode\char> python -u "d:\NOMIsWiki\code\encode\char\python_file_open.py"
文件内容为： "hello!"
欸嘿
文件编码格式检测结果为: {'encoding': 'utf-8', 'confidence': 0.7525, 'language': ''}
~~~
所以文件内容过少时，检测结果其实存在偏差

- 项目初期字符集的选择

可能考虑的点：
1. 项目需求
2. 跨平台性
3. 存储
4. 现有标准，兼容

- 系统各部分字符集的同步

处理代码的字符集/数据库的字符集/使用的其他库代码的字符集设置

处理代码的字符集例如VS项目的字符集设置；

数据库字符集例如常见的MySql的中文字符集设置问题 [对机理讲解比较清楚的博文](https://www.cnblogs.com/wj-1314/p/9147166.html)