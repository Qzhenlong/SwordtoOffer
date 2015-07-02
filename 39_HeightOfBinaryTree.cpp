#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
题目：输入一棵二叉树的根结点，求该树的树高。
思路：遍历二叉树，求最大深度即为树高

追加：判断是否为二叉平衡树？
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
	int getHeight(TreeNode *root){
		if(root == NULL) return 0;
		int lh = getHeight(root->left);
		int rh = getHeight(root->right);
		return (lh < rh) ? lh+1 : rh+1;
		
	}
	bool isBalanceTree(TreeNode *root){ //至顶向下计算树高会重复遍历了很多结点，重复调用了多次计算高度的函数
		if(root == NULL) return true;
		if(abs(getHeight(root->left)-getHeight(root->right)) > 1) return false;
		return (isBalanceTree(root->left) && isBalanceTree(root->right));
	}
	bool isBalanceTree1(TreeNode *root){ //至底向上计算树高，每次记录子树树高，只需要遍历一次即可，边遍历边判断
		int h = 0;
		return isBalance(root, h);
	}
	bool isBalance(TreeNode *b, int &height){
		if(b == NULL){
			height = 0;
			return true;
		}
		int lh,rh; //计算左右子树树高， 不重复调用求树高的函数
		if(isBalance(b->left, lh) && isBalance(b->right, rh)){
			if(abs(lh-rh) <= 1){ //平衡
				height = (lh>rh) ? lh+1 : rh+1;
				return true;
			}
		}
		return false;
	}
};

int main(){
    Solution c;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	cout << c.getHeight(root) << endl;
	cout << c.isBalanceTree(root) << endl;
	cout << c.isBalanceTree1(root) << endl;
	return 0;
}
