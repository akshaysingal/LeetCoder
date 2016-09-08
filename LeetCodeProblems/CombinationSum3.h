#include<vector>

using namespace std;

void bt(vector<vector<int>> &list, vector<int> sublist, int n, int k, int &index_k, int sum, int curNum, bool * visited)
{
	int max_n = 0;
	int half = 0;

	// Reject case
	if (visited[curNum])
	{
		return;
	}

	// Accept case
	// If we are at the last position, we need to guard against the following:
	// 1. Diff has not been visited previously (avoids cases of duplicate entries)
	// 2. Diff is greater than the current number supposed to be added. This avoids any repeated sublists from  being added
	// 3. Diff must be from 1-9, this is a constraint of the question.
	if ((index_k == k - 1)
		&& ((n - sum) < 10)
		&& (!visited[n - sum])
		&& (n - sum) >= curNum)
	{
		// Push the sublist
		sublist.push_back(n - sum);
		list.push_back(sublist);
		return;
	}
	sublist.push_back(curNum);
	sum += curNum;
	index_k++;
	visited[curNum] = true;

	// Find next candidate
	half = (n / 2);
	max_n = half - (k - 1 - index_k);
	for (int i = curNum + 1; (i <= max_n) && (i < 10); i++)
	{
		bt(list, sublist, n, k, index_k, sum, i, visited);
		if (index_k == k - 1)
		{
			break;
		}
	}

	index_k--;
	visited[curNum] = false;
	return;
}

vector<vector<int>> combinationSum3(int k, int n)
{
	vector<vector<int>> list;
	vector<int> sublist;
	int index_k = 0;
	int sum = 0;
	bool visited[10] = { 0 };

	if (k == 0 || k > n)
	{
		// Second condition applies when we have more positions to fill 
		// but the number n is smaller than that.

		// Return an empty list
		return list;
	}

	if (k == 1)
	{
		sublist.push_back(n);
		list.push_back(sublist);
		return list;
	}

	int half = (n / 2);
	int max = half - (k - 1 - index_k);
	for (int i = 1; (i <= max) && (i < 10); i++)
	{
		bt(list, sublist, n, k, index_k, sum, i, visited);
	}

	return list;
}

void tester(int k, int n)
{
	vector<vector<int>> list = combinationSum3(k, n);

	cout << "[";
	for (int i = 0; i < list.size(); i++)
	{
		cout << "[";
		for (int j = 0; j < list[0].size(); j++)
		{
			cout << list[i][j];
			if (j < list[0].size() - 1)
			{
				cout << ", ";
			}
		}
		cout << "]";
		if (i < list.size() - 1)
		{
			cout << ", " << endl;
		}
	}
	cout << "] " << endl;

}

void runTestsForCombinationSum3()
{
	cout << "Test 1: expected output: empty list" << endl;
	tester(0, 0);

	cout << "Test 2: expected output: empty list" << endl;
	tester(1, 0);

	cout << "Test 3: expected output: [[1]]" << endl;
	tester(1, 1);

	cout << "Test 4: expected output: empty list" << endl;
	tester(0, 1);

	cout << "Test 5: expected output: empty list" << endl;
	tester(2, 1);

	cout << "Test 6: expected output: empty list" << endl;
	tester(3, 3);

	cout << "Test 7: expected output: [[1, 2]]" << endl;
	tester(2, 3);

	cout << "Test 8: expected output: [[1,2,6], [1,3,5], [2, 3, 4]]" << endl;
	tester(3, 9);

	cout << "Test 9: expected output: [[6,9]]" << endl;
	tester(2, 15);
}