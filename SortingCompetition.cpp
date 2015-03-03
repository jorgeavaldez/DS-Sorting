//
//  SortingCompetition.cpp
//  Project3
//
//  Created by Microsoft R&D on 2/17/15.
//  Copyright (c) 2015 Microsoft R&D. All rights reserved.
//

#include "SortingCompetition.h"
#include <omp.h>
#define RANGE 255

using namespace std;

//**********************************************************
//
//                          Private
//
//**********************************************************

void SortingCompetition::resizeInput()
{
    char** temp = new char*[inputcapacity * 2];

    for (int i = 0; i < inputsize; i++)
    {
        temp[i] = new char[strlen(inputWords[i]) + 1];

        strcpy(temp[i], inputWords[i]);
    }

    inputcapacity *= 2;

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
    {
        return false;
    }


    int i = 0;
    char* buffer = new char[91];

    while (in >> buffer)
    {
        if (inputsize == inputcapacity)
            resizeInput();


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
    countSort(getSortWords());
    int start = 0;

    // Traverses through the sorted array to find chunks that are of
    // the same length.
    // It then sorts the same size chunks alphabetically.
    for (int i = 1; i < getInputSize(); i++)
    {
        if (strlen(getSortWords()[i - 1]) != strlen(getSortWords()[i]))
        {
            char** shiftedArray = getSortWords() + start;
            ssort(shiftedArray, i - start);

            start = i;
        }
    }
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

int& SortingCompetition::getInputSize()
{
    return this->inputsize;
}

int& SortingCompetition::getInputCapacity()
{
    return this->inputcapacity;
}

/*

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                                                            **
 **                  Multikey QuickSort                        **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

int SortingCompetition::min(int a,int b)
{
    return a <= b ? a : b;
}

#define swap(a,b){ char *t=x[a];x[a]=x[b];x[b]=t;}
#define i2c(i)  x[i][depth]

void SortingCompetition::vecswap(int i, int j, int n, char**& x)
{
    while (n-- > 0)
    {
        swap(i, j);
        i++;
        j++;
    }
}

// char**& x, int n
void SortingCompetition::ssort(char**& x, int n)
{
    ssort1(x, n, 0);

    // ssort1(x, n, left, 0);
}

// char**& x, int n, int depth
void SortingCompetition::ssort1(char**& x, int n, int depth)
{
    int a, b, c, d, r, v;

    if(n <= 1)
        return;

    a = rand() % n;
    swap(0, a);
    v = i2c(0);
    a = b = 1;
    c = d = n - 1;

    for (;;)
    {
        while(b <= c && (r = i2c(b) - v) <= 0)
        {
            if (r == 0)
            {
                swap(a, b);
                a++;
            }

            b++;
        }

        while(b <= c && (r = i2c(c) - v) >= 0)
        {
            if (r == 0)
            {
                swap(c,d);
                d--;
            }

            c--;
        }

        if (b > c)
            break;

        swap(b, c);
        b++;
        c--;
    }

    r = min(a, b - a);
    vecswap(0, b - r, r, x);

    r = min(d - c, n - d - 1);
    vecswap(b, n - r, r, x);

    r = b - a;
    ssort1(x, r, depth);

    char** temp = x + r;

    if (i2c(r) != 0)
        ssort1(temp, a + n - d - 1, depth + 1);

    r = d - c;
    temp = x + n - r;
    ssort1(temp, r, depth);
}

/*

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                      Count Sort                            **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

void SortingCompetition::countSort(char** &inputWords)
{
    omp_set_num_threads(4);

    char** output = new char*[inputsize];

    int count[RANGE + 1];

    #pragma omp parallel
    {
        memset(count, 0, sizeof(count));

        for (int i = 0; i < inputsize; i++)
        {
            ++count[strlen(inputWords[i])];
        }
    }

    #pragma omp parallel
    {
        for (int i = 1; i <= RANGE; ++i)
            count[i] += count[i - 1];
    }

    #pragma omp parallel
    {
        for (int i = 0; i < inputsize; ++i)
        {
            output[count[strlen(inputWords[i])] - 1] = new char[strlen(inputWords[i]) + 1];

            strcpy(output[count[strlen(inputWords[i])] - 1], inputWords[i]);

            --count[strlen(inputWords[i])];
        }
    }

    if (inputWords) delete[] inputWords;
    inputWords = output;
}
