/* Creator:		Chris Wiseman
 * Program name:	fractionOverloading
 * Description:		A program that adds, subtracts, multiplies and divides a
 *			fraction using QString, QTextString and overloaded operators.
 * Last Modification:	29MAR19
 * ==================================================================================
 */

#include "fractionOverloading.h"

Fraction::Fraction(int n, int d):numerator(n), denominator(d){
	if(d==0){
		cout << "can't divide by zero" << endl;
		exit(0);
	}
}

ostream& operator<<(ostream& out, const Fraction &other){
	out << "(" << other.numerator << "/" << other.denominator << ")";
	return out;
}

void Fraction::set(int n, int d){
	numerator = n;
	denominator = d;
}

QString Fraction::toString() const{
	return QString("%1 / %2").arg(numerator).arg(denominator);
};

double Fraction::toDouble(){
	return 1.0 * numerator / denominator;
};

Fraction Fraction::operator+(const Fraction &other)const{
	int n = numerator;
	int d = denominator;
	n = other.denominator*numerator+other.numerator*denominator;
	d *= other.denominator;
	int x = GCD(n,d);
	if(x!=1){
		n/=x;
		d/=x;
	}
	return Fraction(n,d);
}

Fraction Fraction::operator-(const Fraction &other)const{
	int n = numerator;
	int d = denominator;
	n = other.denominator*numerator-other.numerator*denominator;
	d *= other.denominator;
	int x = GCD(n,d);
	if(x!=1){
		n/=x;
		d/=x;
	}
	return Fraction(n,d);
}

Fraction Fraction::operator*(const Fraction &other)const{
	int n = numerator;
	int d = denominator;
	n *= other.numerator;
	d *= other.denominator;
	int x = GCD(n,d);
	if(x!=1){
		n/=x;
		d/=x;
	}
	return Fraction(n,d);
}

Fraction Fraction::operator/(const Fraction &other)const{
	return *this*Fraction(other.denominator, other.numerator);
}

int main(){

	QTextStream cout(stdout);

	Fraction f1(1,2);
	Fraction f2(1,3);
	Fraction f3(1,4);
	Fraction f4(1,8);
	
	Fraction f5 = f1 + f2;
	Fraction f6 = f2 - f3;
	Fraction f7 = f3 * f4;
	Fraction f8 = f4 / f1;

	std::cout << "f1 = " << f1 << endl
		<< "f2 = " << f2 << endl
		<< "f3 = " << f3 << endl
		<< "f4 = " << f4 << endl
		<< "f5 = f1 + f2 = " << f5 << endl
		<< "f6 = f2 - f3 = " << f6 << endl
		<< "f7 = f3 * f4 = " << f7 << endl
		<< "f8 = f4 / f1 = " << f8 << endl;

	return 0;
}
