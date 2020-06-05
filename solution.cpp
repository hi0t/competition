#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    int res = 0;

    cin >> n;

    while (n > 0)
    {
        int cnt = 0;
        for (int i = 2; i <= n; i++)
        {
            if (n % i == 0 && isPrime(i))
            {
                cnt++;
            }
        }

        if (cnt == 2)
        {
            res++;
        }

        n--;
    }

    cout << res << endl;

    return 0;
}
