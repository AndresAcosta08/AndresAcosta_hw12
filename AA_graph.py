import numpy as np
import matplotlib.pyplot as plt

#Se cargan los datos del archivo de texto.
datos=np.loadtxt('advection.txt')

#Se llevan a cabo las divisiones.
division = int(175)

#Se lleva a cabo un arreglo para las futuras divisiones.
i= np.arange(0,750,division)

print i

#Se plotean los resultados en donde la col1 del archivo es = x y la col2 = y.
for t in i:
	x=datos[datos[:,0]==t,1]
	y=datos[datos[:,0]==t,2]
	try:
		plt.plot(x,y,label='t='+str(t))
	except:
		print t

#Se crea la grafica, con sus respectivos ejes y titulo.
plt.xlabel('X')
plt.ylabel('F(X,t)')
plt.legend()
plt.ylim(0,1)
plt.title('Adveccion Lineal')
plt.savefig('grafica.png')
