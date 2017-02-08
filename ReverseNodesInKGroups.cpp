// @Source : https://leetcode.com/problems/reverse-nodes-in-k-group/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-07

/**********************************************************************************
* 25.Reverse Nodes in k-Group
* Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
* k is a positive integer and is less than or equal to the length of the linked list. 
* If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
* 
* For example,
* Given this linked list: 1->2->3->4->5
* For k = 2, you should return: 2->1->4->3->5
* For k = 3, you should return: 3->2->1->4->5
* 
* You may not alter the values in the nodes, only nodes itself may be changed.
* Only constant memory is allowed.
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
	ListNode* reverseKGroup(ListNode* head, int k) {
		// Special Cases
		if (k <= 1)  return head;

		int num = k;
		// Check the Left-out nodes in the end
		ListNode* pEnd = head;
		ListNode* cur = head;
		while (pEnd && k>0){
			cur = pEnd;
			pEnd = pEnd->next;
			k--;
		}
		if (k>0) return head;
		pEnd = cur;

		// Create a new head for the result List
		ListNode* pHead = head;
		ListNode* pre = pHead->next;

		if(pEnd->next){
			pHead->next = reverseKGroup(pEnd->next,num);
		}
		else{
			pHead->next = NULL;
		}

		cur = pHead;

		while(pre != pEnd){
			ListNode *next = pre->next;
			pre->next = cur;
			cur = pre;
			pre = next;
		}
		pre->next = cur;

		return pEnd;
	}
};

int ReverseNodesInKGroups_main()
// int main()
{
	Solution sol;
	int num;
	cin >> num;
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
	print_list(sol.reverseKGroup(head,num));
	
	system("pause");
	return 0;
}
