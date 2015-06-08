#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ�����������ת�������
˼·����ǰ����ɨ�裬����ͷ�巨���췴ת����
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
	ListNode* reverseList(ListNode* head){ 
		ListNode *p, *q;
		if(head == NULL || head->next == NULL) return head;
		p = head->next;
		head->next = NULL;
		while(p != NULL){
			q = p->next;
			p->next = head;
			head = p;
			p = q;
		}
		return head;
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
  p = c.reverseList(headA);
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }  
 return 0;
}

	

 