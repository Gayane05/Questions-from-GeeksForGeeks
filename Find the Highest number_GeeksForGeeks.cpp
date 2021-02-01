#include <iostream>
#include <iostream>
#include <vector>

//
//Given an array in such a way that the elements stored in array are 
//in increasing order initiallyand then after reaching to a peak element, 
//elements stored are in decreasing order.Find the highest element.
//Note: A[i] != A[i + 1]
//
//
//Examples :
//
//	Input :
//	11
//	1 2 3 4 5 6 5 4 3 2 1
//	Output : 6
//	Explanation : Highest element is 6.
//	Example 2 :
//
//	Input :
//	5
//	1 2 3 4 5
//	Output : 5
//	Explanation : Highest element is 5.


int findPeakElement(std::vector<int>& a)
{
	// Execution Time:0.01
	// Code here.
	int l = 0;
	int r = a.size() - 1;

	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (a[mid] > a[mid - 1])
		{
			if (mid + 1 < a.size() && a[mid] > a[mid + 1])
			{
				return a[mid];
			}
			else
			{
				l = mid + 1;
			}
		}
		else if (a[mid] < a[mid - 1])
		{
			r = mid - 1;
		}
		if (l == a.size() - 1)
		{
			if (a[l] > a[0])
			{
				return a[l];
			}
			return a[0];
		}
	}
}


int main()
{
   
	std::vector<int> nums{ 1, 2, 3, 4, 5, 6, 7, 6, 5, 4, 3, 2 };
	findPeakElement(nums);

	return 0;
}
