/**
 * DFS核心伪代码
 * 前置条件是visit数组全部设置成false
 * @param n 当前开始搜索的节点
 * @param d 当前到达的深度
 * @return 是否有解
 */
bool DFS(Node n, int d){
    if (isEnd(n, d)){//一旦搜索深度到达一个结束状态，就返回true
        return true;
    }

    for (Node nextNode in n){//遍历n相邻的节点nextNode
        if (!visit[nextNode]){//
            visit[nextNode] = true;//在下一步搜索中，nextNode不能再次出现
            if (DFS(nextNode, d+1)){//如果搜索出有解
                //做些其他事情，例如记录结果深度等
                return true;
            }

            //重新设置成false，因为它有可能出现在下一次搜索的别的路径中
            visit[nextNode] = false;
        }
    }
    return false;//本次搜索无解
}
