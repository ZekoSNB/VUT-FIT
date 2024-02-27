// C program to demonstrate hexadecimal to decimal 
// conversion using for loop 
#include <math.h> 
#include <stdio.h> 
// #include <string.h> 
int main() { 
  
    char hexdecnumber[17] = "2D"; 
    long  decimalnumber;
    int i = 0, val, len; 
  
    decimalnumber = 0; 
  
    // Find the length of total number of hex digit 
    // finding the length of hexa decimal number 
    len = sizeof(hexdecnumber); 
    len--; 
  
    // for loop iterates the hexa decimal number digits 
    for (i = 0; hexdecnumber[i] != '\0'; i++) { 
  
        // finding the equivalent decimal digit for each 
        // hexa decimal digit 
        if (hexdecnumber[i] >= '0'
            && hexdecnumber[i] <= '9') { 
            val = hexdecnumber[i] - 48; 
        } 
        else if (hexdecnumber[i] >= 'a'
                 && hexdecnumber[i] <= 'f') { 
            val = hexdecnumber[i] - 97 + 10; 
        } 
        else if (hexdecnumber[i] >= 'A'
                 && hexdecnumber[i] <= 'F') { 
            val = hexdecnumber[i] - 65 + 10; 
        } 
  
        decimalnumber += val * pow(16, len); 
        len--; 
    } 
    // printing the result 
    printf("Hexadecimal number = %s\n", hexdecnumber); 
    printf("Decimal number = %ld", decimalnumber); 
    return 0; 
}
