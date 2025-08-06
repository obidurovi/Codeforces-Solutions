#include <iostream>
using namespace std;

int main() {
    int M, N;
    cin >> M >> N;

    // Calculate the maximum number of dominoes
    int max_dominoes = (M * N) / 2;

    // Output the result
    cout << max_dominoes << endl;

    return 0;
}

