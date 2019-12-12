#pragma once
#include <iostream>
#include <string>
#include <exception>
#include <fstream>

using namespace std;

template <class T>
class Keeper {
	T* ptr;						//Указатель на элементы
	int size;					//Размер контейнера
public:
	Keeper();
	Keeper(const Keeper&);
	~Keeper();

	void push(int index);		//Добавление элемента по индексу
	void del(int index);		//Удаление элемента по индексу

	void writefile(string s);	//Запись в файл
	void readfile(string s);	//Чтение из файла

	void print();				//Вывод данных на экран
	void record(int id);		//Изменение данных
};

template<class T>
Keeper<T>::Keeper() {
	cout << "Вызван конструктор по умолчанию класса Keeper" << endl << endl;
	ptr = nullptr;
	size = 0;
}

template<class T>
Keeper<T>::Keeper(const Keeper& other) {
	this->ptr = new T[other.size];				//Создаем массив в новом объекте
	this->size = other.size;					//Копируем размер

	for (int i = 0; i < size; ++i)				//Копируем каждый элемент в новый объект
		this->ptr[i] = other.ptr[i];
}

template<class T>
Keeper<T>::~Keeper() {
	cout << "Вызван деструктор класса Keeper" << endl << endl;
	delete[] ptr;
}

template<class T>
void Keeper<T>::push(int index) {

	try {
		if (index < 0 || index > size)
			throw exception("Некорректный индекс!");

		T* tmp = new T[size + 1];			//Создаем новый массив на один элемент больше

		int j = 0;
		for (int i = 0; i < size; ++i) {	//Копируем все элементы в новый массив
			if (index == i)  				//Если индекс равен введенному значению, то пропускаем это элемент в новом массиве
				j++;

			tmp[j++] = ptr[i];
		}

		delete[] ptr;						//Удаляем старый массив
		ptr = tmp;							//ptr указывает на новый массив
		cin >> ptr[index];					//Вводим данные добавленного элемента, который находится под индексом index
		++size;								//Увеличиваем размер контейнера
		cout << endl << "Новый элемент успешно добавлен" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;
	}
}

template<class T>
void Keeper<T>::del(int id) {
	try {
		if (size == 0) {						//Пуст ли контейнер
			exception ex("Элементов нет! Нечего удалять!");
			throw ex;
		}
		if (id < 0 || id >= size) {				//Корректен ли индекс
			exception ex("Некоректный индекс!");
			throw ex;
		}

		T* tmp = new T[size - 1];				//Создаем новый массив на один элемент меньше

		ptr[id] = ptr[size - 1];				//Копируем последний элемент на место элемента, который хотим удалить
		for (int i = 0; i < size - 1; ++i) {	//Копируем элементы массива в новый массив, кроме последнего
			tmp[i] = ptr[i];
		}
		delete[] ptr;							//Удаляем старый массив
		ptr = tmp;								//ptr указывает на новый массив
		--size;									//Размер контейнера уменьшился
		cout << endl << endl << "Элемент удален" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;		//Вывод ошибки на экран
	}
}

template<class T>
void Keeper<T>::writefile(string s) {
	ofstream fout(s, ios::out);

	try {
		if (size == 0) {
			exception ex("Нечего записывать в файл");
			throw ex;
		}

		fout << size << endl;						//Запись размера контейнера
		for (int i = 0; i < size; ++i) {			//Запись всех элементов контейнера
			fout << ptr[i] << endl;
		}
		fout.close();

		cout << "Запись в файл прошла успешно" << endl << endl;
	}
	catch (exception& ex) {
		cout << ex.what() << endl;
	}


}

template<class T>
void Keeper<T>::readfile(string s) {
	delete[] ptr;								//Очищаем массив, так как будут записаны данные из файла

	ifstream fin(s, ios::in);

	fin >> size;								//Считываем размер контейнера в файле
	ptr = new T[size];							//Создаем массив размером контейнера в файле

	for (int i = 0; i < size; ++i) {			//Считываем все элементы из файла
		fin >> ptr[i];
	}

	fin.close();

	cout << "Чтение из файла прошло успешно" << endl << endl;
}

template<class T>
void Keeper<T>::print() {

	if (size == 0) {							//Если контейнер пуст
		cout << "Элементов нет!" << endl << endl;
	}
	else {
		for (int i = 0; i < size; ++i) {		//Выводим все элементы контейнера на экран
			cout << ptr[i] << endl;
		}
	}
}

template<class T>
void Keeper<T>::record(int id) {
	try {
		if (size == 0) {						//Если контейнер пуст
			exception ex("Элементов нет");
			throw ex;
		}
		if (id < 0 || id >= size) {				//Некорректный индекс
			exception ex("Некорректный индекс!");
			throw ex;
		}
		cin >> ptr[id];							//Вводим новые данные выбранного элемента
	}
	catch (exception& ex) {
		cout << ex.what() << endl << endl;		//Вывод ошибки на экран
	}
}