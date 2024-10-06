/*
 * Plan.h
 *
 *  Created on: Oct 3, 2024
 *      Author: packe
 */

#ifndef PLAN_H_
#define PLAN_H_
#include <chrono>
#include <ctime>
#include <iostream>
#include <vector>
#include "Exercise.h"
using namespace std;

class Exercise;

class Plan {

private:
	string name;
	string weekday;
	time_t currentTime;
	vector<Exercise> exercises;//list of exercise objects
	vector<string> weekdays = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
	vector<int> weekIndices;
	bool containsDay(const vector<int>& vec, int target) {
	    for (int id : vec) {
	        if (id == target) {
	            return true;
	        }
	    }
	    return false;
	}

public:
	//Constructor
	Plan(string n);

	//Getters
	string getName() const;
	string getWeekday() const;
	time_t getCurrentTime() const;
	vector<Exercise> getExercises() const;

	//Setters
	void setName(string n);
	void setWeekday(string w);
	void setCurrentTime(time_t t);
	void setExercices(vector<Exercise> e);

	//methods
	void createExercise() ;
	void displayPlan() ;
};

#endif /* PLAN_H_ */
