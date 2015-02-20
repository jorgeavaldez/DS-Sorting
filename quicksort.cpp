#include "quicksort.h"
#include "SortingCompetition.h"

QuickSort::QuickSort(const string& inputFileName):SortingCompetition(inputFileName)
{
}

void QuickSort::sortData()
{
    int left = 0;
    int right = getInputSize() - 1;
    quickSort(getSortWords(), left, right);
    printArr(getSortWords());
}


void QuickSort::quickSort(char** &inputWords, int left, int right)
{
    int i = left;
    int j = right;
    char* temp;
    char* pivot = inputWords[(left + right) / 2];

    while (i <= j)
    {
        while (strcmp(inputWords[i], pivot) > 0)
            i++;
           
        while (strcmp(inputWords[j], pivot) < 0)
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