// @Source : https://leetcode.com/problems/palindrome-number/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 9.Palindrome Number
* Determine whether an integer is a palindrome. 
* Do this without extra space.
**********************************************************************************/

#include <iostream>

using namespace std;

class Solution {
public:
	bool isPalindrome(int x) 
	{
		// Special Cases
		if(x<0) return 0;

		int base;
		for(base=1;x/base>9;base*=10);

		while(x)
		{
			if(x/base != x%10) return 0;
			x = (x % base) / 10;
			base /= 100;
		}
		return 1;
	}
};

int PalindromeNumber_main()
//int main()
{
	Solution sol;
	
	int n;
	cin >> n;

	cout<<n<<" is Palindrome number? "<<sol.isPalindrome(n)<<endl;
	
	system("pause");
	return 0;
}