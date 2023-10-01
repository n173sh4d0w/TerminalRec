#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

char* output_file = "output.mp4";
char* save_path = "./";
pid_t recording_pid = 0;

// Function to start the terminal recording in the background
void start_recording() {
    char full_output_path[1024];
    snprintf(full_output_path, sizeof(full_output_path), "%s%s", save_path, output_file);

    recording_pid = fork();
    if (recording_pid == 0) {
        execlp("script", "script", "-c", "ttyrec -e cat", full_output_path, NULL);
        perror("Error");
        exit(1);
    }

    printf("Terminal activity recording started with PID: %d\n", recording_pid);
}

// Function to stop the terminal recording gracefully
void stop_recording() {
    if (recording_pid > 0) {
        printf("Stopping recording...\n");
        kill(recording_pid, SIGINT);
        waitpid(recording_pid, NULL, 0);
        printf("Recording stopped. Video saved as %s%s\n", save_path, output_file);
        recording_pid = 0;
    } else {
        printf("No recording session is currently active.\n");
    }
}

int main(int argc, char* argv[]) {
    for (int i = 1; i < argc; i += 2) {
        if (i + 1 < argc) {
            (strcmp(argv[i], "-o") == 0) ? (output_file = argv[i + 1]) : (strcmp(argv[i], "-p") == 0) ? (save_path = argv[i + 1]) : (void)0;
        }
    }

    start_recording();

    // Set a signal handler to stop recording on exit
    atexit(stop_recording);

    printf("Terminal activity recording started. Press Enter to stop...\n");
    getchar();

    return 0;
}
