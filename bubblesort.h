#ifndef BUBBLESORT_H
#define BUBBLESORT_H
#include "OurSortingCompetition.h"

class BubbleSort : public OurSortingCompetition
{
public:
    BubbleSort(const string&);
    void bubbleSortLength(char**&, int);
    void bubbleSortAlpha(char** &inputWords, int left, int size);
    void sortData();
};

#endif // BUBBLESORT_H