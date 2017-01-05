// @Source : https://leetcode.com/problems/3sum/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 15.3Sum
* Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
* Find all unique triplets in the array which gives the sum of zero.
* 
* Note: The solution set must not contain duplicate triplets.
*
* Example:
* given array S = [-1, 0, 1, 2, -1, -4],
* A solution set is:
* [
*   [-1, 0, 1],
*   [-1, -1, 2]
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void print_vector(vector<vector<int>> nums)
{
	cout<<"["<<endl;
	for(int i=0;i<nums.size();i++)
		cout<<"	["<<nums[i][0]<<","<<nums[i][1]<<","<<nums[i][2]<<"]"<<endl;
	cout<<"]"<<endl;
}

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) 
	{
		vector<vector<int>> result;
		sort(nums.begin(),nums.end());

		if(nums.size()<3) return result;

		for(int start = 0;start < nums.size() - 2;start++)
		{
			int i = start + 1;
			int j = nums.size() - 1;
			int target = -nums[start];
			while(i < j)
			{
				if(nums[i] + nums[j] == target)
				{
					vector<int> tuple;
					tuple.push_back(nums[start]);
					tuple.push_back(nums[i]);
					tuple.push_back(nums[j]);
					result.push_back(tuple);
	
					for(;i < j && nums[i] == nums[i+1];i++);
					for(;i < j && nums[j] == nums[j-1];j--);
					i++;j--;
				}
				else{
					if(nums[i] + nums[j] < target)
					{
						for(;i < j && nums[i] == nums[i+1];i++);
						i++;
					}
					else{
						for(;i < j && nums[j] == nums[j-1];j--);
						j--;
					}
				}
		
			}
			for(;start < nums.size()-3 && nums[start] == nums[start+1];start++);
		}
		return result;
    }
};

int ThreeSum_main()
//int main()
{
	Solution sol;
	
	vector<int> num;
	int n;
	cin >> n;
	while(n != -250)
	{
		num.push_back(n);
		cin >> n;
	}

	cout<<"The Solution is: "<<endl;
	print_vector(sol.threeSum(num));
	
	system("pause");
	return 0;
}