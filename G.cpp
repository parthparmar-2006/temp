#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<long long> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    unordered_map<long long, int> modCount;
    modCount[0] = 1; 

    long long prefixSum = 0, cnt = 0;

    for (int i = 0; i < n; i++) {
        prefixSum += arr[i];
        long long mod = ((prefixSum % n) + n) % n;

        if (modCount.find(mod) != modCount.end()) {
            cnt += modCount[mod];
        }

        modCount[mod]++;
    }

    cout << cnt;
    return 0;
}
