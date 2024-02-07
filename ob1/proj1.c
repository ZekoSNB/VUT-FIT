#include<stdio.h>

int invalid_argument();

char get_input(){
    char buffer[200];
    int index = 0;
    char character;
        while((character = getchar()) != '\n' && index < (int)sizeof(buffer) - 1){
        buffer[index++] = character;
    }
    return buffer;
}



int invalid_argument(){
    char text = get_input();
    printf("buffer:  %c \n", text);
    printf("Zadaj validny argument \n");
    printf("Pouzi -x pre prevod do Hexadecimalnej  \n");
    printf("Pouzi -S a -N [pocet] pre vypis postupnosti v binarnom vstupe \n");

    return 0;
}



    
int main(int argc, char *argv[]){

    if (argc == 1) {
        handle_no_arguments();
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
