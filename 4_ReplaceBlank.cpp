#include<iostream>
using namespace std;
/*
��Ŀ����ʵ��һ�����������ַ����е�ÿһ���ո��滻��20%,�������롰We are happy",�����We%20are%20happy".
˼·��
1����ͳ���ַ����пո������t��
2�����ݿո���������2*t�¿ռ�,����������ָ��p1,p2,p1ָ��ԭ�ִ�ĩ��p2ָ�����ַ���������������Ŀռ䣩ĩ��
3��p1��p2�Ӻ���ǰɨ�裬��ͬʱ��ԭ�ַ��������ƶ��������ո����滻��
ֻ������ɨ�裬���Ӷ�ΪO(n)
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
