#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
//����һ����ֵ���������

using namespace std;
class CMyString{
public:
	CMyString(char* pData = nullptr){
		m_pData = pData;
	}
	//ʹ��const ����
	CMyString& CMyString::operator=(const CMyString&str){
		//�ж��Ƿ�͵�ǰ��*this����һ��ʵ��
		if (this == &str){
			return *this;
		}
		//ɾ����ǰʵ�� ��ֹ�ڴ�й©
		delete[]m_pData;
		m_pData = nullptr;
		m_pData = new char[strlen(str.m_pData) + 1];
		strcpy(m_pData, str.m_pData);
		return *this;
	}


	char* m_pData;
};

int main(){
	char A = 'a';
	char B = 'b';
	CMyString test1, test2;
	CMyString a = CMyString(&A);
	cout << "a is " << *a.m_pData << endl;
	//ʵ����ֵ����һ��ʵ��
	CMyString b=a;
	cout << "���ƺ� b is "<<*b.m_pData<<endl;
	a.m_pData = &B;
	cout << "now ��a is " << *a.m_pData << endl;
	cout << "b is " << *b.m_pData << endl;
	//���Կ�����ַ���½��� ������ֱ�ӿ���������

	//��ֵ���Լ�
	a = a;
	//������ֵ

	test1 = test2 = a;
	cout << *test1.m_pData << *test2.m_pData << endl;

	system("pause");
	return 0;
}
