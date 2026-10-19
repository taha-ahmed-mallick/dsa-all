#include <iostream>
using namespace std;

int main()
{
    size_t y, w;
    cin >> y >> w;
    size_t maximum = max(y, w);
    size_t fav_chance = 7 - maximum, total = 6;
    if (fav_chance == 0)
    {
        total = 1;
    }
    else if (fav_chance == 6)
    {
        fav_chance = 1;
        total = 1;
    }
    else if (fav_chance % 3 == 0)
    {
        fav_chance /= 3;
        total = 2;
    }
    else if (fav_chance % 2 == 0)
    {
        fav_chance /= 2;
        total = 3;
    }

    cout << fav_chance << "/" << total << endl;
    return 0;
}