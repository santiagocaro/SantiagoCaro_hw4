import numpy as np 
import matplotlib.pyplot as plt 

datos=genformtxt('map_data.txt')
print datos 


plt.imshow(datos)
plt.savefig("PuntoNemo.pdf")
plt.close()

