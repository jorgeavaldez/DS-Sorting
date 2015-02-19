#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "SortingCompetition.h"

class QuickSort : public SortingCompetition
{
public:
    QuickSort(const string &);
    void quickSort(char**&, int, int);
    void sortData();
};

#endif // QUICKSORT_H
