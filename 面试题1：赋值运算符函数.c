#define  _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdlib>
//面试一：赋值运算符函数

using namespace std;
class CMyString{
public:
	CMyString(char* pData = nullptr){
		m_pData = pData;
	}
	//使用const 引用
	CMyString& CMyString::operator=(const CMyString&str){
		//判断是否和当前（*this）是一个实例
		if (this == &str){
			return *this;
		}
		//删除以前实例 防止内存泄漏
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
	//实例赋值给另一个实例
	CMyString b=a;
	cout << "复制后 b is "<<*b.m_pData<<endl;
	a.m_pData = &B;
	cout << "now ，a is " << *a.m_pData << endl;
	cout << "b is " << *b.m_pData << endl;
	//可以看到地址是新建的 并不是直接拷贝过来的

	//赋值给自己
	a = a;
	//连续赋值

	test1 = test2 = a;
	cout << *test1.m_pData << *test2.m_pData << endl;

	system("pause");
	return 0;
}
