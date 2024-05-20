#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum {
    Rock = 0,
    Paper = 1,
    Scissors = 2,
} value;

value SelectARandomInteger() {
    unsigned char a_random_integer;

    srandom(time(NULL));
    a_random_integer = random() % 3;

    return((value)a_random_integer);
}

signed char EnterAChoiceAsAnInteger() {
    signed char an_integer = 0;

    printf("Enter a value: \n");
    printf("0 is used to represent: Rock\n");
    printf("1 to represent Paper\n");
    printf("2 to represent Scissors\n");
    printf("-1: Exit\n");
    scanf("%3hhd", &an_integer);

    return(an_integer);
}

void RockPaperScissors() {
    unsigned char a_random_integer = SelectARandomInteger();
    signed char an_integer = EnterAChoiceAsAnInteger();

    if (an_integer == -1) {
        return;
    }

    if (an_integer < -1 || an_integer > 2) {
        printf ("An error message.\n\n");
        return(RockPaperScissors());
    }
    
    if (an_integer == a_random_integer) {
        printf("The user draws against the computer.\n\n");
    }
    else {
        switch (a_random_integer) {
        case Rock:
            if (an_integer == 1) {
                printf("The user wins a rock.\n\n");
            }
            if (an_integer == 2) {
                printf("The user loses.\n\n");
            }
            break;

        case Paper:
            if (an_integer == 0) {
                printf("The user loses.\n\n");
            }
            if (an_integer == 2) {
                printf("The user wins a piece of paper.\n\n");
            }
            break;

        case Scissors:
            if (an_integer == 0) {
                printf("The user wins a pair of scissors.\n\n");
            }
            if (an_integer == 1) {
                printf("The user loses.\n\n");
            }
        }
    }
    return(RockPaperScissors());
}

int main() {
    
    RockPaperScissors();

    return(0);
}