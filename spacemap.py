import serial
from math import *
#code to read output from arduino, preferably in oarg,omag,z(height)put
#into variables,
#dictionary in list with arg, mag, z keys
#h=*tan(x-75)
#mag = 8.3 - mag
pointlist = [{'mag':1,'arg':45, 'z':3},{'mag':6,'arg':75, 'z':2}]
cartesians= []
#cylindrical to cartesian
for entry in pointlist:
    entry['x'] = entry['mag'] * cos(radians(entry['arg']))
    entry['y'] = entry['mag'] * sin(radians(entry['arg']))
    #luckily the z value is easy to find
#each cartesian point is given as a list [x,y,z]
for entry in pointlist:
    cartesians.append([entry['x'],entry['y'],entry['z']])
print (cartesians)
