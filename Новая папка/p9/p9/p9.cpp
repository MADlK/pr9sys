

#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

DWORD LWID;
DWORD LEID;
DWORD LPID;
DWORD LNID;

wchar_t Word[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";

//wchar_t Paint[] = L"%C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Word%";
//wchar_t Excel[] = L"%C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Word%";
//wchar_t Notepad[] = L"%C:\ProgramData\Microsoft\Windows\Start Menu\Programs\Word%";

DWORD sp(char* path) 
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
  
  
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    if(!CreateProcess((LPWSTR)path, NULL, NULL, NULL, FALSE, 0, NULL, NULL,&si,&pi))
    {
        cout << "Ошибка запуска " << GetLastError();
        return 0;
    }
    DWORD id = pi.dwProcessId;

    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return id;
};

void Closeid(DWORD id)
{
    if (id == 0)
        cout << "нет процессов";
    return ;

    HANDLE hp = OpenProcess(PROCESS_TERMINATE, FALSE, id);
    if (!hp)
    {
        cout << "неудалось открыть процесс";
        return;
    }
    TerminateProcess(hp, 0);
    CloseHandle(hp);
    cout << "процесс с id " << id << "был завершен";
}




int main()
{
    setlocale(LC_ALL, "rus");
    int sel = 0;
    bool run = true;
    while (run)
    {
        cout <<"1 - запуск Word\n 2 -  запуск Paint\n 3 - запуск Excel\n 4 - запуск Notepad\n 5 - закрыть word\n 6 - закрыть Paint\n7 - закрыть Excel\n 8 - закрыть Notepad\n 9 - закрыть всю программу";
        cin >> sel;
        switch (sel)
        {
        case 1:
        {
            LWID = sp((char*)Word);
        }
        break;
        case 2:
        {

        }
        break;
        case 3:
        {

        }
        break;
        case 4:
        {

        }
        break;
        case 5:
        {
            Closeid(LWID);
            LWID = 0;
            break;

        }
        break;
        case 6:
        {

        }
        break;
        case 7:
        {

        }
        break;
        case 8:
        {

        }
        break;
        case 9:
        {

        }
        break;
        default:
            break;
        }
    }
}


