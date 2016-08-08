// @Source : https://leetcode.com/problems/longest-substring-without-repeating-characters/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-08

/**********************************************************************************
* 3.Longest Substring Without Repeating Characters
* Given a string, find the length of the longest substring without repeating characters.
*
* Examples:
* Given "abcabcbb", the answer is "abc", which the length is 3.
* Given "bbbbb", the answer is "b", with the length of 1.
* Given "pwwkew", the answer is "wke", with the length of 3. 
* Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int maxlen = 0;
		int l = 0;
		int len = s.length();

		int pos[256];
		for(int i = 0;i < 256;i++) pos[i]=-1;

		for(int h = 0;h < len;h++)
		{
			if(pos[s[h]] >= l)
			{
				l = pos[s[h]]+1;
			}
			pos[s[h]] = h;	
			maxlen = max(maxlen,h-l+1);
		}
		return maxlen;        
    }
};

int LongestSubstring_main()
{
    Solution sol;
	
	string j;cin >> j;
	cout<<j<<" has longest substring with length: "<<sol.lengthOfLongestSubstring(j)<<endl;
	
	system("pause");
    return 0;
}