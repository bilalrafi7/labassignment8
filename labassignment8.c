void merge(int pData[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    // Dynamic memory allocation for the two halves
    int *L = (int *)Alloc(n1 * sizeof(int));
    int *R = (int *)Alloc(n2 * sizeof(int));

    // Copy data to temp arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = pData[l + i];
    for (j = 0; j < n2; j++)
        R[j] = pData[m + 1+ j];

    // Merge the temp arrays back into pData[l..r]
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            pData[k] = L[i];
            i++;
        } else {
            pData[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of L[], if there are any
    while (i < n1) {
        pData[k] = L[i];
        i++;
        k++;
    }

    // Copy the remaining elements of R[], if there are any
    while (j < n2) {
        pData[k] = R[j];
        j++;
        k++;
    }

    // Free the dynamically allocated memory
    DeAlloc(L);
    DeAlloc(R);
}
void mergeSort(int pData[], int l, int r) {
    if (l < r) {
        // Find the middle point to divide the array into two halves
        int m = l + (r - l) / 2;

        // Call mergeSort for first and second halves
        mergeSort(pData, l, m);
        mergeSort(pData, m + 1, r);

        // Merge the sorted halves
        merge(pData, l, m, r);
    }
}
