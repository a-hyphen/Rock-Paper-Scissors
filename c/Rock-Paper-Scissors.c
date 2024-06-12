#include <stdio.h>
#include <sys/mman.h>
#include <stdlib.h>
#include <time.h>

register size_t *won_items = mmap(NULL, 3 * sizeof(size_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);

typedef enum {
    rock = 0,
    paper = 1,
    scissors = 2,
} value;

inline value SelectARandomInteger() {
    register unsigned char a_random_integer;

    srandom(time(NULL));
    a_random_integer = random() % 3;

    return((value)a_random_integer);
}

inline signed char EnterAChoiceAsAnInteger() {
    register signed char an_integer = 0;

    printf("Enter a value: \n");
    printf("0 is used to represent: Rock\n");
    printf("1 to represent Paper\n");
    printf("2 to represent Scissors\n");
    printf("-1: Exit\n");
    scanf("%3hhd", &an_integer);

    return(an_integer);
}

size_t* RockPaperScissors(size_t *quantities) {
    
    printf("Rocks: %zu + %zu\n", 0[quantities], 0[won_items]);
    printf("Paper: %zu + %zu\n", 1[quantities], 1[quantities]);
    printf("Scissors: %zu + %zu\n\n", 2[quantities], 2[won_items]);

    register unsigned char a_random_integer = SelectARandomInteger();
    register signed char an_integer = EnterAChoiceAsAnInteger();

    if (an_integer == -1) {
        return(won_items);
    }

    if (an_integer < -1 || an_integer > 2) {
        printf ("An error message.\n\n");
        return(RockPaperScissors(quantities));
    }
    
    if (an_integer == a_random_integer) {
        printf("The user draws against the computer.\n\n");
    }
    else {
        switch (a_random_integer) {
        case rock:
            if (an_integer == 1) {
                printf("The user wins a rock.\n\n");
                ++0[won_items];
            }
            if (an_integer == 2) {
                printf("The user loses.\n\n");
            }
            break;

        case paper:
            if (an_integer == 0) {
                printf("The user loses.\n\n");
            }
            if (an_integer == 2) {
                printf("The user wins a piece of paper.\n\n");
                ++1[won_items];
            }
            break;

        case scissors:
            if (an_integer == 0) {
                printf("The user wins a pair of scissors.\n\n");
                ++2[won_items];
            }
            if (an_integer == 1) {
                printf("The user loses.\n\n");
            }
        }
    }
    return(RockPaperScissors(quantities));
}

int main() {
    register size_t *quantities = mmap(NULL, 3 * sizeof(size_t), PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);;

    RockPaperScissors(quantities);

    return(0);
}
