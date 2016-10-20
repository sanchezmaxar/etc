// programa que ejemplifica el paso de parametros por referencia, por valor, por valor resultado
// compilador usado: gcc
// SO: Ubuntu 16.03 lts
// Editor: Atom 1.10.2
// Desarrollo:
//   Sanchez Hernandez Max Armando
//   Mares Ontiveros Valeria Fernanda
//   Velazquez Sanchez Jose Antonio

// IMPORTANTE EJECUTAR CON gcc p4.c -lm
// Pendientes:
// - Crear las funciones invPorValRes() invPorVal() angPorValor() angPorRef() angPorValRes()
//  -Terminar funcion invPorRef()

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PI 3.141592
void invPorRef(int * lista, int largo);
void invPorVal(int lista[], int largo);
void invPorValRes(int cop[], int largo);
void angPorRef(float **angs,int ** vectores, int largo);
void angPorValRes(float **angs,int ** vectores, int largo);
void angPorVal(float **AngDis,int ** vectores, int largo);
int main(){
	char opc1,opc2,repetir='s';
	int *list;
	int n,i;
	int **vects;
	float **angs;//vectores y angulos
		while(repetir!='n'){
		printf("\n\nMenu\n\n");
		printf("1)Reversa de una lista\n2)Angulo y distancia\n\tOpcion: ");
		scanf("%c",&opc1);
		switch( opc1){
			case '1':
				printf("Introduce el numero de elementos de la lista: " );
				scanf("%d",&n);
				list=(int*)malloc(n*sizeof(int));
				for (i=0;i<n;i++){
					printf("\nDame el elemento %d de la lista: ",i+1);
					scanf("%d",list+i);
				}
				break;
			case '2':
				printf("Cuantos puntos quieres: ");
				scanf("%d",&n);
				vects=(int**)malloc(n*sizeof(int*));
				angs=(float**)malloc(n*sizeof(float*));
				for(i=0;i<n;i++){
						*(vects+i)=(int*)malloc(2*sizeof(int));
						*(angs+i)=(float*)malloc(2*sizeof(float));
						printf("%i) X : ",i+1 );
						scanf("%d",*(vects+i));
						printf("%i) Y : ",i+1 );
						scanf("%d",*(vects+i)+1);
				}
				break;
		}
		printf("Que tipo de paso de parametros quieres ejecutar?\n");
		printf("1) Por referencia\n2) Valor resultado\n3) valor\n\topcion: ");
		// scanf("%c",&opc2);//scanf extra para sistemas linux comentar en otro
		scanf("%c",&opc2);
		switch (opc1){
			case '1':
				if (opc2=='1')
					invPorRef(list,n);
				else if (opc2=='2')
					invPorValRes(list,n);
				else
					invPorVal(list,n);
				printf("\nAl salir:\t");
				for(i=0;i<n;i++){
					printf("%d ",list[i]);
				}
				break;
			 case '2':
			 	printf("Arreglo de angulos y distancias ANTES:\n");
	 			for(i=0;i<n;i++)
	 			printf("\t%d) distancia: %.2f angulo: %.2f\n",i+1,angs[i][0],angs[i][1]);
			 	if (opc2=='1')
					angPorRef(angs, vects,n);
				else if (opc2=='2')
					angPorValRes(angs,vects,n);
				else
					angPorVal(angs,vects,n);
			printf("Arreglo de angulos y distancias DESPUES:\n");
			for(i=0;i<n;i++)
				printf("\t%d) distancia: %.2f angulo: %.2f\n",i+1,angs[i][0],angs[i][1]);
				break;
		}
		printf("Deseas repetir la ejecucion?(s/n): ");
		scanf("%c",&repetir);
		// scanf("%c",&repetir);//esta linea se repite para su ejecucion en linux
	}
	return 0;
}

void invPorRef(int * lista, int largo){
	/* Realiza la operación de inversión de una lista
	utilizando el paso de parámetros por referencia.
	Esto se hace en C simplemente al utilizar un apuntador
	a la lista que se ha de modificar*/
	int aux,i;
	printf("\nAntes:\t\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
	for(i=0;i<(largo/2);i++){
		// La lista original se actualiza automáticamente
		// ya que se trabaja con un apuntador.
		aux=lista[i];
		lista[i]=lista[largo-i-1];
		lista[largo-i-1]=aux;
	}
	printf("\nDespues:\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
}//yasta x2
void invPorVal(int cop[], int largo){
	/* Realiza la operación de inversión de una lista
	utilizando el paso de parámetros por valor.
	Esto se hace en C simplemente al no utilizar
	apuntadores*/
	
	int aux,i;
	int lista[largo];
	for(i=0;i<largo;i++)
		lista[i]=cop[i];
	printf("\nAntes:\t\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
	for(i=0;i<(largo/2);i++){
		aux=lista[i];
		lista[i]=lista[largo-i-1];
		lista[largo-i-1]=aux;
	}
	printf("\nDespues:\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
}//yasta//yasta
void invPorValRes(int cop[], int largo){
	/* Realiza la operación de inversión de una lista
	utilizando el paso de parámetros por valor-resultado
	al actualizar la lista original solo hasta el final
	de la función. Esto, ya que C no soporta de manera nativa
	el paso por valor-resultado*/
	
	int aux,i;
	int lista[largo];
	for(i=0;i<largo;i++)
		lista[i]=cop[i];
	printf("\nAntes:\t\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
	for(i=0;i<(largo/2);i++){
		aux=lista[i];
		lista[i]=lista[largo-i-1];
		lista[largo-i-1]=aux;
	}
	printf("\nDespues:\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
	for(i=0;i<largo;i++)
		cop[i]=lista[i];
}//yasta//yasta
void angPorRef(float **AngDis,int ** vectores, int largo){
	/* Realiza la operación de encontrar la distancia y
	angulos dentro de una lista de puntos,
	utilizando el paso de parámetros por referencia.
	Esto se hace en C simplemente al utilizar un apuntador
	de apuntadores*/
	 int i;
	 float Ax, Ay;
	 for (i=0; (i+1) < largo ; i++)
	 {
		 // Las matrices originales de actualizan automáticamente ya que
		 // se utilizan los apuntadores
		 Ax= (vectores [i][0]-vectores[i+1][0]) * (vectores [i][0]-vectores[i+1][0]);
		 Ay= (vectores [i][1]-vectores[i+1][1]) * (vectores [i][1]-vectores[i+1][1]);
	   AngDis [i][0] = sqrt(Ay+Ax);
		 AngDis[i][1]= atan(Ay/ Ax)*180/PI;
	 }
	 printf("Arreglo de angulos y distancias EN LA FUNCION\n");
	 for(i=0;i<largo-1;i++)
		printf("\t%d) distancia: %.2f angulo: %.2f\n",i+1,AngDis[i][0],AngDis[i][1]);
}

void angPorValRes(float **AngDis,int ** vectores, int largo){
	/* Realiza la operación de encontrar la distancia y
	angulos dentro de una lista de puntos,
	utilizando el paso de parámetros por valor-resultado.
	Esto se hace en C actualizando las matrices originales
	solo al finalizar la ejecución de la función*/
	int i;
	float Ax, Ay;
	float** AngDis2;
	AngDis2=(float **)malloc(largo*sizeof( float *));
	for (i=0; (i+1) < largo ; i++)
	{
		*(AngDis2+i)=(float *)malloc(2*sizeof(float));
		Ax= (vectores [i][0]-vectores[i+1][0]) * (vectores [i][0]-vectores[i+1][0]);
		Ay= (vectores [i][1]-vectores[i+1][1]) * (vectores [i][1]-vectores[i+1][1]);
	   	AngDis2 [i][0] = sqrt(Ay+Ax);
		AngDis2[i][1]= atan(Ay/ Ax)*180/PI;
	 }
	 printf("Arreglo de angulos y distancias EN LA FUNCION\n" );
	 for(i=0;i<largo-1;i++){
		printf("\t%d) distancia: %.2f angulo: %.2f\n",i+1,AngDis2[i][0],AngDis2[i][1]);
		AngDis[i][0] = AngDis2 [i][0];
		AngDis[i][1]= AngDis2[i][1];
	 }
}

void angPorVal(float **AngDis,int ** vectores, int largo){
	/* Realiza la operación de encontrar la distancia y
	angulos dentro de una lista de puntos,
	utilizando el paso de parámetros por valor.
	
	Como las matrices originales no deben ser modificadas,
	se copian dentro de la función para que así solo
	se afecten dentro de la misma.*/
	
	int i;
	float Ax, Ay;
	float** AngDis2;
	AngDis2=(float **)malloc(largo*sizeof( float *));
	for (i=0; (i+1) < largo ; i++){
		*(AngDis2+i)=(float *)malloc(2*sizeof(float));
		Ax= (vectores [i][0]-vectores[i+1][0]) * (vectores [i][0]-vectores[i+1][0]);
		Ay= (vectores [i][1]-vectores[i+1][1]) * (vectores [i][1]-vectores[i+1][1]);
		AngDis2 [i][0] = sqrt(Ay+Ax);
		AngDis2[i][1]= atan(Ay/ Ax)*180/PI;
	}
	printf("Arreglo de angulos y distancias EN LA FUNCION\n" );
	for(i=0;i<largo-1;i++)
		printf("\t%d) distancia: %.2f angulo: %.2f\n",i+1,AngDis2[i][0],AngDis2[i][1]);
}
