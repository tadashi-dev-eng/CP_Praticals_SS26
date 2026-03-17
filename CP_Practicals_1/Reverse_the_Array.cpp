# include <iostream>
# include <vector>
# include <algorithm>

using namespace std;

int main() {

    vector<int> arr = {1, 2, 3, 4, 5};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    reverse(arr.begin(), arr.end());

    cout << "Reversed array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
