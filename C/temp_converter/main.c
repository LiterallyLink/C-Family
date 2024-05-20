#include <stdio.h>

void clear_input_buffer() {
	int c;
	while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
	char input[100];
	float fahrenheit, celsius;
	int success;
	char extra;

	while (1) {
		printf("Enter temperature in Fahrenheit: ");
		if (fgets(input, sizeof(input), stdin) != NULL) {
			if (sscanf(input, "%f %c", &fahrenheit, &extra) == 1) {
				celsius = (fahrenheit - 32) * 5 / 9;
				printf("Temperature in Celsius: %.2f\n", celsius);
			} else {
				printf("Invalid input. Please enter a number.\n");
			}
		} else {
			printf("Failed to read input. Please try again.\n");
			clear_input_buffer();
		}
	}
}