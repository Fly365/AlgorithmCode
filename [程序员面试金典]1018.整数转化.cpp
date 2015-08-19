题目描述

编写一个函数，确定需要改变几个位，才能将整数A转变成整数B。
给定两个整数int A，int B。请返回需要改变的数位个数。
测试样例：
10,5
返回：4

代码
/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1018.整数转化
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/c7df20a5a39e4357aecc1071e7fd523c?rp=2&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
using namespace std;
class Transform {
public:
    int calcCost(int A, int B) {
        return GetOneCount(A ^ B);
    }
private:
    int GetOneCount(int num){
        int count = 0;
        while(num != 0){
            num = num & (num -1);
            count++;
        }//while
        return count;
    }
};
int main() {
    Transform s;
    int a = 10;
    int b = 5;
    cout<<s.calcCost(a,b)<<endl;
    return 0;
}
