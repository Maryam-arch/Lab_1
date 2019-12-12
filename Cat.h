#pragma once
#include "Animals.h"

class Cat : public Animals {
	string FIO;			//¬водить в формате: Efimova_Maryam_Fatherland
	string alias;
public:
	Cat();
	Cat(const Cat&);
	~Cat();

	void setBreed(string bread) override { this->breed = breed; }
	void setColor(string color) override { this->color = color; }
	void setTypeOfFood(string FIO) { this->FIO = FIO; }
	void setHabitat(string alias) { this->alias = alias; }

	string getBreed() override { return breed; }
	string getColor() override { return color; }
	string getFIO() { return FIO; }
	string getAlias() { return alias; }

	friend ofstream& operator << (ofstream& fout, Cat& obj);
	friend ifstream& operator >> (ifstream& fin, Cat& obj);

	friend ostream& operator << (ostream& out, Cat& obj);
	friend istream& operator >> (istream& in, Cat& obj);

	Cat& operator =(const Cat& other);
};