# README

## Introduce

该项目完成了有关PL0语言的词法分析程序的相关C语言代码，其中实现的方式分别有通过flex自动实现和人工通过直接转向法手动实现。

其中手动实现的词法分析程序我放在了DFA_DIR文件夹中，flex的相关程序我放在了`lex_dfa.l` 这个文件中。文件`test.txt`, 和`test1.txt`, `text2.txt`分别是用来测试的PL0相关代码，`program_list.txt` 中记录的是处理的程序行数，他在手动生成的词法分析程序中被创建。

如果你期望运行一下手动生成的源代码，那么我建议你执行`main.c` 函数即可，`tool_function.c` 中记录了常用的工具函数，`lexer_function.c` 定义了各个状态的动作，`lexer.h` 记录了源代码的头文件。

## Environment

开发环境：

- 集成开发环境：CLion

- C语言标准：C11

词法分析工具：

- FLEX.exe

## DFA

实现的对应DFA的原始图片如下:

![dfa_flow_origin](D:\Workplace\WindowsLexer\img\dfa_flow_origin.png)

程序经过我个人的修改调整后的DFA如下所示：

![dfa_flow](D:\Workplace\WindowsLexer\img\dfa_flow.png)

## 演示效果

对于测试1 `test.txt` 文件的运行效果如下所示

- 直接转向法（手动生成）DFA

![test1.1](D:\Workplace\WindowsLexer\img\test1.1.png)

- FLEX自动生成DFA

![test1.2](D:\Workplace\WindowsLexer\img\test1.2.png)

其他测试程序的结果存放在了 `img` 文件夹当中。

## 说明和交流

直接转向法写出的DFA仍然存在一定的bug需要修改和维护，在错误信息的处理方面并没有做的很好，我很感激您向我提出修改意见或提供bug，我将不胜感激。

通讯方式: jiangdetutec@gmail.com# PL0Lexer
