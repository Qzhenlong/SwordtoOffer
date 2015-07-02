#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
题目：输入两个链表，找出它们的第一个公共结点。
思路：根据链表的性质可知，两个链表只可能有一个公共结点，则求解步骤如下：
1）先对两个链表扫描一次，得到各自长度n,m，令l = |n-m|.
2）较长的链表先走l步，然后较短的链表再开始走，相遇则是公共结点
或
定义两个指针p,q同时从两个链表起点开始走，当一个到达尾端时，再定义一个指针t指向已走完的那个链表头，继续走，当另一个指针到达终点时，t到达公共结点
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
		p = n > m? headA : headB; //取较长的链表先走l步
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
