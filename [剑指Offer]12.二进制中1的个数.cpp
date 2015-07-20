/*---------------------------------------
*   日期：2015-07-20
*   作者：SJF0115
*   题目: 12.二进制中1的个数
*   结果：AC
*   网址：http://www.nowcoder.com/books/coding-interviews/8ee967e43c2c4ec193b040ea7fbb10b8?rp=1
*   来源：剑指Offer
*   博客：http://blog.csdn.net/SunnyYoona/article/details/46974595
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    int NumberOf1(int n){
        int count = 0;
        while(n){
            n &= (n-1);
            ++count;
        }//while
        return count;
    }
};

int main(){
    Solution s;
    int n;
    while(cin>>n){
        int result = s.NumberOf1(n);
        // 输出
        cout<<result<<endl;
    }//while
    return 0;
}
