#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
题目：输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历序列的结果，是则返回true, 否则返回false。假设输入数组的任意两个数字互不相同。
思路：根据后序遍历序列的特点，数组的最后一个元素为BST的根结点，从数组起始点开始扫描，直到找到比根结点大的值i,则i之前的为左子树，之后的为右子树。
      扫描i节点之后序列是否存在比根小的值，没有则继续对左右子树执行相同操作，当所有子序列都满足条件，则返回true,否则返回false.
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    //递归实现
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




	

 