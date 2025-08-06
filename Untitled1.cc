#include <bits/stdc++.h>
using namespace std;

const int INF = 1e18;

bool isValidMidpoint(int n, vector<int>& array, int totalSum, int additionValue){
    vector<int> newArray = array;
    newArray[n-1] += additionValue;
    int newSum = totalSum + additionValue;
    double newAverage = newSum/(2.0*n);
    int countBelowAverage = 0;

    for(int i =0; i<n; i++){
        if(newAverage > newArray[i]){
            countBelowAverage++;
        }
    }
    return countBelowAverage > n/2;
}
int findMinimumAdditionValue(int n, vector<int>& array, int totalSum){
    int left =0, right = INF, bestAddition = -1;

    while(left <= right){
        int midpoint = left + (right-left)/2;
        if(isValidMidpoint(n, array, totalSum, midpoint)){
            bestAddition = midpoint;
            right = midpoint -1;
        }else {
            left = midpoint + 1;
        }
    }

    return bestAddition;
}


void processTestCase(){
    int n;
    cin>>n;
    int totalSum = 0;
    vector<int> array(n);
    for(int i=0; i<n;i++){
        cin>>array[i];
        totalSum += array[i];
    }
    if(n==1){
        cout<< -1<< endl;
    }
    if(n==2){
        cout<<-1<<endl;
        return;
    }
    sort(array.begin(), array.end());

    int countBelowAverage = 0;

    int result = findMinimumAdditionValue(n, array, totalSum);
    cout << result<<endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int testCases;
    cin>>testCases;
    while(testCases--)
        processTestCase();
    return 0;
}
