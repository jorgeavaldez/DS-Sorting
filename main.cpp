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

using namespace std;
using namespace chrono;

long fibonacci(int n)
{
    if (n < 3) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main()
{
    //declare 2 time points
      time_point<chrono::system_clock> start, end;

    //store the current time (now()) in start, execute
    //Fibonacci function, then store current time in end
    start = system_clock::now();
    cout << "f(42) = " << fibonacci(9) << '\n';
    end = system_clock::now();

    //subtract end from beginning to get number of seconds elapsed
      duration<double> elapsed_seconds = end-start;
    time_t end_time =
    system_clock::to_time_t(end);

    //output the duration.
    cout << "finished computation at " <<
    ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}
