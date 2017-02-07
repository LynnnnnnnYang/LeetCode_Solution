// @Source : https://leetcode.com/problems/valid-parentheses/
// @Author : LynnnnnnnYang
// @Date   : 2016-12-21

/**********************************************************************************
* 20.Valid Parentheses
* Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
* The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
**********************************************************************************/

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
	bool isValid(string s) {
		if(s.length()==0) return true;

		stack<char> charStack;  
		int i = 0;
		
		while(i != s.length())  
		{  
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')  
			{  
				charStack.push(s[i]);  
			}  
			else  
			{  
				if (charStack.empty())  
				   return false;  
  
				char pre = charStack.top();  
				switch(s[i])  
				{  
				case ')':  
					if (pre == '(')  
					  charStack.pop();  
					else   
					  return false;  
					break;  
						
				case '}':  
					if (pre == '{')  
					  charStack.pop();  
					else   
					  return false;  
					break;  
					  
				case ']':  
					if (pre == '[')  
					  charStack.pop();  
					else   
					  return false;  
					break;  
				}  
			}  
			++i;  
		} 

		if (charStack.empty())  return true;  
		return false;  
	}
};

int ValidParentheses_main()
//int main()
{
	Solution sol;
	string valid[2] = {"not valid","valid"};
	string str;
	cin >> str;

	cout<<"String: "<<str<<" is "<<valid[sol.isValid(str)]<<endl;
	
	system("pause");
	return 0;
}
