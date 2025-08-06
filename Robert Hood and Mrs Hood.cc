#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;

        vector<int> jobs(n + 2, 0);

        for (int i = 0; i < k; ++i) {
            int l, r;
            cin >> l >> r;
            jobs[l]++;
            jobs[r + 1]--;
        }

        for (int i = 1; i <= n; ++i) {
            jobs[i] += jobs[i - 1];
        }

        vector<int> overlapCount(n - d + 2, 0);

        for (int startDay = 1; startDay <= n - d + 1; ++startDay) {
            for (int j = startDay; j < startDay + d; ++j) {
                overlapCount[startDay] += jobs[j];
            }
        }

        int brotherDay = 1;
        int maxOverlaps = overlapCount[1];

        for (int startDay = 2; startDay <= n - d + 1; ++startDay) {
            if (overlapCount[startDay] > maxOverlaps) {
                maxOverlaps = overlapCount[startDay];
                brotherDay = startDay;
            }
        }

        int motherDay = 1;
        int minOverlaps = overlapCount[1];

        for (int startDay = 2; startDay <= n - d + 1; ++startDay) {
            if (overlapCount[startDay] < minOverlaps) {
                minOverlaps = overlapCount[startDay];
                motherDay = startDay;
            }
        }

        cout << brotherDay << " " << motherDay << endl;
    }

    return 0;
}
