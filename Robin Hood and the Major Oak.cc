#include <iostream>
using namespace std;

int main() {
    int t;  // Number of test cases
    cin >> t;

    while (t--) {
        long long n, k;  // Year `n` and leaf duration `k`
        cin >> n >> k;

        // Determine if the number of leaves in year `n` is even or odd.
        bool isOdd = false;  // Tracks whether total number of leaves is odd or not

        // Check from year max(1, n - k + 1) to year n, whether the sum is odd or even
        for (long long i = max(1LL, n - k + 1); i <= n; i++) {
            if (i == 1) {
                isOdd = !isOdd;  // Year 1 adds 1 leaf, which is odd
            } else if (i % 2 == 1) {
                isOdd = !isOdd;  // Odd powers i^i contribute odd values
            }
            // Even powers of i^i do not affect the total parity, as they are even
        }

        // Output the result based on whether the total leaves in year n is odd
        if (isOdd) {
            cout << "NO" << endl;  // Odd number of leaves
        } else {
            cout << "YES" << endl;  // Even number of leaves
        }
    }

    return 0;
}
