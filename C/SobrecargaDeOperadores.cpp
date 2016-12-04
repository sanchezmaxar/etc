// Fecha: 29 de Noviembre del 2016
// lenguaje cpp 
// compilador g++
// ejecucion ~$ g++ SobrecargaDeOperadores.cpp -lgmp && ./a.out 
// OBJETIVO: Este programa sirve para ejemplificar la sobrecarga de operadores 
// Las bibliotecas que se ocupan son iostream para imprimir en pantalla los mensajes auxliares
// 		gmp es la biblioteca para uso de numeros grandes

//cabecera
#include<iostream> 
#include<gmp.h>

typedef mpz_t gmp;

using namespace std;

class Numerote{
// Se declara la clase Numerote la cual esta destinada a 
// ofrecer una interfaz para sobrecarga de operadores la
// cual solo puede lograrse mediante clases
	public:
		mpz_t n; //este atributo es del tipo de mpz_t el cual son enteros de gran tamanio
		Numerote(mpz_t n){ //este constructor inicializa el numerote con el parametro del constructor
			this->n[0]=*n;
		}
		Numerote (unsigned long int n){
			mpz_t num;
			mpz_init(num);
			mpz_set_ui(num,n);
			this->n[0]=*num;
		}
};

// //receta estadar para la sobrecarga de operadores para el uso de numeros grandes
// Numerote& operator <operador> (const Numerote a, const b){ //los & significa que son constates 
// 	mpz_t resultado; //se declara la valiable de resultado
// 	mpz_init(resultado); //se inicializa en memoria resultado
// 	Operacion que se realiza entre los numero ejemplo mpz_add(resultado,a.n,b.n); 
// 	return *(new Numerote (resultado));//se regresa como nuevo numerote
// }

Numerote& operator +(const Numerote a,const Numerote b)
{
	gmp res;
	mpz_init(res);
	mpz_add(res,a.n,b.n);
	return *(new Numerote(res));
}

Numerote& operator *(const Numerote a,const Numerote b)
{
	gmp res;
	mpz_init(res);
	mpz_mul(res,a.n,b.n);
	return *(new Numerote(res));
}
Numerote& operator %(const Numerote a,const Numerote b)
{
	gmp res;
	mpz_init(res);
	mpz_mod(res,a.n,b.n);
	return *(new Numerote(res));
}
Numerote& operator /(const Numerote a,const Numerote b)
{
	gmp res;
	mpz_init(res);
	mpz_fdiv_q(res,a.n,b.n);
	return *(new Numerote(res));
}
Numerote& operator -(const Numerote a,const Numerote b)
{
	gmp res;
	mpz_init(res);
	mpz_sub(res,a.n,b.n);
	return *(new Numerote(res));
}
Numerote& operator ^(const Numerote a,unsigned long int b)
{
	gmp res;
	mpz_init(res);
	mpz_pow_ui(res,a.n,b);
	return *(new Numerote(res));
}
Numerote& operator +(const Numerote a,unsigned long int b)
{
	gmp res;
	mpz_init(res);
	mpz_add_ui(res,a.n,b);
	return *(new Numerote(res));
}
Numerote& operator -(const Numerote a,unsigned long int b)
{
	gmp res;
	mpz_init(res);
	mpz_sub_ui(res,a.n,b);
	return *(new Numerote(res));
}
int primo(Numerote n){
	Numerote i(12);
	Numerote dos(2);
	Numerote tres(3);
	if (mpz_cmp_ui((n%dos).n,0)==0)
		return -1;
	else if (mpz_cmp_ui((n%tres).n,0)==0)
		return -1;
	else{
		for (;mpz_cmp(i.n,(n/(i-7)).n)<0;i=i+6){
			// gmp_printf("i = %Zd \n",i.n);
			if (mpz_cmp_ui((n%(i-1)).n,0)==0){
				gmp_printf("e= %Zd %Zd\n",(i-1).n, n.n);
				return -1;
			}
			else if (mpz_cmp_ui((n%(i+1)).n,0)==0){
				gmp_printf("e= %Zd %Zd\n",(i+1).n,n.n);
				return -1;
			}
		}
	return 1;
	}
}


int main(int argc, char const *argv[])
{
	Numerote siete(121);
	Numerote a(1);
	Numerote b(2);
	Numerote d(8);
	Numerote c=a+b;
	gmp_printf("Este es el valor de c %Zd\n",c.n);
	c=a/d;
	gmp_printf("Este es el valor de c %Zd\n",c.n);
	d=(b^61)-a;
	if (primo(d)==1)
		cout << "Este numero es primo";
	else
		cout << "Este numero no es primo";
	return 0;

}