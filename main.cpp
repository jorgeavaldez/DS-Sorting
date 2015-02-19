//
//  main.cpp
//  Project3
//
//  Created by Jorge Valdez on 2/17/15.
//  Copyright (c) 2015 Jorge Valdez. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include "SortingCompetition.h"

using namespace std;
using namespace chrono;

long fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    string input;
    string output;
    
    cout << "Please enter the input file name: ";
    cin >> input;
    cout << "\n" << input << endl;
    
    cout << "Please enter the output file name: ";
    cin >> output;
    cout << "\n" << input << endl;

    
    SortingCompetition sc("/users/jorgev/projects/project4/" + input);
    sc.readData();
    sc.prepareData();
    sc.sortData();
    sc.outputData("/users/jorgev/projects/project4/" + output);
}
