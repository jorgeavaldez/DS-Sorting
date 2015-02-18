//
//  SortingCompetition.cpp
//  Project3
//
//  Created by Jorge Valdez on 2/17/15.
//  Copyright (c) 2015 Jorge Valdez. All rights reserved.
//

#include "SortingCompetition.h"

using namespace std;

//**********************************************************
//
//                          Private
//
//**********************************************************

void SortingCompetition::resizeInput()
{
    char** temp = new char*[inputcapacity + 50];
    
    for (int i = 0; i < inputsize; i++)
    {
        temp[i] = new char[strlen(inputWords[i]) + 1];
        
        strcpy(temp[i], inputWords[i]);
    }
    
    inputcapacity += 50;
    delete[] inputWords;
    inputWords = temp;
}

//**********************************************************
//
//                          Public
//
//**********************************************************

SortingCompetition::SortingCompetition(const string& inputFileName)
{
    setFileName(inputFileName);
    
    inputcapacity = 50;
    inputsize = 0;
    
    inputWords = new char*[inputcapacity];
}

SortingCompetition::~SortingCompetition()
{
    delete[] inputWords;
    delete[] sortWords;
}

// change the input file name
void SortingCompetition::setFileName(const string &inputFileName)
{
    this->inputFileName = inputFileName;
}

// read the data from the file and store it in
// a linear data structure.
// No sorting actions can be done in this method.
// This includes no duplicate removal or anything else
// that could make your sorting more efficient later.
// Literally, the 5th word in the file should be
// in the 5th place in your structure.
bool SortingCompetition::readData()
{
    ifstream in(inputFileName);
    
    int i = 0;
    char* buffer = new char[91];
    
    while (!in.eof())
    {
        if (inputsize == inputcapacity)
            resizeInput();
        
        in >> buffer;
        
        inputWords[i] = new char[strlen(buffer) + 1];
        strcpy(inputWords[i], buffer);
        
        i++;
        inputsize++;
    }
    
    return true;
}

// copy the data from the original data structure
// into a second location that will be used for sorting.
// This will allow you to sort the same data set (with
// the same starting order of elements) multiple times.
// You can then calculate the average of execution times for
// one data set against one algorithm.
// No sorting actions can be done in this method.
bool SortingCompetition::prepareData()
{
    // Clear out supplementary data structure.
    delete[] sortWords;
    sortWords = new char*[inputsize];
    
    for (int i = 0; i < inputsize; i++)
    {
        sortWords[i] = inputWords[i];
    }
    
    return true;
}

// sort the data based on the criteria set forth in the
// hand out.
// THIS IS THE FUNCTION THAT WILL BE TIMED.
void SortingCompetition::sortData()
{
    
}

// using outputFileName, write the "sorted" data structure
// to the file. This will be used to test the validity of
// your sorting algorithm (in other words, did it sort properly?).
void SortingCompetition::outputData(const string& outputFileName)
{
    for (int i = 0; sortWords[i]; i++)
    {
        cout << sortWords[i] << endl;
    }
}