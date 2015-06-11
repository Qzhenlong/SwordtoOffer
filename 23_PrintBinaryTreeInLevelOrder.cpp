#include<iostream>
#include<vector>
#include<queue>
using namespace std;
/*
题目：从上往下打印二叉树的每个结点，同一层的结点按照从左到右的顺序打印。
思路：二叉树的层次遍历算法，使用队列实现
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
	void LevelPrintTree(TreeNode *root){
		queue<TreeNode* > q;
		if(root == NULL) return;
		q.push(root);
		while(!q.empty()){
			TreeNode *p = q.front();
			q.pop();
			cout << p->val << " ";
			if(p->left != NULL) q.push(p->left);
			if(p->right != NULL) q.push(p->right);
		}
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
    TreeNode *rootA;
    int A[] = {0,1,2,3,4,5,6,7,8,9};
    rootA = c.trans(A,1,sizeof(A)/4);
	c.LevelPrintTree(rootA);
	return 0;
}



	

 