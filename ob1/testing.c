#include <stdio.h>
// #include <ctype.h>

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



int main() {
    char a;
    scanf("%s", &a);
    char* hex_string = &a;
    char str[12]; 
    int value = hex_to_int(hex_string);

    printf("String value: %c\n", value);

    if (value != -1) {
        printf("The integer value of %s is %d\n", hex_string, value);
    }

    return 0;
}

