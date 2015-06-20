#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
题目：输入一棵二叉搜索树，将该树转换成一个排序的双向链表，要求不能创建新的结点，只能调整树中结点的指向。
思路：中序遍历二叉搜索树即为有序序列，将树的左右指针转换成双向链表的前后指针, 空间复杂度O(n)，时间复杂度O(n);
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    //非递归实现
	TreeNode* ConvertBSTtoList(TreeNode *root){
		if(root == NULL || (root->left == NULL && root->right == NULL)) return root;
		stack<TreeNode* > s;
		TreeNode *p = root, *head = NULL, *q;
		while(p != NULL){ s.push(p); p = p->left; }
		while(!s.empty()){
			p = s.top();
			s.pop();
			TreeNode *t = p->right;
			if(head == NULL){ head = p; q = p; }
			else {
				q->right = p;
				p->left = q;
				q = p;
			}
		    while(t != NULL){ s.push(t); t = t->left; }		
		}
		q->right = NULL;
		return head;
	}
	//递归实现
	TreeNode* ConvertBSTtoList1(TreeNode *root){
		TreeNode *head, *tail=NULL;
		toList(root, tail);
		while(tail->left != NULL) tail = tail->left;
		head = tail;
		return head;
	}
	void toList(TreeNode *root, TreeNode *&last){
		if(root == NULL) return;
		else{
			TreeNode *b = root;
			if(b->left != NULL) toList(b->left, last);
			if(last == NULL) last = b;
			else{
				last->right = b;
				b->left = last;
				last = b;
			}
			if(b->right != NULL) toList(b->right, last);
		}
	}
	TreeNode* tran(int A[], int n, int i){
		if(i >= n) return NULL;
		TreeNode *b = new TreeNode(A[i]);
		b->left = tran(A, n, 2*i);
		b->right = tran(A, n, 2*i+1);
		return b;
	}
	void Inprint(TreeNode *b){
		if(b != NULL){
			Inprint(b->left);
			cout << b->val << " ";
			Inprint(b->right);
		}
	}

};
int main()
{	
  Solution c;
  TreeNode *root = NULL, *head = NULL;
  int A[] = {0, 10, 6, 14, 4, 8, 12, 16};
  root = c.tran(A, sizeof(A)/4, 1);
  c.Inprint(root);
  cout << endl;
  head = c.ConvertBSTtoList1(root);
  while(head != NULL){
	cout << head->val << " ";
	head = head->right;
  }
 return 0;
}



	

 