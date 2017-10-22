# 3d plotting sofware

from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plot

figure = plot.figure()
axes = figure.add_subplot(111, projection = '3d')

x = [1,2]
y = [3,4]
z = [5,6]

axes.scatter(x,y,z,c='r',marker = 'x')

plot.show()
