#pragma once

#ifndef ROTATELIST_H
#define ROTATELIST_H

/**
 * Definition for singly-linked list.
 */
typedef struct listNode
{
	int val;
	struct listNode * next;
	struct listNode(int x) : val(x), next(0) {}
} ListNode;

class Solution_RotateRight
{
	public:
		ListNode * rotateRight(ListNode * head, int k);
};

#endif