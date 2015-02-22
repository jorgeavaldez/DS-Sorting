#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "OurSortingCompetition.h"

// QuickSort class, derives from the OurSortingCompetition class.
// Overrides the sortData function to implement a quicksort.
class QuickSort : public OurSortingCompetition
{
public:
    
    // Constructor
    // Takes an string for the input filepath.
    QuickSort(const string &);
    
    // Implements a quicksort by char* length.
    void quickSort(char**&, int, int);
    
    // Implements a quicksort by char* alphabetical order.
    void quickSortAlpha(char** &, int, int);
    
    // The overridden sortData function.
    // First, calls regular quickSort.
    // Then, traverses the sorted array and calls
    // quickSortAlpha on chunks of the same size.
    void sortData();
};

#endif // QUICKSORT_H
