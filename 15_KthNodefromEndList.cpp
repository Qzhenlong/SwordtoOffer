#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个链表，输出链表的倒数第k个结点，从1开始记数，比如1，2，3，4，5，6，倒数第3个结点为4。
思路：定义两个结点指针p,q，p先走k步，然后p,q同时走，当p到链表尾时，q在倒数第k的结点处
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

	

 