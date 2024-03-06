#include <stdio.h>
#include <stdbool.h>

void string_to_bytes_no_arg(int skip, int count);

void bytes_to_string();

void print_distance(int count);

void invalid_arguments();

void help();

int charToInt(char *str);

void string_to_bytes();

int readLine(char buffer[], int max_length, bool ignore_whitespace);

int main(int argc, char *argv[]){

    if (argc == 1){
       string_to_bytes_no_arg(0, 0);
    }

    else{
        switch (argv[1][1])
        {
        case 'h':
            help();
            break;
        case 's':
            string_to_bytes_no_arg(charToInt(argv[2]), 0);
            break;
        case 'n':
            string_to_bytes_no_arg(0, charToInt(argv[2]));
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
    printf("Argument -s to skip letters and you are following the argument -n with a number \n");
    printf("-s is for skipping the letters \n");
    printf("-n is for how many characters should be printed \n");
}

void invalid_arguments() {
    printf("You enter wrong argument. \n");
    printf("Enter -h for help \n");
}

void string_to_bytes_no_arg(int skip, int number_of_letter){

    char buffer[200];
    int i;
    int count = skip;
    printf("%d your count \n", count);
    printf("Printing this much letter: %d \n", number_of_letter);

    int index = readLine(buffer, sizeof(buffer), false);

    while (index != 0){
        printf("\n %08X  ", count);
        if (index > 16){
            for (i = 0; i < 16; i++){
                printf(" %x ", (int)buffer[count]);
                index--;
                count++;
            }
            printf("|");
            for (int j = 0; j < count; j++){
                printf("%c", buffer[j]);
            }
            printf("|");
        }
        else
        {
            for (i = 0; i < index; i++)
            {
                printf(" %x ", (int)buffer[count]);
                count++;
            }
            print_distance(index);
            printf("|");
            for (int j = 0; j < count; j++){
                printf("%c", buffer[j]);
            }
            printf("|");
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

void print_distance(int count){
    // adds a printed distance to the reamining space in the last print_no__arg by calculating space
    // between numbers there is a two space difference + two charactares having the same length 
    int final_distance = (16 - count) * 4;
    for (int i = 0; i < final_distance; i++){
        printf(" ");
    }
    
}

int charToInt(char *str) {
    int result = 0;
    int i = 0;
    int sign = 1;

    // Handle negative numbers
    if (str[0] == '-') {
        sign = -1;
        i++;
    }

    // Iterate through the characters until '\0' is encountered
    while (str[i] != '\0') {
        // Convert character to integer
        int digit = str[i] - '0';
        // Update the result by multiplying by 10 and adding the current digit
        result = result * 10 + digit;
        i++;
    }

    // Apply sign
    result *= sign;

    return result;
}
//testovac.ksp.sk
//gympd.sk/jaro 