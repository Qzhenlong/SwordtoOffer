#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入n个整数，找出其中最小的k个数。例如输入4，5，1，6，2，7，3，8这8个数，则最小的4个数为1，2，3，4
思路：
（1）直接选择排序思想，每次查找最小元素，时间复杂度O(kn)
（2）考虑快排思想，结合查找第k大元素的思路，可得最小k个元素,复杂度O(n)
（3）书上方法：创建一个大小为k的容器来存在最小k个元素，思路与（1）相似，不过是将当前元素与容器中的最大值进行对比，如果利用二叉树存储，则查找复杂度为O(logk),
	总复杂度可达到O(nlogk)。
*/

class Solution{
public:
	//思路1比较简单，直接实现思路2，复杂度O(n)
	vector<int > getKelements(vector<int > nums, int k){
		vector<int > ans;
		int low = 0, high = nums.size()-1;
		int index = partition(nums, low, high);
		while(index != k-1){
			if(index > k-1) high = index - 1;
			else low = index + 1;
			index = partition(nums, low, high);
		}
		for(int i = 0; i <= index; i++) ans.push_back(nums[i]);
		return ans;
	}
	int partition(vector<int > &A, int low, int high){
		int i = low, j = high;
		if(low < high){
			int tmp = A[i];
			while(i != j){
				while(i < j && tmp <= A[j]) j--;
				A[i] = A[j];
				while(i < j && tmp > A[i]) i++;
				A[j] = A[i];
			}
			A[i] = tmp;
		}
		return i;
	}
	
};

int main(){
	Solution c;
	vector<int > n;
	int A[] = {4,5,1,6,2,7,3,8};
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	vector<int > ans = c.getKelements(n, 4);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
