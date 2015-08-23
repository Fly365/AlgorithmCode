/*---------------------------------------
*   日期：2015-08-23
*   作者：SJF0115
*   题目：1001.倒置英文句子中单词的字母顺序
*   来源：华为机试练习题
-----------------------------------------*/
#include <iostream>
#include <string>
using namespace std;


// 判断是否是字母
bool IsLetter(char c){
    if( (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') ){
        return true;
    }//if
    return false;
}
// 翻转单词
string ReverseWord(string str){
    int size = str.size();
    int index = 0;
    string result;
    string tmp;
    while(index < size){
        if(IsLetter(str[index])){
            tmp.insert(tmp.begin(),str[index]);
        }//if
        else{
            result += tmp;
            result += str[index];
            tmp.clear();
        }//else
        ++index;
    }//while
    if(IsLetter(str[index-1])){
        result += tmp;
    }//if
    return result;
}

int main(){
    string str;
    while(getline(cin,str)){
        cout<<ReverseWord(str)<<endl;
    }//while
    return 0;
}
