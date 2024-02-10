#include <stdio.h>

void string_to_bytes();

void handle_no_arguments();

int readLine(char buffer[], int max_length);

int main(int argc, char *argv[])
{

    if (argc == 1)
    {
        handle_no_arguments();
    }
    else
    {
        switch (argv[1][1])
        {
        case 'a':
            printf("you entered -a \n");
            break;
        case 'l':
            printf("you entered -l \n");
            break;

        default:
            handle_no_arguments();
            break;
        }
    }
    printf("\n");

    return 0;
}

void string_to_bytes()
{
    char buffer[200];
    int i;
    int count = 0;

    int index = readLine(buffer, sizeof(buffer));
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

void handle_no_arguments()
{
    string_to_bytes();
    // printf("Zadaj validny argument \n");
    // printf("Pouzi -x pre prevod do Hexadecimalnej  \n");
    // printf("Pouzi -S a -N [pocet] pre vypis postupnosti v binarnom vstupe \n");
}

int readLine(char buffer[], int max_length) {
    char character;
    int index = 0;

    // Read characters until newline or end of buffer
    while ((character = getchar()) != '\n' && index < max_length - 1) {
        buffer[index++] = character;
    }
    buffer[index] = '\0'; // Null-terminate the string
    return index;
}