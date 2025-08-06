#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, x, y;
        cin >> n >> x >> y;

        if (n == 0) {
            cout << 0 << endl;
            continue;
        }

        long long seconds = (n + min(x, y) - 1) / min(x, y);
        cout << seconds << endl;
    }

    return 0;
}

