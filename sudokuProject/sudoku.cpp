// sudoku.cpp: 定义控制台应用程序的入口点。

#include "stdafx.h"
using namespace std;

bool check(char * c); //判断读入的参数n是否为一数字

int main(int argc, char *argv[])
{
	
	if (!(argc == 3 && !strcmp(argv[1],"-c") && check(argv[2]))) //判断命令行读入参数的合理性
	{
		printf("Arguments error.\n"); //参数不合理，输出错误提示
		return 1; 
	}
	
	int n; //待生成的矩阵个数
	n = atoi(argv[2]); //字符串转换为数字
	ofstream out; 
	out.open("./sudoku.txt");
	out.clear(); //清空文件中上次生成的内容
	sudokuMat mat;
	mat.randomMat(n); //生成n个随机矩阵
    return 0;
}


/*
函数名：check
输入：待检验参数 char * c
输出：bool变量。为true代表参数合理，false代表参数错误。
功能：检验输入的字符串参数是否合理
*/
bool check(char * c)
{
	int len = strlen(c);
	for (int i = 0; i < len; i++)
	{
		if (!isdigit(c[i])) return false; //若非数字，返回false
	}
	return true; //是数字，返回true
}
