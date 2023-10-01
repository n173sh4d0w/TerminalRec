#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

// Function to check if a command exists on the system
bool command_exists(const char *cmd) {
    return system(cmd) == 0;
}

int main(int argc, char* argv[]) {
    char* output_file = "output.mp4"; // Default output file name
    char* save_path = "./";          // Default save path

    // Check if 'script' and 'ttyrec' commands exist
    if (!command_exists("script") || !command_exists("ttyrec")) {
        fprintf(stderr, "Error: 'script' and 'ttyrec' commands are required but not found.\n");
        return 1;
    }

    // Parse command-line options
    int opt;
    while ((opt = getopt(argc, argv, "o:p:")) != -1) {
        switch (opt) {
            case 'o':
                output_file = optarg;
                break;
            case 'p':
                save_path = optarg;
                break;
            default:
                fprintf(stderr, "Usage: %s [-o output_file] [-p save_path]\n", argv[0]);
                return 1;
        }
    }

    // Create the full output file path
    char full_output_path[1024];
    snprintf(full_output_path, sizeof(full_output_path), "%s%s", save_path, output_file);

    // Create a command to capture terminal activities using the 'script' command
    char script_command[1024];
    snprintf(script_command, sizeof(script_command), "script -c \"ttyrec -e cat\" %s", full_output_path);

    // Start capturing terminal activities
    if (system(script_command) != 0) {
        fprintf(stderr, "Error: Failed to start terminal recording.\n");
        return 1;
    }

    // Provide a message and wait for user input to stop recording
    printf("Terminal activity recording started. Press Enter to stop...\n");
    getchar();

    // Stop the 'script' command when the user presses Enter
    if (system("pkill -INT -f 'script -c ttyrec -e cat'") != 0) {
        fprintf(stderr, "Error: Failed to stop terminal recording.\n");
        return 1;
    }

    printf("Recording stopped. Video saved as %s\n", full_output_path);

    return 0;
}
