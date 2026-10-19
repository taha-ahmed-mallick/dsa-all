#include <iostream>
#include <vector>
using namespace std;

struct Element
{
    int val;
    size_t ID;
    static size_t Gen_ID;
    Element(int val) : val(val), ID(Gen_ID) {
        Gen_ID++;
    }
};

size_t Element::Gen_ID = 0;

namespace sorting
{
    void bubble(vector<Element> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            for (size_t j = 0; j < arr.size() - i - 1; j++)
                if (arr[j].val > arr[j + 1].val)
                {
                    Element temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
        }
    }

    void insertion(vector<Element> &arr)
    {
        for (size_t i = 1; i < arr.size(); i++)
        {
            Element key = arr[i];
            int j = i - 1;
            for (; j >= 0 && arr[j].val > key.val; j--)
                arr[j + 1] = arr[j];
            arr[j + 1] = key;
        }
    }

    void selection(vector<Element> &arr)
    {
        for (size_t i = 0; i < arr.size() - 1; i++)
        {
            size_t min = i;
            for (size_t j = i + 1; j < arr.size(); j++)
                if (arr[j].val < arr[min].val)
                    min = j;
            Element temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }

    void print(const vector<Element> &arr)
    {
        cout << "\nVAL: ";
        for (auto element : arr)
            cout << element.val << " ";
        cout << "\n ID: ";
        for (auto element : arr)
            cout << element.ID << " ";
        cout << endl;
    }

    bool stable(vector<Element> arr) {
        for (size_t i = 0; i < arr.size() - 1; i++) {
            if (arr[i].val == arr[i + 1].val && arr[i].ID > arr[i + 1].ID)
                return false;
        }
        return true;
    }
} // namespace sorting

int main()
{
    cout << "Enter elements (enter 0 to stop):\n";
    vector<Element> arr;
    int input;
    while (true)
    {
        cin >> input;
        if (input)
            arr.push_back(Element(input));
        else
            break;
    }

    cout << "Entered array: ";
    sorting::print(arr);
    cout << "----------------------------------------\n";
    
    // copy it two time to check all 3 sorting algorithm
    vector<Element> arr1 = arr;
    vector<Element> arr2 = arr;
    
    sorting::bubble(arr);
    cout << "[Bubble] Sorted array: ";
    sorting::print(arr);
    cout << (sorting::stable(arr) ? "\e[1;32mStable\e[0m" : "\e[1;31mUnstable\e[0m");
    cout << endl;
    
    sorting::insertion(arr1);
    cout << "[Insertion] Sorted array: ";
    sorting::print(arr1);
    cout << (sorting::stable(arr1) ? "\e[1;32mStable\e[0m" : "\e[1;31mUnstable\e[0m");
    cout << endl;
    
    sorting::selection(arr2);
    cout << "[Selection] Sorted array: ";
    sorting::print(arr2);
    cout << (sorting::stable(arr2) ? "\e[1;32mStable\e[0m" : "\e[1;31mUnstable\e[0m");
    cout << endl;
    return 0;
}