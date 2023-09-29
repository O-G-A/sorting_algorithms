#include "sort.h"

/**
 * merge_swap - function merge swap
 * @new_array: pointer new_array value the lengeth
 * @array: pointers array
 * @middle: middle of Array
 * @left: initialition of array
 * @right: integer data of finally
 */
void merge_sort(int *array, size_t size) {
    if (size <= 1) {
        return;
    }

    size_t mid = size / 2;
    int *left = malloc(sizeof(int) * mid);
    int *right = malloc(sizeof(int) * (size - mid));

    // Copy the left and right halves of the array into separate arrays.
    for (size_t i = 0; i < mid; i++) {
        left[i] = array[i];
    }

    for (size_t i = mid; i < size; i++) {
        right[i - mid] = array[i];
    }

    // Recursively sort the left and right halves.
    merge_sort(left, mid);
    merge_sort(right, size - mid);

    // Merge the sorted left and right halves back into the original array.
    merge(array, left, right, mid, size - mid);

    free(left);
    free(right);
}

void merge(int *array, int *left, int *right, size_t left_size, size_t right_size) {
    size_t i = 0;
    size_t j = 0;
    size_t k = 0;

    while (i < left_size && j < right_size) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            i++;
        } else {
            array[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < left_size) {
        array[k] = left[i];
        i++;
        k++;
    }

    while (j < right_size) {
        array[k] = right[j];
        j++;
        k++;
    }
}
