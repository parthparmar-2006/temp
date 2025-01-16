#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> sticks(n);
    for (int i = 0; i < n; i++) {
        cin >> sticks[i];
    }

    sort(sticks.begin(), sticks.end());
    int median = sticks[n / 2];
    
    long long totalCost = 0;
    for (int stick : sticks) {
        totalCost += abs(stick - median);
    }
    
    cout << totalCost << endl;
    return 0;
}
