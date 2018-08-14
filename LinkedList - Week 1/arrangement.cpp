#include<bits/stdc++.h>
using namespace std;

void rec( char *arr, int r, int b, int track, int n ){

    // cout << "r = " << r << endl;
    // cout << "b = " << b << endl;
    // cout << "track = " << track << endl;

    if( track == n ){
        for( int i = 0; i < n; ++i ){
            cout << arr[i];
        }
        cout << endl;
        return;
    }

    if( r > 0 ){
        arr[track] = 'R';
        rec( arr, r-1, b, track+1, n );
        // cout << "1" << endl;
    }

    if( b > 0 ){
        arr[track] = 'B';
        rec( arr, r, b-1, track+1, n );
        // cout << "2" << endl;
    }
}

int main(void){
    int r; // No. of red balls
    cout << "Enter the red balls \n";
    cin >> r;

    int b;
    cout << "Enter the blue balls \n";
    cin >> b;

    int n = r + b;
    char arr[n];
    rec( arr, r, b, 0, n );
}