/*
 * Question: 
 * Design a data structure that supports the following two operations:
 * 
 * void addWord(word)
 * bool search(word)
 *  search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.
 *
 * For example:

 *  addWord("bad")
 *  addWord("dad")
 *  addWord("mad")
 *  search("pad") -> false
 *  search("bad") -> true
 *  search(".ad") -> true
 *  search("b..") -> true
 */

// Solution: Store the words as a trie
#include <set>

using namespace std;

typedef struct TrieNode
{
	char value;
	set<struct TrieNode> * nextSet;

	bool operator<(const struct TrieNode& node) const
	{
		return value < node.value;
	}

	bool operator==(const struct TrieNode& node) const
	{
		return value == node.value;
	}

	TrieNode()
	{
		nextSet = new set<struct TrieNode>();
	}

	TrieNode(char c)
	{
		value = c;
		nextSet = new set<struct TrieNode>();
	}

} trieNode;

class WordDictionary
{

private:
	set<trieNode> heads;

public:
	// Stores the word as a trie
	// Time complexity = O(m)	; where m = # of characters in the word
	void addWord(string word)
	{
		set<trieNode> * curSet;

		if (word.size() == 0)
		{
			return;
		}

		curSet = &heads;

		for (int i = 0; i<word.size(); i++)
		{
			trieNode nodeToBeFound;
			nodeToBeFound.value = word.at(i);

			auto it = curSet->find(nodeToBeFound);

			if (it == curSet->end())
			{
				// Character was not found. Add it to the trie
				curSet->insert(nodeToBeFound);
				curSet = nodeToBeFound.nextSet;
			}
			else
			{
				trieNode node = *it;
				curSet = node.nextSet;
			}
		}

		// Want to add a '\0' character to indicate the end of a word
		trieNode newNode;
		newNode.value = '\0';
		curSet->insert(newNode);

		return;
	}

	
	bool search(string word)
	{
		set<trieNode> * curSet;

		if (word.size() == 0)
		{
			return false;
		}

		return bt(word, 0, &heads);
	}

	// A backtracking function that looks through the trie to find a match for the given string
	bool bt(string givenWord, int pos, set<trieNode> * curSet)
	{
		bool result = false;
		trieNode node;

		if (pos >= givenWord.size())
		{
			// Reached the end of the given word, check for the NULL char
			trieNode newNode;
			newNode.value = '\0';
			if (curSet->find(newNode) == curSet->end())
			{
				return false;
			}
			return true;
		}

		if (curSet->size() == 0)
		{
			// No more elements left to be checked
			return false;
		}
				
		node.value = givenWord.at(pos);
		auto it = curSet->find(node);

		if (it == curSet->end())
		{
			// A match for the current character was not found, however, we need to make an exception for '.'
			if (givenWord.at(pos) == '.')
			{
				// Here we need to search using backtracking
				// Pass in the set of the current node
				for (auto s = curSet->begin(); s != curSet->end(); s++)
				{
					result = bt(givenWord, pos + 1, s->nextSet);
					if (result)
					{
						break;
					}
				}
			}
			else
			{
				// Character match not found, return
				return false;
			}
		}
		else
		{
			// Match found, advance to the next char
			return bt(givenWord, pos+1, it->nextSet);
		}
		return result;
	}

	void testWordSearch()
	{
		test1();
		test2();
		test3();
	}

	void test1()
	{
		WordDictionary w;

		cout << "Test 1" << endl;
		cout << "-------" << endl;

		// Test 1
		w.addWord("abc");
		vector<string> validString{ "abc", "a.c", "..." };
		vector<string> invalidString{ "a.", "..", ".", "....", "", "ab", "abcde" };

		for (int i = 0; i < validString.size(); i++)
		{
			bool ret = w.search(validString.at(i));
			cout << "String: " << validString.at(i) << "	| Expected result: Found | Returned result: ";
			if (ret) cout << "Found" << endl;
			else cout << "Not Found" << endl;
		}

		for (int i = 0; i < invalidString.size(); i++)
		{
			bool ret = w.search(invalidString.at(i));
			cout << "String: " << invalidString.at(i) << "	| Expected result: Not Found | Returned result: ";
			if (ret) cout << "Found" << endl;
			else cout << "Not Found" << endl;
		}
	}

	void test2()
	{
		WordDictionary w;

		cout << "Test 2" << endl;
		cout << "-------" << endl;

		// Test 2
		vector<string> invalidString{ "abc", "a.c", "...", "a.", "..", ".", "....", "", "ab", "abcde" };

		for (int i = 0; i < invalidString.size(); i++)
		{
			bool ret = w.search(invalidString.at(i));
			cout << "String: " << invalidString.at(i) << "	| Expected result: Not Found | Returned result: ";
			if (ret) cout << "Found" << endl;
			else cout << "Not Found" << endl;
		}

	}

	void test3()
	{
		WordDictionary w;

		cout << "Test 3" << endl;
		cout << "-------" << endl;

		// Test 3
		w.addWord("abc");
		w.addWord("abcd");
		vector<string> validString{ "abc", "a...", "....", "...d", "...", "a.c" };
		vector<string> invalidString{ "a.", "..", ".", "", "ab", "abcde" };

		for (int i = 0; i < validString.size(); i++)
		{
			bool ret = w.search(validString.at(i));
			cout << "String: " << validString.at(i) << "	| Expected result: Found | Returned result: ";
			if (ret) cout << "Found" << endl;
			else cout << "Not Found" << endl;
		}

		for (int i = 0; i < invalidString.size(); i++)
		{
			bool ret = w.search(invalidString.at(i));
			cout << "String: " << invalidString.at(i) << "	| Expected result: Not Found | Returned result: ";
			if (ret) cout << "Found" << endl;
			else cout << "Not Found" << endl;
		}
	}

};