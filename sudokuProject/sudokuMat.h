#pragma once
#ifndef SUDOKUMAT_H
#define SUDOKUMAT_H

/*
类名：sudokuMat
功能：生成随机矩阵
*/

class sudokuMat
{
public:
	sudokuMat();            //初始化随机种子
	void randomMat(int n);  //生成n个随机矩阵
	void getMat();          //通过交换获得随机矩阵并打印

private:
	const int changeTimes = 50;  //变换矩阵次数
	int initMat[9][9] =          //初始矩阵
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