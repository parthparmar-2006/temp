#include <bits/stdc++.h>
using namespace std;

struct Time {
    int i;
    double v;
};

const int MAXN = 1e5;
int a[MAXN], b[MAXN];
Time t[MAXN + 1];

int main() {
    int n, p;
    cin >> n >> p;

    // Input values for a and b
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
        t[i].v = 1.0 * b[i] / a[i]; // Calculate b[i] / a[i] as a floating-point value
        t[i].i = i;                 // Store the original index
    }

    // Sort by the calculated v = b[i] / a[i] values
    sort(t, t + n, [](Time const &x, Time const &y) { return x.v < y.v; });

    // Set an upper bound for the time
    t[n].v = 1e15; // Artificial upper limit to simplify comparisons
    double sum_a = 0, sum_b = 0;
    double time = -1; // Initialize time with a sentinel value
    cout.precision(10);
    cout << fixed;

    // Calculate the time before any device hits 0 power
    for (int i = 0; i < n; ++i) {
        int j = t[i].i; // Access the original index from sorted order
        sum_a += a[j];
        sum_b += b[j];

        // Avoid division by zero and ensure meaningful calculation
        if (sum_a > p) {
            time = 1.0 * sum_b / (sum_a - p);

            // Check if time is valid and does not exceed the next threshold
            if (time < t[i + 1].v) {
                cout << time;
                return 0;
            }
        }
    }

    // If devices can work indefinitely, print -1
    cout << -1;
    return 0;
}
