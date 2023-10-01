# Terminal Activity Recorder
To record terminal activities.

## Dependencies
script: to capture terminal sessions.
ttyrec: to record terminal activities.

## Usage
Compile&Run the program w/optional params:
```
gcc terminal_recorder.c -o terminal_recorder
./terminal_recorder -o my_session.mp4 -p /path/to/save/directory/
```
## Recording
The program will start capturing terminal activities as soon as you run it.
To stop recording, press Enter in the terminal where the program is running.
The recorded video will be saved in the specified save path with the given output file name(default name 'output.mp4' in the current dir).
You will receive a confirmation message with the file path where the video is saved.

## Error Handling
If the 'script' or 'ttyrec' commands are not found on your system, the program will display an error message and exit.
If there are any issues with starting or stopping the recording process, error messages will be displayed to help diagnose the problem.

## Disclaimer
Please note that the quality and content of the recorded video may vary depending on your terminal and system settings. This tool is meant for basic terminal activity recording and may not capture all terminal behaviors or special configurations.

## Enjoy recording your terminal sessions with this simple and handy tool!
