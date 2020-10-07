/**************************
 *Matthew Reid
 *CPSC 1021, Section 3, F20
 *mhreid@clemson.edu
 *Elliot McMillan and Victoria Xu
 **************************/

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <cstdlib>

using namespace std;


typedef struct Employee{
	string lastName;
	string firstName;
	int birthYear;
	double hourlyWage;
}employee;

bool name_order(const employee& lhs, const employee& rhs);
int myrandom (int i) { return rand()%i;}

int main(int argc, char const *argv[]) {
/*This is to seed the random generator */
	srand(unsigned (time(0)));

	int i;
//eList is my array of 10 employee structs
	employee eList[10];

	for (i = 0; i < 10; ++i) {
//asks for each employee's name
//First + Last <= 20 characters
		cout << endl << "Employee " << i+1 << "'s first and last name ([First] [Last]): ";
		cin >> eList[i].firstName >> eList[i].lastName;
//asks for the employee's birth year
		cout << "Employee " << i+1 << "'s birth year: ";
		cin >> eList[i].birthYear;
//asks for the employee's hourly wage
		cout << "Employee " << i+1 << "'s hourly wage: ";
		cin >> eList[i].hourlyWage;
	}
	cout << endl;

//Randomly shuffles the list of structs using the c++ random_shuffle function
	random_shuffle(eList, eList+10, myrandom);

/*I then created a new array of 5 employee structs where I stored
 *the new first 5 employee structs*/
	employee first5[5] = {eList[0], eList[1], eList[2], eList[3], eList[4]};

//Then sorted the new list of employees by calling the c++ sort function
	sort(first5, first5+5, name_order);

//header for my printed list of employees
	cout << "List of 5 Employees:" << endl;

//loop prints out the data of first5 until there are no more values in first5
//the setw() is set for 22 so it accounts for 20 characters in name plus ", "
//hourly wage is set to a precision of 2 because currency only goes to 2 decimal places
	for (auto x: first5) {
		cout << endl << setw(22) << x.lastName + ", " + x.firstName << endl;
		cout << setw(22) << x.birthYear << endl;
		cout << fixed << showpoint << setprecision(2) << setw(22) << x.hourlyWage << endl;
	}

  return 0;
}

/*This function will be passed to the sort funtion.*/
bool name_order(const employee& lhs, const employee& rhs) {
//checks to see which last name is alphabetically first
//lhs is the last name to the left of the rhs last name
  if (lhs.lastName < rhs.lastName) {
		return true;
	}
	else {
		return false;
	}
}
