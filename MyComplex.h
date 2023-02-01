/*
 * MyComplex.h
 *
 *  Created on: Dec 30, 2022
 *      Author: baran
 */

#ifndef MYCOMPLEX_H_
#define MYCOMPLEX_H_

#include <iostream>
#include <cmath>
#include <fstream>
using namespace std;



class MyComplex {

	private:
		double real_part;
		double imaginary;

	public:
		MyComplex();
		MyComplex(const double real, const double imaginary);
		MyComplex(const MyComplex& other);
		MyComplex(const double real);

		const MyComplex& operator=(const MyComplex& other);
		MyComplex operator+(const MyComplex& other);
		MyComplex operator-();
		MyComplex operator-(const MyComplex& other);
		MyComplex operator*(const MyComplex& other);

		double real() const {return real_part;};
		double imag() const {return imaginary;};
		double norm() const {return sqrt(real_part*real_part + imaginary*imaginary);};

};

ostream &operator<<(ostream &out, const MyComplex &c);

void output_converg_iter(const double Nxmax, const double Nymax, const MyComplex zll, const MyComplex zur, const MyComplex c0, ofstream& outfile);
void output_converg_iter2(const double Nxmax, const double Nymax, const MyComplex cll, const MyComplex cur, const MyComplex z0,ofstream& outfile);
void output_converg_iter3(const double Nxmax, const double Nymax, const MyComplex cll, const MyComplex cur, const MyComplex z0,ofstream& outfile);

#endif /* MYCOMPLEX_H_ */
