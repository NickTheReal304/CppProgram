#include <iostream>
#include <string>
using namespace std;

int main()
{
    /* Declear the input values */
    int p = 0, q = 0, e = 0;

    /* User input */
    cout << "Program Started" << endl;
    cout << "What is p?";
    cin >> p;
    cout << "What is q?";
    cin >> q;
    cout << "What is e?";
    cin >> e;
    cout << endl;

    /* The phi value */
    int phi = (p - 1) * (q - 1);
    /* By using the EEA, The we assume that s1=1,s2=0 & t1=1,t1=0 */
    int A1 = 1, A2 = 0, A3 = phi;
    int B1 = 0, B2 = 1, B3 = e;
    int Q = 0, T1 = 0, T2 = 0, T3 = 0;

    while (true)
    {
        if (B3 == 0)
        {
            /* The GCD */
            /* Probablity using for Encrypyt */
            cout << "GCD is" << A3 << "Without any inverse.";
            break;
        }
        else if (B3 == 1)
        {
            /* The GCD */
            cout << "GCD is " << B3;
            // The inverse of e
            cout << " The d value equal to " << B2 << ".";
            break;
        }
        /* Quotient */
        Q = (A3 / B3);
        /* T1 = 1 - 0xQ */
        T1 = A1 - (Q * B1);
        /* T2 = 0 - 1xQ */
        T2 = A2 - (Q * B2);
        /* Reminder */
        T3 = A3 - (Q * B3);
        /* Shift Left */
        A1 = B1;
        B1 = T1;
        /* Shift Left */
        A2 = B2;
        B2 = T2;
        /* Shitft Left */
        A3 = B3;
        B3 = T3;
    }
}