/*********************************
*   日期：2015-01-28
*   作者：SJF0115
*   题目: 高精度乘法(大数乘法)
*   博客：
**********************************/
#include <iostream>
#include <cstring>
using namespace std;

string MultiplyString(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    // 容错处理
    if(len1 <= 0 || len2 <= 0){
        return "";
    }//if
    int sum = 0;
    int len3 = len1 + len2;
    char result[len3];
    memset(result,'0',sizeof(result[0])*(len3+1));
    for(int i = len1 - 1,m = 0;i >= 0;--i,++m){
        for(int j = len2 - 1,n = 0;j >= 0;--j,++n){
            sum = (num1[i] - '0') * (num2[j] - '0') + result[m+n] - '0';
            result[m+n] = sum % 10 + '0';
            // 进位
            result[m+n+1] += sum / 10;
        }//for
    }//for
    //去掉前导0 确定乘积的位数
    while(result[len3] == '0' && len3 > 0){
        --len3;
    }//while
    //注意：加'\0'
    result[len3+1] = '\0';
    //翻转
    int temp;
    for(int i = 0,j = len3;i < j;++i,--j){
        temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }//for
    return string(result);
}

int main(){
    string num1("2");
    string num2("123");
    string result = MultiplyString(num1,num2);
    // 输出
    cout<<result<<endl;
    return 0;
}<span style="color:#ff0000;">
</span>
