
#include <iostream>
#include "complex.h"

using namespace std;

bool validaResSuma(Complex resultat, Complex c1, Complex c2)
{
	float resultatReal = c1.getReal() + c2.getReal();
	float resultatImag = c1.getImg() + c2.getImg();
	if (resultat.getReal() == resultatReal)
		if (resultat.getImg() == resultatImag)
			return true;
	return false;
}

bool validaResResta(Complex resultat, Complex c1, Complex c2)
{
	float resultatReal = c1.getReal() - c2.getReal();
	float resultatImag = c1.getImg() - c2.getImg();
	if (resultat.getReal() == resultatReal)
		if (resultat.getImg() == resultatImag)
			return true;
	return false;
}

bool validaResMultiplica(Complex resultat, Complex c1, Complex c2)
{
	float resultatReal = (c1.getReal() * c2.getReal()) -
		                 (c1.getImg() * c2.getImg());
	float resultatImag = (c1.getReal() * c2.getImg()) +
	                     (c1.getImg() * c2.getReal());
	if (resultat.getReal() == resultatReal)
		if (resultat.getImg() == resultatImag)
			return true;
	return false;
}

int main()
{
	float grade = 0.0;
	bool valid = true;
	Complex c1, c2, resultat;
	char operacio;

	cout << "Grade :=>> " << grade << endl;

	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> EXERCICI NOMBRES COMPLEXOS                                        " << endl;
	cout << "Comment :=>> ==================================================================" << endl;

	operacio = '1';
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Avaluar operacio SUMA:                                            " << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	c1.setReal(1);
	c1.setImg(2);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Nombre complex  C1                                                " << endl;
	c1.mostra();
	cout << endl;
	cout << "Comment :=>> " << c1.getReal() << "+" << c1.getImg() << "i" << endl;
	c2.setReal(3);
	c2.setImg(4);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Nombre complex  C2                                                " << endl;
	c2.mostra();
	cout << endl;
	cout << "Comment :=>> " << c2.getReal() << "+" << c2.getImg() << "i" << endl;
	resultat=c1.avaluaOperacio(operacio, c2);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Resultat operacio Suma                                            " << endl;
	resultat.mostra();
	cout << endl;
	cout << "Comment :=>> " << resultat.getReal() << "+" << resultat.getImg() << "i" << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	bool validacio=validaResSuma(resultat, c1, c2);
	if (validacio) {
		cout << "Comment :=>> RESULTAT OPERACIO SUMA CORRECTE" << endl;
		grade += 3.3;
	}
	else
	{
		cout << "Comment :=>> ERROR OPERACIO SUMA" << endl;
		valid = false;
	}


	cout << "Grade :=>> " << grade << endl;

    operacio = '2';
    cout << "Comment :=>> ==================================================================" << endl;
    cout << "Comment :=>> Avaluar operacio RESTA:                                           " << endl;
    cout << "Comment :=>> ==================================================================" << endl;
	c1.setReal(1);
	c1.setImg(2);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Nombre complex  C1                                                " << endl;
	c1.mostra();
	cout << endl;
	cout << "Comment :=>> " << c1.getReal() << "+" << c1.getImg() << "i" << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Nombre complex  C2                                                " << endl;
	c2.setReal(3);
	c2.setImg(4);
	c2.mostra();
	cout << endl;
	cout << "Comment :=>> " << c2.getReal() << "+" << c2.getImg() << "i" << endl;
    resultat = c1.avaluaOperacio(operacio, c2);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Resultat operacio RESTA                                           " << endl;
	resultat.mostra();
	cout << endl;
	cout << "Comment :=>> " << resultat.getReal() << "+" << resultat.getImg() << "i" << endl;
	validacio = validaResResta(resultat, c1, c2);
    if (validacio) {
       cout << "Comment :=>> RESULTAT OPERACIO RESTA CORRECTE" << endl;
	   grade += 3.3;
    }
    else
    {
       cout << "Comment :=>> ERROR OPERACIO RESTA" << endl;
	   valid = false;
    }

	cout << "Grade :=>> " << grade << endl;

	operacio = '3';
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Avaluar operacio MULTIPLICA:                                      " << endl;
	cout << "Comment :=>> ==================================================================" << endl;
	c1.setReal(1);
	c1.setImg(2);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Nombre complex  C1                                                " << endl;
	c1.mostra();
	cout << endl;
	cout << "Comment :=>> " << c1.getReal() << "+" << c1.getImg() << "i" << endl;
	c2.setReal(3);
	c2.setImg(4);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Nombre complex  C2                                                " << endl;
	c2.mostra();
	cout << endl;
	cout << "Comment :=>> " << c2.getReal() << "+" << c2.getImg() << "i" << endl;
	resultat = c1.avaluaOperacio(operacio, c2);
	cout << "Comment :=>> ==================================================================" << endl;
	cout << "Comment :=>> Resultat operacio MULTIPLICA                                      " << endl;
	resultat.mostra();
	cout << endl;
	cout << "Comment :=>> " << resultat.getReal() << "+" << resultat.getImg() << "i" << endl;
	validacio = validaResMultiplica(resultat, c1, c2);
	if (validacio) {
		cout << "Comment :=>> RESULTAT OPERACIO MULTIPLICA CORRECTE" << endl;
		grade += 3.3;
	}
	else
	{
		cout << "Comment :=>> ERROR OPERACIO MULTIPLICA" << endl;
		valid = false;
	}

	cout << "Comment :=>> ==================================================================" << endl;
	if (valid)
		cout << "Comment :=>> Final del test sense errors" << endl;

	if (grade > 9)
		grade = 10;

	cout << "Comment :=>> " << endl << "Grade :=>> " << grade << endl;

	return 0;
}