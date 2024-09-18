#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to perform bit stuffing
void bitStuffing(char *data, char *stuffedData) {
    int i, j;
    int count = 0;
    int length = strlen(data);
    
    j = 0;
    for (i = 0; i < length; i++) {
        stuffedData[j++] = data[i];
        if (data[i] == '1') {
            count++;
            // Insert a 0 after 5 consecutive 1s
            if (count == 5) {
                stuffedData[j++] = '0';
                count = 0; // Reset count after stuffing
            }
        } else {
            count = 0; // Reset count on '0'
        }
    }
    stuffedData[j] = '\0'; // Null-terminate the stuffed data
}

int main() {
    char data[MAX_SIZE];
    char stuffedData[MAX_SIZE];

    // Example data
    printf("Enter the data to be stuffed: ");
    scanf("%s", data);

    // Perform bit stuffing
    bitStuffing(data, stuffedData);

    // Output the stuffed data
    printf("Original Data: %s\n", data);
    printf("Stuffed Data: %s\n", stuffedData);

   return 0;
}
