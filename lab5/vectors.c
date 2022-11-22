#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"

void read_vector(int vector[], int vector_length)
{
    int iterator = 0;

    for (iterator = 0; iterator < vector_length; iterator++){
        printf("\n vector[%d]=",iterator);
        scanf("%d",&vector[iterator]);
    }
}

void write_vector(int vector[], int start, int stop)
{
    int iterator = 0;

    printf("\n Vector: ");
    for (iterator = start; iterator < stop; iterator++){
        printf("%d ",vector[iterator]);
    }
}

/* void merge_vectors(int vector_1[], int vector_2[], int vector_1_length, int vector_2_length, int vector_3[])
{
    int i = 0;
    int j = 0;
    int k = -1;

    while (i < vector_1_length && j < vector_2_length)
    {
        k = k  + 1;
        if (vector_1[i] < vector_2[j]) {
            vector_3[k] = vector_1[i];
            i = i + 1;
        } else {
            vector_3[k] = vector_2[j];
            j = j + 1;
        }
    }

    while (i < vector_1_length) {
        k = k + 1;
        vector_3[k] = vector_1[i];
        i = i + 1;
    }

    while (j < vector_2_length) {
        k = k + 1;
        vector_3[k] = vector_2[j];
        j = j + 1;
    }
} */

int *merge_vectors(int *vector_1, int vector_1_length, int *vector_2, int vector_2_length){
    //Interclasarea a doi vectori

    int vector_1_iterator = 0;
    int vector_2_iterator = 0;
    int vector_sorted_iterator = 0;
    int vector_sorted_length = vector_1_length + vector_2_length;
    int *vector_sorted = calloc(vector_sorted_length, sizeof(int));

    // we compare an element from the first vector with an element from the second vector
    // the element with the smallest value is added to the sorted/merged vector
    while ((vector_1_iterator < vector_1_length) && (vector_2_iterator < vector_2_length)) {
        if (*(vector_1 + vector_1_iterator) < *(vector_2 + vector_2_iterator)){
            *(vector_sorted + vector_sorted_iterator) = *(vector_1 + vector_1_iterator);
            vector_1_iterator++;
        }else{
            *(vector_sorted + vector_sorted_iterator) = *(vector_2 + vector_2_iterator);
            vector_2_iterator++;
        }
        vector_sorted_iterator++;
    }

    // if one of the vectors reaches the end
    // the elements from the other vectors get copied to the sorted/merged vector

    if (vector_1_iterator < vector_1_length){
        while (vector_1_iterator < vector_1_length){
            *(vector_sorted + vector_sorted_iterator) = *(vector_1 + vector_1_iterator);
            vector_1_iterator++;
            vector_sorted_iterator++;
        }
    }else{
        while (vector_2_iterator < vector_2_length){
            *(vector_sorted + vector_sorted_iterator) = *(vector_2 + vector_2_iterator);
            vector_2_iterator++;
            vector_sorted_iterator++;
        }
    }

    return vector_sorted;
}

int binary_search(int vector[], int vector_left, int vector_right, int element)
{
    if (vector_right >= vector_left) {
        int mid = vector_left + (vector_right - vector_left) / 2;

        // if the element is present at the middle return it
        if (vector[mid] == element){
            return mid;
        }

        // if element is smaller than middle we have to look in the left sub-array
        if (vector[mid] > element){
            return binary_search(vector, vector_left, mid - 1, element);
        }

        // else we will search in the right sub-array
        return binary_search(vector, mid + 1, vector_right, element);
    }

    // return -1 if we wil not find the element
    return -1;
}


void interchange_values(int *address_1, int *address_2)
{
    int aux;

    aux = *address_1;
    *address_1 = *address_2;
    *address_2 = aux;
}

void merge_left_right(int *vector, int left, int middle, int right)
{
    int iterator_left, iterator_right, merge_iterator;
    int no_elements_left = middle - left + 1;
    int no_elements_right = right - middle;

    // Create temporary array
    int *vector_left = calloc(no_elements_left, sizeof(int));
    int *vector_right = calloc(no_elements_right, sizeof(int));

    // Copy the information from the initial vector to the left, respectively right vector
    for (iterator_left = 0; iterator_left < no_elements_left; iterator_left++)
        vector_left[iterator_left] = vector[left + iterator_left];
    for (iterator_right = 0; iterator_right < no_elements_right; iterator_right++)
        vector_right[iterator_right] = vector[middle + 1 + iterator_right];

    // merge vectors (interclasare)
    iterator_left = 0;
    iterator_right = 0;
    merge_iterator = left;
    while (iterator_left < no_elements_left && iterator_right < no_elements_right)
    {
        if ( *(vector_left + iterator_left) <= *(vector_right + iterator_right) )
        {
            *(vector + merge_iterator) = *(vector_left + iterator_left);
            iterator_left++;
        }
        else
        {
            *(vector + merge_iterator) = *(vector_right + iterator_right);
            iterator_right++;
        }
        merge_iterator++;
    }

    if (iterator_left < no_elements_left) {
        //Copy the remaining elements of left vector, if there are any
        while (iterator_left < no_elements_left) {
            *(vector + merge_iterator) = *(vector_left + iterator_left);
            iterator_left++;
            merge_iterator++;
        }
    }else{
        // Copy the remaining elements of the right vector, if there are any
        while (iterator_right < no_elements_right) {
            *(vector + merge_iterator) = *(vector_right + iterator_right);;
            iterator_right++;
            merge_iterator++;
        }
    }
    //delete the temporary vectors from memory
    free(vector_left);
    free(vector_right);
}

int partition(int *vector, int left, int right)
{
    int pivot = vector[right];
    int ip=left;
    for(int it=left;it<=right-1;it++)
        if(vector[it]<=pivot)
        {
          interchange_values(&vector[it],&vector[ip]);
          ip++;
        }
    interchange_values(&vector[ip],&vector[right]);
    return ip;
}
