#include <stdio.h>
#include <stdbool.h>

void string_to_bytes_no_arg();

void bytes_to_string();

void print_distance(int count);

void invalid_arguments();

void help();

void string_to_bytes();

int readLine(char buffer[], int max_length, bool ignore_whitespace);

int hex_to_int(const char* hex);

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
    int res[200];
    for (int i = 0; i < sizeof(buffer); i++){
        printf("%c", buffer[i]);
    }
    for (int i = 0; i < sizeof(buffer); i += 2){
        char* hex[3] = {buffer[i], buffer[i + 1], '\0'};
        res[i / 2] = hex_to_int(hex);
    }
    printf("%d", res);
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

int hex_to_int(const char* hex) {
    int result = 0;
    int value = 0;

    // Iterate over each character in the hex string
    while (*hex) {
        char digit = *hex;

        // Convert hexadecimal digit to its integer value
        if (digit >= '0' && digit <= '9') {
            value = digit - '0';
        } else if (digit >= 'A' && digit <= 'F') {
            value = digit - 'A' + 10;
        } else if (digit >= 'a' && digit <= 'f') {
            value = digit - 'a' + 10;
        } else {
            // Invalid hexadecimal character
            printf("Error: Invalid hexadecimal digit '%c'\n", digit);
            return -1;
        }

        // Shift the current result to the left by 4 bits (equivalent to multiplying by 16)
        result = (result << 4) | value;

        // Move to the next character
        hex++;
    }

    return result;
}
