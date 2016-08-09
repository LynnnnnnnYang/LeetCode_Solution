// @Source : https://leetcode.com/problems/3sum-closest/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 16.3Sum Closest
* Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
* Return the sum of the three integers. 
* You may assume that each input would have exactly one solution.
* 
* Example:
* given array S = {-1 2 1 -4}, and target = 1.
* The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) 
	{
		sort(nums.begin(),nums.end());
		int res = nums[0]+nums[1]+nums[2];
		int dis = abs(target-res);

		for(int start = 0;start < nums.size() - 2;start++)
		{
			int i = start + 1;
			int j = nums.size() - 1;
			while(i < j)
			{
				int sum = nums[start] + nums[i] + nums[j];
                if (abs(sum - target) < dis) {
                    dis = abs(sum - target);
                    res = sum;
                }
                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    i++;
                } else {
                    j--;
                }		
			}
		}
		return res;
	}
};

int ThreeSumClosest_main()
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
	int tar;
	cin>>tar;

	cout<<"The Closest 3Sum is: "<<sol.threeSumClosest(num,tar)<<endl;
	
	system("pause");
    return 0;
}