#include "quicksort.h"
#include "OurSortingCompetition.h"

// Constructs an instance of OurSortingCompetition where sortData implements
// a quicksort in the data set.
QuickSort::QuickSort(const string& inputFileName):OurSortingCompetition(inputFileName)
{
}

// The overridden OurSortingCompetition sortData method.
// Implements a quicksort first by length and then
// alphabetically.
void QuickSort::sortData()
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
void QuickSort::quickSort(char** &inputWords, int left, int right)
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
void QuickSort::quickSortAlpha(char** &inputWords, int left, int right)
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