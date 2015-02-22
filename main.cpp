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

int main(int argv, char** argc)
{
    string input;
    string output;
    
    if (argv < 3)
    {
        cout << "\nIncorrect number of parameters!!!" << endl;
        
        cout << "Correct usage is:" << endl;
        
        cout << "\t$ ./a.out inputFileName outputFileName\n" << endl;
        
        return 1;
    }
    
    input = argc[1];
    
    output = argc[2];
    
    std::chrono::time_point<std::chrono::system_clock> start, end;
    
    SortingCompetition* sc = new SortingCompetition(input);
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
