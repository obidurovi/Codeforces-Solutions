#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t; // Number of test cases
    cin >> t;

    while (t--) {
        int n; // Total population
        cin >> n;

        vector<long long> wealth(n);
        long long totalWealth = 0;
        long long maxWealth = 0;

        // Input wealth values
        for (int i = 0; i < n; ++i) {
            cin >> wealth[i];
            totalWealth += wealth[i];
            maxWealth = max(maxWealth, wealth[i]);
        }

        // Calculate the initial number of unhappy people
        int unhappyCount = 0;
        long long currentHalfAverage = (totalWealth + maxWealth) / (2 * n); // Current half average

        for (int i = 0; i < n; ++i) {
            if (wealth[i] < currentHalfAverage) {
                unhappyCount++;
            }
        }

        // If more than half are already unhappy, no gold is needed
        if (unhappyCount > n / 2) {
            cout << 0 << endl;
            continue;
        }

        // Binary search for the minimum x needed
        long long low = 0, high = 1e6, answer = -1;

        while (low <= high) {
            long long mid = low + (high - low) / 2;

            // Calculate new half average after adding mid to the richest person's wealth
            long long newHalfAverage = (totalWealth + (maxWealth + mid)) / (2 * n);
            int newUnhappyCount = 0;

            for (int i = 0; i < n; ++i) {
                if (wealth[i] < newHalfAverage) {
                    newUnhappyCount++;
                }
            }

            if (newUnhappyCount > n / 2) {
                answer = mid; // Found a valid x
                high = mid - 1; // Try for a smaller x
            } else {
                low = mid + 1; // Increase x
            }
        }

        cout << answer << endl; // Output the minimum x found
    }

    return 0;
}
