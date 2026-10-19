#include <bits/stdc++.h>
#include <ctime>
#include <cstdlib>
using namespace std;

struct SortMetrics
{
    size_t comparisons = 0, swaps = 0;
};

class Sort
{
private:
    static void bubble(vector<int> &arr, SortMetrics &metrics)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
            for (size_t j = 0; j < arr.size() - i - 1; j++)
            {
                metrics.comparisons++;
                if (arr[j] > arr[j + 1])
                {
                    metrics.swaps++;
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
    }

    static void insertion(vector<int> &arr, SortMetrics &metrics)
    {
        for (size_t i = 1; i < arr.size(); i++)
        {
            int key = arr[i];
            int j = static_cast<int>(i) - 1;
            while (j >= 0)
            {
                metrics.comparisons++;
                if (arr[j] > key)
                {
                    arr[j + 1] = arr[j];
                    metrics.swaps++;
                }
                j--;
            }
            arr[j + 1] = key;
        }
    }

    static void selection(vector<int> &arr, SortMetrics &metrics)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i + 1; j < arr.size(); j++)
            {
                metrics.comparisons++;
                if (arr[j] < arr[min])
                    min = j;
            }
            if (min != i)
            {
                metrics.swaps++;
                int temp = arr[i];
                arr[i] = arr[min];
                arr[min] = temp;
            }
        }
    }

    static void printRow(const string& name, size_t comps, size_t swaps, size_t total) {
        cout << left << setw(15) << name 
                  << setw(18) << comps 
                  << setw(15) << swaps 
                  << total << "\n";
    }
public:
    static void sort(vector<int> &arr, const string &type)
    {
        SortMetrics dummy;
        if (type == "bubble") {
            bubble(arr, dummy);
        } else if (type == "insertion") {
            insertion(arr, dummy);
        } else if (type == "selection") {
            selection(arr, dummy);
        } else {
            cout << "\e[1;31mUnkown sorting technique: " << type << "\n\e[0m";
        }
    }

    static void analyze(size_t size) {
        vector<int> original(size);
        for (int i = 0; i < size; i++)
            original[i] = rand() % 1000 + 1; // random number: 1-1000
        
        vector<int> bArr = original;
        vector<int> iArr = original;
        vector<int> sArr = original;

        SortMetrics bMetrics, iMetrics, sMetrics;

        bubble(bArr, bMetrics);
        insertion(iArr, iMetrics);
        selection(sArr, sMetrics);

        cout << "\n=======================================================\n";
        cout << "  SORTING ANALYSIS (N = " << size << " Random Elements)\n";
        cout << "=======================================================\n";
        cout << left << setw(15) << "Algorithm" 
                  << setw(18) << "Comparisons" 
                  << setw(15) << "Swaps/Shifts" 
                  << "Total Ops\n";
        cout << "-------------------------------------------------------\n";

        size_t bTotal = bMetrics.comparisons + bMetrics.swaps;
        size_t iTotal = iMetrics.comparisons + iMetrics.swaps;
        size_t sTotal = sMetrics.comparisons + sMetrics.swaps;

        printRow("Bubble", bMetrics.comparisons, bMetrics.swaps, bTotal);
        printRow("Insertion", iMetrics.comparisons, iMetrics.swaps, iTotal);
        printRow("Selection", sMetrics.comparisons, sMetrics.swaps, sTotal);

        cout << "-------------------------------------------------------\n";

        // determine best and worst based on overall operations
        vector<pair<string, size_t>> results = {
            {"Bubble Sort", bTotal},
            {"Insertion Sort", iTotal},
            {"Selection Sort", sTotal}
        };

        auto best = min_element(results.begin(), results.end(), 
            [](const auto& a, const auto& b) { return a.second < b.second; });
        auto worst = max_element(results.begin(), results.end(), 
            [](const auto& a, const auto& b) { return a.second < b.second; });

        cout << "\033[1;32m[BEST TECHNIQUE]\033[0m  : " << best->first 
                  << " (" << best->second << " total operations)\n";
        cout << "\033[1;31m[WORST TECHNIQUE]\033[0m : " << worst->first 
                  << " (" << worst->second << " total operations)\n";
        cout << "=======================================================\n";
    }
};

void print(const vector<int> &arr)
{
    for (auto element : arr)
        cout << element << " ";
    cout << endl;
}

int main()
{
    srand(time(0)); // random number generator seed
    cout << "Enter elements (enter 0 to stop):\n";
    vector<int> arr;
    int input;
    while (true)
    {
        cin >> input;
        if (input)
            arr.push_back(input);
        else
            break;
    }
    cout << "Enter choice of sorting:\n";
    cout << "1. bubble\n";
    cout << "2. insertion\n";
    cout << "3. selection\n";
    string choice;
    cin >> choice;
    cout << "Entered array: ";
    print(arr);
    cout << "----------------------\nSorting using: " << choice << endl;

    Sort::sort(arr, choice);
    cout << "Sorted Array: ";
    print(arr);

    size_t size;
    cout << "Enter size of analysis: ";
    cin >> size;
    Sort::analyze(size);
    return 0;
}