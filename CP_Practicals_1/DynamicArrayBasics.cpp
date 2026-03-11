#include <iostream>
#include <vector>
#include <algorithm> 
#include <numeric>


using namespace std;

int main() {
    int n;

    // it reads the n numbers of integers.
    cout << "Enter the number of elements (N): ";
    if (!(cin >> n) || n <= 0) {
        cerr << "Invalid input for N." << std::endl;
        return 1;
    }

    // Storing the data determine by the "n" variable in a dynamic container
    vector<int> vec(n);

    // reading the N intergers
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; ++i) {
        std::cin >> vec[i];
    }

    // 4a. Maximum element
    int max_val = *max_element(vec.begin(), vec.end());

    // 4b. Minimum element
    int min_val = *min_element(vec.begin(), vec.end());

    // 4c. Sum of elements
    long long sum_val = accumulate(vec.begin(), vec.end(), 0LL);

    // Printing Results
    cout << "-----------------" << std::endl;
    cout << "Maximum element: " << max_val << std::endl;
    cout << "Minimum element: " << min_val << std::endl;
    cout << "Sum of elements: " << sum_val << std::endl;

    return 0;
}