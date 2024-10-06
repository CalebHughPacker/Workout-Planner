/*
 * Plan.cpp
 *
 *  Created on: Oct 3, 2024
 *      Author: packe
 */

#include "Plan.h"
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;

Plan::Plan(string n) : name(n) {
	auto now = chrono::system_clock::now();
	currentTime = chrono::system_clock::to_time_t(now);
}

//Getters
string Plan::getName() const {
    return name;
}

string Plan::getWeekday() const {
	return weekday;
}

time_t Plan::getCurrentTime() const {
	return currentTime;
}

//Setters
vector<Exercise> Plan::getExercises() const {
	return exercises;
}

void Plan::setName(string n) {
    name = n;
}

void Plan::setWeekday(string w) {
    weekday = w;
}

void Plan::setCurrentTime(time_t t) {
    currentTime = t;
}

//Methods
void Plan::createExercise() {
	cin.clear();
	string strInput;
	cout << "What workout will you do: ";
	getline(cin, strInput);
	cout << endl;
	int intInput;

	cout << "How many sets do you plan on doing: ";
	cin.clear();
	cin >> intInput;
	cout << endl;
	Exercise exercise(strInput, intInput);
	exercise.createExercise(intInput);
	intInput = 8;
	while (intInput != 0){
		cout << "Enter the number for each weekday on a separate line then enter 0 when you are done." << endl;
		int count = 1;
		for (string& day : weekdays){
			cout << count << "| " << day << endl;
			++count;
		}
		cout << 0 << "| DONE" << endl;
		cin >> intInput;
		if (intInput > 7 || cin.fail()){
			cout << "Not a valid input";
			cin.clear();
			cin.ignore(10000, '\n');
		}
		else if (intInput != 0){
			weekIndices.push_back(intInput-1);
			exercise.addDays(intInput-1);
		}
		else{
			break;
		}
	}
	exercises.push_back(exercise);
}

void Plan::displayPlan() {
	cout << "Date Created | " << ctime(&currentTime) << endl;
	cout << "Plan: " << name << endl;
	cout << "------------------" << endl;
	for (int i=0; i < 7; ++i){
		cout << "<----" << weekdays[i] << "---->" << endl;
		for (Exercise& exercise : exercises) {
			if (containsDay(exercise.getDays(), i)){
				exercise.displayExercise();
				cout << endl;
				cout << endl;
			}
		}
	}
	cout << endl;
}


