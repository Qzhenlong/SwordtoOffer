#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ������һ��Ӣ�ľ��ӣ���ת�����еĵ���˳�򣬵��������ַ���˳�򲻱䣬�磺I am a student
	 �任Ϊ��student. a am I"
˼·�����η�ת��һ�����巭ת��һ�ξֲ���ת����

��أ�����ѭ����λ(�ֲ���ת�����巭ת���� LeetCode�е�Reverse Words in a String.
*/

class Solution {
public:
    void reverseWords(string &s) {
		int i, j=0, n = s.size();
		for(i = 0; i < n/2; i++){ //���巭תһ��
			char tmp = s[i];
			s[i] = s[n-i-1];
			s[n-i-1] = tmp;
		}
		i = 0;
		while(j <= n){ //�ֲ���תһ��
			if(j < n && s[j] != ' ') j++;
			else{
				for(int k = 0; k < (j-i)/2; k++){
					char tmp = s[i+k];
					s[i+k] = s[j-k-1];
					s[j-k-1] = tmp;
				}
				j++;
				i = j;
			}
		}
    }
};

int main()
{
	Solution c;
	string s = " the sky is blue";
	cout << s << endl;
	c.reverseWords(s);
	cout << s << endl;
	return 0;
}

