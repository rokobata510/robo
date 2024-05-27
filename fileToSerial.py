import time
import os
import serial

# Open the serial port
ser = serial.Serial('COM1', 115200)

# Wait for the Arduino to initialize
time.sleep(2)

# Get a list of all files in the frames directory
files = os.listdir('frames')

# Sort the files by their numerical value
files.sort(key=lambda x: int(x.split('.')[0]))

# Send each file to the Arduino
for filename in files:
    # Open the file
    with open(f'frames/{filename}', 'r') as file:
        # Read the file line by line
        for line in file:
            line = line.rstrip('\n')
            ser.write(line.encode())
            print(line.encode())
        # Wait for 1/30th of a second
        #time.sleep(1/30)
        #output the frame to the console

# Close the serial port
ser.close()