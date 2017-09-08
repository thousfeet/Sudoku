#pragma once
#ifndef SUDOKUMAT_H
#define SUDOKUMAT_H

/*
������sudokuMat
���ܣ������������
*/

class sudokuMat
{
public:
	sudokuMat();            //��ʼ���������
	void randomMat(int n);  //����n���������
	void getMat();          //ͨ���������������󲢴�ӡ

private:
	const int changeTimes = 50;  //�任�������
	int initMat[9][9] =          //��ʼ����
	{
		{ 5, 7, 4, 6, 3, 1, 8, 9, 2 },
		{ 8, 9, 6, 7, 2, 5, 4, 3, 1 },
		{ 2, 3, 1, 4, 8, 9, 6, 5, 7 },
		{ 4, 5, 2, 1, 9, 6, 7, 8, 3 },
		{ 7, 6, 8, 3, 5, 4, 2, 1, 9 },
		{ 9, 1, 3, 8, 7, 2, 5, 4, 6 },
		{ 3, 2, 9, 5, 6, 8, 1, 7, 4 },
		{ 1, 8, 7, 2, 4, 3, 9, 6, 5 },
		{ 6, 4, 5, 9, 1, 7, 3, 2, 8 }
	};
};

#endif // !SUDOKUMAT_H