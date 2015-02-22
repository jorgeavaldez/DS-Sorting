//
//  OurSortingCompetition.cpp
//  Project3
//
//  Created by Microsoft R&D on 2/17/15.
//  Copyright (c) 2015 Microsoft R&D. All rights reserved.
//

#include "OurSortingCompetition.h"
#define RANGE 255

using namespace std;

//**********************************************************
//
//                          Private
//
//**********************************************************

void OurSortingCompetition::resizeInput()
{
    char** temp = new char*[inputcapacity + 50];
    
    for (int i = 0; i < inputsize; i++)
    {
        temp[i] = new char[strlen(inputWords[i]) + 1];
        
        strcpy(temp[i], inputWords[i]);
    }
    
    inputcapacity += 50;
    
    for (int i = 0; i < inputsize; i++)
        delete[] inputWords[i];
    
    inputWords = temp;
}

//**********************************************************
//
//                          Public
//
//**********************************************************

OurSortingCompetition::OurSortingCompetition(const string& inputFileName)
{
    setFileName(inputFileName);
    
    inputcapacity = 50;
    inputsize = 0;
    
    inputWords = new char*[inputcapacity];
}

OurSortingCompetition::~OurSortingCompetition()
{
    if (inputWords)
        for (int i = 0; i < inputsize; i++)
            delete[] inputWords[i];
    
    if (sortWords)
        for (int i = 0; i < inputsize; i++)
            delete[] sortWords[i];
    
    delete[] inputWords;
    delete [] sortWords;
}

// change the input file name
void OurSortingCompetition::setFileName(const string &inputFileName)
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
bool OurSortingCompetition::readData()
{
    ifstream in(inputFileName);
    
    if (!in)
        return false;
    
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
    
    delete[] buffer;
    in.close();
    return true;
}

// copy the data from the original data structure
// into a second location that will be used for sorting.
// This will allow you to sort the same data set (with
// the same starting order of elements) multiple times.
// You can then calculate the average of execution times for
// one data set against one algorithm.
// No sorting actions can be done in this method.
bool OurSortingCompetition::prepareData()
{
    // Clear out supplementary data structure.
    //if (sortWords) delete[] sortWords;
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
void OurSortingCompetition::sortData()
{
    countSort(sortWords);
}

// using outputFileName, write the "sorted" data structure
// to the file. This will be used to test the validity of
// your sorting algorithm (in other words, did it sort properly?).
void OurSortingCompetition::outputData(const string& outputFileName)
{
    ofstream out(outputFileName);
    
    for (int i = 0; i < inputsize; i++)
        out << sortWords[i] << endl;
    
    out.close();
}

void OurSortingCompetition::countSort(char** &inputWords)
{
    char** output = new char*[inputsize];

    int count[RANGE + 1];
    
    memset(count, 0, sizeof(count));

    for (int i = 0; i < inputsize; i++)
    {
        ++count[strlen(inputWords[i])];
    }

    for (int i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    for (int i = 0; i < inputsize; ++i)
    {
        output[count[strlen(inputWords[i])] - 1] = new char[strlen(inputWords[i]) + 1];
        
        strcpy(output[count[strlen(inputWords[i])] - 1], inputWords[i]);
        
        --count[strlen(inputWords[i])];
    }

    if (inputWords) delete[] inputWords;
    inputWords = output;
}

string OurSortingCompetition::toString(char**& arr)
{
    string output = "";
    
    for (int i = 0; i < inputsize; i++)
    {
        output = output + arr[i] + "\n";
    }
    
    return output;
}

void OurSortingCompetition::printArr(char**& arr)
{
    for (int i = 0; i < inputsize; i++)
    {
        cout << arr[i] << endl;
    }
}


char**& OurSortingCompetition::getSortWords()
{
    return this->sortWords;
}

char**& OurSortingCompetition::getInputWords()
{
    return this->inputWords;
}

int& OurSortingCompetition::getInputSize(){
    return this->inputsize;
}

int& OurSortingCompetition::getInputCapacity(){
    return this->inputcapacity;
}
