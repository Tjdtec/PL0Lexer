# README

## Introduce

����Ŀ������й�PL0���ԵĴʷ�������������C���Դ��룬����ʵ�ֵķ�ʽ�ֱ���ͨ��flex�Զ�ʵ�ֺ��˹�ͨ��ֱ��ת���ֶ�ʵ�֡�

�����ֶ�ʵ�ֵĴʷ����������ҷ�����DFA_DIR�ļ����У�flex����س����ҷ�����`lex_dfa.l` ����ļ��С��ļ�`test.txt`, ��`test1.txt`, `text2.txt`�ֱ����������Ե�PL0��ش��룬`program_list.txt` �м�¼���Ǵ���ĳ��������������ֶ����ɵĴʷ����������б�������

�������������һ���ֶ����ɵ�Դ���룬��ô�ҽ�����ִ��`main.c` �������ɣ�`tool_function.c` �м�¼�˳��õĹ��ߺ�����`lexer_function.c` �����˸���״̬�Ķ�����`lexer.h` ��¼��Դ�����ͷ�ļ���

## Environment

����������

- ���ɿ���������CLion

- C���Ա�׼��C11

�ʷ��������ߣ�

- FLEX.exe

## DFA

ʵ�ֵĶ�ӦDFA��ԭʼͼƬ����:

![dfa_flow_origin](D:\Workplace\WindowsLexer\img\dfa_flow_origin.png)

���򾭹��Ҹ��˵��޸ĵ������DFA������ʾ��

![dfa_flow](D:\Workplace\WindowsLexer\img\dfa_flow.png)

## ��ʾЧ��

���ڲ���1 `test.txt` �ļ�������Ч��������ʾ

- ֱ��ת�򷨣��ֶ����ɣ�DFA

![test1.1](D:\Workplace\WindowsLexer\img\test1.1.png)

- FLEX�Զ�����DFA

![test1.2](D:\Workplace\WindowsLexer\img\test1.2.png)

�������Գ���Ľ��������� `img` �ļ��е��С�

## ˵���ͽ���

ֱ��ת��д����DFA��Ȼ����һ����bug��Ҫ�޸ĺ�ά�����ڴ�����Ϣ�Ĵ����沢û�����ĺܺã��Һܸм�����������޸�������ṩbug���ҽ���ʤ�м���

ͨѶ��ʽ: jiangdetutec@gmail.com# PL0Lexer
