import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("intento.dat")
n_points = int(np.sqrt(len(data)))
grid = np.reshape(data.T, (201, 201))


plt.figure(figsize=(15,5))
plt.subplot(1,2,1)
plt.imshow(grid)
plt.xlabel("Indice X")
plt.ylabel("Indice T")
plt.colorbar(label="Temperatura")


T1=data[:,0]
T2=data[:,-1]
plt.subplot(1,2,2)
x=np.arange(0,201,1)
plt.xlabel("Indice X")
plt.ylabel("Temperatura")
plt.plot(x,T1, label="tiempo inicial")
plt.plot(x,T2, label="tiempo final")
plt.legend()
plt.savefig("calor.png")