/* poj 3436 最大流-拆点

题意：

有一些机器用来构成一个组装电脑的生产线，每台机器对输入机器的电脑有要求，符合要求的电脑被送入机器后会输出一台规定配件情况的电脑。而且分别告知每台机器在单位时间内处理电脑的台数。将这些机器连成一个生产线，使得单位时间内出产的完整的电脑数量最多，完整的电脑就是具有所有配件的电脑。输出单位时间内的最大出产台数。

分析：

这个是一个网络流，对流过每个点的流量有限制，这样就需要拆点，把每个结点拆成两个，一个入点，一个出点，并从入点到出点连接一条边流量为点的的流向限制，把所有接入该点的边接入它的入点，从该点流出的边从出点流出。

这题的建图方法是，每个机器是一个点，把源与所有没有必须元件的入点连接，所有完整元件的出点与汇连接，若一台机器的输出能符合另一台机器的输入条件则连一条边。把每个机器拆点，其内部边流量为其生产速度，具体建图参考代码。
因为点比较多，而符合要求的边是比较少的，所以求最大流采用的是EK算法，时间复杂度O(nm^2),可以尝试一下，如果用Dinic算法会慢点，时间复杂度是O(n^2m)
*/  
    #include<iostream>  
    #include<cstdio>  
    #include<cstring>  
    #include<vector>  
    #include<queue>  
    using namespace std;  
    const int INF=0x3f3f3f3f;  
    const int N=100+9;  
    struct Edge  
    {  
        int from,to,cap,flow;  
    };  
    vector<Edge>edges;  
    vector<int>G[N];  
    int pre[N];//记录路径  
    int vis[N];//起点到i的可改进量  
    int s,t;  
    bool bfs()  
    {  
        memset(vis,0,sizeof(vis));  
        queue<int>q;  
        q.push(s);  
        vis[s]=INF;  
        while(!q.empty()){  
            int x=q.front();q.pop();  
            for(int i=0;i<G[x].size();i++){  
                Edge& e=edges[G[x][i]];  
                if(!vis[e.to]&&e.cap>e.flow){  
                    vis[e.to]=min(vis[x],e.cap-e.flow);  
                    pre[e.to]=G[x][i];  
                    q.push(e.to);  
                }  
            }  
        }  
        return vis[t];  
    }  
      
    int Maxflow()  
    {  
        int flow=0;  
        while(bfs()){  
            for(int u=t;u!=s;u=edges[pre[u]].from){  
                edges[pre[u]].flow+=vis[t];  
                edges[pre[u]^1].flow-=vis[t];  
            }  
            flow+=vis[t];  
        }  
        return flow;  
    }  
    void addedge(int from,int to,int cap)  
    {  
        edges.push_back((Edge){from,to,cap,0});  
        edges.push_back((Edge){to,from,0,0});  
        int m=edges.size();  
        G[from].push_back(m-2);  
        G[to].push_back(m-1);  
    }  
    int a[N][N],n,p;  
    void build()  
    {  
        //建图拆点，其中1-n是出点，n+1-2n是入点  
        for(int i=1;i<=n;i++){  
            addedge(i,n+i,a[i][0]); //出点指向入点，容量是生产量  
            bool flag=1;  
            for(int j=1;j<=p;j++)if(a[i][j]==1)flag=0;  
            if(flag)addedge(s,i,INF); //超源点指向入点，容量无限  
            flag=1;  
            for(int j=p+1;j<2*p+1;j++)if(a[i][j]!=1)flag=0;  
            if(flag)addedge(n+i,t,INF); //出点指向超汇点，容量无限  
            for(int j=1;j<=n;j++){  
                if(i==j)continue;  
                flag=1;  
                for(int k=1;k<=p;k++)if(a[j][k]!=2&&a[j][k]!=a[i][k+p])flag=0;  
                if(flag)addedge(n+i,j,INF); //如果某个出点可以和某个入点匹配，那么连边，容量无限  
            }  
        }  
      
    }  
    int main()  
    {  
        scanf("%d%d",&p,&n);  
        for(int i=1;i<=n;i++)  
            for(int j=0;j<2*p+1;j++)scanf("%d",&a[i][j]);  
        s=0,t=2*n+1;  
        build();  
        int res=Maxflow();  
        int tot=0;  
        int ans[N][3];  
        for(int u=n+1;u<t;u++)for(int i=0;i<G[u].size();i++){  
            Edge& e=edges[G[u][i]];  
            if(e.to>0&&e.to<=n&&e.flow>0)ans[tot][0]=u-n,ans[tot][1]=e.to,ans[tot++][2]=e.flow;  
        }  
        printf("%d %d\n",res,tot);  
        for(int i=0;i<tot;i++)printf("%d %d %d\n",ans[i][0],ans[i][1],ans[i][2]);  
        return 0;  
    }  