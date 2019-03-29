#ifndef FRACTIONOVERLOADING_H
#define FRACTIONOVERLOADING_H

#include <QString>
#include <QTextStream>
#include <iostream>
#include <cstdlib>
#include <ostream>

using namespace std;

int GCD(int a, int b){
	int rem;
	do{
		rem = a % b;
		a = b;
		b = rem;
	}while(rem!=0);
	return a;
}

class Fraction{
	
	private:
		int numerator;
		int denominator;

	public:
		Fraction(){}
		~Fraction(){}
		Fraction(int n, int d);
		void set(int n, int d);
		QString toString()const;
		double toDouble();
		Fraction operator+(const Fraction &other)const;
		Fraction operator-(const Fraction &other)const;
		Fraction operator*(const Fraction &other)const;
		Fraction operator/(const Fraction &other)const;
		friend ostream& operator<<(ostream& out, const Fraction &other);
};

#endif
