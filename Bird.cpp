#include "Bird.h"

Bird::Bird() {
	cout << "Вызван конструктор Bird" << endl << endl;
	string breed = "Пусто";
	string color = "Пусто";
	string food = "Пусто";
	string habitat = "Пусто";
}

Bird::Bird(const Bird& other) {
	cout << "Вызван конструктор копирования Bird" << endl << endl;
	*this = other;
}


Bird::~Bird() {
	cout << "Вызван деструктор Bird" << endl << endl;
}

Bird& Bird::operator=(const Bird& other) {
	this->breed = other.breed;
	this->color = other.color;
	this->food = other.food;
	this->habitat = other.habitat;

	return *this;
}

ofstream& operator<<(ofstream& fout, Bird& obj) {
	fout << obj.breed << " " << obj.color << " " << obj.food << " " << obj.habitat;
	return fout;
}

ifstream& operator>>(ifstream& fin, Bird& obj) {
	fin >> obj.breed >> obj.color >> obj.food >> obj.habitat;
	return fin;
}

ostream& operator<<(ostream& out, Bird& obj) {
	out << "Порода: " << obj.breed << endl;
	out << "Окрас: " << obj.color << endl;
	out << "Питание: " << obj.food << endl;
	out << "Место обитания: " << obj.habitat << endl;
	out << "--------------------------------------------------------------------------------";

	return out;
}

istream& operator>>(istream& in, Bird& obj) {
	cout << "Введите данные" << endl << endl;
	cout << "Порода: ";
	cin >> obj.breed;
	cout << "Окрас: ";
	cin >> obj.color;
	cout << "Тип питания: ";
	cin >> obj.food;
	cout << "Место обитание: ";
	cin >> obj.habitat;

	return in;
}