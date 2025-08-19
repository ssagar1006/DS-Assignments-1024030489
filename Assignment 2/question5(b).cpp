#include<iostream>
#include<vector>
using namespace std;
int main(){
    int rows,cols;
    int i,j;
    cout<<"Enter number of rows:"<<endl;
    cin>>rows;
    cout<<"Enter number of columns:"<<endl;
    cin>>cols;
    int a[rows][cols];
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if(abs(i-j)<=1){
                cout<<"Enter the values:"<<i<<" "<<j<<endl;
                cin>>a[i][j];
            }
        }
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            cout<<a[i][j]<<"";
        }
        cout<<endl;
    }
    return 0;
}