#include<stdio.h>

int charToInt(char *str);

int main(int argc, char *argv[]){
    printf("%s \n", argv[1]);
    int result = charToInt(argv[1]);

    printf("%d result \n", result*2);
    return 0;
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