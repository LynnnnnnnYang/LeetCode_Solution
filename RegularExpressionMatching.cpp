// @Source : https://leetcode.com/problems/regular-expression-matching/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 10.Regular Expression Matching
* Implement regular expression matching with support for '.' and '*'.
* '.' Matches any single character.
* '*' Matches zero or more of the preceding element.
* The matching should cover the entire input string (not partial).
* 
* The function prototype should be:
* bool isMatch(const char *s, const char *p)
* 
* Some examples:
* isMatch("aa","a") ¡ú false
* isMatch("aa","aa") ¡ú true
* isMatch("aaa","aa") ¡ú false
* isMatch("aa", "a*") ¡ú true
* isMatch("aa", ".*") ¡ú true
* isMatch("ab", ".*") ¡ú true
* isMatch("aab", "c*a*b") ¡ú true
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	bool isMatch(string s, string p)
	{
		// case 1: pattern reach the end
		if(p.length() == 0)	return s.length() == 0;

		// case 2: pattern remains one char or '.'
		if(p.length() == 1) 
			return (s.length() == 1) && (s[0] == p[0] || p[0] == '.');

		// case 3: pattern meets char or '.'
		if(p[1] != '*')
		{
			if(s.length() == 0) return 0;
			if(s[0] == p[0] || p[0] == '.') return isMatch(s.substr(1,s.length()-1),p.substr(1,p.length()-1));
			return 0;
		}

		// case 4: pattern meets char+'*', etc 'a*'
		else{
			while(s.length() > 0 && (p[0] == s[0] || p[0] == '.'))
			{
				if(isMatch(s,p.substr(2,p.length()-2)))	return 1;
				s = s.substr(1,s.length()-1);
			}
			return isMatch(s,p.substr(2,p.length()-2));
		}
	}
};

int RegularExpressionMatching_main()
{
    Solution sol;
	
	string s,p;
	cin>>s>>p;

	cout<<s<<" is match to "<<p<<" ? "<<sol.isMatch(s,p)<<endl;
	
	system("pause");
    return 0;
}