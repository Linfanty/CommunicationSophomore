#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n, x;
vector<int>  dh[4080][2]; // 0: primary 1: secondary
int dg[50005][2];

bool dfs(int j, int xx) { /// 1 4
    if(dh[j][1].size() == 0)
        return false;

    int fg = 1; /// keyi
/*
    for(int i = 0; i < dh[j][0].size(); i++) {
        int tmp = dh[j][0][i]; /// primary

        //if( dh[j][1][i].size() == 0 ) /// no secondary
        //    continue;
        if( dg[tmp][1] == dg[xx][1] ) {
            /// bukeyi lian
            continue;
        }

    }
*/
    for(int i = 0; i < dh[j][1].size(); i++) {
        int tmp = dh[j][1][i]; /// secondary

        //if( dh[j][1][i].size() == 0 ) /// no secondary
        //    continue;

/// 3 ==
/// int tt = dh[ dg[tmp][0] ][1][xxx];
/// || dh[ dg[tmp][0] ][1][xxx]
/// xx == dh[ tt ][0][yyy]
        if( dh[ dg[tmp][0] ][1].size() != 0 ) {
            for(int xxx = 0; xxx < dh[ dg[tmp][0] ][1].size(); xxx++) {
                int tt = dh[ dg[tmp][0] ][1][xxx]; /// dog
                //for(int yyy = 0; yyy < dg[tt][0]; yyy++) {
                    /// yyy :doghouse
                    if( xx == dg[tt][0] )
                        return false;
                //}

            }
        }

        if( dg[tmp][0] == dg[xx][0] ) {
            /// bukeyi lian
            continue;
        }
        else {
            return false;
        }

    }


    return true;
}

int main(){
    cin >> n >> x;
    if( n - x - 1 < 0)
        cout << -1 << endl;
    else {
        for(int i = 1; i <= x * n; i++) {
            int tmp = (ceil)( (double)i/(double)x);
            dg[i][0] =  tmp;
            dh[tmp][0].push_back(i);
           // cout << tmp << ' ' << i << endl;
        }

        for(int i = x * n; i >= 1; i--) { /// dog

            for(int j = 1; j <= n; j++) { /// doghouse
                if( dg[i][0] == j /// primary
                   || (dh[j][1].size() ==  x) /// secondary
                   || dfs(j, i) ) /// 1 4
                    continue;
                else {
                    //cout << "dfswtywtywty" << j << i << dfs(j,i) << endl;
                    dg[i][1] = j, dh[j][1].push_back(i);
                    break;
                }
            }
        }
        for(int i = 1; i <= n; i++) {

            if( dh[i][1].size() < x)
            {
                cout << -1 << endl;
                return 0;
            }
        }


        for(int i = 1; i <= n; i++) {

             for(int j = 0; j < x; j++) {
                cout << dh[i][0][j] << ' ';
            }
             for(int j = 0; j < x - 1; j++) {
                cout << dh[i][1][j] << ' ';
             }
             cout << dh[i][1][x-1];
             cout << endl;
        }
    }

}