#pragma once

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <vector>

using namespace std;

#define NULL	0

/**
 * Definition for singly-linked list.
 */
typedef struct listNode
{
	int val;
	struct listNode * next;
	struct listNode(int x) : val(x), next(0) {}
} ListNode;

class LinkedList
{
	private:
		static ListNode * head;
    
	public:
		
		/* Singleton class - only one object allowed. */
		static ListNode * getInstance();

		/* Linked list functions for testing purposes */
		static ListNode * createList(vector<int> &val);
		void freeList();

		/*  Solution to the "Rotate List" question: https://leetcode.com/problems/rotate-list/ 	 */
		ListNode * rotateRight(ListNode * head, int k);

		/*  Solution to the "Reverse List" question: https://leetcode.com/problems/reverse-linked-list/	  */
		ListNode * reverseList(ListNode * head);
};



#endif