#pragma once
 
#ifndef RSA_H
#define RSA_H

//Aliases//

#include <string>

using ul = unsigned long;

class RSA
{
public:
	
	
	//==Konstruktor(en)==//
	RSA();

	//==Variablen==//
	long double N, M;

	//==Funktionen==//
	inline ul calc_PHI(ul pP, ul pQ);
	inline ul calc_RSAModule(ul primeP, ul primeQ);
	inline ul calc_d(ul E, ul M);
	inline ul publicE(ul M);

	void encrypt(std::string fileInPath, std::string fileOutPath, ul pP, ul pQ);
	void decrypt(std::string fileInPath, std::string fileOutPath);
 		
 private:

	 long double primeP, primeQ;

};

#endif RSAMODULE_H
 