#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ�����飬������һ���������������������һ�������顣������������ĺ͵����ֵ��ʱ�临�Ӷ�Ҫ��ΪO(n)
˼·����̬�滮˼�룬������ΪA��f(i)Ϊi֮ǰ������͵����ֵ����״̬ת�Ʒ��̣�f(i)=max(f(i-1)+A[i], A[i]);
*/

class Solution{
public:
	int MaxSum(vector<int > A){
		if(A.size() == 0) return 0;
		int maxSum = A[0], curMax = A[0];
		for(int i = 1; i < A.size(); i++){
			curMax = max(curMax+A[i], A[i]);
			maxSum = max(curMax, maxSum);
		}
		return maxSum;
	}
	
};

int main(){
	Solution c;
	vector<int > n;
	int A[] = {1,-2,3,10,-4,7,2,-5};
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.MaxSum(n);
	return 0;
}
