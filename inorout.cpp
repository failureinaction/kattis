//inorout aka mandelbrot
#include <iostream>
#include <cmath>
using namespace std;

struct Complex{
	double re;
	double im;
};

double zmodulus(Complex *z){
	return sqrt(z->re*z->re + z->im*z->im);
}

void calcnext(Complex *z, Complex *c){
	double temp = z->re * z->re - z->im * z->im + c->re;
	z->im = 2*z->re*z->im + c->im;
	z->re = temp;
}
int main(){
	Complex *c = new Complex;	
	Complex *zseq = new Complex;
	int r, casecounter = 0, counter;
	while(cin >> c->re >> c->im >> r){
		counter = 0;
		zseq->re = 0;
		zseq->im = 0;
		while(counter < r && zmodulus(zseq) <= 2){
			calcnext(zseq, c);
			counter++;
		}
		casecounter++;
		cout << "Case " << casecounter << " : ";
		if(zmodulus(zseq) > 2){
			cout << "OUT\n";
		}
		else{
			cout << "IN\n";
		}
	}
	return 0;
}
