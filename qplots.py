import numpy as np
import matplotlib.pyplot as plt

data=np.genfromtxt("qdatos.dat")

t=qdata[:,0]
x=qdata[:,1]
y=qdata[:,2]


plt.title("Trayectoria de una particula cargada")
plt.plot(x,y)
plt.xlabel("x")
plt.ylabel("y")
plt.savefig("SalazarNicole_final_15.pdf")
plt.show()
