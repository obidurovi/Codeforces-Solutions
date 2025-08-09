#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool is_prime(int num);

int main() {
    int n, m;
    cin >> n >> m;

    int next_prime = n + 1;
    while (true) {
        if (is_prime(next_prime)) {
            break;
        }
        next_prime++;
    }

    // Check if m is the next prime
    if (next_prime == m) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}


bool is_prime(int num) {
    if (num <= 1) return false;
    for (int i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true; 
}
