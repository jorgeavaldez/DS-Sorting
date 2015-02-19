//
//  Timing.cpp
//  SortingCompetition
//
//  Created by Jorge Valdez on 2/19/15.
//  Copyright (c) 2015 MicrosoftRD. All rights reserved.
//

#include <stdio.h>
#include <chrono>
#include <ctime>
#include <iostream>

int timeMain()
{
    //declare 2 time points
    std::chrono::time_point<std::chrono::system_clock> start, end;

    //store the current time (now()) in start, execute
    //Fibonacci function, then store current time in end
    start = std::chrono::system_clock::now();
    
    // Function to time
    
    end = std::chrono::system_clock::now();

    //subtract end from beginning to get number of seconds elapsed
    std::chrono::duration<double> elapsed_seconds = end-start;
    
    time_t end_time = std::chrono::system_clock::to_time_t(end);

    //output the duration.
    std::cout << "finished computation at " << &end_time << std::endl;
    std::cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
    
    return 0;
}