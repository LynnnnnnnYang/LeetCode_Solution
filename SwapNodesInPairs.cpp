// @Source : https://leetcode.com/problems/swap-nodes-in-pairs/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-07

/**********************************************************************************
* 24.Swap Nodes in Pairs
* Given a linked list, swap every two adjacent nodes and return its head.
* 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
* 
* Your algorithm should use only constant space. You may not modify the values in the list, 
* only nodes itself can be changed.
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
		tmp = tmp->next;
		if(tmp!=NULL) cout<<" -> ";
	}
	cout<<endl;
}

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if(head == NULL || head->next == NULL) return head;

		// Create a new head for the result List
		ListNode h(-1); 
		ListNode* cur = &h;
		ListNode* pre = head;
		while(pre && pre->next)
		{
			ListNode *next = pre->next->next;
			cur->next = pre->next;
			cur = cur->next;
			cur->next = pre;
			cur = cur->next;
			cur->next = NULL;
			pre = next;
		}

		if(pre) cur->next=pre;
		return h.next;
	}
};

int SwapNodesInPairs_main()
// int main()
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
		print_list(head);

	cout<<"After swap: "<<endl;
	print_list(sol.swapPairs(head));
	
	system("pause");
	return 0;
}
