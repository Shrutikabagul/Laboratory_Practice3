#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;

    // Constructor
    Item(int v, int w) : value(v), weight(w) {}
};

// Comparator function to sort items by their value-to-weight ratio
bool compare(const Item &a, const Item &b) {
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}

double fractionalKnapsack(int W, vector<Item> &items) {
    // Sort items by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    int currentWeight = 0;
    double finalValue = 0.0;

    // Iterate through all items
    for (auto &item : items) {
        // If the entire item can be taken
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            finalValue += item.value;
        }
        // Take the fraction of the item that fits
        else {
            int remainingWeight = W - currentWeight;
            finalValue += item.value * ((double)remainingWeight / item.weight);
            break;  // Knapsack is full
        }
    }

    return finalValue;
}

int main() {
    int n, W;

    // Input the number of items and knapsack capacity
    cout << "Enter the number of items: ";
    cin >> n;

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    // Input each item's value and weight
    vector<Item> items;
    for (int i = 0; i < n; i++) {
        int value, weight;
        cout << "Enter value and weight for item " << i + 1 << ": ";
        cin >> value >> weight;
        items.push_back(Item(value, weight));
    }

    // Calculate the maximum value for the knapsack
    double maxValue = fractionalKnapsack(W, items);
    cout << "Maximum value in the knapsack = " << maxValue << endl;

    return 0;
}
