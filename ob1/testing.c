#include <stdio.h>

int main() {
    unsigned char hex_bytes[] = {0x20, 0x6a, 0x6c}; // Bytes represented in hexadecimal format
    char ascii_string[3]; // Assuming 2 bytes -> 2 characters + '\0'

    sprintf(ascii_string, "%c%c", hex_bytes[1], hex_bytes[2]); // Convert bytes to ASCII characters

    printf("ASCII string: %s\n", ascii_string);

    return 0;
}