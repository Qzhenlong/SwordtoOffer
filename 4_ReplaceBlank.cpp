#include<iostream>
using namespace std;
/*
题目：请实现一个函数，把字符串中的每一个空格替换成20%,例如输入“We are happy",输出“We%20are%20happy".
思路：
1）先统计字符串中空格的数量t；
2）根据空格数量申请2*t新空间,并定义两个指针p1,p2,p1指向原字串末，p2指向新字符串（加上新申请的空间）末；
3）p1和p2从后往前扫描，并同时将原字符串向上移动，遇到空格则替换。
只需两次扫描，复杂度为O(n)
*/
class Solution{
public:
	 void ReplaceBlank(string &str){
		int t = 0, p1, p2, n = str.size();
		for(int i = 0; i < str.size(); i++)
			if(str[i] == ' ') t++;
		p1 = str.size()-1;
		p2 = p1 + 2*t;
		for(int i = 0; i < 2*t; i++) str += ' ';
		while(p1 >= 0){
			if(str[p1] != ' ') str[p2--] = str[p1--];
			else{
				str[p2--] = '0';
				str[p2--] = '2';
				str[p2--] = '%';
				p1--;
			}
		}
	}
};

int main()
{
	Solution c;
	string str = "We are  happy";
	cout << str << endl;
	c.ReplaceBlank(str);
	cout << str << endl;
	return 0;
}
