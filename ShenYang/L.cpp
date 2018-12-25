#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5;
const int inf = 0x3f3f3f3f;
const double eps = 1e-9;

int n, k, ans, num[maxn];
vector<int> vec[maxn];

void dfs(int u, int pre)
{
    num[u] = 1; //结点本身也算进去
    for(int i = 0; i < vec[u].size(); i++)
    {
        int v1
*/
// 对每一个点i 设它的子树的节点（包括它自身）有p个
// p≥k和n−p≥k 即可. 只需要查点
// 存在这样的点 那么一定存在这样的一条公共边

int main()
{
    int t, u, v;
    cin >> t;
    while( t-- )
    {
        memset(num, 0, sizeof num);
        cin >> n >> k;
        for(int i = 1; i <= n; i++) vec[i].clear();
        for(int i = 1; i < n; i++)
        {
            cin >> u >> v;
            vec[u].push_back(v);
            vec[v].push_back(u);
        }

        ans = 0;
        dfs(1, -1);
        //for(int i = 0; i <= 6; i ++)
        //cout << "i:" << i << ' ' << num[i] << endl;
        cout << ans << endl;
    }
}


