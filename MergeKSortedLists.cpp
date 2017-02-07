// @Source : https://leetcode.com/problems/merge-k-sorted-lists/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-07

/**********************************************************************************
* 23.Merge k Sorted Lists
* Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

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

bool cmp_greater(const ListNode* a,const ListNode* b)
{
	return a->val > b->val;
}

class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if(lists.empty()) return NULL;
		int num = lists.size();
		vector <ListNode*> heap;
		for(int i=0;i<num;i++)
		{
			if(lists[i])	heap.push_back(lists[i]);
		}
		make_heap(heap.begin(),heap.end(),cmp_greater);
		
		// Create a new head for the result List
		ListNode head(-1); 
		ListNode* p = &head;
		while(!heap.empty()){
			// Pop the minimal Node from heap
			pop_heap(heap.begin(),heap.end(),cmp_greater);
			ListNode* minNode = heap.back();
			heap.pop_back();

			// Add the minimal Node to the result List
			p->next = minNode; 

			// Add the next Node of the minimal Node to the heap
			p = p->next;
			ListNode* next = minNode->next;
			if(next) 
			{
				heap.push_back(next);
				push_heap(heap.begin(),heap.end(),cmp_greater);
			}
		}
		return head.next;
	}
};

int MergeKSortedLists_main()
// int main()
{
	Solution sol;
	int num;
	cin >> num;
	vector<ListNode*> v;

	for(int i=0;i<num;i++)
	{
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
		v.push_back(head);

	}

	cout<<"After merging: "<<endl;
	print_list(sol.mergeKLists(v));
	
	system("pause");
	return 0;
}
