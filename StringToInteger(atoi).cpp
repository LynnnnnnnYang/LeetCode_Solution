// @Source : https://leetcode.com/problems/string-to-integer-atoi/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-08

/**********************************************************************************
* 8.String to Integer (atoi)
* Implement atoi to convert a string to an integer.
*
* Hint: Carefully consider all possible input cases. 
* If you want a challenge, please do not see below and ask yourself what are the possible input cases.
* 
* Notes: It is intended for this problem to be specified vaguely (ie, no given input specs).
* You are responsible to gather all the input requirements up front.
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) 
	{
		if (str.length() == 0) return 0;
		int i;
		for(i=0;i<str.length()&&str[i]==' ';i++);
		
		bool flag = 0;
        if (str[i]=='+') 
		{
            i++;
        } 
		else if (str[i]=='-') 
		{
            i++;flag=1;
        }

        long long int res = 0;
        for (; i<str.length(); i++) 
		{
            if ('0' <= str[i] && str[i] <= '9') 
			{
                res = res * 10 + (str[i] - '0');
            } 
			else
			{
               break;
            }

			if(!flag && res > INT_MAX) {res = INT_MAX;break;}
			if(flag && res > INT_MAX) {res = -INT_MIN;break;}
		}

        if (flag)
            res = -res;

		return (int)res;	
    }
};

int StringToInteger_main()
{
    Solution sol;
	
	string str;
	cin >> str;
	cout<<str<<" is equal to: "<<sol.myAtoi(str)<<endl;
	
	system("pause");
    return 0;
}