#include "CPPBasics.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <cstring>

using namespace std;

// Helper functions for testing
template <typename T>
bool checkTest(int testNum, int& correct, T whatItShouldBe, T whatItIs) {
    if (whatItShouldBe == whatItIs) {
        correct++;
        cout << "***TEST " << testNum << " PASSED***" << endl;
        return true;
    } else {
        cout << "***TEST " << testNum << " FAILED*** " << endl;
        cout << "   Output was " << whatItIs << endl;
        cout << "   Output should have been " << whatItShouldBe << endl;
        return false;
    }
}

// Function to test calculateCircleArea()
void testIncomeCalc(int& correctTests) {
    string incomeInput = "32000 33030.12 34401.5 35010 36600.6\n";
    stringstream inputBuffer(incomeInput);
    streambuf* oldCin = cin.rdbuf(inputBuffer.rdbuf());

    stringstream outputBuffer;
    streambuf* oldCout = cout.rdbuf(outputBuffer.rdbuf());

    double areaResult = incomeCalc();

    cin.rdbuf(oldCin);
    cout.rdbuf(oldCout);

    // Extract the actual result from the output buffer
    stringstream ss;
    ss << fixed << setprecision(2) << areaResult;
    string capturedOutput = ss.str();
    string expectedOutput = "34208.44";
    checkTest(1, correctTests, expectedOutput, capturedOutput);
}

// Function to run all tests
void runAllTests() {
    int correctTests = 0;
    testIncomeCalc(correctTests);
    cout << "Total tests passed: " << correctTests << " out of 1" << endl;
}

// Main function to run specific tests
int main(int argc, char* argv[]) {
    if (argc == 1) {
        runAllTests();
    } else if (argc == 2) {
        int correctTests = 0;
        int testNumber = atoi(argv[1]);

        switch (testNumber) {
            case 1:
                testIncomeCalc(correctTests);
                break;
            default:
                cerr << "Invalid test number. Please enter 1" << endl;
                return 1;
        }

        cout << "Total tests passed: " << correctTests << " out of 1" << endl;
    } else {
        cerr << "Usage: " << argv[0] << " [testNumber]" << endl;
        return 1;
    }

    return 0;
}
