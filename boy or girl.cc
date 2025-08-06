#include<bits/stdc++.h>
using namespace std;

int main(){
    string userName;
    cin>>userName;

    set<char>userSet;

    for(int i =0; i<userName.size(); i++){
        userSet.insert(userName[i]);
    }
    if(userSet.size()%2 == 0){
        cout<<"CHAT WITH HER!"<<endl;
    }else{
        cout<<"IGNORE HIM!"<<endl;

    }

    return 0;
}

