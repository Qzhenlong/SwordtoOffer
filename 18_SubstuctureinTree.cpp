#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ���������ö�����A��B���ж�B�Ƿ�ΪA���ӽṹ��
˼·��
��1���ݹ��㷨������������ÿһ���ڵ㣬�ж�ÿһ�����Ϊ���������Ƿ����B�����򷵻�true, ���򷵻�false
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
	bool isSubTree(TreeNode *A, TreeNode *B){
		bool ans = false;
		if(A != NULL && B != NULL){
			if(A->val == B->val) ans = isSubTreeSub(A, B);
			if(!ans) ans = isSubTree(A->left, B);
			if(!ans) ans = isSubTree(A->right, B);
		}
		return ans;
	}
	bool isSubTreeSub(TreeNode *SA, TreeNode *SB){
		if(SB == NULL) return true;
		if(SA == NULL) return false;
		if(SA->val != SB->val) return false;
		else return isSubTreeSub(SA->left, SB->left) && isSubTreeSub(SA->right, SB->right);
	}
    TreeNode * trans(int A[], int i, int n)
    {
        TreeNode *b;
        if(i >= n) return NULL;
        b = new TreeNode(A[i]);
        b->left = trans(A, 2*i, n);
        b->right = trans(A, 2*i+1, n);
        return b;
    }
};

int main()
{	
	Solution c;
    TreeNode *rootA, *rootB;
    int A[] = {0,1,2,3,4,5,6,7,8,9};
	int B[] = {0,1,2,3};
    rootA = c.trans(A,1,sizeof(A)/4);
	rootB = c.trans(B,1,sizeof(B)/4);
	cout << c.isSubTree(rootA, rootB);
	return 0;
}


	

 