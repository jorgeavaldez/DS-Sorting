//
//  main.cpp
//  Project3
//
//  Created by Microsoft R&D on 2/17/15.
//  Copyright (c) 2015 Microsoft R&D. All rights reserved.
//

#include <iostream>
#include <chrono>
#include <ctime>
#include "SortingCompetition.h"
#include "quicksort.h"
#include "bubblesort.h"

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

    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    SortingCompetition* sc = new BubbleSort(input);
    if (!sc->readData()) return 1;
    if (!sc->prepareData()) return 1;
    
    start = chrono::system_clock::now();
    sc->sortData();
    end = chrono::system_clock::now();
    
    chrono::duration<double> elapsed_seconds = end - start;
    
    sc->outputData(output);
    
    time_t end_time = chrono::system_clock::to_time_t(end);
    
    //output the duration.
    cout << "finished computation at " << end_time << endl;
    cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
