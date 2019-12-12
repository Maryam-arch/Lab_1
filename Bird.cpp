#include "Bird.h"

Bird::Bird() {
	cout << "������ ����������� Bird" << endl << endl;
	string breed = "�����";
	string color = "�����";
	string food = "�����";
	string habitat = "�����";
}

Bird::Bird(const Bird& other) {
	cout << "������ ����������� ����������� Bird" << endl << endl;
	*this = other;
}


Bird::~Bird() {
	cout << "������ ���������� Bird" << endl << endl;
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
	out << "������: " << obj.breed << endl;
	out << "�����: " << obj.color << endl;
	out << "�������: " << obj.food << endl;
	out << "����� ��������: " << obj.habitat << endl;
	out << "--------------------------------------------------------------------------------";

	return out;
}

istream& operator>>(istream& in, Bird& obj) {
	cout << "������� ������" << endl << endl;
	cout << "������: ";
	cin >> obj.breed;
	cout << "�����: ";
	cin >> obj.color;
	cout << "��� �������: ";
	cin >> obj.food;
	cout << "����� ��������: ";
	cin >> obj.habitat;

	return in;
}