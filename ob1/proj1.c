#include <stdio.h>
#include <stdbool.h>

void string_to_bytes_no_arg();

void bytes_to_string();

void string_to_bytes();

int readLine(char buffer[], int max_length, bool ignore_whitespace);

int main(int argc, char *argv[]){

    if (argc == 1){
       string_to_bytes_no_arg();
    }

    else{
        switch (argv[1][1])
        {
        case 'r':
            printf("Your argument was r. \n");
            bytes_to_string();
            break;
        case 'x':
            printf("Your argument was x. \n");
            string_to_bytes();
            break;

        default:
            printf("Zadal si zly argument. \n");
            break;
        }
    }
    printf("\n");

    return 0;
}

void string_to_bytes_no_arg(){

    char buffer[200];
    int i;
    int count = 0;

    int index = readLine(buffer, sizeof(buffer), false);
    printf("Vstupny retazec: %s \n", buffer);
    printf("index: %d \n", index);

    while (index != 0){
        printf("\n %08X  ", count);
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
    printf("Index is %i \n", index);
    for (int i = 0; i < index; i++){
        printf("%x", (int)buffer[i]);
    }
}