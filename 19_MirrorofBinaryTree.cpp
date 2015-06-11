#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一棵二叉树，输出它的镜像树。
思路：先序遍历二叉树，如果当前节点有子节点，则交换其子节点。
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
	void TreeMirror(TreeNode* root){
		if(root == NULL) return;
		if(root->left == NULL && root->right == NULL) return;
		TreeNode *p = root->left; //左右交换
		root->left = root->right;
		root->right = p;
		TreeMirror(root->left);
		TreeMirror(root->right);
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
    void printTree(TreeNode *b)
    {
         if(b != NULL){
             cout << b->val << " ";
             printTree(b->left);
             printTree(b->right);
         }
    }
};

int main()
{	
	Solution c;
    TreeNode *rootA, *rootB;
    int A[] = {0,1,2,3,4,5,6,7};
    rootA = c.trans(A,1,sizeof(A)/4);
	c.printTree(rootA); //前序序列：1 2 4 5 3 6 7
	c.TreeMirror(rootA);
	cout << endl;
	c.printTree(rootA); //镜像的前序序列: 1 3 7 6 2 5 4
	return 0;
}



	

 