#pragma once
#ifndef CHANGETOOL_H
#define CHANGETOOL_H

/*
类名：changeTool
功能：提供矩阵变换和处理的工具函数，其中包括：
	  交换数字；交换行、列；交换大行、大列；
	  修正第一项元素值；输出矩阵
*/

class changeTool
{
public:
	changeTool(int mat[][9]);                 //赋值二维数组Mat为初始矩阵
	void swapNumber(int num1,int num2);       //交换数字（参数范围1~9）
	void swapRow(int i, int row1, int row2);  //交换行
	void swapCol(int i, int col1, int col2);  //交换列
	void swap3Row(int squ1, int squ2);        //以三行交换宫（参数范围0~2）
	void swap3Col(int squ1, int squ2);        //以三列交换宫（参数范围0~2）
	void check();                             //检查第一项是否为5，若非则修正
	int getMat(int a, int b);                 //返回私有成员Mat的元素值，用于测试使用

	int Mat[9][9];
};

#endif //!CHANGETOOL_H