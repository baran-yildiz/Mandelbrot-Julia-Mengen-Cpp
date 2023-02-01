#include <string>
#include "MyComplex.h"


void output_my_cplx(const MyComplex &c,const std::string txt){
    cout<<txt<<": ("<<c.real()<<", "<<c.imag()<<")"<<endl;
}

int main(){


    MyComplex z1 {2., 7.};
    MyComplex z2 {42.,-9};
    MyComplex z3 {-11.,19.};
    MyComplex z4,z5,z6,z7,z8,z9;



    output_my_cplx(z1,"z1 ");
    output_my_cplx(z2,"z2 ");
    output_my_cplx(z3,"z3 ");

    //********************Eigener Ausgabeoperator*******************//
    cout<<"z1:"<<z1<<endl;
    cout<<"z2:"<<z2<<endl;
    cout<<"z3:"<<z3<<endl;

    z4=z1*z2;
    output_my_cplx(z4,"z4=z1*z2 =");

    z5= z1+z2;
    output_my_cplx(z5,"z5=(z1+z2) =");

    z6=(z1+z2)*2.;
    output_my_cplx(z6,"z6=(z1+z2)*2. = ");

    z7=(z2+z3)*z1;
    output_my_cplx(z7,"z7=(z2+z3)*z1 = ");

    z8=z1+5.;
    output_my_cplx(z8,"z8=z1+5. = ");

    z9=-z1+z2;
    output_my_cplx(z9,"z9=-z1+z2 = ");

    //********************Operator-Schreibweise*******************//
    cout<<"Operator-Schreibweise:"<<endl;

	z4.operator =(z1.operator *(z2));
	cout << z4 << endl;

	z5.operator =(z1.operator +(z2));
	cout << z5 << endl;

	z6.operator =((z1.operator +(z2)).operator*(2));
	cout << z6 << endl;

	z7.operator =((z2.operator +(z3)).operator*(z1));
	cout << z7 << endl;

	z8.operator =(z1+5.);
	cout << z8 << endl;

	z9.operator =((z1.operator-()).operator+(z2));
	cout << z9 << endl;



	//********************Ergebnisdateien*******************//
    ofstream ergebnis1A, ergebnis1B, ergebnis2A, ergebnis2B, ergebnis3A;


    //********************Dateien für Ergebnis1A***********//
	const double Nxmax = 750, Nymax=500;
	MyComplex zll {-1.5, -1.}, zur {1.5, 1.}, c0 {-0.75,0.1};


	ergebnis1A.open("ergebnis1A.dat", ios::app);

	output_converg_iter(Nxmax, Nymax, zll, zur, c0, ergebnis1A );

	ergebnis1A.close();

	//*********************Dateien für Ergebnis1B***********//
	c0 = {-0.75,0.55};

	ergebnis1B.open("ergebnis1B.dat", ios::app);

	output_converg_iter(Nxmax, Nymax, zll, zur, c0, ergebnis1B );

	ergebnis1B.close();

	//*********************Dateien für Ergebnis2A***********//
	MyComplex cll {-2, -1.}, cur {1, 1.}, z0 {0.,0.};

	ergebnis2A.open("ergebnis2A.dat", ios::app);

	output_converg_iter2(Nxmax, Nymax, cll, cur, z0, ergebnis2A );

	ergebnis2A.close();

	//*********************Dateien für Ergebnis2B***********//
	cll = {-1.5, 0.};
	cur = {0., 1.};
	z0 = {0.,0.};

	ergebnis2B.open("ergebnis2B.dat", ios::app);

	output_converg_iter2(Nxmax, Nymax, cll, cur, z0, ergebnis2B );

	ergebnis2B.close();

	//*********************Dateien für Ergebnis3A***********//
	cll = {-1.5, -1.};
	cur = {1.5, 1.};
	z0 = {0.,0.};

	ergebnis3A.open("ergebnis3A.dat", ios::app);

	output_converg_iter3(Nxmax, Nymax, cll, cur, z0, ergebnis3A );
	ergebnis3A.close();


    return 0;
}
