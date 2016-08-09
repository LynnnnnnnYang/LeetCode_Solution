// @Source : https://leetcode.com/problems/integer-to-roman/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-09

/**********************************************************************************
* 12.Integer to Roman
* Given an integer, convert it to a roman numeral.
* Input is guaranteed to be within the range from 1 to 3999
* 
* 1  ~  9 : I II III IV V VI VII VIII IX
* 10 ~ 90 : X XX XXX XL L LX LXX LXXX XC
* 100~900 : C CC CCC CD D DC DCC DCCC CM
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

char sig[3][3]={'I','V','X','X','L','C','C','D','M'};

class Solution {
public:
	
	void convert(string &s,int num,int base)
	{
		if(0<=num && num<=3)
		{
			for(int i = 0; i < num;i++)
			{
				s.push_back(sig[base][0]);
			}
			return;
		}
		if(num == 4)
		{
			s.push_back(sig[base][0]);
			s.push_back(sig[base][1]);
			return;
		}
		if(5<=num && num<=8)
		{
			s.push_back(sig[base][1]);
			for(int i = 0; i < num-5;i++)
			{
				s.push_back(sig[base][0]);
			}
			return;
		}
		s.push_back(sig[base][0]);
		s.push_back(sig[base][2]);
	}

    string intToRoman(int num) 
	{
        string roman;
		int times = num / 1000;
		for(int i = 0; i < times;i++)
		{
			roman.push_back('M');
		}

		times = (num % 1000)/100;
		convert(roman,times,2);
		times = (num % 100)/10;
		convert(roman,times,1);
		times = num % 10;
		convert(roman,times,0);
		return roman;
    }
};

int IntegerToRoman_main()
{
    Solution sol;
	
	int n;
	cin >> n;

	cout<<n<<" convert to: "<<sol.intToRoman(n)<<endl;
	
	system("pause");
    return 0;
}