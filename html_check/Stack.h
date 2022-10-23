#pragma once
#include <iostream>
#include <time.h>
using namespace std;

class Stack
{
	// ������ � ������� ������� �����
	enum { EMPTY = -1, FULL = 255 };
	// ������ ��� �������� ������
	char st[FULL + 1];
	// ��������� �� ������� �����
	int top;

public:
	// �����������
	Stack();

	// ���������� ��������
	void Push(char c);

	// ���������� ��������
	char Pop();

	// ������� �����
	void Clear();

	// �������� ������������� ��������� � �����
	bool IsEmpty();

	// �������� �� ������������ �����
	bool IsFull();

	// ���������� ��������� � �����
	int GetCount();

	void Output()
	{
		for (int i = 0; i < top + 1; i++)
		{
			cout << st[i] << " ";
		}
		cout << endl;
	}

	Stack* operator=(const Stack& obj);

	char GetChar(int index)const;

	char GetTopVal()const;
};