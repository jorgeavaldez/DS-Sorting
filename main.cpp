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
#include "quicksort.h"

using namespace std;
using namespace chrono;

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

    
    SortingCompetition* sc = new QuickSort(input);
    sc->readData();
    sc->prepareData();
    sc->sortData();
    sc->outputData(output);
}
