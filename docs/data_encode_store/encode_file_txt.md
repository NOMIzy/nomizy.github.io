# 文本文件的编码
## 文本编辑器如何知道文本编码？

当一个软件打开一个文本时，它要做的第一件事是决定这个文本究竟是使用哪种字符集的哪种编码保存的。软件一般采用三种方式来决定文本的字符集和编码：

1. 检测文件头标识（BOM）
> EF BB BF UTF-8
> FE FF UTF-16/UCS-2, big endian
> FF FE UTF-16/UCS-2, little endian
> FF FE 00 00 UTF-32/UCS-4, little endian.
> 00 00 FE FF UTF-32/UCS-4, big-endian.
2. 软件自己根据编码规则猜测当前文件的编码
3. 提示用户自己输入当前文件的编码