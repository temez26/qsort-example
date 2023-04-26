
# Hybrid Sorting Algorithm

This C++ code implements a hybrid sorting algorithm that combines quicksort and insertion sort.

## Description

The `quicksort` function sorts a subarray using the quicksort algorithm. If the size of the subarray is below a certain threshold (`M`), it switches to using the `insertion_sort` function to sort the subarray using insertion sort. The pivot element for the quicksort algorithm is chosen using the `median_of_three` function, which selects the median of the first, middle and last elements of the subarray as the pivot.

## Usage

To use this code, include it in your C++ project and call the `quicksort` function with the array to be sorted and its lower and upper bounds as arguments.
