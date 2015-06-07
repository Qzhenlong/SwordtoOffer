#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ�������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý����
˼·��Ҫ���ڲ��ܸı�ڵ�ȡֵ������£�Ҫɾ��һ���ڵ㣬�����������ſ���֪����ǰ�̽ڵ㣬���Ӷ�ΪO(n)
	  ���Ҫ��O(1)�����ɾ���ڵ����Ҫ�ı�ڵ㣬��Ҫɾ���ڵ����һ�ڵ�ֵ������ǰ�ڵ㣬��ɾ����һ�ڵ㡣
	  ���Ӷ�ΪO(1)�������������һ���ڵ㣬û�к�̽ڵ㣬ֻ�ܱ�������ɾ��������ƽ�����ӶȻ���O(1).
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
		if(dnode->next != NULL){ //�������һ���ڵ�
			p = dnode;
			dnode = dnode->next;
			p->val = dnode->val;
			q = dnode->next;
			p->next = q;
			free(dnode);
			dnode = NULL; //��ֹ��;ָ��
		}
		else if(dnode == head){ //ֻ��һ��ͷ�ڵ�
			head = NULL;
			free(dnode);
			dnode = NULL;
		}
		else if(dnode->next == NULL){ //���һ���ڵ�
			p = q = head;
			while(p != dnode){ q = p; p = p->next;}
			p = p->next;
			q->next = p;
			free(dnode);
			dnode = NULL; //��ֹ��;ָ��
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

	

 