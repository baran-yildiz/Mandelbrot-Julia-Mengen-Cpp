/*
 * MyComplex.cpp
 *
 *  Created on: Dec 30, 2022
 *      Author: baran
 */

#include "MyComplex.h"


MyComplex::MyComplex(): real_part(0), imaginary(0){}

MyComplex::MyComplex(double real, double imaginary): real_part(real), imaginary(imaginary){}

MyComplex::MyComplex(const MyComplex& other){
	real_part = other.real_part;
	imaginary = other.imaginary;
}

MyComplex::MyComplex(const double other){
	real_part = other;
	imaginary = 0.;
}

const MyComplex& MyComplex::operator=(const MyComplex& other){
	real_part = other.real_part;
	imaginary = other.imaginary;
	return *this;
}

MyComplex MyComplex::operator+(const MyComplex& other){
	MyComplex sum ;

	sum = {this->real() + other.real(), this->imaginary + other.imag()};

	return sum;

}

MyComplex MyComplex::operator*(const MyComplex& other){
	MyComplex mult ;

	if(std::is_same_v<decltype(*this), double>){
		mult = {this->real_part * other.real(), this->real_part * other.imag()};
	}else{
		mult = {this->real() * other.real() - this->imag() * other.imag(), this->real() * other.imag() + this->imag()*other.real()};
	}

	return mult;

}

MyComplex MyComplex::operator-(const MyComplex& other){

	MyComplex subt ;

	subt = {this->real() - other.real(), this->imaginary-other.imag() };

	return subt;

}

MyComplex MyComplex::operator-(){

	MyComplex ret {-this->real_part,-this->imaginary};
	return ret;

}

ostream& operator<<(ostream& out, const MyComplex &c){
	out << "(" << c.real() << "," << c.imag() << ")";
	return out;
}

void output_converg_iter(const double Nxmax, const double Nymax, const MyComplex zll, const MyComplex zur, const MyComplex c0, ofstream& outfile){
	MyComplex zn,tmp;
	double deltaX = (zur.real()-zll.real())/Nxmax, deltaY = (zur.imag()-zll.imag())/Nymax;
	int n_iter=0;

	outfile<<"X" << " "<< "Y" << " "<< "Z" << endl;

	for(int i=0; i<=Nxmax; i++){
		for(int j=0; j<=Nymax; j++){
			tmp = {zll.real() + i*deltaX, zll.imag() + j*deltaY};
			for(int k=0; k<2000; k++){
				zn = tmp*tmp + c0;

				if(zn.norm() >= 100){
					n_iter = k;
					break;
				}

				tmp = zn;

			}
			outfile<<i << " "<< j << " "<< n_iter << endl;
		}

	}


}

void output_converg_iter2(const double Nxmax, const double Nymax, const MyComplex cll, const MyComplex cur, const MyComplex z0,ofstream& outfile){
	MyComplex zn,tmp, c;
	double deltaX = (cur.real()-cll.real())/Nxmax, deltaY = (cur.imag()-cll.imag())/Nymax;
	int n_iter = 0;

	outfile<<"X" << " "<< "Y" << " "<< "Z" << endl;

	for(int i=0; i<=Nxmax; i++){
		for(int j=0; j<=Nymax; j++){
			c = {cll.real() + i*deltaX, cll.imag() + j*deltaY};
			tmp = z0;
			for(int k=0; k<200; k++){
				zn = tmp*tmp + c;

				if(zn.norm() >= 2){
					n_iter = k;
					break;
				}
				tmp = zn;
			}
			outfile<<i << " "<<j << " "<<n_iter <<endl;
		}

	}


}

void output_converg_iter3(const double Nxmax, const double Nymax, const MyComplex cll, const MyComplex cur, const MyComplex z0,ofstream& outfile){
	MyComplex zn,tmp, c;
	double deltaX = (cur.real()-cll.real())/Nxmax, deltaY = (cur.imag()-cll.imag())/Nymax;
	int n_iter=0;

	outfile<<"X" << " "<< "Y" << " "<< "Z" << endl;

	for(int i=0; i<=Nxmax; i++){
		for(int j=0; j<=Nymax; j++){
			c = {cll.real() + i*deltaX, cll.imag() + j*deltaY};
			tmp = z0;
			for(int k=0; k<2000; k++){
				zn = tmp*tmp*tmp*tmp + c;

				if(zn.norm() >= 200){
					n_iter = k;
					break;
				}
				tmp = zn;
			}
			outfile<<i << " "<< j << " "<< n_iter << endl;
		}

	}


}












