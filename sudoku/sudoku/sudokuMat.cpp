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

	while (n--)
	{
		getMat();
	}
	return;
}

/*
函数名：getMat
输入：无
输出：无
功能：循环50次，每次进行随机变换。变换结束后修
	  正矩阵第一位并打印输出。
*/
void sudokuMat::getMat()
{
	changeTool ct(initMat);
	int changeTime = changeTimes; //循环次数为50次
	int changeOption; //随机变换类型
	int i,a,b; //随机传入参数

	while (changeTime--)
	{
		changeOption = rand()%5;
		switch (changeOption)
		{
		case 0:                             //变换类型为0时进行数字交换
			a = rand() % 9 + 1;
			b = rand() % 9 + 1;
			if(a!=b) ct.swapNumber(a, b); 
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
			if (a != b )ct.swap3Row(a, b);
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
	ct.printMat(); //打印输出最终矩阵
}
