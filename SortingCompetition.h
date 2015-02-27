//
//  SortingCompetition.h
//  Project3
//
//  Created by Jorge Valdez on 2/17/15.
//  Copyright (c) 2015 Jorge Valdez. All rights reserved.
//

#ifndef SortingCompetition_h
#define SortingCompetition_h

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include <string>

using namespace std;

class SortingCompetition
{
private:
    // you are free to determine your own internal
    // implementation with the following stipulations:
    
    // 1) when the prepare method is called, you must make a
    // copy of the original dataset into another instance-level
    // data structure which will be used by the sort method. This will
    // allow for multiple executions of the sort method in order to
    // get better timing data.
    // 2) your data structure must be linear (no trees).
    
    // MEMBER DATA
    
    string inputFileName;
    
    char** inputWords;
    char** sortWords;
    
    // the number of elements in the char**
    int inputsize;
    
    // the number of spots we can
    int inputcapacity;
    
    // resizes the char** so we can fit more words.
    // adds 50 to the default capacity.
    void resizeInput();
    
    void countSort(char**& inputWords);
    
public:
    
    // basic constructor that accepts an input
    // file name
    SortingCompetition(const string& inputFileName);
    
    // basic destructor
    ~SortingCompetition();
    
    // change the input file name
    void setFileName(const string& inputFileName);
    
    // read the data from the file and store it in
    // a linear data structure.
    // No sorting actions can be done in this method.
    // This includes no duplicate removal or anything else
    // that could make your sorting more efficient later.
    // Literally, the 5th word in the file should be
    // in the 5th place in your structure.
    bool readData();
    
    // copy the data from the original data structure
    // into a second location that will be used for sorting.
    // This will allow you to sort the same data set (with
    // the same starting order of elements) multiple times.
    // You can then calculate the average of execution times for
    // one data set against one algorithm.
    // No sorting actions can be done in this method.
    bool prepareData();
    // TODO: ^^^^ Clear out supplementary data structure.
    
    // sort the data based on the criteria set forth in the
    // hand out.
    // THIS IS THE FUNCTION THAT WILL BE TIMED.
    virtual void sortData();
    
    void quickSort(char** &inputWords, int left, int right);
    
    void quickSortAlpha(char** &inputWords, int left, int right);

    void mergeSort(char** &inputWords, int low, int high);

    void merge(char** &inputWords, int low, int high, int mid);

    void selectionSort(char** &inputWords, int size);

    void selectionSortAlpha(char** &inputWords, int, int size);

    void shellSort(char** &inputWords, int size);

    void shellSortAlpha(char** &inputWords, int start, int size);
    
    // Multikey Quicksort
    int min(int, int);
    
    void vecswap(int, int, int, char** &);
    
    void ssort(char** &, int);
    
    void ssort1(char** &, int, int);
    
    // using outputFileName, write the "sorted" data structure
    // to the file. This will be used to test the validity of
    // your sorting algorithm (in other words, did it sort properly?).
    void outputData(const string& outputFileName);
    
    string toString(char**& arr);
    
    void printArr(char**& arr);
    
    char**& getSortWords();
    
    char**& getInputWords();
    
    int& getInputSize();
    
    int& getInputCapacity();
};

#endif
