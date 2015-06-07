#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数位于数组前半部分，所有偶数位于后半部分
思路：采用两个头尾指针i,j向数组中间夹逼，设定一个临时变量暂存中间值，
1）当A[i]为偶数，A[j]也为偶数时，j--；
2）当A[j]为奇数，A[i]也为奇数时，i++;
3）当A[i]为偶数，A[j]为奇数时，交换；
4）当i==j时结束。
*/
class Solution{
public:
	void reorderArray(vector<int > &A){
		int i = 0, j = A.size()-1;
		while(i < j){
			if(A[i]%2 == 0 && A[j]%2 == 1){
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
			if(A[i]%2 == 1) i++;
			if(A[j]%2 == 0) j--;
		}
	}

};
int main()
{	
	Solution c;
	int A[] = {1,2};
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++){
		num.push_back(A[i]);
		cout << A[i] << " ";
	}
	cout << endl;
	c.reorderArray(num);
	for(int i = 0; i < num.size(); i++)
		cout << num[i] << " ";
	
	return 0;
}

	

 