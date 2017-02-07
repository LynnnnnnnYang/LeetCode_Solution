// @Source : https://leetcode.com/problems/generate-parentheses/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-07

/**********************************************************************************
* 22.Generate Parentheses
* Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
* 
* For example, given n = 3, a solution set is:
* [
*   "((()))",
*   "(()())",
*   "(())()",
*   "()(())",
*   "()()()"
* ]
**********************************************************************************/

#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

void print_vector(const vector<string>& v){
	for (int i=0; i<v.size();i++){
		cout << v[i] << endl;
	}
}

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> res;
		string par;
		dfs(n,n,par,res);
		return res;
	}

	void dfs(int left, int right, string par, vector<string> &res) {
		if (left == 0 && right == 0) 
			res.push_back(par);

		if (left>0) 
			dfs(left-1,right,par+'(',res);

		if (right>left) 
			dfs(left,right-1,par+')',res);
	}
};

int GenerateParentheses_main()
// int main()
{
	Solution sol;
	int num;
	cin >> num;

	cout<<"Solution Set: "<<endl;
	print_vector(sol.generateParenthesis(num));
	
	system("pause");
	return 0;
}
