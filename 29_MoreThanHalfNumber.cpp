#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：数组中有一个数字出现的次数超过数组的一半，请找出这个数字。
思路: 
（1）用哈希表记录数字出现的次数，时间和空间复杂度都为O(n)；
（2）改进思路(1)，事实上，不需要存储所有数字出现的次数，只需要保存一个次数及数值即可，当保存的数字与上次的数字相同，
	则次数加1，否则减1，当次数为0，则更新数字，就是求最值的思路，时间复杂度为O(n),空间复杂度为O(1)；
（3）转换成求第n/2大的数，肯定为超过一半的数字，利用快排的Partition可快速查找，时间复杂度为O(n),空间复杂度为O(1)。

*/
class Solution{
public:
	int find1(vector<int > nums){ //下面都暂时假设存在出现次数超过一半的数字,且数组不为空
		map<int, int> c; //哈希表记录数字
		for(int i = 0; i < nums.size(); i++) c[nums[i]]=0;
		for(int i = 0; i < nums.size(); i++) c[nums[i]]++;
		for(map<int, int>::iterator it = c.begin(); it != c.end(); it++)
			if(it->second > nums.size()/2) return it->first;
	}
	int find2(vector<int > nums){
		int c = 1, n = nums[0];
		for(int i = 1; i < nums.size(); i++){
			if(n == nums[i]) c++;
			else c--;
			if(c <= 0){
				n = nums[i];
				c = 1;
			}
		}
		return n;
	}
	int find3(vector<int > nums){
		int k = nums.size() >> 1;
		if(nums.size() <= 0) return nums[0];
		return findKth(nums, k); //假定存在
	}
	int findKth(vector<int > A, int k){
		int low = 0, high = A.size()-1, n = A.size();
		int index = partition(A, low, high);
		while(index != (n-k)){ 
			if(index < (n-k)) low = index + 1;
			else high = index - 1;
			index = partition(A, low, high);
		}
		return A[index];
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
int main()
{	
	Solution c;
	vector<int > n;
	int A[] = {1};
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.find1(n) << endl;
	cout << c.find2(n) << endl;
	cout << c.find3(n) << endl;
	return 0;
}


	

 