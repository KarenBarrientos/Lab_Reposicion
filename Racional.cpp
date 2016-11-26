#include "Racional.h"
#include <string>
#include <sstream>
#include <cstdlib>
#include <iostream>

using std::ostream;
using std::istream;
using std::cout;
using std::endl;
using std::string;
using std::stringstream;

Racional::Racional(int num, int den){
	if(den < 0){
		den*=-1;
		num*=-1;
	}
	if(num!=0){
		simplificar(num,den);
	}
	numerador = num;
	denominador = den;
}

bool Racional::operator!=(int num){
	if((numerador!=0)){
		return true;
	}else{
		return false;
	}
}


const Racional& Racional::operator =(const Racional& r){
	numerador = r.numerador;
	denominador = r.denominador;
	return *this;
}

               
ostream& operator<<(ostream& output, const Racional& rat){
	if(rat.denominador == 1){
		output<<rat.numerador;
	}else if(rat.numerador == 0){
		output<<"0";
	}else if(rat.numerador != rat.denominador){
		output<<rat.numerador<<"/"<<rat.denominador;
	}
	return output;
}

                
const double Racional::toDouble()const{
	double retorno = numerador*1.0/denominador;
	return (retorno);
}

                
const Racional Racional::operator +(const Racional& ra){
	int num, den;
	if(denominador == ra.denominador){
		num = ra.numerador + numerador;
		den = denominador;
		return Racional(num, den);
	}else{
		num = (ra.numerador * denominador) + (numerador * ra.denominador);
		den = denominador*ra.denominador;
		return Racional(num, den);
	}
}
               
                
const Racional Racional::operator -(const Racional& ra){
	int num, den;
	if(denominador == ra.denominador){
		num = numerador - ra.numerador;
		den = denominador;
		return Racional(num,den); 
	}else{
		num = (numerador * ra.denominador) - (ra.numerador*denominador);
		den = denominador*ra.denominador;
		return Racional(num, den);
	}
}
              

const Racional Racional::operator *(const Racional& r){
	int num, den;
	num = numerador * r.numerador;
	den = denominador * r.denominador;
	return Racional(num, den);
}


const Racional Racional::operator /(const Racional& ra){
	int num, den;
	num = numerador * ra.denominador;
	den = denominador * ra.numerador;
	return Racional(num, den);
}
 
               
void Racional::simplificar(int& num, int& den){
	if(num == den){
		num = 1;
		den = 1;
	}else if(num < den){
	if(den %num == 0){
		if(num>0){
			den = den/num;
			num = 1;
		}else{
			den = den/num;
			num = -1;
			den*=-1;
		}
	}else{
		int num2;
		if(num < 0){
			num2 = num*-1;
		}else{
			num2 = num;
		}			
		for(int i = num2-1; i >1; i--){
				if(num2 % i == 0 && den % i == 0){
					num2 = num2 / i;
					den = den / i;
					i++;
				}	
			}
			if(num < 0){
				num = num2*-1;
			}else{
				num = num2;
			}
		}
	}else if(den <num){
		if(num%den == 0){
			num = num/den;
			den = 1;
		}else{
			for(int i = den-1; i >1; i--){
				if(num % i == 0 && den % i == 0){
					num = num / i;
					den = den / i;
					i++;
				}
			}
		}
	}					
} // fin simplificar

bool Racional::esPrimo(int num){
	bool retorno = true;
	for(int i = 1; i < num; i++){
		if(num % i ==0){
			retorno = false;
		}
	}
	return retorno;	
}