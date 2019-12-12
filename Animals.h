#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

//����������� �����
class Animals {
protected:
	string breed;
	string color;

public:
	Animals() { cout << "������ ����������� Animals" << endl << endl; }
	virtual ~Animals() { cout << "������ ���������� Animals" << endl << endl; }

	//������ ����������� �������, ����� ����� ���� �����������
	virtual void setBreed(string) = 0;
	virtual void setColor(string) = 0;

	virtual string getBreed() = 0;
	virtual string getColor() = 0;
};