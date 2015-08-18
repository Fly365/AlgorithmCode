/*---------------------------------------
*   日期：2015-08-18
*   作者：SJF0115
*   题目：1006.约瑟夫问题I
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/11b018d042444d4d9ca4914c7b84a968?rp=3&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Joseph {
public:
    int getResult(int n, int m) {
        list<int> circle;
        // 初始状况
        for(int i = 1;i <= n;++i){
            circle.push_back(i);
        }//for
        list<int>::iterator cur = circle.begin();
        while(circle.size() > 1){
            // 数到m的人出局
            for(int i = 0;i < m - 1;++i){
                ++cur;
                if(cur == circle.end()){
                    cur = circle.begin();
                }//if
            }// for
            // 因为删除数到m的人要记录下一个人的地址
            list<int>::iterator next = ++cur;
            if(next == circle.end()){
                next = circle.begin();
            }//if
            --cur;
            // 删除数到m的人
            circle.erase(cur);
            // 从下一个人继续开始
            cur = next;
        }//while
        return circle.front();
    }
};

int main() {
    Joseph s;
    int n = 5;
    int m = 3;
    cout<<s.getResult(n,m)<<endl;
    return 0;
}
