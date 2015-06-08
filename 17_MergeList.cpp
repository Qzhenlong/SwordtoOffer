#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入两个递增链表，合并两个链表，新链表仍递增排列。
思路：归并排序, 尾插法
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
	//非递归实现
	ListNode* mergeList(ListNode* l1, ListNode* l2){ 
		ListNode *l3, *p;
		l3 = NULL;
		while(l1 != NULL && l2 != NULL){
			if(l1->val < l2->val){
				if(l3 == NULL){ l3 = l1; p = l3; }
				else{ p->next = l1; p = l1; }
				l1 = l1->next;
			}
			else {
				if(l3 == NULL){ l3 = l2; p = l3; }
				else{ p->next = l2; p = l2; }
				l2 = l2->next;			
			}
		}
		while(l1 != NULL){
			p->next = l1;
			p = l1;
			l1 = l1->next;
		}
		while(l2 != NULL){
			p->next = l2;
			p = l2;
			l2 = l2->next;
		}
		p->next = NULL;
		return l3;
	}
	//递归实现
	ListNode *mergeList1(ListNode *l1, ListNode *l2){
		if(l1 == NULL) return l2;
		if(l2 == NULL) return l1;
		ListNode *l3;
		if(l1->val < l2->val){
			l3 = l1;
			l3->next = mergeList1(l1->next, l2);
		}
		else{
			l3 = l2;
			l3->next = mergeList1(l1, l2->next);
		}
		return l3;
	}
};
int main()
{	
  Solution c;
  ListNode *headA,*headB;
  ListNode *s;
  int A[] = {4,3,2,1};

  int An = 2;
  headA = NULL;
  headB = NULL;
  for(int i = 0; i < sizeof(A)/4; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = A[i];
          s->next = headA;
          headA = s;  
  }
    for(int i = 0; i < sizeof(A)/4; i++){
          s = (ListNode *)malloc(sizeof(ListNode));
          s->val = A[i];
          s->next = headB;
          headB = s;     
  }
  ListNode *p = headA;
  ListNode *q = headB;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  while(q != NULL){
          cout << q->val << " ";
          q = q->next;
  }
  
  printf("\n");
  p = c.mergeList1(headA,headB);
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
 return 0;
}

	

 