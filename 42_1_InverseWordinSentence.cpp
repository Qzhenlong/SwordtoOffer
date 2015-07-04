#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：输入一个英文句子，翻转句子中的单词顺序，但单词内字符的顺序不变，如：I am a student
	 变换为“student. a am I"
思路：两次翻转，一次整体翻转，一次局部翻转即可

相关：数组循环移位(局部翻转再整体翻转）， LeetCode中的Reverse Words in a String.
*/

class Solution {
public:
    void reverseWords(string &s) {
		int i, j=0, n = s.size();
		for(i = 0; i < n/2; i++){ //整体翻转一次
			char tmp = s[i];
			s[i] = s[n-i-1];
			s[n-i-1] = tmp;
		}
		i = 0;
		while(j <= n){ //局部翻转一次
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

