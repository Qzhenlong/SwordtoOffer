#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ������һ�ö�������һ����������ӡ���������н��ֵ֮��Ϊ��������������·���������ĸ���㿪ʼ���£�һֱ��Ҷ����������Ľ���γ�һ��·����
˼·���������������������ÿһ��·����������ֵ�ĺͣ���ÿ��Ҷ�ӽڵ�ʱ�жϵ�ǰ·���ĺ��Ƿ���ڸ�����ֵ��Ϊ��������·�������ڵ�Ҷ�ӽ�����
	  �ж��Ƿ����������������Ҫ��һ��ջ���ݴ��ѱ��������У���������ʱ�����
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
		path.pop_back(); //������һ��㣬ɾ����ǰ���
	}
	//�ǵݹ�ʵ��
	void FindTreePath1(TreeNode *root, int tar){
		stack<TreeNode* > s;
		vector<TreeNode* > path;
		int curSum = 0;
		TreeNode *p = root;		
		s.push(p);
		while(!s.empty()){
			p = s.top(); //ȡջ��
			s.pop(); //ջ��Ԫ�س�ջ
			curSum += p->val; //����֮
			path.push_back(p); //��¼·��			
			if(p->left != NULL) s.push(p->left); //δ����Ҷ�ӽڵ�
			if(p->right != NULL) s.push(p->right);
			
			if(p->left == NULL && p->right == NULL){ //����Ҷ�ӽڵ�
				if(curSum == tar){
					for(int i = 0; i < path.size(); i++) cout << path[i]->val << " ";
					cout << endl;
				}
				p = s.top(); //ȡ��ǰջ��Ԫ��
				TreeNode *q = path.back(); //ȡ�����ʵ�·���ϵĽڵ�
				while(q->right != p){ //���ݵ�·���Ͻڵ㣬ֱ����ǰ�ڵ����δ���ʹ����ҽڵ�ʱ����
					curSum -= q->val; //���ݵ�ǰ��
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





	

 