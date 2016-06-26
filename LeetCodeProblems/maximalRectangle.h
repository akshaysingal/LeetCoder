#pragma once

#ifndef MAXIMALRECTANGLE_H
#define MAXIMALRECTANGLE_H

#include <iostream>
#include <vector>

using namespace std;

class MaximalRectangleSolution {
public:
	int maximalRectangle(vector<vector<char>>& board);
	void findMaxArea(vector<vector<char>> &board, int &area, int x, int y);

	void testMaximalRectangle();
};

#endif
