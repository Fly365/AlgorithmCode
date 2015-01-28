/*********************************
*   日期：2015-01-28
*   作者：SJF0115
*   题目: 高精度减法(大数减法)
*   博客：
**********************************/
#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
    string MinusString(string num1, string num2) {
        int len1 = num1.length();
        int len2 = num2.length();
        // 正负
        bool positive = true;
        if(len1 < len2 || (len1 == len2 && num1 < num2)){
            positive = false;
            // 交换使之num1 > num2
            string tmp = num1;
            num1 = num2;
            num2 = tmp;
            int temp = len1;
            len1 = len2;
            len2 = temp;
        }//if
        string result;
        int i = len1 - 1,j = len2 - 1;
        int a,b,sum,carray = 0;
        // 从低位到高位对位做减法
        while(i >= 0 || j >= 0){
            a = i >= 0 ? num1[i] - '0' : 0;
            b = j >= 0 ? num2[j] - '0' : 0;
            sum = a - b + carray;
            carray = 0;
            // 不够减
            if(sum < 0){
                sum += 10;
                carray = -1;
            }//if
            result.insert(result.begin(),sum + '0');
            --i;
            --j;
        }//while
        // 删除前导0
        string::iterator it = result.begin();
        while(it != result.end() && *it == '0'){
            ++it;
        }//while
        result.erase(result.begin(),it);
        return positive ? result : "-"+result;
    }
};

int main(){
    Solution solution;
    string num1("9201");
    string num2("0");
    string result = solution.MinusString(num1,num2);
    // 输出
    cout<<result<<endl;
    return 0;
}

