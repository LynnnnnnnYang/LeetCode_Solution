// @Source : https://leetcode.com/problems/median-of-two-sorted-arrays/
// @Author : LynnnnnnnYang
// @Date   : 2016-08-08

/**********************************************************************************
* 4.Median of Two Sorted Arrays
* There are two sorted arrays nums1 and nums2 of size m and n respectively.
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*
* Example 1:
* nums1 = [1, 3]
* nums2 = [2]
* The median is 2.0
* 
* Example 2:
* nums1 = [1, 2]
* nums2 = [3, 4]
* The median is (2 + 3)/2 = 2.5
**********************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{
		int m = nums1.size(), n = nums2.size();
		if((m + n) % 2)
			return findKth((m + n - 1) / 2, nums1, 0, m - 1, nums2, 0, n - 1);
		else return (findKth((m + n) / 2 -1, nums1, 0, m - 1, nums2, 0, n - 1)
						+findKth((m + n) / 2, nums1, 0, m - 1, nums2, 0, n - 1)) /2.0;
	}

	int findKth(int k, vector<int>& A, int l1, int r1, vector<int>& B, int l2, int r2) 
	{
		if (l1 > r1)	return B[l2 + k];
		if (l2 > r2)	return A[l1 + k];

		int m1 = (l1 + r1) / 2, m2 = (l2 + r2) / 2;
		if (A[m1] > B[m2]) {
			if (k + 1 < m1 - l1 + 1 + m2 - l2 + 1) {
				return findKth(k, A, l1, m1 - 1, B, l2, r2);
			} else {
				return findKth(k - (m2 - l2 + 1), A, l1, r1, B, m2 + 1, r2);
			}
		} else {
			if (k + 1 < m1 - l1 + 1 + m2 - l2 + 1) {
				return findKth(k, A, l1, r1, B, l2, m2 - 1);
			} else {
				return findKth(k - (m1 - l1 + 1), A, m1 + 1, r1, B, l2, r2);
			}
		}
	}

};

int MedianOfTwoSortedArrays_main()
//int main()
{
	Solution sol;
	
	vector<int> a,b;int i;
	cin>>i;
	while(i!=-1)
	{   a.push_back(i);cin>>i;}

	cin>>i;
	while(i!=-1)
	{   b.push_back(i);cin>>i;}

	cout<<sol.findMedianSortedArrays(a,b)<<endl;
	
	system("pause");
	return 0;
}