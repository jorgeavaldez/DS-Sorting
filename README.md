# Sorting Competition
Our sorting competition code, or Lab 4.

## The Meat of our String Sorting
For the first half of the project, we have to sort strings according to size.
Strings of the same size are then sorted alphabetically. This is achieved by moving through each index
within the strings and comparing each character.
One of the guides that we read through showed how you can treat strings like strings of numbers in radix
sort. In radix sort, you basically achieve the sort by comparing each digit within the number.
The sort will start from the left, so we will basically be implementing a version of radix sort called
LSD Radix, which stands for "Least Significant Digit" Radix Sort.

## Random Notes
- Clear out the supplementary data structure in the beginning of prepare data
- Use char** because contiguous memory is fast af
- Look into OpenMP for multithreading
- memset() initializes the first arg to the second arg so you don't have segfaults or whatever.'

### Length Prefixed Strings
- [Guide to Strings](http://www.plantation-productions.com/Webster/www.artofasm.com/Linux/HTML/CharacterStrings.html)

### Sorting Guides
- [Counting Sort](http://www.geeksforgeeks.org/counting-sort/)
- [Radix Sort](http://www.geeksforgeeks.org/radix-sort/)

- [Sorting Strings by Length](http://algo2.iti.kit.edu/sanders/courses/algen04/salgdat.pdf)

- [String Radix Sort](http://www.cs.helsinki.fi/u/tpkarkka/opetus/13s/spa/lecture03-2x4.pdf)

### OpenMP
- [Guide](http://openmp.org/mp-documents/omp-hands-on-SC08.pdf)
- [Another Guide](http://bisqwit.iki.fi/story/howto/openmp/)

#### g++ Compiler Flags
> -fopenmp
> -std=c++11

### Selection Sort
- Works fine with small data set, but takes forever to run with larger set
- for loop within function is inefficient and slows down drastically as data set size increases
