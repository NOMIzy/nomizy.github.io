file_path = "test.txt"
encoding = "utf-8"  # 指定解码的编码格式

with open(file_path, 'r', encoding=encoding) as file:
    content = file.read()
    print("文件内容为：",content)


import chardet
file_path = "test.txt"
# 读取文件内容，并使用 chardet.detect() 函数检测编码格式
with open(file_path, 'rb') as file:
    content = file.read()
    result = chardet.detect(content)

print("文件编码格式检测结果为:", result)