#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;

    for(int i =0; i<s.size(); i+=2){
        int min_index = i;

        for(int j =i+2; j<s.size(); j+=2){
            if(s[min_index]> s[j]){
                min_index = j;
            }
        }
        if(min_index != i){
            swap(s[i], s[min_index]);
        }
    }
    cout<<s<<endl;
    return 0;
}
