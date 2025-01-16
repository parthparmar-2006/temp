#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;

    vector<int> vc(n);
    for (int i = 0; i < n; i++) {
        cin >> vc[i];
    }

    set<int> st;
    int max_length = 0, left = 0;

    for (int right = 0; right < n; right++) {
        while (st.find(vc[right]) != st.end()) {
            st.erase(vc[left]);
            left++;
        }
        st.insert(vc[right]);
        max_length = max(max_length, right - left + 1);
    }

    cout << max_length << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();
    return 0;
}
