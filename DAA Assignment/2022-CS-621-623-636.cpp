// input tutorial for Decreasing Function:-
// By Muster theorem:
//  Enter values of a:2
//  Enter values of b:5
//  Enter function f(n): n^2

// input tutorial for Dividing Function:-

// By Master theorem:
//  Enter values of a:8
//  Enter values of b:2
//  Enter function f(n): n^2

// By Extended Master theorem:
//  Enter values of a:2
//  Enter values of b:2
//  Enter function f(n): n^2log^-2n
//             OR
//  Enter function f(n): n^2log^2n

#include <iostream>
#include <cmath>

using namespace std;

bool isconstant(char c)
{
    return ((c >= '0' && c <= '9'));
}
void DivMasterTheorem(double a, double b, char fn[])
{
    double logBaseBofA = log(a) / log(b);
    if (fn[1] == '^' && fn[2] == 'n')
    {
        cout << "T(n) = " << char(233) << " (" << fn << ")" << endl;
    }
    else if (fn[1] == '!')
    {
        cout << "T(n) = " << char(233) << " (" << fn << ")" << endl;
    }
    else
    {
        int fnpower = 0;
        // n^2
        if (fn[0] == 'n' && fn[1] == '^')
        {
            fnpower = fn[2] - '0';
        }
        // n
        else if (fn[0] == 'n')
        {
            fnpower++;
        }
        // 1
        else
        {
            fnpower = 0;
        }
        cout << "T(n) = " << char(233);

        // O(n^k), if k > logb(a)
        // O(n^k*log(n)), if  k = logb(a)
        // O(n^logb(a)), if k < logb(a)

        if (logBaseBofA > fnpower)
        {
            cout << " (n^" << logBaseBofA << ")" << endl;
        }
        else if (logBaseBofA == fnpower)
        {
            cout << "(n^" << logBaseBofA << "logn)" << endl;
        }
        else
        {
            cout << "(" << fn << ")" << endl;
        }
    }
    cout << "By Master Theorem" << endl;
}

void Div_ExtendedMasterTheorem(double a, double b, char fn[])
{
    double logBaseBofA = log(a) / log(b);
    int k = 0, p = 0;
    // n^-3log^2n or n^-2log^-2n or n^-2logn
    if (fn[0] == 'n' && fn[1] == '^' && fn[2] == '-')
    {
        int newK = fn[3] - '0';
        k = newK - (2 * newK);

        if (fn[8] == '-')
        {
            int newP = fn[9] - '0';
            // do it to change in negative sign-->
            p = newP - (2 * newP);
        }
        else if (fn[7] == 'n')
        {
            p = 1;
        }
        else
        {
            p = fn[8] - '0';
        }
    }
    else if (fn[0] == 'n' && fn[1] == '^')
    {
        k = fn[2] - '0';
        if (fn[7] == '-')
        {
            int newP = fn[8] - '0';
            // do it to change in negative sign-->
            p = newP - (2 * newP);
        }
        else if (fn[6] == 'n')
        {
            p = 1;
        }
        else
        {
            p = fn[7] - '0';
        }
    }
    // nlog^2n
    else if (fn[0] == 'n')
    {
        // k = 0;
        k++;
        if (fn[5] == '-')
        {
            int newP = fn[6] - '0';
            p = newP - (2 * newP);
        }
        else if (fn[4] == 'n')
        {
            p = 1;
        }
        else
        {
            p = fn[5] - '0';
        }
    }
    // log^2n
    else
    {
        k = 0;
        if (fn[4] == '-')
        {
            int newP = fn[5] - '0';
            p = newP - (2 * newP);
        }
        else if (fn[3] == 'n')
        {
            p = 1;
        }
        else
        {
            p = fn[4] - '0';
        }
    }
    cout << "P = " << p << endl;
    cout << "K = " << k << endl;

    cout << "T(n) = " << char(233);

    if (logBaseBofA > k)
    {
        if (logBaseBofA == 1)
        {
            cout << "(n)" << endl;
        }
        else
            cout << "(n^" << logBaseBofA << ")" << endl;
    }
    else if (logBaseBofA == k)
    {

        if (p > -1)
        {
            if (k == 0 && p == 0)
                cout << "(logn)\n";
            else if (k == 0)
                cout << "(log^" << p + 1 << "n)\n";
            else if (p == 0)
            {
                if (k == 1)
                    cout << "(nlogn)\n";
                else
                    cout << "(n^" << k << "logn)\n";
            }
            else
            {
                if (k == 1)
                    cout << "(nlog^" << p + 1 << "n)\n";
                else
                    cout << "(n^" << k << "log^" << p + 1 << "n)\n";
            }
        }
        else if (p == -1)
        {
            if (k == 0)
                cout << "(loglogn)\n";
            else if (k == 1)
                cout << "(nloglogn)\n";
            else
                cout << "(n^" << k << "loglogn)\n";
        }
        else
        {
            if (k == 0)
                cout << "(1)\n";
            else if (k == 1)
                cout << "(n)\n";
            else
                cout << "(n^" << k << ")\n";
        }
    }
    else if (logBaseBofA < k)
    {
        if (p >= 0)
        {
            fn[0] = 'n';
            cout << "(" << fn << ")\n";
        }
        else
        {
            if (k == 0)
                cout << "(1)\n";
            else if (k == 1)
                cout << "(n)\n";
            else
                cout << "(n^" << k << ")\n";
        }
    }
    cout << "By Extended Master Theorem" << endl;
}

void DecMusterTheorem(double a, double b, char fn1[])
{
    // Main Cases:
    //  O(n^k ), if a < 1,
    //  O(n^k+1), if a = 1,
    //  O(n^k*a^n/b), if a > 1.
    int i = 0;
    int k = 0;
    cout << "T(n) = " << char(233);
    if (a < 1)
    {
        // n^2
        if (fn1[0] == 'n' && fn1[1] == '^')
        {
            k = fn1[2] - '0';
            cout << "(n^" << k << ")" << endl;
        }
        // n
        else if (fn1[0] == 'n')
        {
            cout << "(n)" << endl;
        }
        // 1
        else
        {
            cout << "(1)" << endl;
        }
    }
    else if (a == 1)
    {
        if (fn1[0] == 'n' && fn1[1] == '^')
        {
            k = fn1[2] - '0';
            k++;
            cout << "(n^" << k << ")" << endl;
        }
        else if (fn1[0] == 'n')
        {
            cout << "(n^2)" << endl;
        }
        else if (fn1[0] == 'l' && fn1[1] == 'o' && fn1[2] == 'g')
        {
            cout << "(n" << fn1 << "n)" << endl;
        }
        else
        {
            cout << "(n)" << endl;
        }
    }
    else
    {
        if (b == 1)
        {
            if (fn1[0] == 'n' && fn1[1] == '^')
            {
                k = fn1[2] - '0';
                cout << "(n^" << k << a << "^n)" << endl;
            }
            else if (fn1[0] == 'n')
            {
                cout << "(n" << a << "^n)" << endl;
            }
            else
            {
                cout << "(" << a << "^n)" << endl;
            }
        }
        else
        {
            if (fn1[0] == 'n' && fn1[1] == '^')
            {
                k = fn1[2] - '0';
                k++;
                cout << "(n^" << k << "*" << a << "^n/" << b << ")" << endl;
            }
            else if (fn1[0] == 'n')
            {
                cout << "(n" << a << "^n/" << b << ")" << endl;
            }
            else
            {
                cout << "(" << a << "^n/" << b << ")" << endl;
            }
        }
    }
    cout << "By Muster Theorem" << endl;
}
void MasterTheorem_Different_SubProblem_Size(double a, double b, double a1, double b1, char fn[])
{
    if (b > b1)
    {
        b = 1 / b1;
    }
    else
    {
        b = 1 / b;
    }
    cout << "Solve By Deep Branch" << endl;
    cout << "T(n) = O(" << fn << "logn/log" << b << ")" << endl;
}

int main()
{

    double a, b;
    int choice = 0;
    do
    {
        cout << "\n\tMenu\n";
        cout << "1. Dividing Function \n";
        cout << "2. Decreasing Function  \n";
        cout << "3. Dividing Function (Different Sub-Problem Size)  \n";
        cout << "4. Exit  \n";
        cin >> choice;

        if (choice == 1)
        {
            char fn[20];
        againInput:
            cout << "Enter value of a:";
            cin >> a;
            if (a <= 0)
            {
                cout << "Invalid Input" << endl;
                goto againInput;
            }
        again:
            cout << "Enter value of b:";
            cin >> b;
            if (b <= 1)
            {
                cout << "Invalid Input" << endl;
                goto again;
            }
            cin.ignore();
            cout << "Enter function f(n): ";
            cin.getline(fn, 20);
            int flag = 0;
            for (int i = 0; i < 20; i++)
            {
                if (fn[i] == 'l' && fn[i + 1] == 'o' && fn[i + 2] == 'g')
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag)
            {
                DivMasterTheorem(a, b, fn);
            }
            else
            {
                Div_ExtendedMasterTheorem(a, b, fn);
            }
        }
        else if (choice == 2)
        {
            char fn1[5];
            cout << "Enter value of a:";
            cin >> a;

        again1:
            cout << "Enter value of b:";
            cin >> b;
            if (b <= 1)
            {
                cout << "Invalid Input" << endl;
                goto again1;
            }
            cin.ignore();
            cout << "Enter function f(n): ";
            cin.getline(fn1, 5);
            DecMusterTheorem(a, b, fn1);
        }
        else if (choice == 3)
        {
            char fn[20];
            double a1 = 0, b1 = 0;
        againInput2:
            cout << "Enter value of first a:";
            cin >> a;
            if (a <= 0)
            {
                cout << "Invalid Input" << endl;
                goto againInput2;
            }
        again2:
            cout << "Enter value of first b:";
            cin >> b;
            if (b <= 0)
            {
                cout << "Invalid Input" << endl;
                goto again2;
            }
        againInput3:
            cout << "Enter value of Second a:";
            cin >> a1;
            if (a1 <= 0)
            {
                cout << "Invalid Input" << endl;
                goto againInput3;
            }
        again3:
            cout << "Enter value of Second b:";
            cin >> b1;
            if (b1 <= 0)
            {
                cout << "Invalid Input" << endl;
                goto again3;
            }
            cin.ignore();
            cout << "Enter function f(n): ";
            cin.getline(fn, 20);
            MasterTheorem_Different_SubProblem_Size(a, b, a1, b1, fn);
        }
        else if (choice == 4)
        {
            return 0;
        }
        else
        {
            cout << "Invalid input." << endl;
        }
    } while (1);
    return 0;
}