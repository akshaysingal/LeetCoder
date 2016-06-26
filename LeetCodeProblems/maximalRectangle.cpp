#include "maximalRectangle.h"
#include <vector>

/*

	Question: Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
	Link: https://leetcode.com/problems/maximal-rectangle/

*/


/*
 * This function looks for the largest rectangle containing all 1's within a given board.
 * 
 * Logic: Given the position (x, y) of the cell were we have seen a '1', we do the following:
 *		1. Find the width of the rectangle: count the number of consecutive '1' seen in the same row.
 *		2. Find the height of the rectangle:
 *			(i)  Look above the current row - count the number of rows above that have all 1's for the width found in step 1.
 *			(ii) Look below the current row - count the number of rows blow that have all 1's for the width found in step 1.
 *		3. Compare the locally found area with the global area. If the local area is greater, make it the new global area.
 * 
 * Time complexity of this function alone: O(m*n)
 */
void MaximalRectangleSolution::findMaxArea(vector<vector<char>> &board, int &area, int x, int y)
{
	int localWidth = 0, localHeight = 0;
	int i = 0, j = 0, k = 0;

	bool lookUpEnd = false, lookDownEnd = false;

	// find max 1's in the same row
	for (i = y + 1; i<board[0].size(); i++)
	{
		if (board[x][i] != '1')
		{
			break;
		}
	}
	i--;
	localWidth = i - y + 1;

	// Look above for rows with 1's
	j = x - 1;
	k = x + 1;
	while ((j >= 0 || k < board[0].size()) && !(lookUpEnd && lookDownEnd))
	{
		i = y;
		if (j < 0)	lookUpEnd = true;
		if (k >= board[0].size()) lookDownEnd = true;

		// Check if all elements in that row's width are 1
		while (i <= (y + localWidth - 1) && !(lookUpEnd && lookDownEnd))
		{
			if (j >= 0 && board[j][i] != '1' && !lookUpEnd)
			{
				lookUpEnd = true;
			}

			if (k < board[0].size() && board[k][i] != '1' && !lookDownEnd)
			{
				lookDownEnd = true;
			}

			i++;
		}

		//i--;

		// Check if we exited prematurely
		if (!lookUpEnd)
		{
			j--;
		}
		if (!lookDownEnd)
		{
			k++;
		}
	}

	j++;
	k--;
	localHeight = x - j;
	localHeight = localHeight + (k - x);
	localHeight = localHeight + 1;      // to include the current row.

										// Update the global maximum area
	area = ((localWidth*localHeight) > area) ? area = localWidth*localHeight : area;
}

/*
 * This function iterates over a 2D matrix and for every '1' seen in the matrix,
 * searches for the largest rectangle containing all 1's within the matrix.
 *
 * Assuming the dimensions of the matrix are m by n.
 * Time Complexity: O( (m*n)^2 )
 */
int MaximalRectangleSolution::maximalRectangle(vector<vector<char>>& board) {
	int area = 0;
	int i = 0, j = 0;

	if (board.size() == 0 || board[0].size() == 0)
	{
		return area;
	}

	for (i = 0; i<board.size(); i++)
	{
		for (j = 0; j<board[0].size(); j++)
		{
			if (board[i][j] == '1')
			{
				findMaxArea(board, area, i, j);
			}
		}
	}

	return area;
}

void MaximalRectangleSolution::testMaximalRectangle()
{
	MaximalRectangleSolution s;

	vector<vector<char>> matrix{   { '0', '1', '1', '1' },
								   { '0', '0', '1', '1' },
								   { '0', '1', '1', '1' },
								   { '0', '0', '0', '1' },
								   { '0', '0', '0', '1' } };

	vector<vector<char>> matrix1{   { '0', '0', '1', '1' },
									{ '1', '1', '1', '1' },
									{ '1', '1', '1', '0' },
									{ '1', '1', '1', '1' },
									{ '1', '1', '1', '0' } };

	vector<vector<char>> matrix2{	{ '0', '0', '0', '0' },
									{ '0', '0', '0', '0' },
									{ '0', '0', '0', '0' },
									{ '0', '0', '0', '0' },
									{ '0', '0', '0', '0' } };

	vector<vector<char>> matrix3{   { '0', '0', '0', '1' },
									{ '1', '1', '1', '0' },
									{ '0', '1', '1', '1' },
									{ '0', '1', '1', '1' },
									{ '0', '1', '1', '0' } };

	vector<vector<char>> matrix4{ {} };
	

	cout << s.maximalRectangle(matrix4) << endl;
}