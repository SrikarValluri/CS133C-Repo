/*
Srikar Valluri
CS 133C
Assignment 1

I created a struct which contained three different data types.
I created a function which returns a newly created struct with the inputs given.
I printed the function in main.

*/

#include <stdio.h>

struct data_types{
    int x;
    float y;
    char z;
};

struct data_types set_data(int x, float y, char z){
    struct data_types number;
    number.x = x;
    number.y = y;
    number.z = z;

    return number;
};

int main(){
    struct data_types number = set_data(5, 2.5, 'H');
    printf("The integer is %d\n", number.x);
    printf("The float is %f\n", number.y);
    printf("The character is %c\n", number.z);
}
