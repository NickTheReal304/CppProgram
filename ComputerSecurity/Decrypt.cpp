#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    int p=0, q=0, e=0;
    
    cout << "Program Started" << endl;
    cout << "What is p?";
    cin >> p;
    cout << "What is q?";
    cin >> q;
    cout << "What is e?";
    cin >> e;
    cout << endl;

    int phi = (p-1)*(q-1);
    cout << "phi: "<< phi;
    int counter =0;

    int A1=1, A2=0, A3=phi, B1=0, B2=1, B3=e;
    int Q=0, T1=0,T2=0,T3=0;

    while(true){
        
        if(B3 == 0){
            cout <<"hello" <<A3;
            break;
        }else if(B3 == 1){
            cout << "g" <<B3;
            break;
        }

        Q = (A3/B3);
        cout <<"Q" << Q <<endl;
        T1=A1-(Q*B1);
        T2=A2-(Q*B2);
        T3=A3-(Q*B3);
        A1=B1;
        A2=B2;
        A3=B3;
        B1=T1;
        B2=T2;
        B3=T3;

        cout << "T1:" <<T1 << endl;
        cout << "T2:" <<T2 << endl;
        cout << "T3:" <<T3 << endl;
        cout << "A1:" <<A1 << endl;
        cout << "A2:" <<A2 << endl;
        cout << "A3:" <<A3 << endl;
    }

}