/*
Programa 7 


DESCRIPCION:
 En el lenguaje OO de tu preferencia, desarrolla los codigos necesarios para mostrar:
 -la forma en la que se realiza la eleccion y el encadenamiento de constructores
 -el uso de los diferentes tipos de vista que provee
 -la forma en la que se realiza la busqueda dinamica de metodos
Nota: Debes dar una breve explicacion de cada concepto, basandote en los codigos y resultados.

EQUIPO:

-Sanchez Hernandez Max Armando
-Mares Ontiveros Valeria Fernanda
-Velázquez Sánchez José Antonio 

MATERIA: Lenguajes de programacion

SEMESTRE: 2017-1
*/

#include<ctime>
#include<iostream>
#include<cstdlib>
using namespace std;
class Clase1{
	public :
		int resultado;
		float resultado2;
		Clase1(float n, float m){
			cout<<"\n--Constructor 2--\n";
			this->resultado2=this->funcion(n,m);
				
		}
		Clase1(int n, int m){
			cout<<"\n--Constructor 1--\n";
			this->resultado=this->funcion(n,m);
			
		}
		void definir(int n){
			this->resultado=n;
		}
		void definir(float n){
			this->resultado2=n;
		}
		void auxiliarProtected(){
				cout<<"\nEsta es la funcion publica auxliar para acceder a los protegido de la Clase1\n";
				this->funcion2();
			}
		
	private:
		int funcion(int numero1, int numero2){
		cout<<"Esta es una funcion privada solo puede acceder desde Clase1\n";
		return numero1*numero2;
		}
		float funcion(float numero1, float numero2){
			cout<<"Esta es una funcion privada solo puede acceder desde Clase1\n";
			return numero1*numero2;
		}
	protected:
		bool boleano;
		void funcion2(){
			cout<<"Esta es una funcion protegida perteneciente a la Clase1, aqui se cambia el valor de la boleano a true\n";
			boleano=true;
		}
};

class Clase2{
	public:
		Clase1 * clase1;
		
		Clase2(int n){
			cout<<"\n--Constructor clase 2--\nEste es el constructor de la clase2, tomara dos numeros aleatorios y construira la clase 1 con ellos";
			int a=rand()%n;
			int b=rand()%n;
			cout<<"\n a= "<<a<<" b = "<<b<<"\n";
			clase1=new Clase1((float)a,(float)b);
		}
		Clase2(float n){
			cout<<"\n--Constructor clase 2--\nEste es el constructor de la clase2, tomara dos numeros aleatorios y construira la clase 1 con ellos";
			float a=(rand()%10+1)*n;
			float b=(rand()%10+1)*n;
			cout<<"\n a= "<<a<<" b = "<<b<<"\n";
			clase1=new Clase1(a,b);
		}
		
};
int main(){
srand(time(0));

	Clase1 ejemplo1(2,3);
	Clase1 ejemplo2((float)2.3,(float)3.3); //sin este cast a flotante la ejecucion se vuelve ambigua ya que se puede tomar la parte entera de 2.3 y de 3.3
	cout<< "\nEste es el ejemplo de como se usan la eleccion de constructor\n";
	cout<<"\nejemplo1-->"<<ejemplo1.resultado<<"  "<<ejemplo1.resultado2;
	cout<<"\nejemplo2-->"<<ejemplo2.resultado<<"  "<<ejemplo2.resultado2;	
	cout<<"\n\n--------------------\n";
	cout<<"\nEste es el ejemplo de como se usan un encadenador de constructores\n";
	Clase2 ejemplo3(10);
	cout<<"\nejemplo3-->"<<ejemplo3.clase1->resultado<<"  "<<ejemplo3.clase1->resultado2<<"\n";	
	cout<<"\nEste es otro ejemplo de como se puede usar un encadenador de constructores y la eleccion";
	Clase2 ejemplo4((float)2.3);//aqui tambien se puede ver la busqueda dinamica de metodos ya que el metodo que tiene tipos enteros de parametros no podra procesarlo
	cout<<"\nejemplo4-->"<<ejemplo4.clase1->resultado<<"  "<<ejemplo4.clase1->resultado2<<"\n";	
	cout<<"\n\n--------------------\n";
	cout<<"\nEjemplo de como es la visibilidad de los metodos y atributos de un objeto ";
	cout<<"\nC++ tiene 3 tipos de visibilidad (protected, public, private):";
	cout<<"\nPrivate: Los atributos/metodos private solo se pueden acceder desde dentro del objeto. EJ.";
		cout<<"\nSe intentara acceder al metodo privado de la clase ejemplo1 ";
		cout<<"\nDesafortunadamente no es posible ni siquiera compilar el codigo que se intente acceder a atributos o metodos privado";
		// int n=ejemplo1.funcion(2,3); // no es posible ni siquiera compilar el codigo que se intente acceder a atributos o metodos privado
		// cout<<"\nEs por eso que se ocupara una funcion auxiliar: ";
		// ClaseHijo1 aux;
		// int n=aux.auxiliarPrivate(2,3);		//ni siquiera con uso de un auxiliar 
	cout<<"\n----\nProtected: sirve para acceder a los atributos y metodos solo en las clases que son de la misma \"familia\" ejemplo: ";
	ejemplo1.auxiliarProtected();// esta funcion nos sirve de puente para ejecutar lo que tenga una funcion privada
	cout<<"\nPublic : Los atributos/metodos privados son aquellos que se puede acceder desde cualquier metodo de la clase en incluso en la funcion principal, ejemplo\n";
	ejemplo1.definir(2);// esta funcion define al atributo resultado como el valor que le des
	cout<<"\nejemplo1-->"<<ejemplo1.resultado<<"  "<<ejemplo1.resultado2;
	cout<<"\n\n--------------------\n";
	cout<<"Para ejemplificar la busqueda dinamica de metodos se ocupara la misma funcion de definir pero con parametros de tipo flotantes: ";
	ejemplo1.definir(4);
	cout<<"\nejemplo1-->"<<ejemplo1.resultado<<"  "<<ejemplo1.resultado2;
	ejemplo1.definir((float)4.24);
	cout<<"\nejemplo1-->"<<ejemplo1.resultado<<"  "<<ejemplo1.resultado2;
	cout<<"\nComo se puede ver se ocupa la misma funcion con diferente tipo de parametros para poder hacer diferentes cosas\n";
}

