#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个字符串，打印出该字符串中字符的所有排列，例如输入abc,打印：abc,acb,bac,bca,cab,cba
思路：使用递归实现
相关：LeetCode中的Permutation一题
扩展：求所有组合
*/
class Solution{
public:
	void Permutation(string s){ 
		vector<char > cur;
		int c;
		findPermutation(s, cur, c);
	}
	void findPermutation(string s, vector<char > cur, int &counter){
		if(s.size() == cur.size()){ //找到一种可能，打印之
			cout << counter++ << ": "; //当前为第几种
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
	void findCombination(string s, int i, int n,  vector<char > &cur, int &counter){ // i为当前要加入的字符下标，n为当前组合序列的长度
		if(n == 0){
			cout << counter++ << ": "; //当前为第几种
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

	

 