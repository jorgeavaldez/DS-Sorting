#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "SortingCompetition.h"

class BubbleSort : public SortingCompetition
{
public:
    BubbleSort(const string&);
    void bubbleSortLength(char**&, int);
    void bubbleSortAlpha(char** &inputWords, int left, int size);
    void sortData();
};

#endif // BUBBLESORT_H