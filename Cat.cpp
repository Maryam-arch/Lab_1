#include "Cat.h"

Cat::Cat() {
	cout << "������ ����������� Cat" << endl << endl;
	string breed = "�����";
	string color = "�����";
	string FIO = "�����";
	string alias = "�����";
}

Cat::Cat(const Cat& other) {
	cout << "������ ����������� ����������� Cat" << endl << endl;
	*this = other;
}

Cat::~Cat() {
	cout << "������ ���������� Cat" << endl << endl;
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
	out << "������: " << obj.breed << endl;
	out << "�����: " << obj.color << endl;
	out << "��� ���������: " << obj.FIO << endl;
	out << "������: " << obj.alias << endl;
	out << "--------------------------------------------------------------------------------";

	return out;
}

istream& operator>>(istream& in, Cat& obj) {
	cout << "������� ������" << endl << endl;
	cout << "������: ";
	cin >> obj.breed;
	cout << "�����: ";
	cin >> obj.color;
	cout << "���: ";
	cin >> obj.FIO;
	cout << "������: ";
	cin >> obj.alias;

	return in;
}