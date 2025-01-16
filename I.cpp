#include <bits/stdc++.h>
using namespace std;

using ll = long long;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second;
}

class TestCase {
    int n, k;
    vector<pair<int, int>> frequency;
    vector<int> result;

public:
    void solve() {
        cin >> n >> k;

        map<int, int> countMap;
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            countMap[x]++;
        }

        for (const auto& [value, count] : countMap) {
            frequency.emplace_back(value, count);
        }

        sort(frequency.begin(), frequency.end(), compare);

        int low = 0, high = 2e5 + 10, optimalTarget = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canFormSet(mid)) {
                optimalTarget = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        for (int x : result) {
            cout << x << " ";
        }
        cout << endl;
    }

private:
    bool canFormSet(int target) {
        if (target == 0) return true;

        int count = 0;
        vector<int> temp;

        for (const auto& [value, freq] : frequency) {
            int fullSets = freq / target;
            if (fullSets == 0) break;

            for (int i = 0; i < fullSets; i++) {
                temp.push_back(value);
                count++;
                if (count == k) {
                    result = temp;
                    return true;
                }
            }
        }

        return false;
    }
};

int main() {
    ios_base::sync_with_stdio(false);

    int testCases = 1;
    while (testCases--) {
        TestCase tc;
        tc.solve();
    }

    return 0;
}
