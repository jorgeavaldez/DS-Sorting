# Sorting Competition
Our sorting competition code, or Lab 4.

## The Meat of our String Sorting
For the first half of the project, we have to sort strings according to size.
Strings of the same size are then sorted alphabetically. This is achieved by moving through each index
within the strings and comparing each character.

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
- [3 Way Radix Quicksort](http://www.drdobbs.com/database/sorting-strings-with-three-way-radix-qui/184410724)
- [3 Way Radix Quicksort Guide](https://www.evernote.com/Home.action#n=f92d20cb-86e7-458c-9ba8-a8d551d5c414&b=2d895922-8d12-4dc5-8150-ea9d9af408f9&ses=4&sh=1&sds=5&)
- [Sorting Strings by Length](http://algo2.iti.kit.edu/sanders/courses/algen04/salgdat.pdf)
- [String Radix Sort](http://www.cs.helsinki.fi/u/tpkarkka/opetus/13s/spa/lecture03-2x4.pdf)

### OpenMP
- [Guide](http://openmp.org/mp-documents/omp-hands-on-SC08.pdf)
- [Another Guide](http://bisqwit.iki.fi/story/howto/openmp/)

#### g++ Compiler Flags
> -fopenmp
> -std=c++11

### Resources
- [Array Sorting Algorithm Comparison - Stack  Overflow](http://cs.stackexchange.com/questions/18536/what-is-a-the-fastest-sorting-algorithm-for-an-array-of-integers)
- [Integer Linear Time Sorting Algorithms - Baptiste Wicht Blog](http://baptiste-wicht.com/posts/2012/11/integer-linear-time-sorting-algorithms.html)
- [Big O Cheat Sheet](http://bigocheatsheet.com/)
- [Princeton String Sorting Algorithms](http://algs4.cs.princeton.edu/51radix/)
