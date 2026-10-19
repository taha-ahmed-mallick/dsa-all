#include <iostream>
using namespace std;

int main() {
    double marks[][5] = {
        {3.66, 3.33, 4.0, 3.0, 2.66},
        {3.33, 3.0, 3.66, 3.0, -1},
        {4.0, 3.66, 2.66, -1, -1},
        {2.66, 2.33, 4.0, -1, -1},
        {3.33, 3.66, 4.0, 3.0, 3.33}
    };
    string names[] = {"Ali", "Hiba", "Asma", "Zain", "Faisal"};

    for (int i = 0; i < 5; i++) {
        double avg = 0;int count = 0;
        for (int j = 0; j < 5; j++)
            if (marks[i][j] != -1) {
                avg += marks[i][j];
                count++;
            }
        avg /= count;
        cout << "GPA of " << names[i] << " in " << count << " courses is: " << avg << endl;
    }

    return 0;
}