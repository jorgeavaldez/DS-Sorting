#include "bubblesort.h"

BubbleSort::BubbleSort(const string& inputFileName):SortingCompetition(inputFileName)
{
}



void BubbleSort::sortData()
{
    int arraySize = getInputSize() - 1;
    bubbleSortLength(getSortWords(), arraySize);

    for (int i = 1; i < getInputSize(); i++)
    {
        if (strlen(getSortWords()[i - 1]) != strlen(getSortWords()[i]))
        {
            bubbleSortAlpha(getSortWords(), i - 1);
            arraySize = i;
        }
    }
}



void BubbleSort::bubbleSortLength(char** &inputWords, int n)
{
      bool swapped = true;
      int j = 0;
      char* temp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (strlen(inputWords[i]) > strlen(inputWords[i + 1])) {
                        temp = inputWords[i];
                        inputWords[i] = inputWords[i + 1];
                        inputWords[i + 1] = temp;
                        swapped = true;
                  }
            }
      }
}


void BubbleSort::bubbleSortAlpha(char** &inputWords, int n)
{
      bool swapped = true;
      int j = 0;
      char* temp;
      while (swapped) {
            swapped = false;
            j++;
            for (int i = 0; i < n - j; i++) {
                  if (strcmp(inputWords[i],inputWords[i + 1]) < 0) {
                        temp = inputWords[i];
                        inputWords[i] = inputWords[i + 1];
                        inputWords[i + 1] = temp;
                        swapped = true;
                  }
            }
      }
}
