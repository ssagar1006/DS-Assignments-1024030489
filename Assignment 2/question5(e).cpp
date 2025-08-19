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
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            cout << "Enter the values:" <<i<<""<<j<<endl;
            cin>>a[i][j];
        }
        cout << endl;
    }
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            a[i][j]=a[j][i];
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