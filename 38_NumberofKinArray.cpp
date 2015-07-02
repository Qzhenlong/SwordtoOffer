#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
题目：统计一个数字在排序数组中出现的次数。
思路：
（1）最简单的方法就是直接定义一个哈希表来统计次数，空间和时间复杂度为O(n)
（2）但是题目中的数组的有序的，如果采用二分查找的思路，空间复杂度可降为O(1),时间复杂度降为O(logn)

注：事实上就是找到某个数字k在有序数组中出现的区间起始点，与LeetCode中的Search for A Range其实是一样的。
*/

class Solution{
public:
	//思路(1)比较简单，直接实现思路(2)
	int CalNumber(vector<int > nums, int target){
        vector<int > range(2, -1);
		int low = 0, high = nums.size()-1, mid;
		while(low <= high){
			mid = (low+high)/2;
			if(nums[mid] == target){
				range[0] = range[1] = mid;
				break;
			}
			if(nums[mid] < target) low = mid+1;
			else high = mid-1;
		}
		if(range[0] == -1) return 0; //查找到一个目标整数的位置， 再对该位置的两边进行二分查找，确定上下界
		int i = low, j = mid-1;
		while(i <= j){ //区间[low,mid]的元素小于等于目标整数
			int _mid = (i+j)/2;
			if(nums[_mid] == nums[mid]){
				range[0] = _mid;
				j = _mid-1;
			}
			else i = _mid+1;
		}
		i = mid+1; j = high;
		while(i <= j){ //区间[mid,high]的元素大于等于目标整数
			int _mid = (i+j)/2;
			if(nums[_mid] == nums[mid]){
				range[1] = _mid;
				i = _mid+1;
			}
			else j = _mid-1;
		}
		return range[1]-range[0]+1;
	}

};

int main(){
    Solution c;
	vector<int > nums;
	int A[] = {1,2,3,3,3,3,3,3,4,5};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.CalNumber(nums, 3);
	return 0;
}
