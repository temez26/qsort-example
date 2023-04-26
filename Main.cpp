
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

const int N = 75000; // Size of the data array
int myData[N]; // Data array to be sorted
const int M = 10; // Empirically determined threshold for switching to insertion sort

// Function to choose the pivot using the median of three method
int median_of_three(int arr[], int low, int high) {
    int mid = (low + high) / 2; // Calculate the index of the middle element
    // Rearrange the first, middle and last elements in ascending order
    if (arr[low] > arr[mid])
        swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        swap(arr[mid], arr[high]);
    // Swap the middle element with the second to last element
    swap(arr[mid], arr[high - 1]);
    // Return the value of the pivot element
    return arr[high - 1];
}

// Function to sort a subarray using the insertion sort algorithm
void insertion_sort(int arr[], int low, int high) {
    // Iterate over the elements in the subarray
    for (int i = low + 1; i <= high; i++) {
        int j = i;
        // Move the current element to its correct position in the sorted part of the subarray
        while (j > low && arr[j - 1] > arr[j]) {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

// Function to sort a subarray using the quicksort algorithm
void quicksort(int arr[], int low, int high) {
    // Check if the size of the subarray is below the threshold for switching to insertion sort
    if (high - low + 1 < M) {
        // Sort the subarray using insertion sort
        insertion_sort(arr, low, high);
        return;
    }
    // Choose the pivot using the median of three method
    int pivot = median_of_three(arr, low, high);
    int i = low;
    int j = high - 1;
    // Partition the subarray around the pivot
    while (true) {
        while (arr[++i] < pivot) {}
        while (pivot < arr[--j]) {}
        if (i < j)
            swap(arr[i], arr[j]);
        else
            break;
    }
    swap(arr[i], arr[high - 1]);
    // Recursively sort the two subarrays on either side of the pivot
    quicksort(arr, low, i - 1);
    quicksort(arr, i + 1, high);
}

int main() {
    srand(time(NULL));
    // Generate random data to be sorted
    for (int i = 0; i < N; i++) {
        myData[i] = rand() % 1000001;
    }

    // Measure the time it takes to sort the data using quicksort
    clock_t start = clock();
    quicksort(myData, 0, N - 1);
    clock_t end = clock();
    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
    cout << "Time spent sorting: " << time_spent << endl;

    // Write the sorted data to an output file
    ofstream outputFile("output.txt");
    for (int i = 0; i < N; i++) {
        outputFile << myData[i] << endl;
    }
    outputFile.close();
    return 0;

}