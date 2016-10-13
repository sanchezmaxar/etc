// programa que ejemplifica el paso de parametros por referencia, por valor, por valor resultado
// compilador usado: gcc
// SO: Ubuntu 16.03 lts
// Editor: Atom 1.10.2
// Desarrollo:
//   Sanchez Hernandez Max Armando
// Pendientes:
// - Crear las funciones invPorValRes() invPorVal() angPorValor() angPorRef() angPorValRes()
// -Terminar funcion invPorRef()

#include<stdio.h>
#include<stdlib.h>

void invPorRef(int * lista, int largo);
int main(){
	char opc1,opc2;
	int *list;
	int n,i;
	int **vects;
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
			for(i=0;i<n;i++){
					*(vects+i)=(int*)malloc(2*sizeof(int));
					printf("%i) X : ",i+1 );
					scanf("%d",*(vects+i));
					printf("%i) Y : ",i+1 );
					scanf("%d",*(vects+i)+1);
			}
			break;
	}
	// hasta aqui bien
	printf("Que tipo de paso de parametros quieres ejecutar?\n");
	printf("1) Por referencia\n2) Valor resultado\n3) valor\n\topcion: ");
	scanf("%c",&opc2);//scanf extra para sistemas linux comentar en otro
	scanf("%c",&opc2);
	switch (opc1){
		case '1':
			if (opc2=='1')
				invPorRef(list,n);
			// else if (opc2=='2')
			// 	invPorValRes();
			// else
			// 	invPorValor();
			printf("\nAl salir:\t");
			for(i=0;i<n;i++){
				printf("%d ",list[i]);
			}
			break;
		// case '2':
		// 	if (opc2=='1')
		// 		angPorRef();
		// 	else if (opc2=='2')
		// 		angPorValRes();
		// 	else
		// 		angPorValor();
		// 	break;
	}
	//prueba
	// for(i=0;i<n;i++){
	// 	printf("vector %d: x: %d y: %d\n",i+1,vects[i][0],vects[i][1]);
	// }

	return 0;
}

void invPorRef(int * lista, int largo){
	int aux,i;
	printf("\nAntes:\t\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
	for(i=0;i<(largo/2);i++){//PROBAR LARGO/2 CON NUMEROS IMPARES
		aux=lista[i];
		lista[i]=lista[largo-i-1];
		lista[largo-i-1]=aux;
	}
	printf("\nDespues:\t");
	for(i=0;i<largo;i++){
		printf("%d ",lista[i]);
	}
}
