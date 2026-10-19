#include <iostream>
using namespace std;

bool isPrime(size_t num)
{
    if (num < 2)
        return false;
    if (num % 2 == 0 && num != 2)
        return false;

    for (size_t i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    size_t n;
    cin >> n;

    for (size_t i = 4; i < n; i++)
    {
        for (size_t j = 4; j < n; j++)
        {
            if (i + j == n)
            {
                if (!isPrime(i) && !isPrime(j))
                {
                    cout << i << " " << j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}



#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 2 == 0)
        cout << 4 << " " << n - 4 << '\n';
    else
        cout << 9 << " " << n - 9 << '\n';

    return 0;
}