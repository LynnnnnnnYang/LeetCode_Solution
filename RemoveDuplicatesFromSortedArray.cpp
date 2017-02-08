// @Source : https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-07

/**********************************************************************************
* 26.Remove Duplicates from Sorted Array
* Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
* 
* Do not allocate extra space for another array, you must do this in place with constant memory.
* 
* For example,
* Given input array nums = [1,1,2],
* Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
* It doesn't matter what you leave beyond the new length.
**********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v){
	for (int i=0; i<v.size();i++)
	{
		cout << v[i] << endl;
	}
}

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		// Special Cases
		if(nums.size()<=1) return nums.size();

		int pos = 1;
		int val = nums[0];
		int num = 1;

		while(pos < nums.size())
		{
			if(nums[pos] != val){
				val = nums[pos];
				nums[num] = val;
				num++;
			}
			pos++;
		}
		return num;
	}
};

int RemoveDuplicatesFromSortedArray_main()
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
		
	cout<<"After remove duplicate: "<<endl;
	cout<<"Number of nums: "<<sol.removeDuplicates(nums)<<endl;
	print_vector(nums);
	
	system("pause");
	return 0;
}