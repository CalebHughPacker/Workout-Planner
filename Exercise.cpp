/*
 * Exercise.cpp
 *
 *  Created on: Oct 3, 2024
 *      Author: packe
 */

#include "Exercise.h"
#include <iostream>
#include <vector>
using namespace std;

Exercise::Exercise(string n, int s) : name(n), sets(s){

}

string Exercise::getName() const {
    return name;
}

int Exercise::getSets() const {
	return sets;
}

vector<int> Exercise::getReps() const {
	return reps;
}

vector <int> Exercise::getDays() const {
	return days;
}

void Exercise::setName(string n) {
    name = n;
}

void Exercise::setSets(int s) {
    sets = s;
}

void Exercise::setReps(vector<int> r) {
    reps = r;
}

void Exercise::setDays(vector<int> d){
	days = d;
}

void Exercise::createExercise(int setsCount) {
	for (int i=0; i < setsCount; i++){
		int rep;
		cout << "How many reps do you plan on doing in set " << i+1 << ": ";
		cin >> rep;
		reps.push_back(rep);
	}
}
void Exercise::displayExercise(){
	cout << name << endl << "Sets: " << sets << endl << "Reps: ";
	int count = 1;
	for (const int& rep : reps) {
		char comma = ',';
		if (count == sets){
			comma = ' ';
		}
		cout << rep << comma << ' ';
		++count;
	}
}

void Exercise::addDays(int day){
	days.push_back(day);
}
