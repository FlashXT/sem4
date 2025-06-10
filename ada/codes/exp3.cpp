#include <iostream>
using namespace std;

int fib(int n)
{
    if (n == 0)
    {
        return 0;
    }
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fib(n - 1) + fib(n - 2);
    }
}

int main()
{
    cout << endl;
    int n;
    cout << "Enter a number of terms: ";
    cin >> n;
    cout << "Fibonacci series of " << n << " numbers is : ";
    for (int i = 0; i < n; i++)
    {
        cout << fib(i) << " ";
    }
    cout << endl
         << endl;
    return 0;
}
