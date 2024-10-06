/*
 * Exercise.h
 *
 *  Created on: Oct 3, 2024
 *      Author: packe
 */

#ifndef EXERCISE_H_
#define EXERCISE_H_

#include <iostream>
#include <vector>
using namespace std;
/*
 * Make two child classes: Strength and Cardio
 */
class Exercise{

protected:
	string name;
	int sets;
	vector<int> reps;
	vector<int> days;

public:
	Exercise(string n, int s);

	//getters
	string getName() const;
	int getSets() const;
	vector<int> getReps() const;
	vector<int> getDays() const;

	//setters
	void setName(string n);
	void setSets(int s);
	void setReps(vector<int> r);
	void setDays(vector<int> d);

	void createExercise(int setsCount) ;
	void displayExercise();
	void addDays(int day);
};



#endif /* EXERCISE_H_ */
