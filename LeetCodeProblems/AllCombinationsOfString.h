#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

void bt(string s, unordered_set<string> &sol, int &pos, string &word, vector<int> &visited)
{
	// Reject case
	/*
	if (word.length >= s.length)
	{
		return;
	}
	*/

	// Accept case
	sol.insert(word);

	// Find next candidate
	for (int i = 0; i < s.length(); i++)
	{
		if (find(visited.begin(), visited.end(), i) == visited.end())
		{
			char c = s[i];
			word += c;
			visited.push_back(i);

			bt(s, sol, i, word, visited);

			visited.pop_back();
			word.erase(word.end()-1);
		}
	}
}

void getAllCombinationsOfString(string s)
{
	unordered_set<string> sol;
	int pos = 0;
	string word = "";
	vector<int> visited;

	bt(s, sol, pos, word, visited);

	for (auto it = sol.begin(); it != sol.end(); it++)
	{
		cout << *it << endl;
	}
}

void ACOS_test()
{
	//getAllCombinationsOfString("");
	//getAllCombinationsOfString("a");
	//getAllCombinationsOfString("aaa");
    //getAllCombinationsOfString("abc");
	getAllCombinationsOfString("a1235");
}