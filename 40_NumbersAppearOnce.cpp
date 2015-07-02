#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
题目：一个整型数组中除了两个数字之外，其它数字都出现了两次，请写程序找出这两个出现一次的数字，要求时间复杂度O(n)，空间复杂度O(1)
思路：
（1）如果不要求空间复杂度，使用一张哈希表记录次数即可，空间和时间都为O(n)
（2）考虑O(1)的空间复杂度，注意到其它数字都出现两次，如果全部数字异或会得到两个不同数字异或的结果（相同数字异或为0），记为x
	 x肯定有为1的比特，根据该比特将原数组进行划分，划分后会使两个不同的数落入不同集合，而相同的数必然落进相同集合，因为该位为1，相同数字必然在该位上同时为0或1，
	 只有两个不同的数字在该位上不同，得到两个子数组后，分别将子数组所有元素异或即可得到两个不同数字。
*/
class Solution{
public:
	vector<int > getTwoDifNumbers(vector<int > nums){
		vector<int > ans(2, 0);
		int x = 0, bit = 0;
		for(int i = 0; i < nums.size(); i++) x ^= nums[i];
		for(bit = 0; bit < sizeof(x)*4; bit++)
			if(((x >> bit) & 0x01) > 0) break;
		for(int i = 0; i < nums.size(); i++){
			if(((nums[i] >> bit) & 0x01) > 0) ans[0] ^= nums[i];
			else ans[1] ^= nums[i];
		}
		return ans;
	}
};

int main(){
	Solution c;
	int A[] = {2,4,3,6,3,2,5,5};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<int > ans = c.getTwoDifNumbers(nums);
	cout << ans[0] << endl;
	cout << ans[1] << endl;
	return 0;
}
