// @Source : https://leetcode.com/problems/merge-two-sorted-lists/
// @Author : LynnnnnnnYang
// @Date   : 2016-12-21

/**********************************************************************************
* 21.Merge Two Sorted Lists
* Merge two sorted linked lists and return it as a new list. 
* The new list should be made by splicing together the nodes of the first two lists.
**********************************************************************************/

#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void print_list(ListNode* head)
{
	ListNode* tmp = head;
	while(tmp!=NULL)
	{
		cout << tmp->val;
		tmp = tmp ->next;
		if(tmp!=NULL) cout<<" -> ";
	}
	cout<<endl;
}

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;

		ListNode* head = NULL;
		if(l1->val < l2->val)
		{
			head = l1;
			head->next = mergeTwoLists(l1->next,l2);
			return head;
		}
		else
		{
			head = l2;
			head->next = mergeTwoLists(l1,l2->next);
			return head;
		}
	}
};

int MergeTwoSortedLists_main()
//int main()
{
	Solution sol;
	ListNode* head = NULL;
	ListNode* head2 = NULL;
	
	int n;
	cin >> n;
	head = new ListNode(n);
	ListNode* tmp = head;

	cin >> n;
	while(n != -1)
	{
		tmp -> next = new ListNode(n);
		tmp = tmp -> next;
		cin >> n;
	}
	print_list(head);

	cin >> n;
	head2 = new ListNode(n);
	tmp = head2;

	cin >> n;
	while(n != -1)
	{
		tmp -> next = new ListNode(n);
		tmp = tmp -> next;
		cin >> n;
	}
	print_list(head2);

	print_list(sol.mergeTwoLists(head,head2));
	
	system("pause");
	return 0;
}