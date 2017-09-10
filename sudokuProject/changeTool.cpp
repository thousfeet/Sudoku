#include "stdafx.h"
using namespace std;

changeTool::changeTool(int mat[][9])
{
	memcpy(&Mat[0][0], &mat[0][0], 9 * 9 * sizeof(int)); //��ó�ʼ����
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
��������swapNumber
���룺int num1��int num2 ����ֵ��Χ1~9��
�������
���ܣ�����ֵΪnum1��ֵΪnum2��Ԫ��λ��
*/
void changeTool::swapNumber(int num1, int num2) 
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Mat[i][j] = Mat[i][j] == num1 ? num2 : (Mat[i][j] == num2 ? num1 : Mat[i][j]); //��Ԫ��ֵΪnum1���滻Ϊnum2����ֵΪnum2���滻Ϊnum1
		}
	}
}

/*
��������swapRow
���룺int i, int row1, int row2
�������
���ܣ�����λ��i�����ڲ����У������������±�ֱ�Ϊrow1%3��row2%3
*/
void changeTool::swapRow(int i, int row1, int row2)
{
	row1 = i * 3 + row1 % 3; //���մ��������±�
	row2 = i * 3 + row2 % 3; //���մ��������±�
	if (row1 != row2)
	{
		swap(Mat[row1], Mat[row2]);
	}
}

/*
��������swapCol
���룺int i, int col1, int col2
�������
���ܣ�����λ��i�����ڲ����У������������±�ֱ�Ϊcol1%3��col2%3
*/
void changeTool::swapCol(int i, int col1, int col2)
{
	col1 = i * 3 + col1 % 3; //���մ��������±�
	col2 = i * 3 + col2 % 3; //���մ��������±�
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
��������swap3Row
���룺int squ1, int squ2 ����ֵ��Χ0~2��
�������
���ܣ�������squ1���к�squ2���е�Ԫ��
*/
void changeTool::swap3Row(int squ1, int squ2) 
{
	for (int i = 0; i < 3; i++)
	{
		swap(Mat[squ1 * 3 + i], Mat[squ2 * 3 + i]); //���������е�ÿС��
	}
}

/*
��������swap3Col
���룺int squ1, int squ2 ����ֵ��Χ0~2��
�������
���ܣ�������squ1���к�squ2���е�Ԫ��
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
				swap(Mat[j][a], Mat[j][b]); //���������е�ÿС�е�Ԫ��
			}		
		}
	}
}

/*
��������changeTool
���룺��
�������
���ܣ����������һ�ȷ����ֵΪ5
*/
void changeTool::check()
{
	if (Mat[0][0] != 5)
	{
		swapNumber(5, Mat[0][0]); //����һ��ֵ��5��������ֵΪ5��Ԫ��λ�ý��н���
	}
}

int changeTool::getMat(int a, int b)
{
	return Mat[a][b];
}