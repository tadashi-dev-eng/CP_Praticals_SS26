#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int total = 1 << N;
    int evenCount = 0;

    for (int mask = 0; mask < total; ++mask) {
        int sum = 0;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                sum += arr[i];
            }
        }
        if ((sum & 1) == 0) {
            evenCount++;
        }
    }

    cout << evenCount << endl;
    return 0;
}
