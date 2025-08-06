#include<bits/stdc++.h>
using namespace std;

int main(){
    string capital;
    cin>> capital;

    if(capital[0]>=97 && capital[0]<=122){
        capital[0] = char(int(capital[0])) - 32;
    }

    cout<<capital<<endl;

    return 0;
}
