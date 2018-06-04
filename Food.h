#pragma once
#include<iostream>  
#include "Point.h"  
using namespace std;

class CFood
{
public:
	CFood()		//默认食物（初始食物）位置
	{
		position.SetPosition(20, 20);
	}

	CFood(int x, int y)		//后来的食物的位置设定
	{
		position.SetPosition(x, y);
	}

	void PlaceFood(int x, int y)			//	在控制台输出食物
	{
		position.SetPosition(x, y);
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);		
		SetConsoleTextAttribute(hOut, FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		CPoint::SetOutputPosition(x, y, hOut);				//CPoint 静态方法
		cout << "$$";
	}

	CPoint& GetPosition()		//返回的值是一个CPoint对象
	{
		return position;
	}

	void Show()
	{
		cout << '(' << position.GetX() << ',' << position.GetY() << ')';
	}

private:
	CPoint position;		//	对象成员- CPoint的一个对象作为Food类私有成员
};