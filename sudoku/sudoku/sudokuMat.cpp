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

	while (n--)
	{
		getMat();
	}
	return;
}

/*
��������getMat
���룺��
�������
���ܣ�ѭ��50�Σ�ÿ�ν�������任���任��������
	  �������һλ����ӡ�����
*/
void sudokuMat::getMat()
{
	changeTool ct(initMat);
	int changeTime = changeTimes; //ѭ������Ϊ50��
	int changeOption; //����任����
	int i,a,b; //����������

	while (changeTime--)
	{
		changeOption = rand()%5;
		switch (changeOption)
		{
		case 0:                             //�任����Ϊ0ʱ�������ֽ���
			a = rand() % 9 + 1;
			b = rand() % 9 + 1;
			if(a!=b) ct.swapNumber(a, b); 
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
			if (a != b )ct.swap3Row(a, b);
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
	ct.printMat(); //��ӡ������վ���
}