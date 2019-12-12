#pragma once
#include "Keeper.h"
#include "Bird.h"
#include "Cat.h"
#include "Fish.h"
#include <iostream>

using namespace std;

template <typename T>
void menu(T& obj, string s) {
	int button;
	int id;
	bool flag = true;

	while (flag) {
		system("cls");
		cout << "Выберите действие: " << endl << endl;
		cout << "1 - Добавить объект" << endl;
		cout << "2 - Удалить объект" << endl;
		cout << "3 - Вывод данных из объектов" << endl;
		cout << "4 - Изменение данных" << endl;
		cout << "5 - Сохранение в файл" << endl;
		cout << "6 - Восстонавление из файла" << endl;
		cout << "0 - Выход в основное меню" << endl << endl;
		cout << "Выберите команду: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}
		system("cls");
		switch (button) {
		case 1: cout << "На какое место вставить новый элемент: "; cin >> id; obj.push(id); system("pause"); break;
		case 2: obj.print(); cout << "Какой элемент удалить: "; cin >> id; obj.del(id); system("pause"); break;
		case 3: obj.print(); system("pause"); break;
		case 4: obj.print(); cout << "Какой элемент изменить: "; cin >> id; obj.record(id); system("pause"); break;
		case 5: obj.writefile(s); system("pause"); break;
		case 6: obj.readfile(s); system("pause"); break;
		case 0: flag = false; break;
		default: cout << "Введена некорректная команда!" << endl << endl; system("pause"); break;
		}
	}
}