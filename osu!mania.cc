#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>columns;
        for(int i=0; i<n; i++){
            string row;
            cin>>row;
            for(int j=0; j < 4; j++){
                if(row[j] == '#'){
                    columns.push_back(j + 1);
                    break;
                }
            }
        }
        for(int i=n-1; i >= 0; i--){
            cout<< columns[i]<<endl;
        }
    }
    return 0;
}


