#pragma once 
#include <string>
#include <iostream>

using std::ostream;
using std::istream;
using std::string;

class Racional{
	private:
		int numerador;
		int denominador;
	public:
		Racional(int, int);
		const double toDouble()const;
		const Racional operator +(const Racional&);
		const Racional operator -(const Racional&);
		const Racional& operator =(const Racional&);
		const Racional operator *(const Racional&);
		bool operator!=(int);
		const Racional operator /(const Racional&);
		void simplificar(int&, int&);
		bool esPrimo(int);
		friend ostream& operator<<(ostream&, const Racional&);	
};
