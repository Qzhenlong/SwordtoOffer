#include<iostream>
#include<vector>
using namespace std;
/*
题目：把一个数组的最开始的若干个元素搬到数组的末尾，称为数组的旋转，输入一个递增排序的数组的一个旋转，输出最小元素。
如：输入{1，2，3，4，5}的旋转{3，4，5，1，2}，返回1.
解析：与LeetCode中的Find Minimum in Rotated Sorted Array I和II相同
思路：分两种情况：允许重复值还是不允许重复值，假设旋转数组为A，分析过程如下：
1.不允许重复值，这种情况比较简单，借助二分查找的思想
（1）A[low] < A[high], 直接返回A[low];
（2）A[low] > A[high] && A[low] < A[mid], 前半部分有序，最小值一定在后半部分，low = mid+1;
（3）A[low] > A[high] && A[low] > A[mid], 后半部分有序，最小值一定在前半部分，high = mid;

2.允许重复值，这种情况复杂一点，排除边界情况即可
（1）A[low] < A[high], 直接返回A[low]，还是相同；
（2）A[low] == A[mid], low++;
（3）A[high] == A[mid], high--;
（4）A[low] > A[high] && A[low] < A[mid], 前半部分有序，最小值一定在后半部分，low = mid+1;
（5）A[low] > A[high] && A[low] > A[mid], 后半部分有序，最小值一定在前半部分，high = mid;

很明显允许重复值的解法兼容不允许重复值的解法。
*/
class Solution {
public:
	int findMinI(vector<int > nums){ //不允许重复值
		int low = 0, high = nums.size()-1, mid;
		//if(nums.size() <= 0) return NULL;
		if(nums.size() == 1 || nums[low] < nums[high]) return nums[0];
		while(low < high){
			mid = (high+low)/2;
			if(nums[low] < nums[high]) return nums[low];
			if(nums[low] < nums[mid]) low = mid+1;
			else high = mid;
		}
		return nums[low];
	}
	int findMinII(vector<int > nums){ //允许重复值
		int low = 0, high = nums.size()-1, mid;
		//if(nums.size() <= 0) return NULL;
		if(nums.size() == 1 || nums[low] < nums[high]) return nums[0];
		while(low < high){
			mid = (low+high)/2;
			if(nums[low] < nums[high]) return nums[low];
			if(nums[low] == nums[mid]){ low++; continue;}
			if(nums[high] == nums[mid]){ high--; continue;}
			if(nums[low] < nums[mid]) low = mid+1;
			if(nums[low] > nums[mid]) high = mid;
		}
		return nums[low];
	}
};
int main(){
  Solution c;
  vector<int > n;
  int sn = 7;
  for(int i = 0; i < sn; i++)
  {
          //cout << (i+3)% sn << " ";
          // n.push_back((i+3)% sn);
           if(i != 5) n.push_back(0);
           else n.push_back(1);
           
  }
  for(int i = 0; i < n.size(); i++) cout << n[i] << " "; 
  cout << endl;
  cout << c.findMinI(n) << endl;
  return 0;
 }
  