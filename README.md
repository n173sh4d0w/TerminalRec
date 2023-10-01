# TermRec
To capture&recording terminal sessions in the background, and you can stop it gracefully at any time.

## Features
Gracefully stop recording with a simple keypress.
## Dependencies
script and ttyrec
## Usage
Clone the repository and compile the program; Run the program with optional arguments:
```
gcc -o recorder recorder.c
./recorder -o my_recording.mp4 -p /path/to/save
```
-o output_file: Specify the output file name (default is "output.mp4").
-p save_path: Specify the save path (default is the current directory).
The program will start recording your terminal activity in the background. You will see a message with the PID (Process ID) of the recording session.

To stop recording, simply press Enter in your terminal(file auto-saved in the specified location).
## License
MIT License
