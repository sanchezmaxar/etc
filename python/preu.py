import os
import threading
from time import *
def hola():
	global opcion
	global cont
	while opcion:
		os.system("clear")
		print("presiona f para salir")
		print(time())
		cont+=1
		print(cont)
		sleep(0.1)

cont=0
opcion=True
hilo=threading.Thread(target=hola)
hilo.start()
while opcion:
	opcion=input("")
	if opcion=='f':	
		opcion=False

print(opcion)
