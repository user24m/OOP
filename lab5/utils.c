#include <stdio.h>
#include <stdlib.h>
#include "utils.h"

int is_prime(int num)
{
    if (num <= 1) return 0;
    if (num == 2) return 1;

    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) {
            return 0;
        }
    }

    return 1;
}

int sum_of_digits(int num){
    int sum = 0;

    while(num != 0){
        sum = sum + (num % 10);
        num = num / 10;
    }

    return  sum;
}