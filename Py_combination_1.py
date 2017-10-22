import serial
from math import *

# Key variable initialization
counter = 0
switch = 0
halt = False

# Serial setup
ser = serial.Serial('COM5',9600, timeout = 1)

# Function for withdrawing a line of data from Arduino
def evaluate():
    ser.write(b'g')
    data = ser.readline().decode('ascii')
    return int(data)


while halt == False:
    

        if switch == 0:       
            mag_data = 9.5 - evaluate()
        elif switch == 1:
            angle_data = evaluate()
            
            x_values[counter] = mag_data * cos(radians(angle_data))
            y_values[counter] = mag_data * sin(radians(angle_data))
            
        elif switch == 2:
            z_values[counter] = evaluate()

        
        if switch == 2:
            switch = 0
            counter =+ 1
        else:
            switch =+ 1

        if counter > 480:
            halt = True

# Plotting on 3d Graph


from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plot

figure = plot.figure()
axes = figure.add_subplot(111, projection = '3d')

x = [x_values]
y = [y_values]
z = [z_values]

axes.scatter(x,y,z,c='r',marker = 'x')

plot.show()
