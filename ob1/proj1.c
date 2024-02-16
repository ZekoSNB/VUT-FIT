#include <stdio.h>
#include <stdbool.h>

void string_to_bytes_no_arg();

void bytes_to_string();

void invalid_arguments();

void help();

void string_to_bytes();

int readLine(char buffer[], int max_length, bool ignore_whitespace);

int main(int argc, char *argv[]){

    if (argc == 1){
       string_to_bytes_no_arg();
    }

    else{
        switch (argv[1][1])
        {
        case 'h':
            help();
            break;
        case 'r':
            bytes_to_string();
            break;
        case 'x':
            string_to_bytes();
            break;

        default:
            invalid_arguments();
            break;
        }
    }
    printf("\n");

    return 0;
}

void help(){
    printf("argument -x for converting string to nbytes  \n");
    printf("Argument -r for converting from bytes to string \n");
    printf("Argument -S for printing i have no fucking idea what :D \n");
    printf("Argument -s following the argument -n with a number \n");
    printf("-s is for skipping the letters \n");
    printf("-n is for how many characters should be printed \n");
}

void invalid_arguments() {
    printf("You enter wrong argument. \n");
    printf("Enter -h for help \n");
}

void string_to_bytes_no_arg(){

    char buffer[200];
    int i;
    int count = 0;

    int index = readLine(buffer, sizeof(buffer), false);
    printf("Vstupny text: %s \n", buffer);

    while (index != 0){
        // printf("\n %08X  ", count);
        if (index > 16){
            for (i = 0; i < 16; i++){
                printf(" %x ", (int)buffer[count]);
                index--;
                count++;
            }
        }
        else
        {
            for (i = 0; i < index; i++)
            {
                printf(" %x ", (int)buffer[count]);
                count++;
            }
            index = 0;
        }
    }
}

void bytes_to_string(){
    char buffer[200];
    int index = readLine(buffer, sizeof(buffer), true);
    if (index % 2 == 1){
        printf("The last character is %c \n", buffer[index-1]);
    }
}

int readLine(char buffer[], int max_length, bool ignore_whitespace) {
    char character;
    int index = 0;

    while ((character = getchar()) != '\n' && index < max_length - 1) {
        if (ignore_whitespace && (character == ' ' || character == '\t')) {
            continue;
        }
        buffer[index++] = character;
    }
    buffer[index] = '\0'; 
    return index;
}

void string_to_bytes(){
    char buffer[200];
    int index = readLine(buffer, sizeof(buffer), false);
    for (int i = 0; i < index; i++){
        printf("%x", (int)buffer[i]);
    }
}