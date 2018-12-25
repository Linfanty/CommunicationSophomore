/*
  ����station���Ϻ���ȳ��������Կ�����һ��stack<int>����ʾstation��
  Ȼ�����ģ��Ĺ�����д����Ϊ����station�ǰ��ձ�ŵ������룬���Կ�����pos������ʾ��
  ����������ģ��ʱ��Ӧ��ע�������������֪�����������������һ����һ����station���ͳ�station
  Ҳ���� pos == A_train[lenB]; һ���ǽ���ʱ������վ����ô��ʱ���Ҫs.push(pos),������һ�ֵ������أ�
  ������������ų�����һ�֣���ô�޷Ǿ��ǵڶ����ˡ���������Ҫ֪�����ڽ�վ֮ǰ�����վ̨���г����ǿ����ȳ�վ��
  ������״̬���������� !s.empty() && s.top() == A_train[lenB].����ֻҪ����˳���ж��⼸������
  �Ϳ���д�����ģ������ˡ�


 �ܽ᣺
 �������Ĺؼ��㣬���ڹ��������ģ�͡��󲿷ֶ��ǿ��������еĻ������ݽṹ���������Ӧ�����ݽṹ���ر��Ƕ���ģ����
 �޷Ǿ���״̬����ת�ƴ������Ǿ�Ҫ�ڻ���ģ�͵Ļ����ϡ���д��ӳ�䵽����״̬��Ψһ������Ȼ���������߼�һһ�Ⱥ��ж�
 ���ɡ�
 */
#include <iostream>
#include <stack>
using namespace std;
const int len = 1e5+5;
int A_train[len];

int main() {
    int n;
    while (cin >> n && n) {
     stack<int> s;
     while ( cin >> A_train[0] && A_train[0]) {

         for (int i = 1; i < n; i++)    cin >> A_train[i];
         int lenB = 0, pos = 1;

         bool ok = true;
         while (lenB < n) {
             if (pos == A_train[lenB]) {  pos++; lenB++; }
             else if(!s.empty() && s.top() == A_train[lenB])
                { s.pop(); lenB++; }
             else if(pos <= n) s.push(pos++);
             else { ok = false; break; }
         }

         cout << (ok ? "Yes" : "No") << endl;
     }
     cout << endl;
    }
}
