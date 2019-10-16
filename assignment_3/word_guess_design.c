/*
Srikar Valluri
CS 133C
Assignment 3

Hangman! :)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct word{
    char word[100];
    char guess[100];
    char prediction[100];
    bool done;
};

int str_len(char* array){
    int i = 0;
    for(i = 0; array[i] != '\0'; i++);
    return i - 1;
}

void str_print(char* array){
    printf("[");
    for(int i = 0; array[i] != '\0'; i++){
        printf("%c,", array[i]);
    }
    printf("]");
}

struct word guess_update(struct word word){
    int i = 0;
    int x = 0;
    int y = 0;
    while(i <= str_len(word.word)){
        if(word.word[i] == word.guess[0]){
            word.prediction[i] = word.guess[0];
            x = 1;
        }
        i++;
    }
    word.prediction[i] = 0;
    if(x == 1){
        printf("Your letter worked! Congrats! :)\n");
        printf("Prediction: %s\n", word.prediction);
        printf("Actual: %s\n", word.word);
    }
    else{
        printf("Sorry! Your letter didn't work.\n");
    }
    if(strcmp(word.word, word.prediction) == 0){
        printf("You won the hangman! Congrats! :)\n");
        word.done = true;
    }
    return word;
}

int main(){
    struct word word;
    word.done = false;
    printf("Welcome to Hangman! Player 1, enter a word: ");
    scanf("%s", word.word);
    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
    for(int i = 0; i <= str_len(word.word); i++){
        word.prediction[i] = '#';
    }
    while(true){
        printf("Player 2, start guessing. Start by guessing a letter from the alphabet: ");
        scanf("%s", word.guess);
        word = guess_update(word);
        if(word.done){
            break;
        }
    }
    return 0;
}