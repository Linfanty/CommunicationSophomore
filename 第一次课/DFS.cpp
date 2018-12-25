/**
 * DFS����α����
 * ǰ��������visit����ȫ�����ó�false
 * @param n ��ǰ��ʼ�����Ľڵ�
 * @param d ��ǰ��������
 * @return �Ƿ��н�
 */
bool DFS(Node n, int d){
    if (isEnd(n, d)){//һ��������ȵ���һ������״̬���ͷ���true
        return true;
    }

    for (Node nextNode in n){//����n���ڵĽڵ�nextNode
        if (!visit[nextNode]){//
            visit[nextNode] = true;//����һ�������У�nextNode�����ٴγ���
            if (DFS(nextNode, d+1)){//����������н�
                //��Щ�������飬�����¼�����ȵ�
                return true;
            }

            //�������ó�false����Ϊ���п��ܳ�������һ�������ı��·����
            visit[nextNode] = false;
        }
    }
    return false;//���������޽�
}
