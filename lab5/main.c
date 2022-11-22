#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "sort.h"
#include "utils.h"
#include "homework.h"

int main()
{
    
    printf("\n=========== Insertion Sort ===========");
    printf("\nThe sorted values, insertion sort method, of vector 4 is:");
    insertion_sort(vector_4, vector_4_length);
    printf("\n=========== Selection Sort ===========");
    write_vector(&vector_4[0], 0, vector_4_length);
    printf("\nThe sorted values, insertion sort method, of vector 5 is:");
    merge_sort(vector_5, 0, vector_5_length - 1);
    write_vector(&vector_5[0], 0, vector_5_length);

    printf("\n=========== Merging sorted arrays ===========");
    merged_vector = merge_vectors(vector_4, vector_4_length, vector_5, vector_5_length);
    printf("\nThe result of merging vectors is:");
    write_vector(merged_vector, 0, vector_4_length + vector_5_length);

    printf("\n=========== Binary Search ===========\n");
    int element_to_find = 13;
    int result = binary_search(vector_5, 0, vector_5_length - 1, element_to_find);

    if (result == -1){
        printf("\n The element was not found!");
    }else{
        printf("The element was found at index %d", result);
    }*/

    FILE* file = fopen ("data.in", "r");
    FILE* file_out = fopen ("data.out", "w");
    if(!file || !file_out)
    {
        return -1;
    }
    int n,m,M;
    fscanf(file,"%d",&n);
    int S[2*n];
    for(int i=0;i<2*n;i++)
         fscanf(file,"%d",&S[i]);
    minim_maxim(S,0,2*n-1,&m,&M); //// ->> O(n) time complex.
    printf("%d %d",m,M);

    solve_problem_3(S,2*n);  ////->>> O(nlogn)
    fprintf(file_out,"Problem 3 solution: \n( ");
    for(int i=1;i<2*n;i+=2)
            fprintf(file_out,"( %d , %d )",S[i-1],S[i]);


    fprintf(file_out,")\n");
     quick_sort(S,0,2*n-1); ////->> O(nlogn) am modificat un pic implementarea pentru ca mi se parea mai curata si usor de urmarit
    fprintf(file_out,"\nSorted array: \n");
    fprintf(file_out,"%d",S[0]);
    for(int i=1;i<2*n;i++)
            fprintf(file_out,", %d",S[i]);



    fclose (file);
    fclose (file_out); //

    return 0;
}
