#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, count = 0;
    cin>> n;

    string stoneColor;
    cin>> stoneColor;

    for(int i = 0; i<n-1; i++){
        if(stoneColor[i] == stoneColor[i+1]){
            count++;
        }
    }
    cout<<count<<endl;
    return 0;
}
