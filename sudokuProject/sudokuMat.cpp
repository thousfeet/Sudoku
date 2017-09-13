#include "stdafx.h"
using namespace std;

sudokuMat::sudokuMat()
{
	srand((unsigned)time(NULL)); //以运行时间初始化随机种子
}

/*
函数名：randomMat
输入：int n
输出：无
功能：循环n次，每次调用getMat函数得到一个矩阵
*/
void sudokuMat::randomMat(int n)
{	
	ofstream out;
	out.open("./sudoku.txt", ios::app); //打开文件，将当前结果追加到文件末尾
	set<string> checkSet;

	while (n--)
	{
		changeTool ct(initMat);
		int changeTime = changeTimes; //循环次数为50次
		int changeOption; //随机变换类型
		int i, a, b; //随机传入参数
		
		while (changeTime--)
		{
			changeOption = rand() % 5;
			switch (changeOption)
			{
			case 0:                             //变换类型为0时进行数字交换
				a = rand() % 9 + 1;
				b = rand() % 9 + 1;
				if (a != b) ct.swapNumber(a, b);
				break;
			case 1:                             //变换类型为1时进行行交换
				i = rand() % 3;
				a = rand();
				b = rand();
				if (a != b) ct.swapRow(i, a, b);
				break;
			case 2:                             //变换类型为2时进行列交换
				i = rand() % 3;
				a = rand();
				b = rand();
				if (a != b) ct.swapCol(i, a, b);
				break;
			case 3:                              //变换类型为3时进行大行交换
				a = rand() % 3;
				b = rand() % 3;
				if (a != b)ct.swap3Row(a, b);
				break;
			case 4:                              //变换类型为3时进行大列交换
				a = rand() % 3;
				b = rand() % 3;
				if (a != b) ct.swap3Col(a, b);
				break;
			default:
				a = rand() % 9 + 1;
				b = rand() % 9 + 1;
				if (a != b) ct.swapNumber(a, b);
				break;
			}
		}
		ct.check(); //修正第一项不为5的情况
		
		char result[200]; //结果矩阵字符串
		int cnt = 0;
		for (int i = 0; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				result[cnt++] = '0' + ct.getMat(i, j);
				result[cnt++] = ' ';
			}
			result[cnt++] = '\n';
		}
		result[cnt++] = '\n';
		result[cnt] = '\0';

		string re = result;
		if (checkSet.find(re) != checkSet.end()) n++; //若找到
		else
		{
			checkSet.insert(re);
			out << result;
		}
	}
	out.close();
	return;
}
