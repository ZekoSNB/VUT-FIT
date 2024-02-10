#include <stdio.h>

void readLine(char buffer[], int max_length) {
    char character;
    int index = 0;

    // Read characters until newline or end of buffer
    while ((character = getchar()) != '\n' && index < max_length - 1) {
        buffer[index++] = character;
    }
    buffer[index] = '\0'; // Null-terminate the string
}

int main() {
    char buffer[1000]; // Assuming a maximum buffer size of 999 characters
    printf("Enter a line of text: ");
    readLine(buffer, sizeof(buffer));
    printf("You entered: %s\n", buffer);
    return 0;
}
