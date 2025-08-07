#include <iostream>
using namespace std;

int light(int n){
    if (n == 0) return 1;
    else return 0;
}
int main(){
    int grid[3][3], initiallight[3][3];
    for(int i = 0; i < 3; i++){
        for ( int j = 0; j < 3; j++){
            cin>>grid[i][j];
            if( grid[i][j] % 2 == 0  ){
                grid[i][j] = 0;
            }else{
                grid[i][j] = 1;
            }

            initiallight[i][j] = 1;
        }
    }

    // This is the corrected loop
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++) {
            // Only do something if the button was pressed an odd number of times
            if (grid[i][j] % 2 == 1) {
                // Toggle the current light
                initiallight[i][j] = light(initiallight[i][j]);
                
                // AND toggle all adjacent lights
                if (i > 0) initiallight[i-1][j] = light(initiallight[i-1][j]);
                if (j > 0) initiallight[i][j-1] = light(initiallight[i][j-1]);
                if (i < 2) initiallight[i+1][j] = light(initiallight[i+1][j]);
                if (j < 2) initiallight[i][j+1] = light(initiallight[i][j+1]);
            }
        }
    }

    for(int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout<<initiallight[i][j];
        }
        cout<<endl;
    }
    
    return 0;
}