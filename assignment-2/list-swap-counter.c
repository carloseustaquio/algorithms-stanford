#include <stdio.h>
#include <stdlib.h>

void mergeSortCountingSwaps(int arr[], int l, int r, unsigned int *swaps);
void subArray(int arr[], int newArr[], int index, int size);
void merge(int A[], int l, int r, int m, unsigned int *swaps);
void loadNumbers(int *buffer, int length);
void printArr(int *buffer, int length);

int main(void)
{
  int SIZE = 100000;
  int arr[SIZE];
  loadNumbers(arr, SIZE);

  unsigned int swaps = 0;
  
  mergeSortCountingSwaps(arr, 0, SIZE - 1, &swaps);

  printf("\nNumber of swaps %u\n", swaps);
  
  return 0;
}

void mergeSortCountingSwaps(int arr[], int l, int r, unsigned int *swaps)
{
  if (l < r) {
    int m = (l + r)/2;
    
    mergeSortCountingSwaps(arr, l, m, swaps);
    mergeSortCountingSwaps(arr, m + 1, r, swaps);

    merge(arr, l, r, m, swaps);
  }
}

void merge(int A[], int l, int r, int m, unsigned int *swaps)
{
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  subArray(A, L, l, n1);
  subArray(A, R, m + 1, n2);

  int i = 0, j = 0, k = l;

  while (i < n1 && j < n2) {
    if (L[i] <= R[j]) {
      A[k] = L[i];
      i++;
    } else { // R[j] >= L[i]
      A[k] = R[j];
      j++;
      *swaps += n1 - i; // incrementing swaps
    }
    k++;
  }

  while (i < n1) {
    A[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    A[k] = R[j];
    j++;
    k++;
  }
}

void subArray(int A[], int newA[], int start, int size)
{
  for (int i = 0; i < size; i ++) {
    newA[i] = A[start + i];
  }
}

void loadNumbers(int A[], int size)
{
  FILE *myFile;
  myFile = fopen("numbers.txt", "r");

  for (int i = 0; i < size; i++) {
    fscanf(myFile, "%d", &A[i]);
  } 
}
