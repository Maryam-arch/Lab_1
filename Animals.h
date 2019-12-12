#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

//Абстрактный класс
class Animals {
protected:
	string breed;
	string color;

public:
	Animals() { cout << "Вызван конструктор Animals" << endl << endl; }
	virtual ~Animals() { cout << "Вызван деструктор Animals" << endl << endl; }

	//Чистые виртуальные функции, чтобы класс стал абстрактным
	virtual void setBreed(string) = 0;
	virtual void setColor(string) = 0;

	virtual string getBreed() = 0;
	virtual string getColor() = 0;
};