#include<iostream>
#include<string>
using namespace std;
/*
题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数
class CMyString {
public:
	CMyString(char* pData=NULL);
	CMyString(const CMyString &str);
	~CMyString(void);
private:
	char *m_pData;
};
扩展：实现构造函数、析构函数及拷贝构造函数（程序员面试宝典）
注意点：赋值运算符函数应该返回*this,而不是this指针
*/
class CMyString {
public:
	CMyString(char* pData){ //构造函数
		if(pData == NULL){ //如果不判断NULL,直接用strlen计算长度为报错
			m_pData = new char[1];
			m_pData[0] = '\0'; //结束符
		}
		else{
			m_pData = new char[strlen(pData)+1]; //拷贝
			strcpy(m_pData, pData);
		}
	}
	~CMyString(void){ //析构函数
		delete[] m_pData;
	}
	CMyString(const CMyString &str){ //拷贝构造函数
		if(str.m_pData == NULL){
			m_pData = new char[1];
			m_pData[0] = '\0'; //结束符			
		}
		else{
			m_pData = new char[strlen(str.m_pData)+1]; //拷贝
			strcpy(m_pData, str.m_pData);
		}
	}
	CMyString& operator =(const CMyString &str){ //赋值运算符函数
		if(this == &str)
			return *this; //注意加*
		delete [] m_pData;
		m_pData = NULL; //防止迷途指针
		if(str.m_pData == NULL){
			m_pData = new char[1];
			m_pData[0] = '\0'; //结束符			
		}
		else{
			m_pData = new char[strlen(str.m_pData)+1]; //拷贝
			strcpy(m_pData, str.m_pData);
		}
		return *this;
	}
	
private:
	char *m_pData;
};

int main()
{
	CMyString cs("hello world!");
	return 0;
}
