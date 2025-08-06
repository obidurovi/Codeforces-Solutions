#include <iostream>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long n, k;
        cin>> n >> k;

        long long start_year = max(1LL, n - k + 1);

        long long num_leaves = (n * (n+1)/2) - (start_year * (start_year -1)/2);

        if(num_leaves % 2 == 0){
            cout << "YES\n";
        }else{
            cout<< "NO\n";
        }
    }

    return 0;
}
