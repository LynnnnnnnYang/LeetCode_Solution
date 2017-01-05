// @Source : https://leetcode.com/problems/zigzag-conversion/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-08

/**********************************************************************************
* 6.ZigZag Conversion
* The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
* (you may want to display this pattern in a fixed font for better legibility)
* P   A   H   N
* A P L S I I G
* Y   I   R
* And then read line by line: "PAHNAPLSIIGYIR"
* 
* Write the code that will take a string and make this conversion given a number of rows:
* string convert(string text, int nRows);
* 
* Examples:
* convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
**********************************************************************************/

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
	string convert(string s, int numRows) 
	{
		string res = "";
		int pos = 0,cur = 0;
		int len = s.length();

		if(numRows == 1) return s;

		// i = 0
		res.push_back(s[cur]);
		cur += 2 * (numRows - 1);
		while(cur < len)
		{
			res.push_back(s[cur]);
			cur += 2 * (numRows - 1);
		}

		for(int i = 1;i < numRows-1;i++)
		{
			cur = i;
			if(cur < len) res.push_back(s[cur]);

			cur += 2 * (numRows - 1 - i);
			while(cur < len)
			{
				res.push_back(s[cur]);

				cur += 2 * i;
				if(cur >= len) break;
				res.push_back(s[cur]);

				cur += 2 * (numRows - 1 - i);
			}
		}

		// i = numRows - 1
		cur = numRows - 1;
		if(cur < len) res.push_back(s[cur]);
		cur += 2 * (numRows - 1);
		while(cur < len)
		{
			res.push_back(s[cur]);
			cur += 2 * (numRows - 1);
		}

		return res;
	}
};

int ZigZagConversion_main()
//int main()
{
	Solution sol;
	
	string str;
	int n;
	cin >> str >> n;

	cout<<str<<" convert to: "<<sol.convert(str,n)<<endl;
	
	system("pause");
	return 0;
}