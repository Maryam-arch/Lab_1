#include "Cat.h"

Cat::Cat() {
	cout << "Вызван конструктор Cat" << endl << endl;
	string breed = "Пусто";
	string color = "Пусто";
	string FIO = "Пусто";
	string alias = "Пусто";
}

Cat::Cat(const Cat& other) {
	cout << "Вызван конструктор копирования Cat" << endl << endl;
	*this = other;
}

Cat::~Cat() {
	cout << "Вызван деструктор Cat" << endl << endl;
}

Cat& Cat::operator=(const Cat& other) {
	this->breed = other.breed;
	this->color = other.color;
	this->FIO = other.FIO;
	this->alias = other.alias;

	return *this;
}

ofstream& operator<<(ofstream& fout, Cat& obj) {
	fout << obj.breed << " " << obj.color << " " << obj.FIO << " " << obj.alias;
	return fout;
}

ifstream& operator>>(ifstream& fin, Cat& obj) {
	fin >> obj.breed >> obj.color >> obj.FIO >> obj.alias;
	return fin;
}

ostream& operator<<(ostream& out, Cat& obj) {
	out << "Порода: " << obj.breed << endl;
	out << "Окрас: " << obj.color << endl;
	out << "ФИО владельца: " << obj.FIO << endl;
	out << "Кличка: " << obj.alias << endl;
	out << "--------------------------------------------------------------------------------";

	return out;
}

istream& operator>>(istream& in, Cat& obj) {
	cout << "Введите данные" << endl << endl;
	cout << "Порода: ";
	cin >> obj.breed;
	cout << "Окрас: ";
	cin >> obj.color;
	cout << "ФИО: ";
	cin >> obj.FIO;
	cout << "Кличка: ";
	cin >> obj.alias;

	return in;
}