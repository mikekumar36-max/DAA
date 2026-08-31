#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// 25/DA/011
// Aman Mandal
struct Item {
    int value;
    int weight;
};

bool compare(Item a, Item b) {
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

double fractionalKnapsack(int capacity, vector<Item>& items) {

    // Sort items by value/weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;

    for (auto item : items) {

        // If the complete item can be taken
        if (item.weight <= capacity) {
            capacity -= item.weight;
            totalValue += item.value;
        }
        // Otherwise take the fraction that fits
        else {
            totalValue += (double)item.value / item.weight * capacity;
            break;
        }
    }

    return totalValue;
}

int main() {

    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    vector<Item> items(n);

    cout << "Enter value and weight of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].value >> items[i].weight;
    }

    double ans = fractionalKnapsack(capacity, items);

    cout << "Maximum value = " << ans << endl;

    return 0;
}