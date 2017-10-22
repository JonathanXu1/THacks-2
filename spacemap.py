import serial
from math import *
#code to read output from arduino, preferably in arg,mag,z(height), and number and put
#into variables,
#dictionary in list with arg, mag, z keys

pointlist = [{'mag':1,'arg':45, 'z':3},{'mag':6,'arg':75, 'z':2}]
cartesians= []
#cylindrical to cartesian
for entry in pointlist:
    entry['x'] = entry['mag'] * cos(radians(entry['arg']))
    entry['y'] = entry['mag'] * sin(radians(entry['arg']))
#each cartesian point is given as a list [x,y,z]
for entry in pointlist:
    cartesians.append([entry['x'],entry['y'],entry['z']])
print (cartesians)
