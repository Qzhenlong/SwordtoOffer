#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
��Ŀ���������������ҳ����ǵĵ�һ��������㡣
˼·��������������ʿ�֪����������ֻ������һ��������㣬����ⲽ�����£�
1���ȶ���������ɨ��һ�Σ��õ����Գ���n,m����l = |n-m|.
2���ϳ�����������l����Ȼ��϶̵������ٿ�ʼ�ߣ��������ǹ������
��
��������ָ��p,qͬʱ������������㿪ʼ�ߣ���һ������β��ʱ���ٶ���һ��ָ��tָ����������Ǹ�����ͷ�������ߣ�����һ��ָ�뵽���յ�ʱ��t���﹫�����
*/
struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
public:
	ListNode* getCommonNode(ListNode *headA, ListNode *headB){
		int n = 0, m = 0 , l = 0;
		ListNode *p = headA, *q = headB;
		while(p != NULL){ n++; p = p->next; }
		while(q != NULL){ m++; q = q->next; }
		l = abs(n-m);
		p = n > m? headA : headB; //ȡ�ϳ�����������l��
		q = (p == headB) ? headA : headB;
		for(int i = 0; i < l; i++) p = p->next;
		while(p != NULL && q != NULL){
			if(p == q) return p;
			p = p->next;
			q = q->next;
		}
		return NULL;
	}

};

int main(){
  Solution c;
  ListNode *p = NULL,*q = NULL;
  ListNode *headA = NULL, *headB = NULL;
  int A[] = {1,2,3,4,5,6};
  int B[] = {2,6,4,5};
  for(int i = 0; i < sizeof(A)/4; i++){
		ListNode *s = new ListNode(A[i]);
		if(headA == NULL) headA = p = s;
		else{
			p->next = s;
			p = s;
		}
  }
  p->next = NULL;
  p = headA->next->next;
  ListNode *s = new ListNode(8);
  headB = s;
  headB->next = p;
  p = headA;
  q = headB;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  printf("\n");
  while(q != NULL){ 
          cout << q->val << " ";
          q = q->next;
  }
  printf("\nIntersection Node:\n");
  p = c.getCommonNode(headA,headB);
  cout<< p->val << endl;
	return 0;
}
