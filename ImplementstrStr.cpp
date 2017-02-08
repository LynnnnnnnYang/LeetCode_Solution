// @Source : https://leetcode.com/problems/implement-strstr/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-05

/**********************************************************************************
* 28.Implement strStr()
* Implement strStr().
* Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		int lenStr=haystack.length();
		int lenSubstr=needle.length();

		// Special Cases
		if(lenSubstr>lenStr) return -1;

		vector<int> next;
		next.push_back(-1);
		
		int i = 0,j = -1;
		while(i < lenSubstr)
		{		
			if(j == -1 || needle[i] == needle[j])
			{
				i++;j++;
				if(needle[i] == needle[j])
					next.push_back(next[j]);
				else
					next.push_back(j);
			}
			else
				j = next[j];
		}

		i=0;j=0;
		while(i<lenStr && j<lenSubstr)
		{
			if(j == -1 || haystack[i] == needle[j]) 
			{
				i++;j++;
			}
			else
				j=next[j]; 
		}

		if(j>=lenSubstr)
			return i-lenSubstr;
		else
			return -1;
	}
};

int ImplementstrStr_main()
//int main()
{
	Solution sol;
	string haystack;
	string needle;
	cin>>haystack>>needle;

	cout<<"Find needle at haystack: "<<sol.strStr(haystack,needle)<<endl;
	
	system("pause");
	return 0;
}
