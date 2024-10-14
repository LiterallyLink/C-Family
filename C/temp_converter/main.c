#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 100

int get_float_input(const char* prompt, float* value) {
    char input[MAX_INPUT];
    char* endptr;

    printf("%s", prompt);

    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 0;
    }

    input[strcspn(input, "\n")] = 0;

    // Check if the input is 'q'
    if (strcmp(input, "q") == 0) {
        return -1; // Special value to indicate quit
    }

    *value = strtof(input, &endptr);
    if (*endptr != '\0' && *endptr != '\n') {
        return 0;
    }

    return 1;
}

float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32) * 5.0 / 9.0;
}

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    float fahrenheit, celcius;

    while (1) {
        int result = get_float_input("Enter a temperature in Fahrenheit (or 'q' to quit): ", &fahrenheit);
        if (result == 1) {
            celcius = fahrenheit_to_celsius(fahrenheit);
            printf("Temperature in Celsius: %.2f\n", celcius);
        } else if (result == -1) {
            printf("Quitting...\n");
            break;
        } else {
            if (feof(stdin)) {
                printf("End of input. Exiting...\n");
                break;
            }
            if (ferror(stdin)) {
                printf("Error reading input. Exiting...\n");
                break;
            }
            printf("Invalid input. Please enter a valid number or 'q' to quit.\n");
            clear_input_buffer();
        }
    }

    return EXIT_SUCCESS;
}