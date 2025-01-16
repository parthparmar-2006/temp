#include<bits/stdc++.h>
using namespace std;
bool canSplit(const vector<int>& arr, int k, long long maxSum) {
    long long currentSum = 0;
    int subarrays = 1;
    for (int num : arr) {
        if (currentSum + num > maxSum) {
            subarrays++;
            currentSum = num;
            if (subarrays > k) return false;
        } else {
            currentSum += num;
        }
    }
    return true;
}

long long findMaxMinSum(int n, int k, const vector<int>& arr) {
    long long low = *max_element(arr.begin(), arr.end());
    long long high = accumulate(arr.begin(), arr.end(), 0LL);
    long long answer = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canSplit(arr, k, mid)) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << findMaxMinSum(n, k, arr) << endl;

    return 0;
}
