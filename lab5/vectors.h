//
// Created by Ionut on 2/16/2019.
//

#ifndef CODE_VECTORS_H
#define CODE_VECTORS_H

void read_vector(int *vector, int vector_length);
void write_vector(int *vector, int start, int stop);
// void merge_vectors(int vector_1[], int vector_2[], int vector_1_length, int vector_2_length, int vector_3[]);
int *merge_vectors(int *vector_1, int vector_1_length, int *vector_2, int vector_2_length);
int binary_search(int vector[], int vector_left, int vector_right, int element);
void interchange_values(int *address_1, int *address_2);
void merge_left_right(int *vector, int left, int middle, int right);
int partition(int *vector, int left, int right);

#endif //CODE_VECTORS_H
