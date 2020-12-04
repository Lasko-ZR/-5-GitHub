#include <iostream>
#include "../Лаб 5. Зд 1/Лаб 5. Зд 1.cpp"

class CLink
{
public:
    CLink(CDataChain& data);
    virtual ~CLink(void);
    //Пробує прив"язати об"єкт до підстрічки у послідовності
    bool Attach(const char* sSubStr);
    //Форматований вивід на консоль
    virtual void Output(ostream& os);
    //Зберігає об"єкт у вихідному потоці
    virtual bool Save(ostream& so)
    {
        so << m_nPos << " " << m_nSize << std::endl;
        return true;
    }
    //Зчитує об"єкт із вхідного потоку
    virtual bool Load(istream& is)
    {
        std::string str;
        std::getline(is, str);
        if (str == "")
            std::cout << "Error load";
        else {
            std::string strNum;
            int j = 0;
            while (str[j] != ' ') {
                strNum += str[j];
                j++;
            }
            m_nPos = std::stoi(strNum);
            strNum = "";
            for (++j; j < size(str); j++) {
                strNum += str[j];
            }
            m_nSize = std::stoi(strNum);
            return true;
        }

        return false;
    }
protected:
    //Посилання на контейнер з повною послідовністю
    CDataChain& m_refChain;
    //Позиція початку у повній послідовності
    int m_nPos;
    //Довжина підстрічки, до якої прив"язується об"єкт
    int m_nSize;
};

typedef vector<CLink*> LinksArray;

int main()
{
    
}

