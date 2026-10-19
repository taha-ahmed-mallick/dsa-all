#include <iostream>
#include <vector>
using namespace std;

class ProductOfNumbers {
    vector<int> products;

public:
    ProductOfNumbers() : products() { products.push_back(1); }

    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
        } else
            products.push_back(num * products.back());
    }

    int getProduct(int k) {
        if (k >= (int)products.size()) return 0;
        return products.back() / products[products.size() - k - 1];
    }
};

int main() {
    ProductOfNumbers* product = new ProductOfNumbers();
    product->add(3);
    product->add(0);
    product->add(2);
    product->add(5);
    product->add(4);
    cout << product->getProduct(2) << endl;
    cout << product->getProduct(3) << endl;
    cout << product->getProduct(4) << endl;
    product->add(8);
    cout << product->getProduct(2) << endl;
    return 0;
}