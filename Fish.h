#pragma once
#include "Animals.h"

class Fish : public Animals {
	string type_of_food;
public:
	Fish();
	Fish(const Fish&);
	~Fish();

	void setBreed(string bread) override { this->breed = breed; }
	void setColor(string color) override { this->color = color; }
	void setTypeOfFood(string type_of_food) { this->type_of_food = type_of_food; }

	string getBreed() override { return breed; }
	string getColor() override { return color; }
	string getTypeOfFood() { return type_of_food; }

	friend ofstream& operator << (ofstream& fout, Fish& obj);
	friend ifstream& operator >> (ifstream& fin, Fish& obj);

	friend ostream& operator << (ostream& out, Fish& obj);
	friend istream& operator >> (istream& in, Fish& obj);

	Fish& operator =(const Fish& other);
};