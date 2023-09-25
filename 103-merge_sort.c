#include "sort.h"

void merge_sort(int *array, size_t size)
{
  if (size <= 1)
    return;
  size_t mid = size / 2;
  int *left = malloc(mid * sizeof(int));
  int *right = malloc((size - mid) * sizeof(int));

  for (size_t i = 0; i < mid; i++)
    left[i] = array[i];
  for (size_t i = mid; i < size; i++)
    right[i - mid] = array[i];
  merge_sort(left, mid);
  merge_sort(right, size - mid);

  int i = 0, j = 0, k = 0;

  while (i < mid && j < size - mid) {
    if (left[i] <= right[j]) {
      array[k] = left[i];
      i++;
    } else {
      array[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < mid) {
    array[k] = left[i];
    i++;
    k++;
  }
  while (j < size - mid) {
    array[k] = right[j];
    j++;
    k++;
  }
  free(left);
  free(right);
}
