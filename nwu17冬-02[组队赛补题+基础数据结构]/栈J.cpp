/*
  由于station符合后进先出规则，所以可以用一个stack<int>来表示station。
  然后采用模拟的规则来写，因为进入station是按照编号递增进入，所以可以用pos变量表示。
  接下来就是模拟时候应该注意的条件，我们知道有以下两种情况，一种是一进来station，就出station
  也就是 pos == A_train[lenB]; 一种是进来时还不出站，那么这时候就要s.push(pos),但是这一种的条件呢？
  我们如果可以排除掉第一种，那么无非就是第二种了。但是我们要知道，在进站之前，如果站台里有车它是可以先出站的
  ，这种状态就条件就是 !s.empty() && s.top() == A_train[lenB].所以只要按照顺序判断这几个条件
  就可以写出这个模拟程序了。


 总结：
 解决问题的关键点，在于构建问题的模型、大部分都是可以用现有的基础数据结构。构造完对应的数据结构，特别是对于模拟题
 无非就是状态见的转移处理，这是就要在基于模型的基础上、先写出映射到个个状态的唯一条件，然后按照问题逻辑一一先后判断
 即可。
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
