/*---------------------------------------
*   日期：2015-08-18
*   作者：SJF0115
*   题目：1007.基本字符串压缩
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/21f3a84300c94db092e0b5a7bf2d0ad1?rp=1&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Zipper {
public:
    string zipString(string iniString) {
        string result = "";
        int size = iniString.size();
        if(size == 0){
            return result;
        }//if
        result += iniString[0];
        int index = 1;
        int count = 1;
        while(index < size){
            // 如果当前字符不同于前一个字符则压缩前面字符
            if(iniString[index] != iniString[index-1]){
                result += to_string(count);
                count = 0;
                result += iniString[index];
            }//if
            ++count;
            ++index;
        }//while
        result += to_string(count);
        // 压缩后的字符串没有变短，则返回原先的字符串
        if(result.size() >= size){
            return iniString;
        }//if
        return result;
    }
};

int main() {
    Zipper s;
    //string str("aabcccccaaa");
    string str("welcometonowcoderrrrr");
    cout<<s.zipString(str)<<endl;
    return 0;
}
