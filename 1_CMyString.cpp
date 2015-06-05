#include<iostream>
#include<string>
using namespace std;
/*
��Ŀ������Ϊ����CMyString����������Ϊ��������Ӹ�ֵ���������
class CMyString {
public:
	CMyString(char* pData=NULL);
	CMyString(const CMyString &str);
	~CMyString(void);
private:
	char *m_pData;
};
��չ��ʵ�ֹ��캯���������������������캯��������Ա���Ա��䣩
ע��㣺��ֵ���������Ӧ�÷���*this,������thisָ��
*/
class CMyString {
public:
	CMyString(char* pData){ //���캯��
		if(pData == NULL){ //������ж�NULL,ֱ����strlen���㳤��Ϊ����
			m_pData = new char[1];
			m_pData[0] = '\0'; //������
		}
		else{
			m_pData = new char[strlen(pData)+1]; //����
			strcpy(m_pData, pData);
		}
	}
	~CMyString(void){ //��������
		delete[] m_pData;
	}
	CMyString(const CMyString &str){ //�������캯��
		if(str.m_pData == NULL){
			m_pData = new char[1];
			m_pData[0] = '\0'; //������			
		}
		else{
			m_pData = new char[strlen(str.m_pData)+1]; //����
			strcpy(m_pData, str.m_pData);
		}
	}
	CMyString& operator =(const CMyString &str){ //��ֵ���������
		if(this == &str)
			return *this; //ע���*
		delete [] m_pData;
		m_pData = NULL; //��ֹ��;ָ��
		if(str.m_pData == NULL){
			m_pData = new char[1];
			m_pData[0] = '\0'; //������			
		}
		else{
			m_pData = new char[strlen(str.m_pData)+1]; //����
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
