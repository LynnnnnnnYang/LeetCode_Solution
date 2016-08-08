// @Source : https://leetcode.com/problems/longest-palindromic-substring/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-08

/**********************************************************************************
* 5.Longest Palindromic Substring
* Given a string S, find the longest palindromic substring in S. 
* You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
		int maxlen = 1, res = 0;
		int len = s.length();
		//bool **Is_Palindromic = new bool* [len];
		//for(int i=0;i<len;i++) Is_Palindromic[i] = new bool[len];
		bool Is_Palindromic[1000][1000];
		for(int i=0;i<len;i++)		Is_Palindromic[i][i] = 1; 
		for(int i=0;i<len-1;i++)		Is_Palindromic[i+1][i] = 1;

		/*
		for(int i=0;i<len-1;i++)
		{
			Is_Palindromic[i][i+1] = 0;
			if(s[i]==s[i+1])
			{   
				Is_Palindromic[i][i+1]=1; 
				maxlen = 2;
				res = i;
			}
		}
		*/

		for(int gap=1;gap<len;gap++)
		{
			for(int i=0,j=i+gap;j<len;i++,j++)
			{
				Is_Palindromic[i][j] = 0;
				if(s[i] == s[j]) 
				{
					if(Is_Palindromic[i+1][j-1])
					{
						Is_Palindromic[i][j] = 1;
						maxlen = gap+1;
						res = i;
					}
				}
			}
		}

		return s.substr(res,maxlen);
    }
};

int LongestPalindromicSubstring_main()
{
    Solution sol;
	
	string str;
	cin >> str;
	cout<<str<<" has Longest Palindromic Substring "<<sol.longestPalindrome(str)<<endl;
	
	system("pause");
    return 0;
}