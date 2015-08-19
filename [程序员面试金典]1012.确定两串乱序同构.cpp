以空间换时间。
（1）如果两个字符串的长度不相等，那肯定是不能进行同构。
（2）如果两个字符串的长度相等，则分别统计字符串AB中的各个字符的个数。没出现的字符个数肯定为0。
最多256个字符，从0开始遍历到256，判断这256个字符出现情况是否一样。如果一样则说明可以重新排列获得。
/*---------------------------------------
*   日期：2015-08-19
*   作者：SJF0115
*   题目：1012.确定两串乱序同构
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/164929d4acd04de5b0ee2d93047b3b20?rp=1&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Same {
public:
    bool checkSam(string stringA, string stringB) {
        int size1 = stringA.size();
        int size2 = stringB.size();
        if(size1 != size2){
            return false;
        }//if
        vector<int> hash1(256,0);
        vector<int> hash2(256,0);
        // 统计A字符串中各字符的个数
        for(int i = 0;i < size1;++i){
            ++hash1[stringA[i]];
        }//for
        // 统计B字符串中各字符的个数
        for(int i = 0;i < size2;++i){
            ++hash2[stringB[i]];
        }//for
        // 判断各字符的个数是否一样
        for(int i = 0;i < 256;++i){
            if(hash1[i] != hash2[i]){
                return false;
            }//if
        }//for
        return true;
    }
};

int main() {
    Same s;
    string str1("Here you are");
    string str2("Are you here");
    cout<<s.checkSam(str1,str2)<<endl;
    return 0;
}
