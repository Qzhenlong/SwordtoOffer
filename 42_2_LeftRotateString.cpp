#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：字符串的左旋转操作是把字符串前面的若干字符转移到字符串尾部，请定义一个函数实现字符串左旋转操作的功能，如：
	  输入”abcdefg"和数字2，返回cdefgab

思路：经典题，局部翻转再整体翻转，两个子串内部翻转一次，再将整个字符串翻转一镒
*/

class Solution {
public:
    void reverseWords(string &s, int n) {
		//子字符串1翻转一次
		for(int i = 0; i < n/2; i++){
			char tmp = s[i];
			s[i] = s[n-i-1];
			s[n-i-1] = tmp;
		}
		//子字符串2翻转一次
		for(int i = 0; i < (s.size()-n)/2; i++){
			char tmp = s[n+i];
			s[n+i] = s[s.size()-i-1];
			s[s.size()-i-1] = tmp;
		}
		//整体翻转一次
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

