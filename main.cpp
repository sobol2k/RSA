// RSA.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include "RSAModule.h"
#include <random>
#include <ctime>


int _tmain(int argc, _TCHAR* argv[])
{
	srand(time(NULL));
	RSA newencryp;

	newencryp.encrypt("textin.txt","textout.txt",5,7);
	
	
	

	return 0;
}

