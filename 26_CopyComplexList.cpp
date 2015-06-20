#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：实现一个函数复制一个复杂链表，复杂链表中，每个结点除了有一个指向下一结点的指针，还有一个指向任意结点或NULL的指针。
思路：
(1)用一个哈希表存储原结点与克隆结点的映射关系，则复制的时间复杂度及空间复杂度都为O(n);
(2)为了降低空间复杂度，使得时间复杂度为O(n)，空间复杂度为O(1), 可采用另一个思路：
   a. 对原链表进行扫描，每次克隆当前结点，并将克隆结点插入到原结点后; 
   b. 通过前后关系可在O(n)时间复杂度的情况下，完成克隆节点之间关系的构建;
   c. 拆分两个链表，奇数结点构成原链表，偶数结点构成克隆链表。 
*/
struct ComplexListNode{
	int val;
	ComplexListNode *next;
	ComplexListNode *sibling;
	ComplexListNode(int x) : val(x), next(NULL), sibling(NULL) {}
};
class Solution{
public:
	ComplexListNode* Clone(ComplexListNode *head){
		ComplexListNode* copy = NULL;
		if(head == NULL) return copy;
		map<ComplexListNode*, ComplexListNode*> r; //映射关系
		ComplexListNode *p = head;
		while(p != NULL){ //新建每个克隆结点
			ComplexListNode *s = new ComplexListNode(p->val);
			if(p == head) copy = s; //克隆链表头结点
			r[p] = s;
			p = p->next;
		}
		for(map<ComplexListNode*, ComplexListNode*>::iterator it = r.begin(); it != r.end(); it++){
			it->second->next = (it->first->next == NULL) ? NULL : r[it->first->next]; //考虑空指针
			it->second->sibling = (it->first->sibling == NULL) ? NULL : r[it->first->sibling];
		}
		return copy;
	}
	ComplexListNode* Clone1(ComplexListNode *head){
		ComplexListNode* copy = NULL;
		if(head == NULL) return copy;
		ComplexListNode *p = head, *q;
		while(p != NULL){ //新建每个克隆结点
			ComplexListNode *s = new ComplexListNode(p->val);
			s->next = p->next; //将克隆结点插入当前结点后
			p->next = s;
			p = s->next; //指向下一个原链表结点
		}
		p = head;
		while(p != NULL){ //第二次扫描，完成sibling指针构建
			q = p->sibling;
			p->next->sibling = (q == NULL) ? NULL : q->next;
			p = p->next->next;
		}
		copy = p = head->next; //克隆链表的头结点
		q = p->next;
		while(q != NULL){ //第三次扫描，拆分链表，这里舍弃原链表，如果要求不能改变原链表，则拆分时可将其保留
			q = p->next->next; //记录克隆结点
			p->next = q; 
			p = q;
			q = p->next;
		}
		return copy;
	}	

};
int main()
{	
  Solution c;
  ComplexListNode *headA,*headB;
  ComplexListNode *s;
  int A[] = {4,3,2,1};
  headA = NULL;
  for(int i = 0; i < sizeof(A)/4; i++){
          s = new ComplexListNode(A[i]);
          s->next = headA;
          headA = s;  
  }
  ComplexListNode *p = headA;
  p->sibling = p->next->next;
  cout << p->sibling->val << endl;
  p = c.Clone1(headA);
  cout << p->sibling->val << endl;
  while(p != NULL){
          cout << p->val << " ";
          p = p->next;
  }
  
 return 0;
}


	

 