#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q1, q2, result;
    int arr[] = {4, 7, 11, 20, 5, 9};
    int n = (sizeof(arr)) / (sizeof(arr[0]));

    for(int i = 0; i < n/2; i++){
        q1.push(arr[i]);
    }
    for(int i = n/2; i < n; i++){

        q2.push(arr[i]);
}

    while(!q1.empty() && !q2.empty()) {
        result.push(q1.front());
        q1.pop();
        result.push(q2.front());
        q2.pop();
    }

    while(!result.empty()) {
        cout << result.front() << " ";
        result.pop();
    }
    cout << endl;
    return 0;
}
