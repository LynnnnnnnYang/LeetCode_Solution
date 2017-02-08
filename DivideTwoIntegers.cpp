// @Source : https://leetcode.com/problems/divide-two-integers/
// @Author : LynnnnnnnYang
// @Date   : 2017-02-08

/**********************************************************************************
* 29.Divide Two Integers
* Divide two integers without using multiplication, division and mod operator.
* If it is overflow, return MAX_INT.
**********************************************************************************/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
		// Special Cases
		if(divisor == 0)
            return INT_MAX;
        if(dividend == 0)
            return 0;    

		bool IsNeg = (dividend < 0) ^ (divisor < 0);

	    long long part = 1;
		// Note: abs(INT_MIN) = INT_MIN
		long long tmp2 = abs((long long)dividend);
	    long long tmp = abs((long long)divisor);

	    while(tmp2 > tmp){
	        tmp  = tmp<<1;
	        part = part<<1;
	    }

	    long long result = 0;
	    while(tmp2 >= abs((long)divisor)){
	        while(tmp2 >= tmp){
	            tmp2 = tmp2 - tmp;
	            result += part;
	        }
	        tmp = tmp>>1;
	        part = part>>1;
	    }

		if(IsNeg) result = -result;
		// Check if result is overflow
		if(result > INT_MAX || result < INT_MIN)
            return INT_MAX;
	    return result;
    }
};

int DivideTwoIntegers_main()
//int main()
{    
	Solution sol;
	int dividend;
	int divisor;

	cin>>dividend>>divisor;
	cout<<dividend<<" / "<<divisor<<" = "<<sol.divide(dividend,divisor)<<endl;
	
	system("pause");
	return 0;
}

