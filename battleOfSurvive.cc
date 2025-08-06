#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<long long> a(n);

        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        // If the array has only one element, the result is 0
        if (n == 1) {
            cout << 0 << endl;
            continue;
        }

        // Calculate the potential differences
        long long result = LLONG_MAX;

        // Option 1: Check the difference between max and min in the whole array
        result = min(result, a[n-1] - a[0]);

        // Option 2: Check the difference between consecutive elements
        for (int i = 1; i < n; i++) {
            result = min(result, a[i] - a[i-1]);
        }

        // Option 3: Consider the last element - minimum in the range and max in the range - first element
        long long max_val = *max_element(a.begin(), a.end());
        long long min_val = *min_element(a.begin(), a.end());

        result = min(result, max_val - a[0]);
        result = min(result, a[n-1] - min_val);

        // Output the minimum possible difference
        cout << result << endl;
    }

    return 0;
}
