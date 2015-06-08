#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ�������������ĵ�����k����㣬��1��ʼ����������1��2��3��4��5��6��������3�����Ϊ4��
˼·�������������ָ��p,q��p����k����Ȼ��p,qͬʱ�ߣ���p������βʱ��q�ڵ�����k�Ľ�㴦
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
	ListNode* LastKthNode(ListNode* head, int k){ 
		ListNode *p,*q;
		p = q = head;
		for(int i = 0; i < k; i++){
			if(p == NULL) return NULL;
			p = p->next;
		}
		while(p != NULL){
			p = p->next;
			q = q->next;
		}
		return q;
	}
};
int main()
{	
  Solution c;
  ListNode *headA;
  ListNode *s;
  int A[] = {6,5,4,3,2,1};
  headA = NULL;
  for(int i = 0; i < sizeof(A)/4; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = A[i];
          s->next = headA;
          headA = s;        
  }
  ListNode *p = headA;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  printf("\n");
  p = c.LastKthNode(headA, 3);
  cout << p->val;

 return 0;
}

	

 