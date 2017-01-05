// @Source : https://leetcode.com/problems/add-two-numbers/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-05

/**********************************************************************************
* 2. Add Two Numbers
* You are given two linked lists representing two non-negative numbers. 
* The digits are stored in reverse order and each of their nodes contain a single digit. 
* Add the two numbers and return it as a linked list.
* 
* Example:
* Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
* Output: 7 -> 0 -> 8
**********************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int a = 0, b = 0, car = 0, sum = 0;
		
		ListNode head(-1);
		ListNode *res = &head;

		while (l1!=NULL || l2!=NULL){
			a = 0;b = 0;
			if( l1!=NULL ){a = l1->val;l1 = l1->next;}
			if( l2!=NULL ){b = l2->val;l2 = l2->next;}
			sum = car + a + b;

			res -> next =  new ListNode(sum%10);
			res = res->next;
			car = sum/10;
		}
		
		if (car > 0) {
			res -> next = new ListNode(car%10);
		}
		return head.next;
	}
};

ListNode* int2list(int num)
{
	ListNode head(-1);
	ListNode *res = &head;

	while(num)
	{
		res -> next =  new ListNode(num%10);
		res = res->next;
		num /= 10;
	}
	return head.next;
}

void list_print(ListNode *head)
{
	while(head!=NULL) 
	{
		cout<< head->val;
		head = head->next;
	}
}

int AddTwoNumbers_main()
//int main()
{
	Solution sol;

	int i;cin >> i;
	int j;cin >> j;

	cout<<i<<" + "<<j<<" = "<<i+j<<endl;

	ListNode* l1 = int2list(i);
	ListNode* l2 = int2list(j);
	list_print(l1);
	cout<<" + ";
	list_print(l2);
	cout<<" = ";
	list_print(sol.addTwoNumbers(l1,l2));
	cout<<endl;
	
	system("pause");
	return 0;
}
