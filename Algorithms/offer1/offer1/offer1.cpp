/*
赋值运算符函数：
	如下为类型CMystring的声明，请为该类型添加赋值运算符函数
*/
#include <iostream>

class CMystring
{
public:
	CMystring(char* p_Data = nullptr);
	CMystring(const CMystring& str);
	CMystring& operator=(const CMystring& lhs);
	~CMystring(void);
private:
	char* m_pData;
};

CMystring& CMystring::operator=(const CMystring& lhs)
{
	//自身赋值
	/*if (this == &lhs)
		return *this;

	delete[] m_pData;
	m_pData = nullptr;

	m_pData = new char[strlen(lhs.m_pData) + 1];
	if (!m_pData) std::cerr << "out of memory" << std::endl;
	strcpy(m_pData, lhs.m_pData);
	 
	return *this;*/

	//exception safety
	if (this != &lhs)
	{
		CMystring lhsTmp(lhs);

		char* ptmp = lhsTmp.m_pData;
		lhsTmp.m_pData = m_pData;
		m_pData = ptmp;
	}

	return *this;
}

