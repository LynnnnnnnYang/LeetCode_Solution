// @Source : https://leetcode.com/problems/substring-with-concatenation-of-all-words/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-08

/**********************************************************************************
* 30.Substring with Concatenation of All Words
* You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
* 
* For example, given:
* s: "barfoothefoobarman"
* words: ["foo", "bar"]
* You should return the indices: [0,9].
* (order does not matter).
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void print_vector(const vector<int>& v){
	cout<<"[";
	int i;
	for (i=0; i<v.size()-1;i++){
		cout << v[i] << ", ";
	}
	cout<<v[i]<<"]"<<endl;
}

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		
	}
};

int SubstringWithConcatenationOfAllWords_main()
//int main()
{
	Solution sol;
	string str;
	cin>>str;

	string word;
	vector<string> words;
	cin>>word;
	while(word!="")
	{
		cin>>word;
		words.push_back(word);
	}
	cout<<"Find words in: "<<endl;
	print_vector(sol.findSubstring(str,words));
	
	system("pause");
	return 0;
}
