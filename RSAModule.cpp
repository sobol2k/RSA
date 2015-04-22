#include "stdafx.h"

#include <fstream>
#include <iostream>
#include <streambuf>
#include <vector>

#include "RSAModule.h"

#include <time.h>

//#include "PrimeSieve.h"

RSA::RSA()
{
	primeP = primeQ = 0;
}

inline ul RSA::calc_PHI(ul primeP, ul primeQ)
{
	 ul M = (primeP - 1)*(primeQ - 1);
	 
	 std::cout << "M: " << M << std::endl;
	 return M;
}

inline ul RSA::calc_RSAModule(ul primeP, ul primeQ)
{
	ul N = primeP*primeQ;

	std::cout << "N: " << N << std::endl;

	return N;
}


//================================================================================//
ul ggT(ul u, ul v) {
	while (v != 0) {
		unsigned r = u % v;
		u = v;
		v = r;
	}
	return u;
}
//================================================================================//


ul RSA::publicE(ul M)
{
	auto pubE= rand() % M + 1;
		
	while (ggT(pubE, M) != 1)
	{
		++pubE;
	}
	 
	std::cout << "E: " << pubE << std::endl;

	return pubE;

}

ul RSA::calc_d(ul E, ul M)
{	
	auto d = 0;

	while ((d*E) % M!=1)
	{
		d++;
	}

	std::cout << "D: " << d << std::endl;

	return d;
}



void RSA::encrypt(std::string fileInPath, std::string fileOutPath, ul pP, ul pQ)
{

	primeP = pP;
	primeQ = pQ;

	ul M = calc_PHI(pP, pQ);
	ul N = calc_RSAModule(pP, pQ);
	ul pubE = publicE(M);
	ul D = calc_d(pubE,M);

	//==In/Out FS==//
	std::ifstream encryptDataInStream(fileInPath);
	//std::ofstream encryptDataOutStream(fileOutPath);

	std::vector<char> instr( (std::istreambuf_iterator<char>(encryptDataInStream)) , std::istreambuf_iterator<char>() );

	//==Vectors for saving the cypher==//
	double strSize = instr.size();

	std::vector<ul> cypherAsInt;
	std::vector<ul> cypherAsIntEnc;
	
	cypherAsInt.resize(strSize);
	cypherAsIntEnc.resize(strSize);

	if (!encryptDataInStream.bad())

		std::cout << "Filestream opened" << std::endl;

	for (unsigned int i = 0; i < instr.size(); ++i)
	{
		cypherAsInt[i] = instr[i];
		cypherAsIntEnc[i] = unsigned long long(pow(cypherAsInt[i], pubE)) % N ;
		std::cout << cypherAsIntEnc[i];
		//std::cout << cypherAsInt[i];
	}

	encryptDataInStream.close();

}

void RSA::decrypt(std::string fileInPath, std::string fileOutPath)
{
}
