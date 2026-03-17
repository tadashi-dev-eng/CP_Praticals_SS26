#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N = 3;
    cin >> N;

    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    int total = 1 << N; // 2^N possible subsets
    for (int mask = 0; mask < total; ++mask) {
        cout << "{";

        bool first = true;
        for (int i = 0; i < N; ++i) {
            if (mask & (1 << i)) {
                if (!first) cout << " ";
                cout << arr[i];
                first = false;
            }
        }

        cout << "}" << endl;
    }

    return 0;
}
