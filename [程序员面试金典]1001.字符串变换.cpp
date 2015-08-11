/*---------------------------------------
*   日期：2015-08-11
*   作者：SJF0115
*   题目：1001.字符串变换
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/4818ae796bbc4a85a8cdd8e155c06d46?rp=4&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>
using namespace std;

class Change {
public:
    int countChanges(vector<string> dic, int n, string s, string t) {
        vector<string>::iterator ite = find(dic.begin(),dic.end(),s);
        int result = BFS(s,t,dic);
        if(ite != dic.end()){
            --result;
        }//if
        return result;
    }
private:
    int BFS(string start,string end,vector<string> &dict){
        if(start == end){
            return 0;
        }//if
        // 存放单词和单词所在层次
        queue<pair<string,int> > q;
        q.push(make_pair(start,1));
        // 判断是否访问过
        vector<string> visited;
        visited.push_back(start);
        while(!q.empty()){
            pair<string,int> cur = q.front();
            q.pop();
            string word = cur.first;
            int size = word.size();
            // 穷尽所有可能的变换
            for(int i = 0;i < size;++i){
                string newWord(word);
                // 每次只变换一个字符 有26种可能
                for(int j = 0;j < 26;++j){
                    newWord[i] = 'a'+j;
                    // 找到目标返回
                    if(newWord == end){
                        return cur.second + 1;
                    }//if
                    // 判断之前访问过或者是否在字典里
                    vector<string>::iterator ite = find(dict.begin(),dict.end(),newWord);
                    vector<string>::iterator ite2 = find(visited.begin(),visited.end(),newWord);
                    if(ite2 == visited.end() && ite != dict.end()){
                        visited.push_back(newWord);
                        q.push(make_pair(newWord,cur.second+1));
                    }//if
                }//for
            }//for
        }//while
        return -1;
    }
};

int main() {
    Change s;
    //vector<string> set = {"vvz","bbaa","f","bbba","bbaa","baoa","btoa","bbba","dcki","bbbb","ge","atoj","baaa","btoj","ae"};
    vector<string> set = {"abc","adc","bdc","aaa"};
    string start("abc");
    string end("bdc");
    int result = s.countChanges(set,5,start,end);
    // 输出
    cout<<result<<endl;
    return 0;
}
