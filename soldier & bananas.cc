#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, w, totalCost = 0;
    cin>>k>>n>>w;

    for(int i = 1; i<=w; i++){
        totalCost += k*i;
    }
    if(totalCost > n){
        cout<< totalCost - n<<endl;
    }else{
        cout<< 0<<endl;
    }

    return 0;
}
