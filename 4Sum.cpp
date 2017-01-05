// @Source : https://leetcode.com/problems/4sum/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-11

/**********************************************************************************
* 18.4Sum
* Given an array S of n integers, are there elements a, b, c, and d in S such that a + b + c + d = target?
* Find all unique quadruplets in the array which gives the sum of target.
* 
* Note: The solution set must not contain duplicate quadruplets.
*
* Example:
* given array [1, 0, -1, 0, -2, 2], and target = 0.
* A solution set is:
* [
*   [-1,  0, 0, 1],
*   [-2, -1, 1, 2],
*   [-2,  0, 0, 2]
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

void print_vector_4(vector<vector<int>> nums)
{
	cout<<"["<<endl;
	for(int i=0;i<nums.size();i++)
		cout<<"	["<<nums[i][0]<<","<<nums[i][1]<<","<<nums[i][2]<<","<<nums[i][3]<<"]"<<endl;
	cout<<"]"<<endl;
}

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) 
	{
		vector<vector<int>> result;
		if(nums.size()<4) return result;
		sort(nums.begin(),nums.end());

		for(int start = 0;start < nums.size() - 4;start++)
		{
			for(int end = nums.size() - 1;end > start + 2;end--)
			{
				int i = start + 1;
				int j = end - 1;
				int tar = target - nums[start] - nums[end];

				while(i < j)
				{
					cout << nums[start] <<" + " <<nums[i] <<" + " <<nums[j] <<" + " <<nums[end] << " = " << nums[start]+nums[i]+nums[j]+nums[end]<<endl;
					if(nums[i] + nums[j] == tar)
					{
						vector<int> quad;
						quad.push_back(nums[start]);
						quad.push_back(nums[i]);
						quad.push_back(nums[j]);
						quad.push_back(nums[end]);
						result.push_back(quad);

						for(;i < j && nums[i] == nums[i+1];i++);
						for(;i < j && nums[j] == nums[j-1];j--);
						i++;j--;
					}
					else{
						if(nums[i] + nums[j] < tar)
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
				for(;end > start + 2 && nums[end] == nums[end-1];end--);
			}
			for(;start < nums.size()-4 && nums[start] == nums[start+1];start++);
		}
		return result;
	}
};

int FourSum_main()
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
	int tar;cin>>tar;

	cout<<"The Solution is: "<<endl;
	print_vector_4(sol.fourSum(num,tar));
	
	system("pause");
	return 0;
}