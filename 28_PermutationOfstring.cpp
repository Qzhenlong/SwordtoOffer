#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������У���������abc,��ӡ��abc,acb,bac,bca,cab,cba
˼·��ʹ�õݹ�ʵ��
��أ�LeetCode�е�Permutationһ��
��չ�����������
*/
class Solution{
public:
	void Permutation(string s){ 
		vector<char > cur;
		int c;
		findPermutation(s, cur, c);
	}
	void findPermutation(string s, vector<char > cur, int &counter){
		if(s.size() == cur.size()){ //�ҵ�һ�ֿ��ܣ���ӡ֮
			cout << counter++ << ": "; //��ǰΪ�ڼ���
			for(int i = 0; i < cur.size(); i++) cout << cur[i] << " ";
			cout << endl;
			return;
		}
		for(int i = 0; i < s.size(); i++){
			if(find(cur.begin(), cur.end(), s[i]) == cur.end()){
				cur.push_back(s[i]);
				findPermutation(s, cur, counter);
				cur.pop_back();
			}
		}
	}
	void Combination(string s){
		vector<char > cur;
		int c = 0;
		for(int i = 0; i < s.size(); i++)
			findCombination(s, 0, i+1, cur, c); 
	}
	void findCombination(string s, int i, int n,  vector<char > &cur, int &counter){ // iΪ��ǰҪ������ַ��±꣬nΪ��ǰ������еĳ���
		if(n == 0){
			cout << counter++ << ": "; //��ǰΪ�ڼ���
			for(int i = 0; i < cur.size(); i++) cout << cur[i] << " ";
			cout << endl;
			return;			
		}
		if(i >= s.size()) return;
		cur.push_back(s[i]);
		findCombination(s, i+1, n-1, cur, counter);
		cur.pop_back();
		findCombination(s, i+1, n, cur, counter);
	}
};
int main()
{	
	Solution c;
	cout << "Permutation: " << endl;
	c.Permutation("abc");
	cout << "Combination: " << endl;
	c.Combination("abc");
	return 0;
}

	

 