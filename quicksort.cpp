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
}


void QuickSort::quickSort(char** &inputWords, int left, int right)
{
<<<<<<< HEAD
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
=======
      int i = left, j = right;
      char* temp;
      int pivot = strlen(inputWords[(left + right) / 2]);

      while (i <= j) {
            while (strlen(inputWords[i]) < pivot)
                  i++;
            while (strlen(inputWords[j]) > pivot)
                  j--;
            if (i <= j) {
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
      /* recursion */



>>>>>>> c94a282f4cd84f1b98916f0628126e4486c0a831
