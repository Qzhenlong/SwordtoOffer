#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：输入一棵二叉树和一个整数，打印出二叉树中结点值之和为输入整数的所有路径，从树的根结点开始往下，一直到叶结点所经过的结点形成一条路径。
思路：先序遍历二叉树，计算每一条路径上所有数值的和，到每个叶子节点时判断当前路径的和是否等于给定数值则为符合条件路径，由于到叶子结点才能
	  判断是否满足条件，因此需要用一个栈来暂存已遍历的序列，满足条件时输出。
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
	void FindTreePath(TreeNode *root, int tar){
		vector<int > path;
		int curSum = 0;
		TreeTraversal(root, path, curSum, tar);
	}
	void TreeTraversal(TreeNode *p, vector<int > &path, int curSum, int tar){
		path.push_back(p->val);
		curSum += p->val;
		if(p->left == NULL && p->right == NULL){
			if(curSum == tar){
				for(vector<int >:: iterator it = path.begin(); it != path.end(); it++) cout << *it << " ";
				cout << endl;
			}
		}
		if(p->left != NULL) TreeTraversal(p->left, path, curSum, tar);
		if(p->right != NULL) TreeTraversal(p->right, path, curSum, tar);
		path.pop_back(); //返回上一结点，删除当前结点
	}
	//非递归实现
	void FindTreePath1(TreeNode *root, int tar){
		stack<TreeNode* > s;
		vector<TreeNode* > path;
		int curSum = 0;
		TreeNode *p = root;		
		s.push(p);
		while(!s.empty()){
			p = s.top(); //取栈顶
			s.pop(); //栈顶元素出栈
			curSum += p->val; //访问之
			path.push_back(p); //记录路径			
			if(p->left != NULL) s.push(p->left); //未到达叶子节点
			if(p->right != NULL) s.push(p->right);
			
			if(p->left == NULL && p->right == NULL){ //到达叶子节点
				if(curSum == tar){
					for(int i = 0; i < path.size(); i++) cout << path[i]->val << " ";
					cout << endl;
				}
				p = s.top(); //取当前栈顶元素
				TreeNode *q = path.back(); //取最后访问的路径上的节点
				while(q->right != p){ //回溯到路径上节点，直到当前节点存在未访问过的右节点时结束
					curSum -= q->val; //回溯当前和
					path.pop_back(); //
					q = path.back();
				}
			}
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
    TreeNode *rootA, *rootB;
    int A[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15}; //{0,10, 5, 12, 4, 7};
    rootA = c.trans(A,1,sizeof(A)/4);
	c.FindTreePath(rootA, 22);
	cout << endl;
	c.FindTreePath(rootA, 22);
	return 0;
}





	

 