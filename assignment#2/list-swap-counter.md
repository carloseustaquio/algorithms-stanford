## Programming Assignment #2

This file contains all of the 100,000 integers between 1 and 100,000 (inclusive) in some order, with no integer repeated.
Your task is to compute the number of inversions in the file given, where the ith row of the file indicates the ith th entry of an array.
Because of the large size of this array, you should implement the fast divide-and-conquer algorithm covered in the video lectures.

## Recursive Method

To solve it, I'm using a merge sort algorithm, with a tiny trick to count the number of swaps. I'm setting a swap counter outside the recursion, and I increment this counter every time that the merge step selects an item from the right array. In that point, I increment the counter with the number of remaining items in the left array. I do that because it means that the selected item is swapped in comparison to all the remaining items (that are already sorted) of the left array.

```c
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
```
