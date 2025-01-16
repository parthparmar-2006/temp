#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main() {
    long long x;
    int n;
    cin >> x >> n;

    vector<int> positions(n);
    for (int i = 0; i < n; i++) {
        cin >> positions[i];
    }

    set<long long> lights;
    multiset<long long> gaps;

    lights.insert(0);
    lights.insert(x);
    gaps.insert(x);

    for (int i = 0; i < n; i++) {
        long long p = positions[i];
        auto it = lights.upper_bound(p);
        long long right = *it;
        long long left = *prev(it);
        gaps.erase(gaps.find(right - left));
        gaps.insert(p - left);
        gaps.insert(right - p);
        lights.insert(p);
        cout << *gaps.rbegin() << " ";
    }

    return 0;
}
