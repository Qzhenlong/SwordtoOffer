#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
��Ŀ�����ַ������ҳ���һ��ֻ����һ�ε��ַ��������롱abaccdeff",�����b
˼·�������Ź�ϣ��һ�Ŵ洢�ַ����ֵĴ�����һ�Ŵ洢�ַ����ֵ����꣬�ҳ����ִ���Ϊ1������Ϊ��Сֵ���ַ�����
	  �ռ�O(n),ʱ��O(n)
*/
class Solution{
public:
	char fun(string s){
		map<char, int> num;
		map<char, int> index;
		for(int i = 0; i < s.size(); i++){
			num[s[i]] = 0;
			index[s[i]] = i;
		}
		for(int i = 0; i < s.size(); i++)	num[s[i]]++;
		int min = -1; //��һ�γ��ֲ��ظ��ַ�������
		for(map<char, int>::iterator it = num.begin(); it != num.end(); it++){
			if(it->second == 1){
				if(min == -1) min = index[it->first];
				else min = (min > index[it->first]) ? index[it->first] : min;
			}
		}
		return s[min];
	}
};

int main(){
	Solution c;
	string s = "abaccdeff";
	cout << c.fun(s);
	return 0;
}
