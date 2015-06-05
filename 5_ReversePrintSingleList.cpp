#include<iostream>
#include<vector>
#include<stack>
using namespace std;
/*
��Ŀ������һ������ͷ��㣬��β��ͷ��ӡÿ���ڵ�ֵ��
˼·��
��1��������Ըı�����ṹ���ɽ���������������
��2��������ı�����ṹ����ʹ��һ��ջ����Žڵ�ֵ�����������Ҫ����һ��ջ�ռ�
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) { }
};
class Solution{
public:
	vector<int > ReversePrint(ListNode *head){ //(1)
		vector<int > ans;
		if(head == NULL) return ans;
		ListNode *p, *q;
		p = head->next;
		head->next = NULL;
		while(p != NULL){
			q = p->next;
			p->next = head;
			head = p;
			p = q;
		}
		while(head != NULL){
			ans.push_back(head->val);
			head = head->next;
		}
		return ans;
	}
	vector<int > ReversePrint1(ListNode *head){ //(2)
		stack<int > s;
		vector<int > ans;
		while(head != NULL){
			s.push(head->val);
			head = head->next;
		}
		while(!s.empty()){
			ans.push_back(s.top());
			s.pop();
		}
		return ans;
	}
};

int main(){
	Solution c;
	ListNode *head = NULL;
	int A[] = {4,3,2,1};
	for(int i = 0; i < sizeof(A)/4; i++){
		ListNode *s = new ListNode(A[i]);
		s->next = head;
		head = s;
	}
	ListNode *p = head; 
	while(p != NULL){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
	
	//vector<int > ans = c.ReversePrint(head);
	vector<int > ans = c.ReversePrint1(head);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	cout << endl;

	return 0;
}
