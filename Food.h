#pragma once
#include<iostream>  
#include "Point.h"  
using namespace std;

class CFood
{
public:
	CFood()		//Ĭ��ʳ���ʼʳ�λ��
	{
		position.SetPosition(20, 20);
	}

	CFood(int x, int y)		//������ʳ���λ���趨
	{
		position.SetPosition(x, y);
	}

	void PlaceFood(int x, int y)			//	�ڿ���̨���ʳ��
	{
		position.SetPosition(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		CPoint::SetOutputPosition(x, y, hOut);				//CPoint ��̬����
		cout << "$$";
	}

	CPoint& GetPosition()		//���ص�ֵ��һ��CPoint����
	{
		return position;
	}

	void Show()
	{
		cout << '(' << position.GetX() << ',' << position.GetY() << ')';
	}

private:
	CPoint position;		//	�����Ա- CPoint��һ��������ΪFood��˽�г�Ա
};