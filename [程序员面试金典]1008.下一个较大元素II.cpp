/*---------------------------------------
*   日期：2015-08-18
*   作者：SJF0115
*   题目：1008.下一个较大元素II
*   来源：程序员面试金典
*   网址：http://www.nowcoder.com/practice/a0c19f3489774fe693d71490ce83b648?rp=4&ru=/ta/cracking-the-coding-interview
-----------------------------------------*/
#include <iostream>
#include <map>
#include <vector>
using namespace std;

class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        vector<int> result;
        int size = A.size();
        if(size == 0 || n <= 0){
            return result;
        }//if
        map<int,int> Map;
        for(int i = size - 1;i >= 0;--i){
            map<int,int>::iterator ite = Map.begin();
            // 每个元素的后面比它大的最小的元素
            while(ite != Map.end() && A[i] >= ite->first){
                ++ite;
            }//while
            // 未找到
            if(ite == Map.end()){
                result.insert(result.begin(),-1);
            }//if
            else{
                result.insert(result.begin(),ite->first);
            }//else
            Map.insert(make_pair(A[i],i));
        }//for
        return result;
    }
};

int main() {
    NextElement s;
    vector<int> vec = {11,13,10,5,12,21,3};
    int n = 7;
    vector<int> result = s.findNext(vec,n);
    for(int i = 0;i < result.size();++i){
        cout<<result[i]<<" ";
    }//for
    cout<<endl;
    return 0;
}



class NextElement {
public:
    vector<int> findNext(vector<int> A, int n) {
        // write code here
        map<int,int> mm;
        vector<int> bigger(n,-1);
        for (int i = n - 1 ; i >= 0 ; --i) {
            map<int,int>::iterator mmit = mm.upper_bound(A[i]);
            if (mmit != mm.end())
                bigger[i] = mmit->first;
            mm.insert(make_pair(A[i],i));
        }
        return bigger;
    }
};
