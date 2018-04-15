#include "expenses.h"

void Expenses::setFoodCost(double food) {
	this->foodCost = food;
}

double Expenses::getFoodCost() {
	return this->foodCost;
}

void Expenses::setRentCost(double rent) {
	this->rentCost = rent;
}

double Expenses::getRentCost() {
	return this->rentCost;
}

void Expenses::setEntertainmentCost(double entertainment) {
	this->entertainmentCost = entertainment;
}

double Expenses::getEntertainmentCost() {
	return this->entertainmentCost;
}

void Expenses::setTuitionCost(double tuition) {
	this->tuitionCost = tuition;
}

double Expenses::getTuitionCost() {
	return this->tuitionCost;
}

void Expenses::setSavingsCost(double savings) {
	this->savingsCost = savings;
}

double Expenses::getSavingsCost() {
	return this->savingsCost;
}

void Expenses::setMiscCost(double misc) {
	this->miscCost = misc;
}

double Expenses::getMiscCost() {
	return this->miscCost;
}

double totalExpenses(){
	return getFoodCost() + getRentCost() + getEntertainmentCost() + getTuitionCost() + getSavingsCost() + getMiscCost();
}
