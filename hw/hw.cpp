#include<iostream>
#include<cstring>
using namespace std;

class Hw {
	public: 
		char hola[9];
};

int main(){
	Hw hol;
	strcpy(hol.hola,"hola mundo");
	cout<<hol.hola; 
	return 0;
}