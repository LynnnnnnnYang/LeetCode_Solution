// @Source : https://leetcode.com/problems/remove-element/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-08

/**********************************************************************************
* 27.Remove Element
* Given an array and a value, remove all instances of that value in place and return the new length.
* 
* Do not allocate extra space for another array, you must do this in place with constant memory.
* The order of elements can be changed. It doesn't matter what you leave beyond the new length.
* 
* Example:
* Given input array nums = [3,2,2,3], val = 3
* Your function should return length = 2, with the first two elements of nums being 2.
**********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v){
	for (int i=0; i<v.size();i++){
		cout << v[i] << endl;
	}
}

class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		// Special Cases
		if(nums.empty()) return 0;
		
		vector<int>::iterator it = nums.begin();
		int num = nums.size();
		while(it != nums.end())
		{
			if(*it == val)
			{
				it = nums.erase(it);
				num--;
			}
			else
				it++;
		}
		return num;
	}
};

int RemoveElement_main()
//int main()
{
	Solution sol;
	vector<int> nums;
	int n;
	cin >> n;
	while(n != -1)
	{
		nums.push_back(n);
		cin >> n;
	}
	int val;
	cin>>val;
	cout<<"After remove element: "<<endl;
	cout<<"Number of nums: "<<sol.removeElement(nums,val)<<endl;
	print_vector(nums);
	
	system("pause");
	return 0;
}
