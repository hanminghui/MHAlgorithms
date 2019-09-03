#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

class MyString
{
public:
	MyString(char *pData = nullptr);
	MyString(const MyString &str);
	~MyString(void);

	MyString& operator = (const MyString &str);

	void Print();

private:
		char *pData_;
};

MyString::MyString(char *pData)
{
	if(pData == nullptr)
	{
		pData_ = new char[1];
		pData_[0] = '\0';
	}
	else
	{
		int length = strlen(pData);
		pData_ = new char[length + 1];
		strcpy(pData_, pData);
	}
}

MyString::MyString(const MyString &str)
{
	int length = strlen(str.pData_);
	pData_ = new char[length+1];
	strcpy(pData_, str.pData_);
}

MyString& MyString::operator= (const MyString &str)
{
	if(this == &str)
		return *this;
	delete[] pData_;
	pData_ = nullptr;

	pData_ = new char[strlen(str.pData_)+1];
	strcpy(pData_, str.pData_);
	return *this;
}

void MyString::Print()
{
	printf("%s", pData_);
}

MyString::~MyString()
{
	delete[] pData_;
}

int main(int argc, char *argv[])
{
	char hello[] = "hello!";
	MyString a(hello);
	a.Print();
	MyString b(a);
	b.Print();
	char fuck[] = "fuck!";
	MyString c(fuck);
	b = c;
	b.Print();
	MyString d;
	d = c;
	d.Print();

    return 0;
}
