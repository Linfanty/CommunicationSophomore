#include <bits/stdc++.h>
using namespace std;
bool h[11][11];
bool v[11][11];

int main()
{
    int n, m;
    int ww = 1, www = 1;
    while(cin >> n >> m)
    {
        int mm = m;

        int cnt[15];
        string s;
        memset(h, 0, sizeof(h));
        memset(v, 0, sizeof(v));
        memset(cnt, 0, sizeof(cnt));

        while(mm--)
        {
            int uu, vv;
            cin >> s >> uu >> vv;
            //cout << s[0] << ' ';
            if( s[0] == 'H')
                h[uu][vv] = 1;
            else
                v[vv][uu] = 1;
            //cout << h[uu][vv] << ' ' << v[uu][vv];
        }
/*
        for(int i = 1; i <= n-1; i++)
        {
            for(int j = 1; j <= n-1; j++)
            {
                if(h[i][j] && h[i+1][j] && v[i][j] && v[i][j+1])
                    cnt[1]++;
            }
        }

        for(int i = 1; i <= n-2; i++)
        {
            for(int j = 1; j <= n-2; j++)
            {
                if(h[i][j] && h[i][j+1]                     && v[i][j] && v[i+1][j] &&
                   h[i+2][j] && h[i+2][j+1]                   && v[i][j+2] && v[i+1][j+2])
                    cnt[2]++;
            }
        }
*/
        for(int w = 1; w <= n-1; w++)
        {
            for(int i = 1; i <= n-w; i++)
            {
                for(int j = 1; j <= n-w; j++)/// 遍历左上角的点
                {
                    //cout << w << ' ' << i << ' ' << j << endl;
                    int flag = 1;
                    for(int p = 0; p < w; p++)
                    {
                        //cout << w << ' '<<  p << ' '<< ' ' << i << ' ' << j << ' ' << flag << " h[i][j+p]: " << !h[i][j+p] << " !v[i+p][j]: " << !v[i+p][j]<< endl;
                        if(!h[i][j+p])
                        {
                            flag = 0;
                            break;
                        }
                        if(!v[i+p][j])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if(!flag)   continue;

                    //cout << w << ' ' << i << ' ' << j << ' ' << flag << endl;
                    for(int p = 0; p < w; p++)
                    {
                        if(!h[i+w][j+p])
                        {
                            flag = 0;
                            break;
                        }
                    }//cout << w << ' ' << i << ' ' << j << ' ' << flag << endl;
                    for(int p = 0; p < w; p++)
                    {
                        if(!v[i+p][j+w])
                        {
                            flag = 0;
                            break;
                        }
                    }
                    //cout << w << ' ' << i << ' ' << j << ' ' << flag << endl;

                    if( flag ) cnt[w]++;
                }
            }
        }
        if(www != 1)
            cout << endl << "**********************************" << endl << endl;
        cout << "Problem #" << ww++ << endl << endl;
        int flag = 0;
        for(int i = 1; i <= 9; i++)
        {
            //cout << cnt[i] << endl;
            if( cnt[i] )
           {
                flag = 1;
                cout << cnt[i] << " square (s) of size "<< i << endl;
           }
        }
        if( !flag )
            cout << "No completed squares can be found." << endl;
        www = 0;
    }
}
