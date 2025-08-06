#include<bits/stdc++.h>
using namespace std;

int main(){
    int x, step;
    cin>> x;

    if(x%5==0){
        step = x/5;

    }else{
        step = (x/5) +1;
    }

    cout<<step<<endl;

    return 0;
}
