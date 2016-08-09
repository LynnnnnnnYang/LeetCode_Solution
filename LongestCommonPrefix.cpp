// @Source : https://leetcode.com/problems/longest-common-prefix/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 14.Longest Common Prefix
* Write a function to find the longest common prefix string amongst an array of strings.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
	{
		if (strs.size() == 0) return "";
		
		// For every character in strs[0]
        for (int i = 0; i < strs[0].size(); ++i) 
		{
			// For every string in the string array
            for (int j = 1; j < strs.size(); ++j) 
			{
				// Reach the end of strs[j]
				if (i == strs[j].size()) return strs[j];

				// Reach the end of Common Prefix
                if (strs[j][i] != strs[0][i]) 
                    return strs[0].substr(0, i);
            }
        }
		// Reach the end of strs[0]
        return strs[0];

    }
};

int LongestCommonPrefix_main()
{
    Solution sol;
	
	vector<string> str_arr;
	string str;
	cin >> str;
	while(str != "0")
	{
		str_arr.push_back(str);
		cin >> str;
	}

	cout<<"The Longest Common Prefix is: "<<sol.longestCommonPrefix(str_arr)<<endl;
	
	system("pause");
    return 0;
}