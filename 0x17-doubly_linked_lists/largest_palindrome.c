#include <stdio.h>

int isPalindrome(int number) {
    int original = number;
    int reversed = 0;
    
    while (number > 0) {
        reversed = (reversed * 10) + (number % 10);
        number /= 10;
    }
    
    return original == reversed;
}

int main() {
    int largestPalindrome = 0;

    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            int product = i * j;
            if (isPalindrome(product) && product > largestPalindrome) {
                largestPalindrome = product;
            }
        }
    }

    FILE *file = fopen("102-result", "w");
    if (file != NULL) {
        fprintf(file, "%d", largestPalindrome);
        fclose(file);
    }

    return 0;
}
