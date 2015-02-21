#include "bubblesort.h"

BubbleSort::BubbleSort(const string& inputFileName):SortingCompetition(inputFileName)
{
}

void BubbleSort::sortData()
{
    int left = 0;
    bubbleSortLength(getSortWords(), getInputSize());
    printArr(getSortWords());
    
    cout << "\n\nYOU'RE FAT\n" << endl;
    
    for (int i = 1; i < getInputSize(); i++)
    {
        if (strlen(getSortWords()[i - 1]) != strlen(getSortWords()[i]))
        {
            cout << "iside if statement" << endl;
            bubbleSortAlpha(getSortWords(), left, i - 1);
            cout << "attempted alpha sort" << endl;
            left = i;
        }
    }
    
    printArr(getSortWords());
}

void BubbleSort::bubbleSortLength(char** &inputWords, int size)
{
    char* temp;
    
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - 1; j++)
            if (strlen(inputWords[j]) < strlen(inputWords[j + 1]))
            {
                temp = inputWords[j];
                inputWords[j] = inputWords[j + 1];
                inputWords[j + 1] = temp;
            }
}


void BubbleSort::bubbleSortAlpha(char** &inputWords, int left, int size)
{
    char* temp;
    
    for (int i = left; i < size - 1; i++)
        for (int j = left; j < size - 1; j++)
            if (strcmp(inputWords[j], inputWords[j + 1]) > 0)
            {
                temp = inputWords[j - 1];
                inputWords[j - 1] = inputWords[j];
                inputWords[j] = temp;
            }
}
