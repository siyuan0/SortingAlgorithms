# SortingAlgorithms

This is a C++ implementation of various sorting algorithms, to observe their runtime and memory usage for sorting an unsorted
array of random integers. Their performance is also tested on an already sorted array.

To test, run `./eval <size of array>`. For example, `./eval 10000`

It is not necessary to build since the compiled programme is included in the repo, but if build is required, run `cmake --build .`

Currently implemented sorting algorithms include:
1. insertion sort (used as baseline to check for sortedness of the products of other sorting algorithms)
2. quick sort
3. merge sort
4. bubble sort
5. bucket sort
