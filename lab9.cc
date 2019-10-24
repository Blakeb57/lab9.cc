/*
*   @file: lab9.cc
*  
* @author: Blake Boehringer
*
*   @date: 10-24-19
*
*  @brief: A program that uses arrays to determine the highest daily low, the lowest daily low, and the average daily low
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;

/*prototypes*/

double lowestLowTemp(int dailyLow[], const int count);
double highestLowTemp(int dailyLow[], const int count);
double averageLowTemp(int dailyLow[], const int count);

int main(int argc, char const *argv[]) {

    int dailyLow[30];
    const int count = 30;
    ifstream inStream;
    ofstream outStream;
    inStream.open("athens_low_temps.txt");
    outStream.open("output.txt");

        for(int i = 0; i < count; i++){

            inStream >> dailyLow[i];

            cout << dailyLow[i] << endl;

        }
        
        cout << "-This is the lowest low temperature: " << lowestLowTemp(dailyLow, count) << endl;
        cout << "-This is the average low temperature: " << averageLowTemp(dailyLow, count) << endl;
        cout << "-This is the highest low temperature: " << highestLowTemp(dailyLow, count) << endl;
}

double lowestLowTemp(int dailyLow[], const int count){

    double low = 100;

    for(int i = 0; i < count; i++){

        if(dailyLow[i] < low){
            low = dailyLow[i];

        }

    }
    return low;

}

double highestLowTemp(int dailyLow[], const int count){

    double high = -100;

    for(int i = 0; i < count; i++){

        if(dailyLow[i] > high){
            high = dailyLow[i];

        }

    }
    return high;


}

double averageLowTemp(int dailyLow[], const int count){

    double total = 0;
    double average = 0;

    for(int i = 0; i < count; i++){

        total += dailyLow[i];
        average = (total / 30);

    }
    return average;

}
