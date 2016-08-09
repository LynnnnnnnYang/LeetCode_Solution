// @Source : https://leetcode.com/problems/container-with-most-water/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 11.Container With Most Water 
* Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
* n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). 
* Find two lines, which together with x-axis forms a container, such that the container contains the most water.
* 
* Note: You may not slant the container.
**********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) 
	{
		if(height.size()<2) return 0;

		int l = 0, r = height.size()-1, maxSize = 0;
		while(l < r) 
		{
			maxSize = max(maxSize, min(height[l],height[r]) * (r - l));
			if(height[l] < height[r]) l++;
			else r--;
		}
		return maxSize;
    }
};

int ContainerWithMostWater_main()
{
    Solution sol;
	
	vector<int> h;
	int n;
	cin >> n;

	while(n!=-1)
	{
		h.push_back(n);
		cin>>n;
	}
	cout<<"The max Area is "<<sol.maxArea(h)<<endl;
	
	system("pause");
    return 0;
}