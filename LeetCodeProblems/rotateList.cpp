#include "rotateList.h"

using namespace std;

/* 
 * Question: Given a list, rotate the list to the right by k places, where k is non-negative.
 */

ListNode * Solution_RotateRight::rotateRight(ListNode * head, int k)
{
	ListNode *newHead = 0;
	ListNode *lastElement = 0;
	ListNode *tempPtr = 0;

	int listSize = 0;

	// Handle base cases
	if (head == 0 || k < 0)
	{
		goto exit;
	}

	tempPtr = head;

	// Get the size of the list
	while (tempPtr != 0)
	{
		listSize++;
		tempPtr = tempPtr->next;
	}

	// Handle edge case
	if (listSize == 1)
	{
		newHead = head;
		goto exit;
	}

	// For values of k >= listSize, find the minimum elements to be actually rotated
	if (k >= listSize)
	{
		k = k % listSize;
	}

	// If k is 0, there is nothing to be rotated
	if (k == 0)
	{
		newHead = head;
		goto exit;
	}

	tempPtr = head;
	k--;
	while (k > 0)
	{
		tempPtr = tempPtr->next;
		k--;
	}

	// At this point, tempPtr points to the element that will be 
	// the last element in the new rotated list

	// Check if we are looking at the last element in the current list
	if (tempPtr->next == 0)
	{
		// Since the rotated list is the same as the actual list, we will simply return this list.
		newHead = head;
		goto exit;
	}
	else
	{
		newHead = tempPtr->next;
		tempPtr->next = 0;
	}

	// Get the last element if not found yet
	tempPtr = newHead;
	while (tempPtr->next != 0)
	{
		tempPtr = tempPtr->next;
	}

	lastElement = tempPtr;
	lastElement->next = head;

exit:
	return newHead;
}
