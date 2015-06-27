#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
题目：在字符串中找出第一个只出现一次的字符，如输入”abaccdeff",则输出b
思路：用两张哈希表，一张存储字符出现的次数，一张存储字符出现的坐标，找出出现次数为1，坐标为最小值的字符即可
	  空间O(n),时间O(n)
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
		int min = -1; //第一次出现不重复字符的坐标
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
