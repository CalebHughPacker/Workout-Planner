//============================================================================
// Name        : Workout-Planner.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Plan.h"
#include <string>

vector<Plan> plans;

int main() {

	int input;
	while (input != 4){
		std::cout << "1. Create a new Plan\n2. Add Exercises to Existing Plan\n3. View Plan\n4. Quit " << endl;
		std::cout << "What would you like to do? | " << endl;
		std::cin >> input;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if ( cin.fail()){
			cin.clear();
			cin.ignore(10000, '\n');
			input = 5;
		}
		switch (input){
			case 1:{
				std::cout << "What would you like to name your plan: ";
				std::string name;
				std::getline(std::cin,name);
				Plan plan(name);
				plans.push_back(plan);
				std::cout << endl << "Plan Created!" << endl << endl;
				break;
			}
			case 2: {
				std::cout << "What is the name of the plan you would like to modify? (or just hit ENTER for most recent plan) ";
				std::string name;
				std::getline(std::cin,name);
				bool found = false;
				if (name != ""){
					for (Plan& plan : plans) {
						if (plan.getName() == name){
							plan.createExercise();
							found = true;
							break;
						}
					}
					if (!found){
						std::cout << "Plan not found" << endl;
					}
				} else {
					plans.back().createExercise();
				}

				break;
			}
			case 3: {
				std::cout << "What is the name of the plan you would like to view? (or just hit ENTER for most recent plan) ";
				std::string name;
				std::getline(std::cin,name);
				if (name != ""){
					for (Plan& plan : plans) {
						if (plan.getName() == name){
							plan.displayPlan();
							break;
						}
					}
					std::cout << "Plan not found" << endl;
				} else {
					plans.back().displayPlan();
				}
				break;
			}
			case 4: {
				return 0;
				break;
			}
			default: {
				std::cout << "Invalid input. Please try again." << std::endl;
				break;

			}
		}
	}
	return 0;
}
