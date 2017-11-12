import numpy as np
import matplotlib.pyplot as plt
import scipy.io.wavfile

data=np.genfromtxt("Resultados_hw4.tex",delimiter=" ")
data1=np.genfromtxt("audio.dat")
x=data[:,1]
amplitud1= data[:,2]

amplitud2= data[:,3]
amplitud3= -data[:,4]
amplitud4= data[:,5]
amplitud5= data[:,6]


amplitud9= data[:,7]
amplitud10= data[:,8]
amplitud11= data[:,9]
amplitud12= data[:,10]





plt.figure()
plt.plot(x,amplitud2)
plt.plot(x,amplitud3, c="red")
plt.plot(x,amplitud4, c="yellow")
plt.plot(x,amplitud5, c="black")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.show()

plt.figure()
plt.plot(x,amplitud9)
plt.plot(x,amplitud10, c="red")
plt.plot(x,amplitud11, c="yellow")
plt.plot(x,amplitud12, c="black")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.show()

scipy.io.wavfile.write("sonido.wav",0.00001,data1)
