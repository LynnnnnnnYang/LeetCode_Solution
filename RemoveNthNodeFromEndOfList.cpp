// @Source : https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-11

/**********************************************************************************
* 19.Remove Nth Node From End of List
* Given a linked list, remove the nth node from the end of list and return its head.
*
* Example:
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
**********************************************************************************/

#include <iostream>

using namespace std;

//Definition for singly-linked list.
struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
/*
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
*/
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) 
	{
		ListNode pre_head(0);
		pre_head.next = head;
		
		ListNode *prev = &pre_head;
		ListNode *l = head;
		ListNode *r = head;
		
		for (int i = 0; i < n; i++)
			r = r->next;

		while (r != NULL) {
			prev = prev->next;
			l = l->next;
			r = r->next;
		}
		
		prev->next = l->next;
		delete l;

		return pre_head.next;
	}
};

int RemoveNthNodeFromEndOfList_main()
//int main()
{
	Solution sol;
	ListNode* head = NULL;

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
	//print_list(head);

	int pos;cin>>pos;
	cout<<"The result is: ";
	//print_list(sol.removeNthFromEnd(head,pos));
	
	system("pause");
	return 0;
}