//
//  SortingCompetition.cpp
//  Project3
//
//  Created by Microsoft R&D on 2/17/15.
//  Copyright (c) 2015 Microsoft R&D. All rights reserved.
//

#include "SortingCompetition.h"
#define RANGE 255

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
    
    for (int i = 0; i < inputsize; i++)
        delete[] inputWords[i];
    
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
bool SortingCompetition::prepareData()
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
void SortingCompetition::sortData()
{
    int left = 0;
    int right = getInputSize() - 1;
    
    quickSort(getSortWords(), left, right);
    
    // By alpha
    left = 0;
    
    // Traverses through the sorted array to find chunks that are of
    // the same length.
    // It then sorts the same size chunks alphabetically.
    for (int i = 1; i < getInputSize(); i++)
    {
        if (strlen(getSortWords()[i - 1]) != strlen(getSortWords()[i]))
        {
            quickSortAlpha(getSortWords(), left, i - 1);
            left = i;
        }
    }
}

// This quicksorts by size.
// inputWords is the array to be sorted, passed by reference.
// left is the first index, right is the last index.
// The pivot is calculated using these indeces.
void SortingCompetition::quickSort(char** &inputWords, int left, int right)
{
    int i = left;
    int j = right;
    char* temp;
    long pivot = strlen(inputWords[(left + right) / 2]);
    
    while (i <= j)
    {
        while (strlen(inputWords[i]) < pivot)
            i++;
        
        while (strlen(inputWords[j]) > pivot)
            j--;
        
        if (i <= j)
        {
            // Swap
            temp = inputWords[i];
            inputWords[i] = inputWords[j];
            inputWords[j] = temp;
            
            i++;
            j--;
        }
    }
    
    if (left < j)
        quickSort(inputWords, left, j);
    
    if (i < right)
        quickSort(inputWords, i, right);
}

// Same as regular quickSort, except sorts alphabetically.
// inputWords is the array to be sorted, passed by reference.
// left is the first index, right is the last index.
void SortingCompetition::quickSortAlpha(char** &inputWords, int left, int right)
{
    int i = left;
    int j = right;
    char* temp;
    char* pivot = inputWords[(left + right) / 2];
    
    while (i <= j)
    {
        while (strcmp(inputWords[i], pivot) < 0)
            i++;
        
        while (strcmp(inputWords[j], pivot) > 0)
            j--;
        
        if (i <= j)
        {
            // Swap
            temp = inputWords[i];
            inputWords[i] = inputWords[j];
            inputWords[j] = temp;
            
            i++;
            j--;
        }
    }
    
    if (left < j)
        quickSortAlpha(inputWords, left, j);
    
    if (i < right)
        quickSortAlpha(inputWords, i, right);
}

// using outputFileName, write the "sorted" data structure
// to the file. This will be used to test the validity of
// your sorting algorithm (in other words, did it sort properly?).
void SortingCompetition::outputData(const string& outputFileName)
{
    ofstream out(outputFileName);
    
    for (int i = 0; i < inputsize; i++)
        out << sortWords[i] << endl;
    
    out.close();
}

void SortingCompetition::countSort(char** &inputWords)
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

string SortingCompetition::toString(char**& arr)
{
    string output = "";
    
    for (int i = 0; i < inputsize; i++)
    {
        output = output + arr[i] + "\n";
    }
    
    return output;
}

void SortingCompetition::printArr(char**& arr)
{
    for (int i = 0; i < inputsize; i++)
    {
        cout << arr[i] << endl;
    }
}


char**& SortingCompetition::getSortWords()
{
    return this->sortWords;
}

char**& SortingCompetition::getInputWords()
{
    return this->inputWords;
}

int& SortingCompetition::getInputSize(){
    return this->inputsize;
}

int& SortingCompetition::getInputCapacity(){
    return this->inputcapacity;
}
