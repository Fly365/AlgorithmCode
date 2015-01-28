//代码一
/*********************************
*   日期：2015-01-28
*   作者：SJF0115
*   题目: 大数加法(高精度加法)
*   博客：
**********************************/
#include <iostream>
using namespace std;

string AddString(string num1,string num2){
    int len1 = num1.length();
    int len2 = num2.length();
    // 容错处理
    if(len1 <= 0){
        return num2;
    }//if
    if(len2 <= 0){
        return num1;
    }
    string result;
    int i = len1-1,j = len2-1;
    int a,b,sum,carry = 0;
    // 倒序相加
    while(i >= 0 || j >= 0 || carry > 0){
        a = i >= 0 ? num1[i] - '0' : 0;
        b = j >= 0 ? num2[j] - '0' : 0;
        // 按位相加并加上进位
        sum = a + b + carry;
        // 进位
        carry = sum / 10;
        result.insert(result.begin(),sum % 10 + '0');
        --i;
        --j;
    }//while
    return result;
}


int main(){
    string num1("72");
    string num2("874");
    string result = AddString(num1,num2);
    // 输出
    cout<<result<<endl;
    return 0;
}

//思路二
/*********************************
*   日期：2015-01-28
*   作者：SJF0115
*   题目: 大数加法(高精度加法)
*   博客：
**********************************/
#include <iostream>
using namespace std;

string AddString(string num1,string num2){
    int len1 = num1.length();
    int len2 = num2.length();
    int max = len1 > len2 ? (len1 + 2) : (len2 + 2);
    char* result = new char[max];
    int index = 0;
    int i = len1 - 1,j = len2 - 1;
    int numA,numB,carry = 0,sum = 0;
    //加法
    while(i >= 0 || j >= 0 || carry > 0){
        numA = i >= 0 ? (num1[i] - '0') : 0;
        numB = j >= 0 ? (num2[j] - '0') : 0;
        sum = numA + numB + carry;
        carry = sum / 10;
        result[index++] = sum % 10 + '0';
        --i;
        --j;
    }//while
    result[index] = '\0';
    //反转
    for(i = 0,j = index - 1;i < j;++i,--j){
        char temp = result[i];
        result[i] = result[j];
        result[j] = temp;
    }//for
    return string(result);
}


int main(){
    string num1("872");
    string num2("874");
    string result = AddString(num1,num2);
    // 输出
    cout<<result<<endl;
    return 0;
}
