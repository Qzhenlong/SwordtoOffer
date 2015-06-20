#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ������һ�ö�����������������ת����һ�������˫������Ҫ���ܴ����µĽ�㣬ֻ�ܵ������н���ָ��
˼·���������������������Ϊ�������У�����������ָ��ת����˫�������ǰ��ָ��, �ռ临�Ӷ�O(n)��ʱ�临�Ӷ�O(n);
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution{
public:
    //�ǵݹ�ʵ��
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
	//�ݹ�ʵ��
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



	

 