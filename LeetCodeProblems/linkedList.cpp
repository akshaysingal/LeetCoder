#include "linkedList.h"

#include "stdlib.h"	/* malloc */


using namespace std;

ListNode * LinkedList::head = NULL;

ListNode * LinkedList::getInstance()
{
	// Check if head has been defined already
	if (head != 0)
	{
		return head;
	}

	// First instantiation - create new object
	head = (ListNode *) malloc( sizeof(ListNode) );
	head->val = 0;
	head->next = 0;

	return head;
}



void LinkedList::freeList()
{
	ListNode * temp = head;

	while(temp != 0)
	{
		head = head->next;
		free(temp);
		temp = head;
	}

	head = 0;
}

ListNode * LinkedList::createList(vector<int> &val)
{
	int i = 0;
	ListNode * prevNode = NULL;
	ListNode * node = NULL;

	if (val.size() == 0)
	{
		return 0;
	}

	// Handle the head node
	prevNode = getInstance();
	prevNode->val = val[0];

	for (i = 1; i < val.size(); i++)
	{
		node = (ListNode *) malloc(sizeof(ListNode));
		node->val = val[i];
		node->next = NULL;
		
		// Link this node to the linked list
		prevNode->next = node;
		prevNode = node;
	}

	// Return the head node of the list
	return getInstance();
}


/* 
 * Question: Given a list, rotate the list to the right by k places, where k is non-negative.
 */
ListNode * LinkedList::rotateRight(ListNode * listHead, int k)
{
	ListNode *newHead = 0;
	ListNode *lastElement = 0;
	ListNode *tempPtr = 0;

	int listSize = 0;

	// Handle base cases
	if (listHead == 0 || k < 0)
	{
		goto exit;
	}

	tempPtr = listHead;

	// Get the size of the list
	while (tempPtr != 0)
	{
		listSize++;
		tempPtr = tempPtr->next;
	}

	// Handle edge case
	if (listSize == 1)
	{
		newHead = listHead;
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
		newHead = listHead;
		goto exit;
	}

	tempPtr = listHead;
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
		newHead = listHead;
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
	lastElement->next = listHead;

exit:
	return newHead;
}

ListNode * LinkedList::reverseList(ListNode * listHead)
{
	ListNode * prevNode2 = NULL;
	ListNode * prevNode = NULL;
	ListNode * nextNode = NULL;

	if (listHead == NULL)
	{
		return NULL;
	}

	prevNode2 = listHead;
	prevNode = prevNode2->next;
	
	if (prevNode == NULL)
	{
		goto exit;
	}

	prevNode2->next = NULL;
	nextNode = prevNode->next;

	while (prevNode != NULL)
	{
		prevNode->next = prevNode2;
		prevNode2 = prevNode;
		prevNode = nextNode;
		if (nextNode != NULL)
		{
			nextNode = nextNode->next;
		}
	}

exit:
	listHead = prevNode2;
	return listHead;
}