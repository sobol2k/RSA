
extern inline int primesieve(int upperBorder)
{
	
	//bool* isPrime = new bool[upperBorder + 1];

	int* isPrime = new int[upperBorder + 1];


	for (int i = 0; i <= upperBorder; i++)
	{
		isPrime[i] = 1;
	}

	for (int i = 2; i*i <= upperBorder; ++i)
	{
		if (isPrime[i])

		for (int j = i*i; j <= upperBorder; j += i)
		{
			isPrime[j] = 0;
		}
	}

	int foundCntr = 0;

	for (int i = 2; i <= upperBorder; i++)
	{
		foundCntr += isPrime[i];
	}

	delete[] isPrime;

	return foundCntr;

}