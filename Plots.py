import numpy as np
import matplotlib.pyplot as plt
import scipy.io.wavfile

data=np.genfromtxt("cuerda.tex",delimiter=" ")
data1=np.genfromtxt("audio.dat")
data2=np.genfromtxt("tambor.tex")
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
plt.plot(x,amplitud2, c="blue", label="t=0")
plt.plot(x,amplitud3, c="red",label="t=T/8")
plt.plot(x,amplitud4, c="yellow",label="t=T/4")
plt.plot(x,amplitud5, c="black",label="t=T/2")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.legend()
plt.show()

plt.figure()
plt.plot(x,amplitud9, c="blue",label="t=0")
plt.plot(x,amplitud10, c="red",label="t=T/8")
plt.plot(x,amplitud11, c="yellow",label="t=T/4")
plt.plot(x,amplitud12, c="black",label="t=T/2")
plt.xlabel("Posicion")
plt.ylabel("Amplitud")
plt.legend()
plt.show()

scipy.io.wavfile.write("sonido.wav",0.00001,data1)
