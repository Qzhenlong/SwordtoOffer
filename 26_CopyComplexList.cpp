#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ��ʵ��һ����������һ�������������������У�ÿ����������һ��ָ����һ����ָ�룬����һ��ָ���������NULL��ָ�롣
˼·��
(1)��һ����ϣ��洢ԭ������¡����ӳ���ϵ�����Ƶ�ʱ�临�Ӷȼ��ռ临�Ӷȶ�ΪO(n);
(2)Ϊ�˽��Ϳռ临�Ӷȣ�ʹ��ʱ�临�Ӷ�ΪO(n)���ռ临�Ӷ�ΪO(1), �ɲ�����һ��˼·��
   a. ��ԭ�������ɨ�裬ÿ�ο�¡��ǰ��㣬������¡�����뵽ԭ����; 
   b. ͨ��ǰ���ϵ����O(n)ʱ�临�Ӷȵ�����£���ɿ�¡�ڵ�֮���ϵ�Ĺ���;
   c. �����������������㹹��ԭ����ż����㹹�ɿ�¡���� 
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
		map<ComplexListNode*, ComplexListNode*> r; //ӳ���ϵ
		ComplexListNode *p = head;
		while(p != NULL){ //�½�ÿ����¡���
			ComplexListNode *s = new ComplexListNode(p->val);
			if(p == head) copy = s; //��¡����ͷ���
			r[p] = s;
			p = p->next;
		}
		for(map<ComplexListNode*, ComplexListNode*>::iterator it = r.begin(); it != r.end(); it++){
			it->second->next = (it->first->next == NULL) ? NULL : r[it->first->next]; //���ǿ�ָ��
			it->second->sibling = (it->first->sibling == NULL) ? NULL : r[it->first->sibling];
		}
		return copy;
	}
	ComplexListNode* Clone1(ComplexListNode *head){
		ComplexListNode* copy = NULL;
		if(head == NULL) return copy;
		ComplexListNode *p = head, *q;
		while(p != NULL){ //�½�ÿ����¡���
			ComplexListNode *s = new ComplexListNode(p->val);
			s->next = p->next; //����¡�����뵱ǰ����
			p->next = s;
			p = s->next; //ָ����һ��ԭ������
		}
		p = head;
		while(p != NULL){ //�ڶ���ɨ�裬���siblingָ�빹��
			q = p->sibling;
			p->next->sibling = (q == NULL) ? NULL : q->next;
			p = p->next->next;
		}
		copy = p = head->next; //��¡�����ͷ���
		q = p->next;
		while(q != NULL){ //������ɨ�裬���������������ԭ�������Ҫ���ܸı�ԭ��������ʱ�ɽ��䱣��
			q = p->next->next; //��¼��¡���
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


	

 