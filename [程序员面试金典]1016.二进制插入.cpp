          i   j    
1024：10000000000
19  ：    10011
可以看到上面得出，只要我们用1011与1024的第j位到第i位做或运算（|）即可。
我们想到可以让10011左移j位就可以正常做运算了。
10000000000
00001001100
-------------------
10001001100 ---->1100（十进制）

/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1016.二进制插入
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/30c1674ad5694b3f8f0bc2de6f005490?rp=2&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
using namespace std;

class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // m左移j位
        m <<= j;
        return n | m;
    }
};


class BinInsert {
public:
    int binInsert(int n, int m, int j, int i) {
        // write code here
        return n+(m<<j);
    }
};

int main() {
    BinInsert s;
    int n = 1024,m = 19,j = 2,i = 6;
    cout<<s.binInsert(n,m,j,i)<<endl;
    return 0;
}
