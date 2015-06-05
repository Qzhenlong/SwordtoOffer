#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入某二叉树的前序和中序序列，重建该二叉树，假设两个序列中不包含相同的数字。
思路：递归构建
相关：输入中序和后序序列，重建二叉树。
*/
struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution{
public:
	//先序与中序构建
	TreeNode* PreIn_Rebuild(int *pre, int *in, int n){
		if(n <= 0) return NULL;
		TreeNode *s;
		int *p, k;
		//s = new TreeNode(*pre);
		//cout << s->val << endl;
		s = (TreeNode*)malloc(sizeof(TreeNode));
		s->val = *pre;
		for(p = in; p < in+n; p++)
			if(*p == *pre) break; 
		k = p-in;
		s->left = PreIn_Rebuild(pre+1, in, k);
		s->right = PreIn_Rebuild(pre+k+1, in+k+1, n-k-1);
		return s;
	}
	//中序与后序构建
	TreeNode* PostIn_Rebuild(int *post, int *in, int n){
		if(n <= 0) return NULL;
		TreeNode *s = new TreeNode(*(post+n-1));
		int *p,k;
		for(p = in; p < in+n; p++)
			if(*p == *(post+n-1)) break;
		k = p-in;
		s->left = PostIn_Rebuild(post, in, k);
		s->right = PostIn_Rebuild(post+k, in+k+1, n-k-1);
		return s;
	}
	//层次遍历算法 
	vector<vector<int > > levelOrder(TreeNode* root) {
        vector<vector<int > > ans;
        if(root == NULL) return ans;
        int MAX = 65535;
        TreeNode *qu[MAX];
        int rear, front;
        front = rear = -1;
        qu[++rear] = root;
        rear = (rear + 1) % MAX;
        qu[rear] = NULL;
        vector<int > cur;
        TreeNode *p;
        while(abs(front-rear) > 1)
        {
                   front = (front + 1) % MAX;
                   p = qu[front];
                   if(p == NULL)
                   {
                        rear = (rear+1) % MAX;
                        qu[rear] = NULL;
                        ans.push_back(cur);
                        cur.clear();
                        continue;
                   }
                   cur.push_back(p->val);
                   if(p->left != NULL)
                   {
                        rear = (rear+1) % MAX;
                        qu[rear] = p->left;
                   }
                   if(p->right != NULL)
                   {
                        rear = (rear+1) % MAX;
                        qu[rear] = p->right;
                   } 
        }
        ans.push_back(cur);
        for(int i = 0; i < ans.size(); i++){
                for(int j = 0; j < ans[i].size(); j++)
                        cout << ans[i][j] << " ";
                cout << "" << endl;
                }
        return ans;
    }

};

int main()
{
  Solution c;
  TreeNode *root;
  int pre[] = {1,2,4,7,3,5,6,8};
  int in[]  = {4,7,2,1,5,3,8,6};
  int post[] = {7,4,2,5,8,6,3,1};
  root = c.PreIn_Rebuild(pre, in, 8);
  cout << "Pre+In Rebuild: " << endl;
  c.levelOrder(root);    
  root = c.PostIn_Rebuild(post, in, 8);
  cout << "Post+In Rebuild: " << endl;
  c.levelOrder(root);

  return 1;   
}
