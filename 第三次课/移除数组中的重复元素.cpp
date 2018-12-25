#include <iostream>
using namespace std;
int main(){
    int n, ans;
    cin >> n;
    ans = n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n-1; i++){
        if(a[i] == a[i+1])
            ans--;
    }
    cout << ans << endl;
    return 0;
}
