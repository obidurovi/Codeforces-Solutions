#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin>>n;

        string password = "";

        for(int i=0; i<n; ++i){
            string query = "?";
            for(int j=0; j<i; ++j){
                query += password[j];
            }

            query += "0";
            cout<<query<<endl;
            cout.flush();
            int response_zero;
            cin>> response_zero;

            query[i] = '1';
            cout<< query << endl;
            cout.flush();
            int response_one;
            cin>> response_one;

            if(response_one){
                password += '1';
            }else {
                password += '0';
            }
        }

        cout<< "!"<<password<<endl;
        cout.flush();
    }

    return 0;
}
