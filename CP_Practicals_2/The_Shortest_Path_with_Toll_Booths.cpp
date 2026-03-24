#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    ll M;
    int K;
    if (!(cin >> N >> M >> K)) return 0;
    vector<ll> toll(N);
    for (int i = 0; i < N; i++) {
        cin >> toll[i];
    }

    ll total = 0;
    for (ll x : toll) total += x;

    sort(toll.begin(), toll.end(), greater<ll>());
    ll skip_sum = 0;
    ll best_s = -1;
    for (int s = 0; s <= min(K, N); s++) {
        ll paid = total - skip_sum;
        if (paid <= M) {
            best_s = s;
            break;
        }
        if (s < N) skip_sum += toll[s];
    }

    if (best_s == -1) {
        cout << "-1\n";
    } else {
        ll min_time = (ll)N + best_s;
        cout << min_time << "\n";
    }

    return 0;
}