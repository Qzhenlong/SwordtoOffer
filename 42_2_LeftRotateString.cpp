#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ���ַ���������ת�����ǰ��ַ���ǰ��������ַ�ת�Ƶ��ַ���β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܣ��磺
	  ���롱abcdefg"������2������cdefgab

˼·�������⣬�ֲ���ת�����巭ת�������Ӵ��ڲ���תһ�Σ��ٽ������ַ�����תһ��
*/

class Solution {
public:
    void reverseWords(string &s, int n) {
		//���ַ���1��תһ��
		for(int i = 0; i < n/2; i++){
			char tmp = s[i];
			s[i] = s[n-i-1];
			s[n-i-1] = tmp;
		}
		//���ַ���2��תһ��
		for(int i = 0; i < (s.size()-n)/2; i++){
			char tmp = s[n+i];
			s[n+i] = s[s.size()-i-1];
			s[s.size()-i-1] = tmp;
		}
		//���巭תһ��
		for(int i = 0; i < s.size()/2; i++){
			char tmp = s[i];
			s[i] = s[s.size()-i-1];
			s[s.size()-i-1] = tmp;
		}
    }
};

int main()
{
	Solution c;
	string s = "abcdefg";
	cout << s << endl;
	c.reverseWords(s, 2);
	cout << s << endl;
	return 0;
}

