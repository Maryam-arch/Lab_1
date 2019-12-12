#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

using namespace std;

template <class T>
class Keeper {
	T* ptr;						//��������� �� ��������
	int size;					//������ ����������
public:
	Keeper();
	Keeper(const Keeper&);
	~Keeper();

	void push(int index);		//���������� �������� �� �������
	void del(int index);		//�������� �������� �� �������

	void writefile(string s);	//������ � ����
	void readfile(string s);	//������ �� �����

	void print();				//����� ������ �� �����
	void record(int id);		//��������� ������
};

template<class T>
Keeper<T>::Keeper() {
	cout << "������ ����������� �� ��������� ������ Keeper" << endl << endl;
	ptr = nullptr;
	size = 0;
}

template<class T>
Keeper<T>::Keeper(const Keeper& other) {
	this->ptr = new T[other.size];				//������� ������ � ����� �������
	this->size = other.size;					//�������� ������

	for (int i = 0; i < size; ++i)				//�������� ������ ������� � ����� ������
		this->ptr[i] = other.ptr[i];
}

template<class T>
Keeper<T>::~Keeper() {
	cout << "������ ���������� ������ Keeper" << endl << endl;
	delete[] ptr;
}

template<class T>
void Keeper<T>::push(int index) {

	try {
		if (index < 0 || index > size)
			throw exception("������������ ������!");

		T* tmp = new T[size + 1];			//������� ����� ������ �� ���� ������� ������

		int j = 0;
		for (int i = 0; i < size; ++i) {	//�������� ��� �������� � ����� ������
			if (index == i)  				//���� ������ ����� ���������� ��������, �� ���������� ��� ������� � ����� �������
				j++;

			tmp[j++] = ptr[i];
		}

		delete[] ptr;						//������� ������ ������
		ptr = tmp;							//ptr ��������� �� ����� ������
		cin >> ptr[index];					//������ ������ ������������ ��������, ������� ��������� ��� �������� index
		++size;								//����������� ������ ����������
		cout << endl << "����� ������� ������� ��������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
}

template<class T>
void Keeper<T>::del(int id) {
	try {
		if (size == 0) {						//���� �� ���������
			exception ex("��������� ���! ������ �������!");
			throw ex;
		}
		if (id < 0 || id >= size) {				//��������� �� ������
			exception ex("����������� ������!");
			throw ex;
		}

		T* tmp = new T[size - 1];				//������� ����� ������ �� ���� ������� ������

		ptr[id] = ptr[size - 1];				//�������� ��������� ������� �� ����� ��������, ������� ����� �������
		for (int i = 0; i < size - 1; ++i) {	//�������� �������� ������� � ����� ������, ����� ����������
			tmp[i] = ptr[i];
		}
		delete[] ptr;							//������� ������ ������
		ptr = tmp;								//ptr ��������� �� ����� ������
		--size;									//������ ���������� ����������
		cout << endl << endl << "������� ������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;		//����� ������ �� �����
	}
}

template<class T>
void Keeper<T>::writefile(string s) {
	ofstream fout(s, ios::out);

	try {
		if (size == 0) {
			exception ex("������ ���������� � ����");
			throw ex;
		}

		fout << size << endl;						//������ ������� ����������
		for (int i = 0; i < size; ++i) {			//������ ���� ��������� ����������
			fout << ptr[i] << endl;
		}
		fout.close();

		cout << "������ � ���� ������ �������" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}


}

template<class T>
void Keeper<T>::readfile(string s) {
	delete[] ptr;								//������� ������, ��� ��� ����� �������� ������ �� �����

	ifstream fin(s, ios::in);

	fin >> size;								//��������� ������ ���������� � �����
	ptr = new T[size];							//������� ������ �������� ���������� � �����

	for (int i = 0; i < size; ++i) {			//��������� ��� �������� �� �����
		fin >> ptr[i];
	}

	fin.close();

	cout << "������ �� ����� ������ �������" << endl << endl;
}

template<class T>
void Keeper<T>::print() {

	if (size == 0) {							//���� ��������� ����
		cout << "��������� ���!" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) {		//������� ��� �������� ���������� �� �����
			cout << ptr[i] << endl;
		}
	}
}

template<class T>
void Keeper<T>::record(int id) {
	try {
		if (size == 0) {						//���� ��������� ����
			exception ex("��������� ���");
			throw ex;
		}
		if (id < 0 || id >= size) {				//������������ ������
			exception ex("������������ ������!");
			throw ex;
		}
		cin >> ptr[id];							//������ ����� ������ ���������� ��������
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;		//����� ������ �� �����
	}
}