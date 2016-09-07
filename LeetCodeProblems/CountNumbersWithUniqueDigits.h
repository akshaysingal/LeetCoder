#include <cmath>

using namespace std;

void bt(int prev, int max, bool *seen, int &counter)
{
	if (prev >= max)
	{
		return;
	}

	counter++;

	for (int i = 0; i < 10; i++)
	{
		if (seen[i])
		{
			continue;
		}
		seen[i] = true;
		int newNum = (prev * 10) + i;
		bt(newNum, max, seen, counter);
		seen[i] = false;
	}
}

int countNumbersWithUniqueDigits(int n) {
	int counter = 1;
	bool seen[10] = { 0 };
	int max = 0;

	if (n<0)
	{
		return 0;
	}
	else if (n == 0)
	{
		return 1;
	}

	max = pow(10, n);

	for (int i = 1; i <= 9; i++)
	{
		seen[i] = true;
		bt(i, max, seen, counter);
		seen[i] = false;
	}

	return counter;
}



/*
 * Optimized version of the same question 
 */
int countNumbersWithUniqueDigits_Optimized(int n)
{
	int counter = 1;	// x == 0

	if(n < 0)
	{
		return 0;
	}
	if(n == 0)
	{
		return counter;
	}
	
	for (int i = 1; i <= n; i++)
	{
		// For each number, calculate the unique permutations of numbers for varying 
		// number sizes.
		int permutations = 1;
		int multFactor = 9;

		for (int j = 1; j <= i; j++)
		{
			if (j > 2)
			{
				multFactor -= 1;
			}
			permutations *= multFactor;
		}
		counter += permutations;
	}

	return counter;
}

void runTests()
{
	cout << countNumbersWithUniqueDigits(0) << endl;
	cout << countNumbersWithUniqueDigits(1) << endl;
	cout << countNumbersWithUniqueDigits(2) << endl;
	cout << countNumbersWithUniqueDigits(3) << endl;
	cout << countNumbersWithUniqueDigits(4) << endl;

	cout << countNumbersWithUniqueDigits_Optimized(0) << endl;
	cout << countNumbersWithUniqueDigits_Optimized(1) << endl;
	cout << countNumbersWithUniqueDigits_Optimized(2) << endl;
	cout << countNumbersWithUniqueDigits_Optimized(3) << endl;
	cout << countNumbersWithUniqueDigits_Optimized(4) << endl;
}