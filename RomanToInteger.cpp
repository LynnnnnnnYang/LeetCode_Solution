// @Source : https://leetcode.com/problems/roman-to-integer/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 13.Roman to Integer
* Given a roman numeral, convert it to an integer.
* Input is guaranteed to be within the range from 1 to 3999
* 
* 1  ~  9 : I II III IV V VI VII VIII IX
* 10 ~ 90 : X XX XXX XL L LX LXX LXXX XC
* 100~900 : C CC CCC CD D DC DCC DCCC CM
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

char sig2[3][3]={'I','V','X','X','L','C','C','D','M'};

class Solution {
public:
	int convert(string s,int &pos,int base)
	{
		int res = 0;
		
		// case1: res = 0 - 3 || 5 - 8
		if(s[pos] == sig2[base][1])	{pos++;res = 5;}
		while(s[pos] == sig2[base][0])
		{
			pos++;res++;
		}
		if(base!=0 && (s[pos] == sig2[base-1][0] || s[pos] == sig2[base-1][1])) return res;

		// case2: res = 4
		if(res == 1 && s[pos] == sig2[base][1]) {pos++;return 4;}

		// case3: res = 9
		if(res == 1 && s[pos] == sig2[base][2]) {pos++;return 9;}

		return res;

	}
	int romanToInt(string s) 
	{
		int pos = 0,res = 0;
		while(s[pos] == 'M')
		{
			pos++;res++;
		}
		res *= 1000;
		res += 100 * convert(s,pos,2);
		res += 10 * convert(s,pos,1);
		res += convert(s,pos,0);
		return res;
	}
};

int RomanToInteger_main()
//int main()
{
	Solution sol;
	
	string str;
	cin >> str;

	cout<<str<<" convert to: "<<sol.romanToInt(str)<<endl;
	
	system("pause");
	return 0;
}