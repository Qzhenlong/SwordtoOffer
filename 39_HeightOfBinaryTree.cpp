#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
��Ŀ������һ�ö������ĸ���㣬����������ߡ�
˼·���������������������ȼ�Ϊ����

׷�ӣ��ж��Ƿ�Ϊ����ƽ������
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
	bool isBalanceTree(TreeNode *root){ //�������¼������߻��ظ������˺ܶ��㣬�ظ������˶�μ���߶ȵĺ���
		if(root == NULL) return true;
		if(abs(getHeight(root->left)-getHeight(root->right)) > 1) return false;
		return (isBalanceTree(root->left) && isBalanceTree(root->right));
	}
	bool isBalanceTree1(TreeNode *root){ //�������ϼ������ߣ�ÿ�μ�¼�������ߣ�ֻ��Ҫ����һ�μ��ɣ��߱������ж�
		int h = 0;
		return isBalance(root, h);
	}
	bool isBalance(TreeNode *b, int &height){
		if(b == NULL){
			height = 0;
			return true;
		}
		int lh,rh; //���������������ߣ� ���ظ����������ߵĺ���
		if(isBalance(b->left, lh) && isBalance(b->right, rh)){
			if(abs(lh-rh) <= 1){ //ƽ��
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
