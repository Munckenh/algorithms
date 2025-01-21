#include "merge.h"

void _merge_subarrays(int array[], int left, int middle, int right) {
    int left_size = middle - left + 1;
    int right_size = right - middle;

    // Create left and right temporary arrays
    int left_array[left_size];
    int right_array[right_size];

    // Copy to temporary arrays
    for (int i = 0; i < left_size; i++) {
        left_array[i] = array[left + i];
    }
    for (int i = 0; i < right_size; i++) {
        right_array[i] = array[middle + 1 + i];
    }

    // Merge temporary arrays by comparing current elements, copying the smallest, and incrementing the current index
    int left_index = 0;
    int right_index = 0;
    int array_index = left;
    while (left_index < left_size && right_index < right_size) {
        if (left_array[left_index] < right_array[right_index]) {    // Compare
            array[array_index++] = left_array[left_index++];        // Copy and increment
        }
        else {
            array[array_index++] = right_array[right_index++];
        }
    }

    // Copy remaining elements (by now, one of the temporary arrays is empty)
    while (left_index < left_size) {
        array[array_index++] = left_array[left_index++];
    }

    while (right_index < right_size) {
        array[array_index++] = right_array[right_index++];
    }
}

void _merge_recursive(int array[], int left, int right) {
    // Base case: 1 element
    if (left >= right)
        return;

    int middle = (left + right) / 2;

    _merge_recursive(array, left, middle);
    _merge_recursive(array, middle + 1, right);
    
    _merge_subarrays(array, left, middle, right);
}

void merge_sort(int array[], int length) {
    _merge_recursive(array, 0, length - 1);
}