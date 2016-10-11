#programa n de lp
#Equipo

#
#
#
#

# Desarrollar el programa que implemente las funciones diseniadas usando el tipo de paso
# de parametros que indicaste.
#tipos de parametros 
#por valor
#por referencia
#por valor-resultado

def f1Val(lista):
	lista.reverse()
	return lista

def productCart(vect):
	return vect

def defFunc(nombre):
	print("Dime que tipo de paso de parametros quieres: ")
	print("1- paso por valor\n2- paso por referencia\n3- paso por valor-resultado")
	opcion=input("\tOpcion: ")
	if nombre=="lista":
		if opcion=='1':
			return f1Val
		elif opcion=='2':
			return f1Ref
		else:
			return f1ValRe
	if nombre=="prod":
		if opcion=='1':
			return f2Val
		elif opcion=='2':
			return f2Ref
		else:
			return f2ValRe

def main():
	print("MENU")
	print("1- la lista en reversa\n2-Angulo y distancia ")
	opcion=input("\tOpcion: ")
	if opcion=='1':
		n=int(input("De que tamanio quieres tu lista: "))
		lista=[]
		for i in range(n):
			lista.append(input("Dame el valor "+str(i)+": "))
		funcion=defFunc("lista")
		lista=funcion(lista)
		print(lista)
	else:
		n=int(input("Dame el numero de puntos que quieres introducir "))	
		vects=[]
		for i in range(n*2):
			aux=[]
			aux.append(input("Dame la coordenada en x del "+str(i+1)+" punto: "))
			aux.append(input("Dame la coordenada en y del "+str(i+1)+" punto: "))
			vects.append(aux)
		funcion=defFunc("lista")
		funcion(lista)
main()

#avance aun falta
 
