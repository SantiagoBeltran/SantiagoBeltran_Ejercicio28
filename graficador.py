import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

data= np.loadtxt("intento.dat")
x=np.arange(0,70,1)
y=np.arange(0,70,1)

def f(x,y):
    return data[x,y]

X,Y=np.meshgrid(x,y)

fig = plt.figure()
ax = Axes3D(fig)
ax.plot_wireframe(X,Y,f(X,Y),color="r")
plt.show()
plt.savefig("laplace.png")