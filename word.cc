#include<bits/stdc++.h>
using namespace std;

int main(){
    int upperCase =0, lowerCase=0;
    string s;
    cin>>s;

    for(int i = 0; i<s.size(); i++){
        if(isupper(s[i])){
            upperCase++;
        }else {
            lowerCase++;
        }
    }
    if(upperCase>lowerCase){
        for(int i = 0; i<s.size(); i++){


            cout<<char(toupper(s[i]));
        }

    }else{
        for(int i = 0; i<s.size(); i++){

            cout<<char(tolower(s[i]));
        }
    }

return 0;
}
