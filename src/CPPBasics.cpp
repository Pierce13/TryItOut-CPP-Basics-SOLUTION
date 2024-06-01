#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double incomeCalc(){
    //TODO: Declare a variable of type int called year and set it equal to 2020
    int year = 2020;
    //TODO: write a loop (either for or while will work) that will iterate from 2020-2024
    //TODO: Inside of the loop, write a cout statement that prompts the user to enter their
    //      their income for the current year. It should say the following:
    //      "Enter income for <year>:"
    //TODO: Still within the loop, write a cin statement that prompts the user to enter their
    //      income (hint: the variable should be of type double)
    double income;
    double totalIncome;
    for(int i = 0; i < 5; i++){
        cout << "Enter income for " << year <<": ";
        cin >> income;
        totalIncome += income;
        year += 1;
    }
    //TODO: Calculate the average income (hint: you will need a variable inside the loop
    //      that keeps a running total of the income)
    //      remember that the average is the sum divided by the number of observations
    double average = totalIncome / 5;
    //TODO: print the average to the console and format the output to 2 decimal places
    cout << fixed << setprecision(2) << average << endl;

    return average;
}

#ifndef TESTING
int main(){
    incomeCalc();
    return 0;
}
#endif
