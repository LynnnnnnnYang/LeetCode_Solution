// @Source : https://leetcode.com/problems/two-sum/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-05

/**********************************************************************************
* 1.Two Sum
* Given an array of integers, return indices of the two numbers such that they add up to a specific target.
* You may assume that each input would have exactly one solution.
*
* Example:
* Given nums = [2, 7, 11, 15], target = 9,
* Because nums[0] + nums[1] = 2 + 7 = 9,
* return [0, 1].
**********************************************************************************/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
    {
        vector<int> result;
        map<int,int> mp;
		int pos2 = 0;
        for(int i = 0; i < numbers.size(); ++i)
            mp[numbers[i]] = i+1;

		for(int i = 0; i < numbers.size(); ++i)
		{
			pos2 = mp[target - numbers[i]];
			if(pos2 && (pos2-1)!=i)
			{
				result.push_back(i);
				result.push_back(pos2-1);
				return result;
			}
		}  

		return result;
    }
};

int TwoSum_main()
{
    Solution sol;
	vector <int> nums;
	int j;cin >> j;
	while(j != -1)		
	{
		nums.push_back(j);cin >> j;
	}

	int tar;cin >> tar;

	vector <int> two = sol.twoSum(nums,tar);
	if(two.size()){cout<<two[0]<<" "<<two[1]<<endl;}
	
	system("pause");
    return 0;
}
