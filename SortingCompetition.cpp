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
    cout << "in read data" << endl;
    ifstream in(inputFileName);

    if (!in)
    {
        cout << "Unable to open file" << endl;
        return false;
    }


    int i = 0;
    char* buffer = new char[91];
    cout << "about to enter while loop" << endl;

    while (in >> buffer)
    {
        if (inputsize == inputcapacity)
            resizeInput();


        inputWords[i] = new char[strlen(buffer) + 1];
        strcpy(inputWords[i], buffer);

        i++;
        inputsize++;
    }

    cout << "about to close file" << endl;
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
    cout << "in prepare data" << endl;
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
    cout << "in sortData" << endl;
    int left = 0;
    int right = getInputSize() - 1;

    int low = 0;
    int high = getInputSize() - 1;

//    selectionSort(getSortWords(), getInputSize());

//    insertionSort(getSortWords(), getInputSize());

      bubbleSortLength(getSortWords(), getInputSize());
//
//    shellSort(getSortWords(), getInputSize());
//
//    mergeSort(getSortWords(),low, high);
//
//    quickSort(getSortWords(), left, right);
//
      // By alpha
//    left = 0;
//
    int start = 0;

    // Traverses through the sorted array to find chunks that are of
    // the same length.
    // It then sorts the same size chunks alphabetically.
    for (int i = 1; i < getInputSize(); i++)
    {
        if (strlen(getSortWords()[i - 1]) != strlen(getSortWords()[i]))
        {
//            shellSortAlpha(getSortWords(), start, i - 1 - start);
//            selectionSortAlpha(getSortWords(), start, i - 1);
//            quickSortAlpha(getSortWords(), left, i - 1);
            bubbleSortAlpha(getSortWords(), start, i - 1);
//            insertionSortAlpha(getSortWords(), start, i -1);
              start = i;
        }
    }
    //ssort(getSortWords(), getInputSize());

//    printArr(getSortWords());
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
<<<<<<< HEAD
 **                       Fuck Sort Shit                       **
=======
 **                     Multikey  QuickSort Shit               **
>>>>>>> 7d5204654b5ec9552a2d12328fd0906cbc3003f5
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
void SortingCompetition::ssort(char**& x, int left, int n)
{
    // ssort1(x, n, 0);

    ssort1(x, n, left, 0);
}

// char**& x, int n, int depth
void SortingCompetition::ssort1(char**& x, int n, int left, int depth)
{
    int a, b, c, d, r, v;

    if(n <= 1)
        return;

    a = rand() % n;
    swap(left, a);
    v = i2c(left);
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
    vecswap(left, b - r, r, x);

    r = min(d - c, n - d - 1);
    vecswap(b, n - r, r, x);

    r = b - a;
    ssort1(x, r, left, depth);

    char** temp = x + r;

    if (i2c(r) != 0)
        ssort1(temp, a + n - d - 1, left, depth + 1);

    r = d - c;
    temp = x + n - r;
    ssort1(temp, r, left, depth);
}

/*

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                       QuickSort Shit                       **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

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

/*

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                      Count Sort Shit                       **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

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

/*

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                    Selection Sort Shit                     **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

void SortingCompetition::selectionSort(char** &inputWords, int size)
{
    cout << "in selectionSort" << endl;

    int i, j, minIndex;
    char* temp;

    cout << "selectionSort for loop" << endl;
    cout << "size is " << size << endl;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < size; j++)
            if (strlen(inputWords[j]) < strlen(inputWords[minIndex]))
                minIndex = j;

        if (minIndex != i)
        {
            temp = inputWords[i];
            inputWords[i] = inputWords[minIndex];
            inputWords[minIndex] = temp;
        }
    }

    cout << "out of for loop" << endl;
}

void SortingCompetition::selectionSortAlpha(char** &inputWords, int start, int size)
{
    int i = start;
    int j, minIndex;

    char* temp;

    for (start; start < size - 1; start++)
    {
        minIndex = start;
        for (j = start + 1; j < size; j++)
            if (strcmp(inputWords[j],inputWords[minIndex]) < 0)
                minIndex = j;

        if (minIndex != start)
        {
            temp = inputWords[start];
            inputWords[start] = inputWords[minIndex];
            inputWords[minIndex] = temp;
        }
    }
}

/*

****************************************************************
****************************************************************
**                                                            **
**                  Insertion Sort Shit                       **
**                                                            **
****************************************************************
****************************************************************

*/

void SortingCompetition:: insertionSort(char** &inputWords, int size) {
    int i, j;
    char* temp;
    for (i = 1; i < size; i++) {
        j = i;
        while (j > 0 && strlen(inputWords[j - 1]) > strlen(inputWords[j])) {
            temp = inputWords[j];
            inputWords[j] = inputWords[j - 1];
            inputWords[j - 1] = temp;
            j--;
        }
    }
}

void SortingCompetition:: insertionSortAlpha(char** &inputWords, int start, int size) {
    int i, j;
    char* temp;
    for (i = start - 1; i < size; i++) {
        j = i;
        while (j > start && strcmp(inputWords[j - 1],inputWords[j]) > 0) {
            temp = inputWords[j];
            inputWords[j] = inputWords[j - 1];
            inputWords[j - 1] = temp;
            j--;
        }
    }
}

/*

****************************************************************
****************************************************************
**                                                            **
**                  Bubble Sort Shit                          **
**                                                            **
****************************************************************
****************************************************************

*/

void SortingCompetition::bubbleSortLength(char** &inputWords, int size)
{
    char* temp;

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size - 1; j++)
            if (strlen(inputWords[j]) > strlen(inputWords[j + 1]))
            {
                temp = inputWords[j];
                inputWords[j] = inputWords[j + 1];
                inputWords[j + 1] = temp;
            }
}


void SortingCompetition::bubbleSortAlpha(char** &inputWords, int start, int size)
{
    char* temp;

    for (int i = start; i < size; i++)
        for (int j = start; j < size - 1; j++)
            if (strcmp(inputWords[j], inputWords[j + 1]) > 0)
            {
                temp = inputWords[j];
                inputWords[j] = inputWords[j+1];
                inputWords[j+1] = temp;
            }
}

/*

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                      Merge Sort Shit                       **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

void SortingCompetition::mergeSort(char** &inputWords, int low, int high)
{
    cout << "in mergeSort" << endl;
    int mid;
    if (low < high)
    {
        mid=(low+high)/2;
        mergeSort(inputWords,low,mid);
        mergeSort(inputWords,mid+1,high);
        merge(inputWords,low,high,mid);
    }
    return;
}

void SortingCompetition::merge(char** &inputWords, int low, int high, int mid)
{
    cout << "in merge" << endl;
    int i, j, k;
    char* exchanger[91];

    i = low;
    k = low;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (strlen(inputWords[i]) < strlen(inputWords[j]))
        {
            exchanger[k] = inputWords[i];
            k++;
            i++;
        }

        else
        {
            exchanger[k] = inputWords[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        exchanger[k] = inputWords[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        exchanger[k] = inputWords[j];
        k++;
        j++;
    }

    for (i = low; i < k; i++)
    {
        inputWords[i] = exchanger[i];
    }
}

/*
<<<<<<< HEAD

 ****************************************************************
 ****************************************************************
 **                                                            **
 **                    Selection Sort Shit                     **
 **                                                            **
 ****************************************************************
 ****************************************************************

*/

void SortingCompetition::selectionSort(char** &inputWords, int size)
{
    cout << "in selectionSort" << endl;

    int i, j, minIndex;
    char* temp;

    cout << "selectionSort for loop" << endl;
    cout << "size is " << size << endl;

    for (i = 0; i < size - 1; i++)
    {
        minIndex = i;

        for (j = i + 1; j < size; j++)
            if (strlen(inputWords[j]) < strlen(inputWords[minIndex]))
                minIndex = j;

        if (minIndex != i)
        {
            temp = inputWords[i];
            inputWords[i] = inputWords[minIndex];
            inputWords[minIndex] = temp;
        }
    }

    cout << "out of for loop" << endl;
}

void SortingCompetition::selectionSortAlpha(char** &inputWords, int start, int size)
{
    int i = start;
    int j, minIndex;

    char* temp;

    for (start; start < size - 1; start++)
    {
        minIndex = start;
        for (j = start + 1; j < size; j++)
            if (strcmp(inputWords[j],inputWords[minIndex]) < 0)
                minIndex = j;

        if (minIndex != start)
        {
            temp = inputWords[start];
            inputWords[start] = inputWords[minIndex];
            inputWords[minIndex] = temp;
        }
    }
}

/*

=======

>>>>>>> 7d5204654b5ec9552a2d12328fd0906cbc3003f5
****************************************************************
****************************************************************
**                                                            **
**                      Shell Sort Shit                       **
**                                                            **
****************************************************************
****************************************************************

*/

void SortingCompetition::shellSort(char** &inputWords, int size)
{
    int gap, i, j;
    char* temp;

    for (gap = size / 2; gap > 0; gap /= 2)
        for (i = gap; i < size; i++)
            for (j = i - gap; j >= 0 && combinedSorting(inputWords[j], inputWords[j+gap]); j -= gap)
            {
                temp = inputWords[j];
                inputWords[j] = inputWords[j + gap];
                inputWords[j + gap] = temp;
            }
}

void SortingCompetition::shellSortAlpha(char** &inputWords, int start, int size)
{
    int gap, i, j;
    char* temp;

    cout << "enters shellSortAlpha" << endl;
    for (gap = (size/2) + start; gap > start; gap = (gap+start)/2)
        for (i = gap; i < size + start; i++)
        {
            temp = inputWords[i];
            for (j=i; j>=gap && strcmp(inputWords[j-gap+start],temp) > 0; j-=gap+start) {
                inputWords[j] = inputWords[j-gap+start];
            }
            inputWords[j] = temp;
        }
}

bool SortingCompetition::combinedSorting(char* a, char* b) {
    if(strlen(a) > strlen(b)) return true;
    else if(strcmp(a, b) > 0) return true;
    else return false;
}
