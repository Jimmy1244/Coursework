#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<math.h>

#include "Complex.h"

using namespace std;

int main(){
	Complex::uniTest();
	cout << "Please iput three real coefficients a x^2 + b x + c ? ";
	double a, b, c;
	cin >> a >> b >> c;
	double i;
	i = b * b - 4 * a * c;
	Complex x1, x2;
	if (i >= 0){
		x1.setValue((-b + sqrt(i)) / 2 / a, 0);
	}
	else{
		x1.setValue((-b) / 2 / a, sqrt(-i) / 2 / a);
	}
	cout << "x1 = ";
	x1.print();
	i = b * b - 4 * a * c;
	if (i >= 0){
		x2.setValue((-b - sqrt(i)) / 2 / a, 0);
	}
	else{
		x2.setValue((-b) / 2 / a, -sqrt(-i) / 2 / a);
	}
	cout << "x2 = ";
	x2.print();
	int j;
	Complex x1m = x1, x2m = x2, x1a;
	for(j = 1; j < 5; j++){
		x1m.mutiply(x1);
	}
	for(j = 1; j < 5; j++){
		x2m.mutiply(x2);
	}
	x1m.add(x2m);
	x1a = x1m;
	x1m = x1;
	x2m = x2;
	for(j = 1; j < 10; j++){
		x2m.mutiply(x2);
	}
	for(j = 1; j < 7; j++){
		x1m.mutiply(x1);
	}
	x2m.subtract(x1m);;
	x1a.divide(x2m);
	cout<< "The result of ((x1)^5 + (x2)^5) / ((x2)^10 - (x1)^7) = ";
	x1a.print();
	system("pause");
}