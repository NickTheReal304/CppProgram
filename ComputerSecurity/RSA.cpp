#include <iostream>
#include <Windows.h>
#include <TlHelp32.h>
#include <string>
#include <cstdint>
#include <fstream>

using namespace std;
DWORD pid;
DWORD Temp = (int)0;
int NumValue;

int main()
{
    NumValue = 0;
    HWND hWnd = FindWindowA(0, ("WannaCry V1.0"));
    if (hWnd == NULL)
    {
        cout << "can't find the process." << endl;
        Sleep(2000);
        exit(-1);
    }
    else
    {
        GetWindowThreadProcessId(hWnd, &pid);
        HANDLE pHandle = OpenProcess(PROCESS_VM_READ, FALSE, pid);

        if (pid == NULL)
        {
            cout << "can't find the process." << endl;
            Sleep(2000);
            exit(-1);
        }
        else
        {
            /* Prompt the user to enter the value of n, obtained in Step 1 */
            /* Assign n to a variable */
            int n = 0;
            cout << "Input the value of n: ";
            cin >> n;

            //"140737488355327" is the end of memory address.
            while (Temp != 140737488355327)
            {
                ReadProcessMemory(pHandle, (LPVOID)Temp, &NumValue, sizeof(NumValue), 0);
                /* NumValue is the value read from a memory address */
                /* Check and print out the values that can be p or q such that n = pq */
                if (NumValue != 0 && NumValue != 1 && NumValue != -1)
                {
                    /* If NumValue can be divisible by n */
                    if ((n % NumValue) == 0)
                    {
                        /* Print the Number Value */
                        cout << "The value: " << NumValue << endl;
                    }
                }
                Temp += 1;
            }
        }
    }

    system("pause");
}