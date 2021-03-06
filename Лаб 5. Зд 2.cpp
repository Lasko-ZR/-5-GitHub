﻿#include <iostream>
#include <string>
#include "../Лаб 5. Зд 1/Лаб 5. Зд 1.cpp"
#include "../5lab/cData.h"


class CWorkspace
{
public:
    CWorkspace(CDataChain &data);
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
};

int main()
{
    CDataSimple data;
    CWorkspace ws(data);
    
    return 0;
}
