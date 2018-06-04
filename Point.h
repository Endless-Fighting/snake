#pragma once
#include<iostream>  
#include<windows.h>  //调用HANDLE 进程句柄 - 进程索引指针（要访问该进程时取得的，使用完毕必须释放）

using namespace std;

class CPoint		//设置的这个类只用于Food和Snake类，并不在cpp中出现
{
public:
	CPoint() {}
	CPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void Plot(HANDLE hOut)
	{
		SetOutputPosition(x, y, hOut);
		cout << "■";
	}
	void Clear(HANDLE hOut)
	{
		SetOutputPosition(x, y, hOut);
		cout << "  ";			//两个空占位符
	}
	void Clear()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
		cout << " ";
	}
	//静态方法，用于设定输出点在控制台的位置  
	static void SetOutputPosition(int x, int y, HANDLE hOut)
	{
		COORD position;		//临时对象
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hOut, position);
	}
	bool operator == (CPoint& point)          //运算符重载
	{
		return (point.x == this->x) && (point.y == this->y);
	}
	//改变CPoint对象的位置  
	void SetPosition(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int GetX()
	{
		return x; 
	}
	int GetY()
	{ 
		return y; 
	}

private:
	int x;
	int y;
};