
#include <iostream>
#include "../Лаб 5. Зд 2/Лаб 5. Зд 2.cpp"
#include <vector>

//Декларація типу функції, що буде використовуватися для виконання користувацьких команд
typedef void (*ptDlgCommandFunc)(CWorkspace& data);
class CDlgCommand
{
public:
    CDlgCommand(const char* sName, ptDlgCommandFunc pFunc = NULL);
    ~CDlgCommand(void);
    //Отримання назви команди
    const char* GetName() 
    { 
        return m_sName.c_str(); 
    }
    //Виклик зв"язаної функції
    void Run(CWorkspace& ws)
    {
        m_pFunc(ws);
    }
private:
    //Назва команди
    string m_sName;
    //Вказівник на функцію, що буде використовуватися для виконання користувацьких команд
    ptDlgCommandFunc m_pFunc;
};

class CDialogManager
{
public:
    CDialogManager(CWorkspace& ws);
    ~CDialogManager(void);
    //Реєструє нову команду з ім"ям sName і функцією pFunc
    void RegisterCommand(const char* sName, ptDlgCommandFunc pFunc)
    {
        m_aCommands.push_back(new CDlgCommand(sName, pFunc));
    }
    //Виконує цикл обробки команд користувача
    void Run()
    {
        int nCommand = 1;

        while (nCommand) {
            for (size_t i = 0; i < m_aCommands.size(); i++)
                std::cout << i << ". " << m_aCommands[i]->GetName() << std::endl;
            std::cout << "Enter command:";
            std::cin >> nCommand;
            if ((nCommand > 0) && (nCommand < (int)m_aCommands.size()))
                m_aCommands[nCommand]->Run(m_refWorkspace);
            else
                break;

            system("pause");
            system("cls");
        }
    }
private:
    //Вектор вказівників на зареєстровані команди
    vector m_aCommands;
    //Зсилка на робочий простір
    CWorkspace& m_refWorkspace;
};

int main()
{
    CDataSimple data;
    CWorkspace ws(data);
    CDialogManager mgr(ws);
    mgr.RegisterCommand("Init sequence", Init);
    mgr.RegisterCommand("Show sequence", ShowFullSequence);
    mgr.RegisterCommand("Save", Save);
    mgr.RegisterCommand("Load", Load);
    mgr.Run();
    return 0;
}


