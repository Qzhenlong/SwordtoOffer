#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
��Ŀ������һ���������飬�жϸ������ǲ���ĳ�����������ĺ���������еĽ�������򷵻�true, ���򷵻�false��������������������������ֻ�����ͬ��
˼·�����ݺ���������е��ص㣬��������һ��Ԫ��ΪBST�ĸ���㣬��������ʼ�㿪ʼɨ�裬ֱ���ҵ��ȸ������ֵi,��i֮ǰ��Ϊ��������֮���Ϊ��������
      ɨ��i�ڵ�֮�������Ƿ���ڱȸ�С��ֵ��û�����������������ִ����ͬ�����������������ж������������򷵻�true,���򷵻�false.
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    //�ݹ�ʵ��
	bool isPostSeqBST(vector<int > A){
		if(A.size() == 0) return false;
		return isBST(A, 0, A.size()-1);
	}
	bool isBST(vector<int > A, int low, int high){
		if(high-low <= 0) return true;
		int index = high-1;
		for(int i = low; i < high; i++)
			if(A[i] > A[high]){ index = i; break;}
		for(int i = index; i < high; i++)
			if(A[i] < A[high]) return false;
		return isBST(A, low, index-1) && isBST(A, index, high-1);
	}
};

int main()
{	
	Solution c;
    int A[] = {7,4,6,5};//{5,7,6,9,11,10,8};
	vector<int > n;
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);	
	cout << c.isPostSeqBST(n);
	return 0;
}




	

 