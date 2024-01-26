#include<stdio.h>

int main(int argc, char *argv[]){

    char buffer[200];
    char character;
    int index = 0;

    while((character = getchar()) != '\n' && index < (int)sizeof(buffer)){
        buffer[index++] = character;
    }


    if (argc == 1) {
        printf("you didn't enter any arguments \n");
        return 0;
    }

    
    else {
        switch (argv[1][1]) {
            case 'a':
                printf("you entered -a \n");
                break;
            case 'l':
                printf("you entered -l \n");
                break;

            default:
                printf("Zadaj validny argument \n");
                printf("Pouzi -x pre prevod do Hexadecimalnej  \n");
                printf("Pouzi -S a -N [pocet] pre vypis postupnosti v binarnom vstupe \n");
                break;
        }
    }
    return 0;
}
