import serial
from math import *

# Key variable initialization
counter = 0
switch = 0
halt = False

# Serial setup
ser = serial.Serial('',9600, timeout = 1)

# Function for withdrawing a line of data from Arduino
def evaluate():
    ser.write(b'g')
    data = ser.readline().decode('ascii')
    return int(data)


while halt = False:
    
        temp_data = evaluate()

        if switch = 0:       
            dist_data = evaluate()
        elif switch = 1:
            angle_dat = evaluate()

            # - - - - - - - - - - - -
            # Spooky scary mathematics
            # - - - - - - - - - - - -
            
            x_values[counter] =
            y_values[counter] =
            
        elif switch = 2:
            z_values[counter] =

        
        if switch = 2:
            switch = 0
            counter =+ 1
        else:
            switch =+ 1

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
