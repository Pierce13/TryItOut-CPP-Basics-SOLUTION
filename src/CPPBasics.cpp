#include <iostream>
#include <iomanip>
#include <cmath>

double incomeCalc(){
    //TODO: Declare a variable of type int called year and set it equal to 2020
    int year = 2020;
    double moneyBag = 0;
    double income = 0;
    int cnt = 0;
    //TODO: write a loop (either for or while will work) that will iterate from 2020-2024
    for(int i = 0; i < 5; i++){
        //TODO: Inside of the loop, write a cout statement that prompts the user to enter their
        //      their income for the current year. It should say the following:
        //      "Enter income for <year>:"
        std::cout << "Enter income for " << year << ": " << std::endl;
        //TODO: Still within the loop, write a cin statement that prompts the user to enter their
        //      income (hint: the variable should be of type double)
        std::cin >> income;
        moneyBag += income;
        year++;
        cnt++;
    }
    //TODO: Calculate the average income (hint: you will need a variable inside the loop
    //      that keeps a running total of the income)
    //      remember that the average is the sum divided by the number of observations
    double average = moneyBag / cnt;

    //TODO: print the average to the console and format the output to 2 decimal places
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Your average income is: " << average << std::endl;
    return average;
}

#ifndef TESTING
int main(){
    incomeCalc();
    return 0;
}
#endif
