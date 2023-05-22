#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <stdint.h>

int wrap_main(int argc, char *argv[]) {
    // Define the desired winning numbers
    char *winning_numbers[] = { "9", "8", "10", "24", "75", "9" };

    // Load the original gm program
    void *handle = dlopen("./gm", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error: Failed to load original gm program\n");
        return 1;
    }

    // Get the address of the original main function
    int (*original_main)(int, char **) = (int (*)(int, char **))(intptr_t)dlsym(handle, "main");
    if (!original_main) {
        fprintf(stderr, "Error: Failed to find the original main function\n");
        dlclose(handle);
        return 1;
    }

    // Call the original main function with the modified arguments
    char **new_argv = malloc((argc + 6) * sizeof(char *));
    if (!new_argv) {
        fprintf(stderr, "Error: Failed to allocate memory\n");
        dlclose(handle);
        return 1;
    }

    // Copy the original arguments
    for (int i = 0; i < argc; i++) {
        new_argv[i] = argv[i];
    }

    // Add the winning numbers to the arguments
    for (int i = 0; i < 6; i++) {
        new_argv[argc + i] = winning_numbers[i];
    }
    new_argv[argc + 6] = NULL;

    // Call the original main function with the new arguments
    int result = original_main(argc + 6, new_argv);

    // Cleanup and exit
    dlclose(handle);
    free(new_argv);
    return result;
}
