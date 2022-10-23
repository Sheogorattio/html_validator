#include <iostream>
#include<fstream>
#include "Stack.h"
using namespace std;

void GetPath(char* arr, const int size) {
	cout << "Enter path:\t";
	cin >> arr;
}

bool IsOpen(char c) {
	return c == '<';
}

bool IsClose(char c) {
	return c == '>';
}

char CompareBeg(char c) {
	return c == '>' ? '<' : '\0';
}

void Check(Stack& obj, char* arr) {
	for (int i = 0; i < strlen(arr); i++) {
		if (IsOpen(arr[i]) == 1) {
			obj.Push(arr[i]);
		}
		else {
			if (IsClose(arr[i]) == 1) {
				if (obj.IsEmpty() != 1 && obj.GetTopVal() == CompareBeg(arr[i])) {
					obj.Pop();
				}
				else {
					cout << "error" << i << "index\n" << arr[i] << endl;
					return;
				}
			}
		}
	}
	cout << "Ok\n";
}

int main() {
	const int size = 255;
	char PATH[size];
	GetPath(PATH, size);
	fstream inout("hypertext.txt", ios::in | ios::out );
	inout.seekg(0, ios::end);
	int buff_size = inout.tellg();
	char* buffer = new char[buff_size];
	inout.seekg(0, ios::beg);
	int i = -1;
	while (!inout.eof()) {
		char c = inout.get();
		c == '<' || c == '>' ? buffer[++i] = c : c ='\0';
	}
	inout.close();
	char *temp = new char[i+2];
	for (int q = 0; q <= i; q++) {
		temp[q] = buffer[q];
	}
	temp[i+1] = '\0';
	delete[]buffer;
	buffer = new char[strlen(temp) + 1];
	for (int q = 0; q < strlen(temp) + 1; q++) {
		buffer[q] = temp[q];
	}
	buffer[i + 1] = '\0';
	delete[]temp;
	Stack st;
	Check(st, buffer);
	delete[]buffer;
}