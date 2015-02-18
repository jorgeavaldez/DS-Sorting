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



//**********************************************************
//
//                          Public
//
//**********************************************************

SortingCompetition::SortingCompetition(const string& inputFileName)
{
    setFileName(inputFileName);
}

SortingCompetition::~SortingCompetition()
{
    delete[] lines;
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
    return false;
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
    // TODO: Clear out supplementary data structure.
    return false;
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
    
}