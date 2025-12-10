#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;




struct Nodepotok
{
    DWORD poid;
    Nodepotok* Next;
};

Nodepotok* potokFirst = nullptr;


struct NodeWord
{
    DWORD wid;
    NodeWord* Next;
};

NodeWord* wordFirst = nullptr;


struct NodePaint
{
    DWORD pid;
    NodePaint* Next;
};

NodePaint* paintFirst = nullptr;


struct NodeExcel
{
    DWORD eid;
    NodeExcel* Next;
};

NodeExcel* excelFirst = nullptr;


struct NodeNotepad
{
    DWORD nid;
    NodeNotepad* Next;
};

NodeNotepad* notepadFirst = nullptr;

////////potok


void npotok(DWORD id)
{
    Nodepotok* n = new Nodepotok;
    n->poid = id;
    n->Next = potokFirst;
    potokFirst = n;
}

DWORD delpotok()
{
    if (!potokFirst)
        return 0;

    DWORD id = potokFirst->poid;

    potokFirst = potokFirst->Next;

    return id;
}

////////////word

void nword(DWORD id)
{
    NodeWord* n = new NodeWord;
    n->wid = id;
    n->Next = wordFirst;
    wordFirst = n;
}

DWORD delword()
{
    if (!wordFirst)
        return 0;

    DWORD id = wordFirst->wid;
    
    wordFirst = wordFirst->Next;
    
    return id;
}

////////////Paint

void npaint(DWORD id)
{
    NodePaint* n = new NodePaint;
    n->pid = id;
    n->Next = paintFirst;
    paintFirst = n;
}

DWORD delpaint()
{
    if (!paintFirst)
        return 0;

    DWORD id = paintFirst->pid;
    paintFirst = paintFirst->Next;
    return id;
}

//
//
//////////////Excel
//
void nexcel(DWORD id)
{
    NodeExcel* n = new NodeExcel;
    n->eid = id;
    n->Next = excelFirst;
    excelFirst = n;
}

DWORD delexcel()
{
    if (!excelFirst)
        return 0;

    DWORD id = excelFirst->eid;
    excelFirst = excelFirst->Next;
    return id;
}
//
//
//
//////////////Notepad
//

void nnotepad(DWORD id)
{
    NodeNotepad* n = new NodeNotepad;
    n->nid = id;
    n->Next = notepadFirst;
    notepadFirst = n;
}

DWORD delnotepad()
{
    if (!notepadFirst)
        return 0;

    DWORD id = notepadFirst->nid;
    notepadFirst = notepadFirst->Next;
    return id;
}














wchar_t Word[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\WINWORD.EXE";
wchar_t Paint[] = L"C:\\WINDOWS\\system32\\mspaint.exe";
wchar_t Excel[] = L"C:\\Program Files\\Microsoft Office\\root\\Office16\\EXCEL.EXE";
wchar_t Notepad[] = L"C:\\Program Files\\Notepad++\\notepad++.exe";
wchar_t Potok[] = L"C:\\Users\\st310-09\\Desktop\\pr9sys\\Новая папка\\p9\\x64\\Debug\\potok.exe";

DWORD sp(LPWSTR path, LPWSTR cl)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;  
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    if(!CreateProcess((LPWSTR)path, cl, NULL, NULL, FALSE, 0, NULL, NULL,&si,&pi))
    {
        cout << "Ошибка запуска " << GetLastError();
        return 0;
    }
    DWORD id = pi.dwProcessId;
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return id;
};



DWORD potok(LPWSTR path)
{
    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    ZeroMemory(&si, sizeof(STARTUPINFO));
    si.cb = sizeof(STARTUPINFO);
    if (!CreateProcess((LPWSTR)path,NULL , NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi))
    {
        cout << "Ошибка запуска " << GetLastError();
        return 0;
    }
    DWORD id = pi.dwProcessId;
    CloseHandle(pi.hProcess);
    CloseHandle(pi.hThread);
    return id;

}

void Closeid(DWORD id)
{
    if (id == 0)
    {
        cout << "нет процессов";
        return;
    }     
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
        cout <<"0 - запуск потока\n1 - запуск Word\n 2 -  запуск Paint\n 3 - запуск Excel\n 4 - запуск Notepad\n 5 - закрыть word\n 6 - закрыть Paint\n7 - закрыть Excel\n 8 - закрыть Notepad\n 9 - закрыть  поток\n 10 закрыть всю программу";
        cin >> sel;
        switch (sel)
        {
        case 0:
        {
            DWORD poid = potok(Potok);
            npotok(poid);
        }
        break;
        case 1:
        {
            DWORD wid = sp(Word, (LPWSTR)L"WINWOR.EXE /w");
            nword(wid);
            
        }
        break;
        case 2:
        {
            DWORD pid = sp(Paint, NULL);
            npaint(pid);
        }
        break;
        case 3:
        {
            DWORD eid = sp(Excel, (LPWSTR)L"EXCEL.EXE /e");
            nexcel(eid);
        }
        break;
        case 4:
        {
            DWORD nid = sp(Notepad, (LPWSTR)L"notepad++.exe");
            nnotepad(nid);
        }
        break;
        case 5:
        {

            DWORD id = delword();
            Closeid(id);
            
        }
        break;
        case 6:
        {
            DWORD id = delpaint();
            Closeid(id);
            
        }
        break;
        case 7:
        {
            DWORD id = delexcel();
            Closeid(id);
            
        }
        break;
        case 8:
        {
            DWORD id = delnotepad();
            Closeid(id);
            
        }
        break;
        case 9:
        {
            DWORD id = delpotok();
            Closeid(id);
        }
        break;
        case 10:
        {
            return 0;
        }
        break;
        
        default:
        {
            cout << "нет такого выбора";
                
        }
            break;
        }
    }
    return 0;
}


