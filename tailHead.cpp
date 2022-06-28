#include <iostream>

using namespace std;

void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1);
        cout << n << " ";
        // fun(n - 1); Head
    }
}

int main()
{
    int x = 3;

    fun(x);
    return 0;
}