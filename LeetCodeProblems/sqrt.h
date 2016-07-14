using namespace std;

class SqrtSolution
{
public:

	/*
	 * Link: https://leetcode.com/problems/sqrtx/
	 * Question: Implement int sqrt(int x). Compute and return the square root of x.
	 * 
	 * Solution: The trick here is to use binary search. You want to find the midpoint from the 
	 *			 range of numbers starting from [1, x] and then move to the left or right side
	 *			 depending on whether mid <= (x/mid)
	 *
	 * Reason for checking  mid <= (x/mid): If mid <= (x/mid) ==> mid^2 <= x, which if true, means
	 *										we need to move further up to possibly find the sqrt.
	 *
	 */
	int mySqrt(int x)
	{
		int l = 1;
		int r = x;
		int mid = 0;

		if (x <= 1)
		{
			return x;
		}

		while (l<r)
		{
			mid = (l + r) / 2;
			if (mid <= x / mid)
			{
				l = mid + 1;
			}
			else
			{
				r = mid;
			}
		}
		return l - 1;
	}
};
