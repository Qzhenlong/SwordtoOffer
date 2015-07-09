#include<iostream>
#include<vector>
using namespace std;
/*
题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这一张牌是不是连续，扑克中2-10为数字本身，A为1，J-K为11，12，13， 大小王可看成任意数字
思路：将大小王记为0， 那么抽到的5张牌对应一个数组，对数组排序，前后两个数字之差为1，即是顺子
	  如果包含一个0，那么其它部分可以包含差为2的数字一对，如果有两个0，可以包含差为2的数字两对，或者差为3的数字一对。
*/
class Solution{
public:
	bool isContinous(vector<int > nums){
		sort(nums.begin(), nums.end());
		int zero = 0;
		for(int i = 0; i < 2; i++)
			if(nums[i] == 0) zero++;
		for(int i = zero; i < nums.size()-1; i++){
			int div = nums[i+1]-nums[i];
			if(div > 3) return false; //差为3以上，不可能是顺子
			if(div == 0) return false; //相同数字，不可能是顺子
			if(div == 3){
				if(zero < 2) return false;
				else zero = 0; //王的数量清零
			}
			if(div == 2){
				if(zero < 1) return false;
				else zero--; //王的数量减1
			}
		}
		return true;
	}
	
};

int main(){
	Solution c;
	int A[] = {0, 0, 4, 6, 7};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.isContinous(nums);
	return 0;
}
