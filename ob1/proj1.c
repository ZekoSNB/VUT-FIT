#include<stdio.h>

int string_to_int(char *str) {
    int result = 0;

    for (int i = 0; str[i] != '\0'; i++){
        result = result * 10 + str[i] - '0';
    }

    return result;
}


int invalid_argument(){

    printf("Zadaj validny argument \n");
    printf("Pouzi -x pre prevod do Hexadecimalnej  \n");
    printf("Pouzi -S a -N [pocet] pre vypis postupnosti v binarnom vstupe \n");

    return 0;
}

void make_something_with_character(char character){
    printf("%X ", (int)character);
}

int main(int argc, char *argv[]){
    if (argc == 1) {invalid_argument();}
    printf("argument number: %i \n", string_to_int(argv[2]));
    char character;

    while((character = getchar()) != '\n'){
        make_something_with_character(character);
    }

        switch (argv[1][1]) {
            case 'a':
                printf("you entered -a \n");
                break;
            case 'l':
                printf("you entered -l \n");
                break;

            default:
                invalid_argument();
                break;
        }
    return 0;
}
