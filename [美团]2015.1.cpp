/*-------------------------------------
*   日期：2015-08-05
*   作者：SJF0115
*   来源：美团
*   博客：
------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string SortLetter(string letter){
    int size = letter.size();
    vector<int> lowerCount(26,0);
    // 判断是否是小写字母
    for(int i = 0;i < size;++i){
        if(islower(letter[i])){
            ++lowerCount[letter[i]-'a'];
            letter[i] = letter[i] - 'a' + 'A';
        }//if
    }//for
    // 排序
    sort(letter.begin(),letter.end());
    // 还原小写
    for(int i = 0;i < size;++i){
        int index = letter[i]-'A';
        if(lowerCount[index] > 0){
            letter[i] = index + 'a';
            --lowerCount[index];
        }//if
    }//for
    return letter;
}

int main(){
    string str;
    //freopen("C:\\Users\\Administrator\\Desktop\\acm.txt","r",stdin);
    while(cin>>str){
        cout<<SortLetter(str)<<endl;
    }//while
    return 0;
}
