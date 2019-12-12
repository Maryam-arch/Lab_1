#pragma once
#include "Animals.h"

class Bird : public Animals {
	string food;
	string habitat;
public:
	Bird();
	Bird(const Bird&);
	~Bird();

	void setBreed(string bread) override { this->breed = breed; }
	void setColor(string color) override { this->color = color; }
	void setTypeOfFood(string type_of_food) { this->food = type_of_food; }
	void setHabitat(string habitat) { this->habitat = habitat; }

	string getBreed() override { return breed; }
	string getColor() override { return color; }
	string getTypeOfFood() { return food; }
	string getHabitat() { return habitat; }

	friend ofstream& operator << (ofstream& fout, Bird& obj);
	friend ifstream& operator >> (ifstream& fin, Bird& obj);

	friend ostream& operator << (ostream& out, Bird& obj);
	friend istream& operator >> (istream& in, Bird& obj);

	Bird& operator =(const Bird& other);
};