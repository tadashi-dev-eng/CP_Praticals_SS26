# include <iostream>
# include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> arr = {1,2,2,3,4,4,5};

    cout << "Original values: ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    sort(arr.begin(), arr.end());

    auto last = unique(arr.begin(), arr.end());
    arr.erase(last, arr.end());

    cout << "Unique values: ";
    for (auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    return 0;

}
