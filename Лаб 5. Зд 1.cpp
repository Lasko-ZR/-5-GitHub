#include <stdio.h>
#include <iostream>
using namespace std;


class CDataChain
{
public:
	CDataChain(void);
	virtual ~CDataChain(void);
	//віртуальна функція, що має генерувати повну послідовність цифр.
	virtual void Generate(int nDepth, int nMaxLength = 0) = 0;
	//повертає довжину згенерованої послідовності цифр.
	size_t GetLength()
	{
		return m_sChain.length();
	}

	//повертає позицію входження підстрічки sSubStr починаючи із nPos.
	// -1, якщо підстрічки не знайдено
	int Find(const char* sSubStr, int nPos = 0)
	{
		size_t length = strlen(sSubStr);
		for (size_t i = 0; i < m_sChain.length(); i++)
		{
			if (m_sChain[i] != sSubStr[0])
				continue;
			size_t j = 0;
			for (; j < length; j++)
			{
				if ((i + j) >= m_sChain.length())
					return -1;
				if (m_sChain[i + j] != sSubStr[j])
					break;
			}
			if ((j == length) && (m_sChain[i + j] == sSubStr[j - 1]))
				return i;
		}
		return -1;
	}

	//повертає підстрічку починаючи із nPos довжиною nLength. або до кінця послідовності
	string GetSubStr(int nPos, int nLength = -1)
	{
		string subStr;
		if ((nPos >= m_sChain.length()) || ((nPos + nLength) >= m_sChain.length()))
			return subStr;
		subStr = m_sChain.substr(nPos, nLength);
		return subStr;
	}

	//повертає всю згенеровану послідовність цифр
	const char* GetFullString()
	{
		return m_sChain.c_str();
	}

protected:
	//стрічка із згенерованою послідовністю цифр
	string m_sChain;
};

class CDataSimple : public CDataChain
{
public:
	CDataSimple(void);
	~CDataSimple(void);
	//Реалізація генератора повної послідовності цифр
	void Generate(int nDepth, int nMaxLength = 0)
	{
		while (m_sChain.length() <= (size_t)nMaxLength)
		{
			int num = rand() % (10 * nDepth);
			m_sChain.append(std::to_string(num));
		}
		if (m_sChain.length() > nMaxLength)
			m_sChain.resize(nMaxLength);
	}
};



int main()
{
	cout << "Generate(a, b)" << endl;
	int a;
	cout << "a = ";
	cin >> a;
	int b;
	cout << "b = ";
	cin >> b;

	CDataSimple First;
	First.Generate(a, b);
	cout << First.GetFullString() << endl;

	return 0;
}
