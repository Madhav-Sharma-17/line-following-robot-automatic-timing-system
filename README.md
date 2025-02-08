LFR Automatic Timing System
Overview
The LFR Automatic Timing System is designed to measure the time taken by a line-following robot (LFR) to complete a track. It uses two infrared (IR) sensors placed at the start and end points to trigger timing events.

Features
Automatic timing using IR sensors
Real-time stopwatch functionality
Serial output for time recording and analysis
Hardware Requirements
Microcontroller (e.g., Arduino)
IR Sensors (2x)
LFR Robot
Circuit Connections
IR Sensor 1 (Start Line): Connect to GPIO 15
IR Sensor 2 (End Line): Connect to GPIO 4
Ensure proper VCC (5V) and GND connections
How It Works
Start Detection:
When the robot moves past IR Sensor 1, the timer starts.
Stop Detection:
When the robot moves past IR Sensor 2, the timer stops, and the elapsed time is displayed via Serial Monitor.
Installation & Usage
Upload the Code

Open the provided lfr_automatic_timing_system.ino file in Arduino IDE.
Select the correct board and COM port.
Upload the code to your microcontroller.
Monitor the Output

Open the Serial Monitor at 115200 baud rate.
Observe timing results as the LFR completes the track.
Code Breakdown
Setup Phase (setup())
Initializes IR sensor pins and Serial Communication.
Loop (loop())
Continuously checks sensor states.
Starts/stops the stopwatch based on IR sensor triggers.
Displays the elapsed time on the Serial Monitor.
Example Serial Output
css
Copy
Edit
Stopwatch started.
Stopwatch stopped. Time elapsed: 5.32 seconds
Potential Enhancements
Add an LCD/OLED Display for real-time time tracking.
Store timing logs for multiple runs.
Wireless transmission of timing data via Bluetooth/WiFi.
