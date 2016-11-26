#include "Racional.h"
#include <iostream>
#include <string>
#include <vector>

using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;

void mostrarRacionales(vector<Racional>& );

int main(int argc, char*argv[]){
	vector <Racional> racionales;
	Racional fraccion(1,1);
	int posicion1, posicion2;
	int read = 0, numerador = 0, denominador = 0;
	bool continuar = true;

	while(continuar){
		cout<<endl<<"------------------ MENU -------------------"<<endl;
		cout<<"1. Crear racionales "<<endl;
		cout<<"2. Mostrar todos los Racionales"<<endl;
		cout<<"3. Sumar racionales "<<endl;
		cout<<"4. Restar reacionales " <<endl;
		cout<<"5. Multiplicar Racionales "<<endl;
		cout<<"6. Dividir racionales "<<endl;
		cout<<"7. Salir "<<endl;
		cin>>read;

		if(read ==1){
				cout<<"Ingrese numerador: ";
				cin>>numerador;
				cout<<"Ingrese denominador: ";
				cin>>denominador;
				
				while(denominador==0){
					cout<<"Su denominador no puede ser cero"<<endl;
					cout<<"Ingrese otro denominador: "<<endl;
					cin>>denominador;
				}

				fraccion = Racional(numerador,denominador);
				racionales.push_back(fraccion);	
				cout<<"Numero ingresado correctamente..."<<endl;
							
						
		} // fkn opcion 1

		if(read == 3){
			cout<<endl<<"------------------ SUMA ------------------"<<endl;
			mostrarRacionales(racionales);
			cout<<"Ingrese posicion primera fraccion: ";
			cin>>posicion1;
			cout<<"Ingrese posicion segunda fraccion: ";
			cin>>posicion2;

			if(posicion1 <= 0 || posicion1 > racionales.size()){
				cout<<"No existe esa primera posicion"<<endl;
			}else if(posicion2 <= 0 || posicion2 > racionales.size()){
				cout << "No existe esa segunda posicion"<<endl;
			}else{
				fraccion = racionales[posicion1-1] + racionales[posicion2-1];
				cout<<"La suma es: "<< fraccion<<endl;
			}

		} // fin opcion 3

		if(read == 4){
			cout<<endl<<"------------------ RESTA ------------------"<<endl;
			mostrarRacionales(racionales);
			cout<<"Ingrese posicion primera fraccion: ";
			cin>>posicion1;
			cout<<"Ingrese posicion segunda fraccion: ";
			cin>>posicion2;

			if(posicion1 <= 0 || posicion1 > racionales.size()){
				cout<<"No existe esa primera posicion"<<endl;
			}else if(posicion2 <= 0 || posicion2 > racionales.size()){
				cout << "No existe esa segunda posicion"<<endl;
			}else{
				fraccion = racionales[posicion1-1] - racionales[posicion2-1];
				cout<<"La resta es: "<< fraccion<<endl;
			}
                       
		} // fin opcion 4

		if(read == 5){
			cout<<endl<<"------------------ MULTIPLICACION ------------------"<<endl;
			mostrarRacionales(racionales);
			cout<<"Ingrese posicion primera fraccion: ";
			cin>>posicion1;
			cout<<"Ingrese posicion segunda fraccion: ";
			cin>>posicion2;

			if(posicion1 <= 0 || posicion1 > racionales.size()){
				cout<<"No existe esa primera posicion"<<endl;
			}else if(posicion2 <= 0 || posicion2 > racionales.size()){
				cout << "No existe esa segunda posicion"<<endl;
			}else{
				fraccion = racionales[posicion1-1] * racionales[posicion2-1];
				cout<<"La multiplicacion es: "<< fraccion<<endl;
			}
                        	
		} // fin opcion 5

		if(read == 6){
			cout<<endl<<"------------------ DIVISION ------------------"<<endl;
			mostrarRacionales(racionales);
			cout<<"Ingrese posicion primera fraccion: ";
			cin>>posicion1;
			cout<<"Ingrese posicion segunda fraccion: ";
			cin>>posicion2;

			if(posicion1 <= 0 || posicion1 > racionales.size()){
				cout<<"No existe esa primera posicion"<<endl;
			}else if(posicion2 <= 0 || posicion2 > racionales.size()){
				cout << "No existe esa segunda posicion"<<endl;
			}else{
				if((racionales[posicion2-1] != 0)){
					fraccion = racionales[posicion1-1] / racionales[posicion2-1];
					cout<<"La division es: "<< fraccion<<endl;
				}else{
					cout<<"No se puede hacer una division entre cero"<<endl;
				}
			}
                       
			
		} // fi opcion 6

		if(read == 2){
			cout<<endl<<"------------------ RACIONALES ------------------"<<endl;
			mostrarRacionales(racionales);
		}

		if(read == 7){
			continuar = false;
		}
	} // fin while
		
	return 0;
}

void mostrarRacionales(vector<Racional>& todo){
	for(int i = 0; i < todo.size(); i++){
		cout<< i + 1<<") "<<todo[i]<<endl;
	}
}

