#pragma once
#ifndef CHANGETOOL_H
#define CHANGETOOL_H

/*
������changeTool
���ܣ��ṩ����任�ʹ���Ĺ��ߺ��������а�����
	  �������֣������С��У��������С����У�
	  ������һ��Ԫ��ֵ���������
*/

class changeTool
{
public:
	changeTool(int mat[][9]);                 //��ֵ��ά����MatΪ��ʼ����
	void swapNumber(int num1,int num2);       //�������֣�������Χ1~9��
	void swapRow(int i, int row1, int row2);  //������
	void swapCol(int i, int col1, int col2);  //������
	void swap3Row(int squ1, int squ2);        //�����н�������������Χ0~2��
	void swap3Col(int squ1, int squ2);        //�����н�������������Χ0~2��
	void check();                             //����һ���Ƿ�Ϊ5������������
	int getMat(int a, int b);                 //����˽�г�ԱMat��Ԫ��ֵ�����ڲ���ʹ��

	int Mat[9][9];
};

#endif //!CHANGETOOL_H