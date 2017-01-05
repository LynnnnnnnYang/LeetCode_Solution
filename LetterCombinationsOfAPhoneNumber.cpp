// @Source : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-11

/**********************************************************************************
* 17.Letter Combinations of a Phone Number
* Given a digit string, return all possible letter combinations that the number could represent.
* A mapping of digit to letters (just like on the telephone buttons) is given below.
* 2 -> abc, 3 -> def, 4 -> ghi, 5 -> jkl, 6 -> mno, 7 -> pqrs, 8 -> tuv, 9 -> wxyz
*
* Example:
* Input:Digit string "23"
* Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
*
* Note:
* Although the above answer is in lexicographical order, your answer could be in any order you want.
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

void print_vector_str(vector<string> s)
{
	for(int i=0;i<s.size();i++)
		cout<<s[i]<<" ";
	cout<<endl;
}

class Solution {
public:
	void dfs(string digits, int pos, string letter, vector<string> &res, string *map)
	{
		if(pos == digits.length())
		{
			res.push_back(letter);
			return;
		}

		int num = digits[pos] - '0';
		for(int i = 0;i < map[num].length();i++)
		{
			letter.push_back(map[num][i]);
			dfs(digits,pos+1,letter,res,map);
			letter.pop_back();
		}
	}

	vector<string> letterCombinations(string digits) 
	{
		vector<string> res;
		if(digits.length() == 0) return res;

		string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
		int pos = 0;
		string letter;
		dfs(digits,pos,letter,res,map);
		return res;
	}
};

int LetterCombinationsOfAPhoneNumber_main()
//int main()
{
	Solution sol;
	
	string num;
	cin >> num;

	cout<<"The Solution is: "<<endl;
	print_vector_str(sol.letterCombinations(num));
	
	system("pause");
	return 0;
}