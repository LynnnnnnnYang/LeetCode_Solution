// @Source : https://leetcode.com/problems/reverse-integer/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-08

/**********************************************************************************
* 7.Reverse Integer
* Reverse digits of an integer.
*
* Example1: 
* x = 123, return 321
* Example2: 
* x = -123, return -321
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    int reverse(int x) 
	{
		int flag = 0;
		long long res = 0;

		//int: -2147483648 ~ 2147483647
		if(x == INT_MIN)	return 0;

		if(x < 0) {x = -x;flag = 1;}

		for(;x;x/=10)
		{
			res = res*10 + x % 10; 
		}
		if(res > INT_MAX) return 0;

		if(flag) res = -res;
        return (int)res;
    }
};

int ReverseInteger_main()
{
    Solution sol;
	
	int n;
	cin >> n;

	cout<<n<<" reverse to: "<<sol.reverse(n)<<endl;
	
	system("pause");
    return 0;
}
