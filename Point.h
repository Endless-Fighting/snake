#pragma once
#include<iostream>  
#include<windows.h>  //����HANDLE ���̾�� - ��������ָ�루Ҫ���ʸý���ʱȡ�õģ�ʹ����ϱ����ͷţ�

using namespace std;

class CPoint		//���õ������ֻ����Food��Snake�࣬������cpp�г���
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
		cout << "��";
	}
	void Clear(HANDLE hOut)
	{
		SetOutputPosition(x, y, hOut);
		cout << "  ";			//������ռλ��
	}
	void Clear()
	{
		HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE); 
		cout << " ";
	}
	//��̬�����������趨������ڿ���̨��λ��  
	static void SetOutputPosition(int x, int y, HANDLE hOut)
	{
		COORD position;		//��ʱ����
		position.X = x;
		position.Y = y;
		SetConsoleCursorPosition(hOut, position);
	}
	bool operator == (CPoint& point)          //���������
	{
		return (point.x == this->x) && (point.y == this->y);
	}
	//�ı�CPoint�����λ��  
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