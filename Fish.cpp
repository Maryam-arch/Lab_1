#include "Fish.h"

Fish::Fish() {
	cout << "Вызван конструктор Fish" << endl << endl;
	string breed = "Пусто";
	string color = "Пусто";
	string type_of_food = "Пусто";
}

Fish::Fish(const Fish& other) {
	cout << "Вызван конструктор копирования Fish" << endl << endl;
	*this = other;
}


Fish::~Fish() {
	cout << "Вызван деструктор Fish" << endl << endl;
}

Fish& Fish::operator=(const Fish& other) {
	this->breed = other.breed;
	this->color = other.color;
	this->type_of_food = other.type_of_food;

	return *this;
}

ofstream& operator<<(ofstream& fout, Fish& obj) {
	fout << obj.breed << " " << obj.color << " " << obj.type_of_food;
	return fout;
}

ifstream& operator>>(ifstream& fin, Fish& obj) {
	fin >> obj.breed >> obj.color >> obj.type_of_food;
	return fin;
}

ostream& operator<<(ostream& out, Fish& obj) {
	out << "Порода: " << obj.breed << endl;
	out << "Окрас: " << obj.color << endl;
	out << "Тип питания: " << obj.type_of_food << endl;
	out << "--------------------------------------------------------------------------------";

	return out;
}

istream& operator>>(istream& in, Fish& obj) {
	cout << "Введите данные" << endl << endl;
	cout << "Порода: ";
	cin >> obj.breed;
	cout << "Окрас: ";
	cin >> obj.color;
	cout << "Тип питания: ";
	cin >> obj.type_of_food;

	return in;
}