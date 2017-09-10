#include "stdafx.h"
using namespace std;

changeTool::changeTool(int mat[][9])
{
	memcpy(&Mat[0][0], &mat[0][0], 9 * 9 * sizeof(int)); //获得初始矩阵
	/*	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			printf("%d ", Mat[i][j]);
		}
		printf("\n");
	}*/
}

/*
函数名：swapNumber
输入：int num1、int num2 （数值范围1~9）
输出：无
功能：交换值为num1和值为num2的元素位置
*/
void changeTool::swapNumber(int num1, int num2) 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Mat[i][j] = Mat[i][j] == num1 ? num2 : (Mat[i][j] == num2 ? num1 : Mat[i][j]); //若元素值为num1则替换为num2；若值为num2则替换为num1
		}
	}
}

/*
函数名：swapRow
输入：int i, int row1, int row2
输出：无
功能：交换位于i大行内部的行，待交换的行下标分别为row1%3和row2%3
*/
void changeTool::swapRow(int i, int row1, int row2)
{
	row1 = i * 3 + row1 % 3; //最终待交换行下标
	row2 = i * 3 + row2 % 3; //最终待交换行下标
	if (row1 != row2)
	{
		swap(Mat[row1], Mat[row2]);
	}
}

/*
函数名：swapCol
输入：int i, int col1, int col2
输出：无
功能：交换位于i大列内部的列，待交换的列下标分别为col1%3和col2%3
*/
void changeTool::swapCol(int i, int col1, int col2)
{
	col1 = i * 3 + col1 % 3; //最终待交换列下标
	col2 = i * 3 + col2 % 3; //最终待交换列下标
	if (col1 != col2)
	{
		for (int i = 0; i < 9; i++)
		{
			if(Mat[i][col1] != Mat[i][col2])
			{
				swap(Mat[i][col1], Mat[i][col2]);
			}		
		}
	}
}

/*
函数名：swap3Row
输入：int squ1, int squ2 （数值范围0~2）
输出：无
功能：交换第squ1大行和squ2大行的元素
*/
void changeTool::swap3Row(int squ1, int squ2) 
{
	for (int i = 0; i < 3; i++)
	{
		swap(Mat[squ1 * 3 + i], Mat[squ2 * 3 + i]); //交换大行中的每小行
	}
}

/*
函数名：swap3Col
输入：int squ1, int squ2 （数值范围0~2）
输出：无
功能：交换第squ1大列和squ2大列的元素
*/
void changeTool::swap3Col(int squ1, int squ2)
{
	int a, b;
	for (int i = 0; i < 3; i++)
	{
		a = squ1 * 3 + i;
		b = squ2 * 3 + i;
		for (int j = 0; j < 9; j++)
		{
			if(Mat[j][a] != Mat[j][b])
			{
				swap(Mat[j][a], Mat[j][b]); //交换大列中的每小列的元素
			}		
		}
	}
}

/*
函数名：changeTool
输入：无
输出：无
功能：修正矩阵第一项，确保其值为5
*/
void changeTool::check()
{
	if (Mat[0][0] != 5)
	{
		swapNumber(5, Mat[0][0]); //若第一项值非5，则将其与值为5的元素位置进行交换
	}
}

int changeTool::getMat(int a, int b)
{
	return Mat[a][b];
}