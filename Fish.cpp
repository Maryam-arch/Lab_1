#include "Fish.h"

Fish::Fish() {
	cout << "������ ����������� Fish" << endl << endl;
	string breed = "�����";
	string color = "�����";
	string type_of_food = "�����";
}

Fish::Fish(const Fish& other) {
	cout << "������ ����������� ����������� Fish" << endl << endl;
	*this = other;
}


Fish::~Fish() {
	cout << "������ ���������� Fish" << endl << endl;
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
	out << "������: " << obj.breed << endl;
	out << "�����: " << obj.color << endl;
	out << "��� �������: " << obj.type_of_food << endl;
	out << "--------------------------------------------------------------------------------";

	return out;
}

istream& operator>>(istream& in, Fish& obj) {
	cout << "������� ������" << endl << endl;
	cout << "������: ";
	cin >> obj.breed;
	cout << "�����: ";
	cin >> obj.color;
	cout << "��� �������: ";
	cin >> obj.type_of_food;

	return in;
}