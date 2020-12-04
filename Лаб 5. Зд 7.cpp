#include <iostream>
#include <string>
#include "../Лаб 5. Зд 1/Лаб 5. Зд 1.cpp"
#include "../5lab/cData.h"


class CWorkspace
{
public:
    CWorkspace(CDataChain& data);
    ~CWorkspace(void);
    //Ініціалізує повну послідовність цифр
    void Init(int nDepth, int nLength)
    {
        if (nDepth != -1)
            m_refChain.Generate(nDepth, nLength);
        else {
            CDataPi pi;
            pi.Generate(-1, nLength);
            m_refChain.SetM_sChain(pi.GetString());
        }

    }
    //Повертає стрічку із повною послідовністю цифр.
    const char* GetChainString()
    {
        return m_refChain.GetFullString();
    }

private:
    //Зсилка на контейнер (породжений від CDataChain) із послідовністю
    CDataChain& m_refChain;

    //Зберігає стан Workspace у файл sFilepath
    bool Save(string& sFilepath)
    {
        if (sFilePath == "")
            return false;

        std::string save = GetChainString();
        std::ofstream saveFile(sFilePath, std::fstream::app);
        saveFile << m_refChain.GetLength(save.c_str()) << std::endl;
        saveFile << GetChainString() << std::endl;
        saveFile << m_aLinks.size() << std::endl;
        for (int i = 0; i < m_aLinks.size(); i++) {
            m_aLinks[i]->Save(saveFile);
        }

        saveFile.close();
        return true;
    }
}
//Відновлює стан Workspace із файлу sFilepath;
bool Load(string& sFilepath);

//Добавляє лінк pLink у список у вибрану позицію nStartPos із довжиною nLength
bool AddLink(int nStartPos, int nLength, CLink* pLink)
{
    pLink->SetM_nPos(nStartPos);
    pLink->SetM_nSize(nLength);

    m_aLinks.push_back(pLink);
    return true;
}
//Видаляє лінк із списку у вибраній позиції(в списку) nPosInList
bool RemoveLink(int nPosInList)
{
    if (nPosInList < 0 || nPosInList >= m_aLinks.size()) {
        std::cout << "Error no such element with this id in list";
        return false;
    }

    m_aLinks.erase(m_aLinks.begin() + nPosInList);
    return true;
}
//Повертає всі лінки, що присутні в списку
bool GetAllLinks(LinksArray& aLinks)
{
    for (int i = 0; i < m_aLinks.size(); i++) {
        aLinks.push_back(m_aLinks[i]);
    }

    return true;
}
//Перевіряє позицію nPos на наявність лінків. Повертає ті,що включають вказану позицію
bool TestPosition(int nPos, LinksArray& aNearestLinks)
{
    if (nPos < 0 || nPos > m_aLinks.size() - 1)
        return false;

    for (int i = 0; i < m_aLinks.size(); i++) {
        if (m_aLinks[i]->GetM_nPos() == nPos) {
            aNearestLinks.push_back(m_aLinks[i]);
        }
    }
    return true;
}

//Повертає всі лінки, що включають в себе хоч одну цифру з інтервалу [nStartPos,nEndPos)
bool TestInterval(int nStartPos, int nEndPos, LinksArray& aNearestLinks)
{
    std::string chain = GetChainString();

    if (nStartPos < 0 || nStartPos > nEndPos || nEndPos > size(chain) - 1)
        return false;

    for (int i = 0; i < m_aLinks.size(); i++) {
        if (m_aLinks[i]->GetM_nPos() >= nStartPos && m_aLinks[i]->GetM_nPos() <= nEndPos)
            aNearestLinks.push_back(m_aLinks[i]);
    }

    return true;
}

};