import numpy as np 
import matplotlib.pyplot as plt 

datos=np.genfromtxt('map_data.txt')
#print datos 
salida=np.genfromtxt('salida.txt')
y=salida[0]
x=salida[1]
r=salida[2]

n_y=500
n_x=744
#print y,x 

if(x > n_x):
	x = x % n_x;
elif(x < 0.0):
	x = n_x + x;
if(y > n_y):
	y = y % n_y; 
elif(y < 0.0):
	y = n_y + y;
	

#print y,x 

cir=plt.Circle((x,y),r,alpha=.2, color='r')	
fig,ax=plt.subplots()
ax.add_artist(cir)
ax.add_artist(plt.imshow(datos))
plt.scatter(x,y, c='y')
fig.savefig("PuntoNemo.pdf")



