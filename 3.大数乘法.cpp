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
}

/*********************************
*   日期：2015-01-29
*   作者：SJF0115
*   题目: Karatsuba快速相乘算法
*   博客：
**********************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// given two unequal sized bit strings, converts them to
// same length by adding leading 0s in the smaller string. Returns the
// the new length
int MakeSameLen(string& num1,string& num2){
    int len1 = num1.length();
    int len2 = num2.length();
    if(len1 < len2){
        for(int i = 0;i < len2 - len1;++i){
            num1 = "0" + num1;
        }//for
        return len2;
    }//if
    else{
        for(int i = 0;i < len1 - len2;++i){
            num2 = "0" + num2;
        }//for
        return len1;
    }//else
}
// big number minus function
string MinusString(string num1, string num2) {
    int len1 = num1.length();
    int len2 = num2.length();
    // 相等
    if(num1 == num2){
        return "0";
    }//if
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
// big number add function
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
// 移位
string ShiftString(string num,int len){
    if(num == "0"){
        return num;
    }//if
    for(int i = 0;i < len;++i){
        num += "0";
    }//for
    return num;
}
// Karatsuba快速相乘算法
string KaratsubaMultiply(string num1, string num2) {
    int len = MakeSameLen(num1,num2);
    if(len == 0){
        return 0;
    }//if
    // all digit are one
    if(len == 1){
        return to_string((num1[0] - '0')*(num2[0] - '0'));
    }//if
    int mid = len / 2;
    // Find the first half and second half of first string.
    string x1 = num1.substr(0,mid);
    string x0 = num1.substr(mid,len - mid);
    // Find the first half and second half of second string
    string y1 = num2.substr(0,mid);
    string y0 = num2.substr(mid,len - mid);
    // Recursively computer
    string z0 = KaratsubaMultiply(x0,y0);
    string z1 = KaratsubaMultiply(AddString(x1,x0),AddString(y1,y0));
    string z2 = KaratsubaMultiply(x1,y1);
    // (z2*10^(2*m))+((z1-z2-z0)*10^(m))+(z0)
    // z2*10^(2*m)
    string r1 = ShiftString(z2,2*(len - mid));
    // (z1-z2-z0)*10^(m)
    string r2 = ShiftString(MinusString(MinusString(z1,z2),z0),len - mid);
    return  AddString(AddString(r1,r2),z0);
}


int main(){
    string num1("12345001");
    string num2("1006789");
    string result = KaratsubaMultiply(num1,num2);
    // 输出
    cout<<result<<endl;
    return 0;
}

/*********************************
*   日期：2015-01-29
*   作者：SJF0115
*   题目: Karatsuba快速相乘算法
*   博客：
**********************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// given two unequal sized bit strings, converts them to
// same length by adding leading 0s in the smaller string. Returns the
// the new length
int MakeSameLen(string& num1,string& num2){
    int len1 = num1.length();
    int len2 = num2.length();
    if(len1 < len2){
        for(int i = 0;i < len2 - len1;++i){
            num1 = "0" + num1;
        }//for
        return len2;
    }//if
    else{
        for(int i = 0;i < len1 - len2;++i){
            num2 = "0" + num2;
        }//for
        return len1;
    }//else
}

// big number add function
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
// 移位
long int Shift(int len){
    int num = 1;
    for(int i = 0;i < len;++i){
        num *= 10;
    }//for
    return num;
}


long int KaratsubaMultiply(string num1, string num2) {
    int len = MakeSameLen(num1,num2);
    if(len == 0){
        return 0;
    }//if
    // all digit are one
    if(len == 1){
        return (num1[0] - '0')*(num2[0] - '0');
    }//if
    int mid = len / 2;
    // Find the first half and second half of first string.
    string x1 = num1.substr(0,mid);
    string x0 = num1.substr(mid,len - mid);
    // Find the first half and second half of second string
    string y1 = num2.substr(0,mid);
    string y0 = num2.substr(mid,len - mid);

    long int z0 = KaratsubaMultiply(x0,y0);
    long int z1 = KaratsubaMultiply(AddString(x1,x0),AddString(y1,y0));
    long int z2 = KaratsubaMultiply(x1,y1);
    // Recursively computer
    return (z2 * Shift(2*(len - mid)) + ((z1 - z2 - z0) * Shift(len - mid))) + z0;
}


int main(){
    string num1("12345");
    string num2("6789");
    long int result = KaratsubaMultiply(num1,num2);
    // 输出
    cout<<result<<endl;
    return 0;
}


