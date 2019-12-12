#include "Func.h"

int main() {
	setlocale(LC_ALL, "");

	Keeper<Fish> fish;
	Keeper<Bird> bird;
	Keeper<Cat> cat;

	system("pause");

	int button;
	bool flag = true;
	while (flag) {
		system("cls");
		cout << "Выберите животное: " << endl << endl;
		cout << "1 - Рыба" << endl;
		cout << "2 - Птица" << endl;
		cout << "3 - Кот" << endl;
		cout << "0 - Выход из программы" << endl << endl;
		cout << "Выберите команду: ";
		cin >> button;
		if (cin.fail()) {
			button = -1;
			cin.clear();
			cin.ignore(10000, '\n');
		}

		switch (button) {
		case 1: menu(fish, "Fish.txt"); break;
		case 2: menu(bird, "Bird.txt"); break;
		case 3: menu(cat, "Cat.txt"); break;
		case 0: flag = false; break;
		default: cout << endl << "Введена некорректная команда!" << endl << endl; system("pause"); break;
		}
	}
	return 0;
}