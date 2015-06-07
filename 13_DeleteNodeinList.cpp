#include<iostream>
#include<vector>
using namespace std;
/*
题目：给定单链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结果。
思路：要是在不能改变节点取值的情况下，要删除一个节点，必须遍历链表才可能知道其前继节点，复杂度为O(n)
	  如果要在O(1)情况下删除节点就需要改变节点，把要删除节点的下一节点值赋给当前节点，再删除下一节点。
	  复杂度为O(1)，对于链表最后一个节点，没有后继节点，只能遍历才能删除，但是平均复杂度还是O(1).
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
	void DeleteNode(ListNode* &head, ListNode* dnode){ 
		ListNode *p,*q;
		if(head == NULL || dnode == NULL) return;
		if(dnode->next != NULL){ //不是最后一个节点
			p = dnode;
			dnode = dnode->next;
			p->val = dnode->val;
			q = dnode->next;
			p->next = q;
			free(dnode);
			dnode = NULL; //防止迷途指针
		}
		else if(dnode == head){ //只有一个头节点
			head = NULL;
			free(dnode);
			dnode = NULL;
		}
		else if(dnode->next == NULL){ //最后一个节点
			p = q = head;
			while(p != dnode){ q = p; p = p->next;}
			p = p->next;
			q->next = p;
			free(dnode);
			dnode = NULL; //防止迷途指针
		}

	}
};
int main()
{	
  Solution c;
  ListNode *headA;
  ListNode *s;
  int A[] = {1,2,3,4};

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
  p = headA;
  for(int i = 0; i < 3; i++) p = p->next;
  c.DeleteNode(headA, p);
  p = headA;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }

 return 0;
}

	

 