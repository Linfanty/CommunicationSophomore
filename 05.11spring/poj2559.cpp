#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

struct Node {
    long long val;
    long long len;
};

stack<Node> s;

int main() {
    int n;
    while( cin >> n ) {
        if( n == 0) break;
        Node q;
        long long maxn = 0, tmp;
        for(int i = 0; i < n; i++) {
            cin >> q.val;
            q.len = 1;
            tmp = 0;

            if(s.empty() || q.val > (s.top().val)) s.push(q);
            else {
                while( !s.empty() && q.val <= (s.top().val)) {
                    s.top().len += tmp;
                    maxn = max(maxn, s.top().val * s.top().len);
                    tmp = s.top().len;
                    s.pop();
                }
                q.len += tmp;
                s.push(q);
            }
        }
        tmp = 0;
        while( !s.empty() ) {
            s.top().len += tmp;
            maxn = max(maxn, s.top().val * s.top().len);
            tmp = s.top().len;
            s.pop();
        }
        cout << maxn << endl;

    }


}

