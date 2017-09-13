#include "stdafx.h"
using namespace std;

sudokuMat::sudokuMat()
{
	srand((unsigned)time(NULL)); //������ʱ���ʼ���������
}

/*
��������randomMat
���룺int n
�������
���ܣ�ѭ��n�Σ�ÿ�ε���getMat�����õ�һ������
*/
void sudokuMat::randomMat(int n)
{	
	ofstream out;
	out.open("./sudoku.txt", ios::app); //���ļ�������ǰ���׷�ӵ��ļ�ĩβ
	set<string> checkSet;

	while (n--)
	{
		changeTool ct(initMat);
		int changeTime = changeTimes; //ѭ������Ϊ50��
		int changeOption; //����任����
		int i, a, b; //����������
		
		while (changeTime--)
		{
			changeOption = rand() % 5;
			switch (changeOption)
			{
			case 0:                             //�任����Ϊ0ʱ�������ֽ���
				a = rand() % 9 + 1;
				b = rand() % 9 + 1;
				if (a != b) ct.swapNumber(a, b);
				break;
			case 1:                             //�任����Ϊ1ʱ�����н���
				i = rand() % 3;
				a = rand();
				b = rand();
				if (a != b) ct.swapRow(i, a, b);
				break;
			case 2:                             //�任����Ϊ2ʱ�����н���
				i = rand() % 3;
				a = rand();
				b = rand();
				if (a != b) ct.swapCol(i, a, b);
				break;
			case 3:                              //�任����Ϊ3ʱ���д��н���
				a = rand() % 3;
				b = rand() % 3;
				if (a != b)ct.swap3Row(a, b);
				break;
			case 4:                              //�任����Ϊ3ʱ���д��н���
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
		ct.check(); //������һ�Ϊ5�����
		
		char result[200]; //��������ַ���
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
		if (checkSet.find(re) != checkSet.end()) n++; //���ҵ�
		else
		{
			checkSet.insert(re);
			out << result;
		}
	}
	out.close();
	return;
}
