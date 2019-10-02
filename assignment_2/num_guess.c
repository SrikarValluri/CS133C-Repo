/*
Srikar Valluri
CS 133C
Assignment 2

Number Guessing Game.
*/

#include <stdio.h>
#include <stdbool.h>

struct num_guess{
    int actual;
    int guess;

    int lower;
    int upper;
};

int main(){
    struct num_guess num_guess;
    while(true){
        printf("Player 1 - Enter a number between 0 and 100 for Player 2 to guess: ");
        scanf("%d", &num_guess.actual);
        if(num_guess.actual < 0 || num_guess.actual > 100){
            printf("Invalid input. Try again.\n");
        }
        else{
            break;
        }
    }
    num_guess.lower = 0;
    num_guess.upper = 100;

    printf("Okay, it's time for Player 2 to start guessing!\n");
    while(true){
        printf("Player 2 - Enter a number between %d and %d, including the end values: ", num_guess.lower, num_guess.upper);
        scanf("%d", &num_guess.guess);
        if(num_guess.guess < num_guess.actual){
            printf("Too Low. Try again!\n");
            if(num_guess.guess > num_guess.lower){
                num_guess.lower = num_guess.guess + 1;
            }
        }
        else if(num_guess.guess > num_guess.actual){
            printf("Too High. Try again!\n");
            if(num_guess.guess < num_guess.upper){
                num_guess.upper = num_guess.guess - 1;
            }
        }
        else{
            printf("You did it! %d is the right answer.\n", num_guess.guess);
            break;
        }
    }
    return 0;
}