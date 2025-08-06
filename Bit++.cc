#include <iostream>
using namespace std;


int main(){
    int n, x = 0;
    cin>>n;
    string s;
    while(n--){
        cin>>s;
        if(s == "++x" || s == "x++"){
            x++;
        }else{
        x--;
        }
    }
    cout<<x<<endl;
    return 0;
}
