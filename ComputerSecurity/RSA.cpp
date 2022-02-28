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

int main() {
    HWND hWnd = FindWindowA(0, ("WannaCry V1.0"));
    GetWindowThreadProcessId(hWnd, &pid);
    HANDLE pHandle = OpenProcess(PROCESS_VM_READ, FALSE, pid);

    /* Prompt the user to enter the value of n, obtained in Step 1 */
    /* Assign n to a variable */
    int n = 0;
    cout << "Input the value of n:";
    cin >> n;
    int p = 0;
    int q = 0; 
    
    //"140737488355327" is the end of memory address.
    while (Temp != 140737488355327) {
        ReadProcessMemory(pHandle, (LPVOID)Temp, &NumValue, sizeof(NumValue), 0); 
        /* NumValue is the value read from a memory address */
        /* Check and print out the values that can be p or q such that n = pq */
         if(n%NumValue == 0){
            if(p!=0){
                p = NumValue;
                cout << "The p-value is " << p;
            }else{
                q = NumValue;
                cout << "The p-value is " << q;
            }
        }
        Temp += 1;
    }
    system("pause");
}