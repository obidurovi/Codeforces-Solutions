#include<bits/stdc++.h>
using namespace std;

int main(){
    string task, result = "";
    cin>> task;

    for(int i =0; i<task.size(); i++){
        char letter = tolower(task[i]);
        if(letter == 'a' || letter == 'o' || letter == 'y' || letter == 'e' || letter == 'u' || letter == 'i'){
            continue;
        }else{
            result += ".";
            result += letter;
        }
    }

    cout<< result <<endl;
    return 0;
}
