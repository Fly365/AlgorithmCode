#include <iostream>
#include <vector>
#include <limits.h>
#include <list>
using namespace std;

#define N 100002

// Any two cities are connected directly or indirectly and there is ONLY one path between any 2 cities
class Solution {
public:
    int ShortestPath(vector<list<int> > Map,vector<bool> city,int num){
        if(num <= 0){
            return 0;
        }//if
        if(city[num]){
            return 0;
        }//if
        vector<bool> visited(N,false);
        int result = INT_MAX;
        BFS(Map,city,visited,0,result,num);
        return result;
    }
private:
    void BFS(vector<list<int> > &Map,vector<bool> &city,vector<bool> &visited,int cur,int &result,int pos){
        if(city[pos]){
            if(cur < result){
                result = cur;
            }//if
            return;
        }//if
        visited[pos] = true;
        // 相邻城市
        list<int> c = Map[pos];
        list<int>::iterator ite = c.begin();
        while(ite != c.end()){
            int num = *ite;
            if(!visited[num]){
                int tmp = cur + 1;
                BFS(Map,city,visited,tmp,result,num);
            }//if
            ++ite;
        }//while
        visited[pos] = false;
    }
};

int main(){
    Solution s;
    int x,y,n,m;
    //freopen("C:\\Users\\Administrator\\Desktop\\acm.txt","r",stdin);
    while(cin>>n>>m){
        vector<list<int> > Map(N,list<int>());
        vector<bool> city(N,false);
        city[1] = true;
        for(int i = 1;i <= n-1;++i){
            cin>>x>>y;
            Map[x].push_back(y);
            Map[y].push_back(x);
        }//for
        for(int i = 1;i <= m;++i){
            cin>>x>>y;
            if(x == 1){
                city[y] = true;
            }//if
            else if(x == 2){
                cout<<s.ShortestPath(Map,city,y)<<endl;
            }//else
        }//for
    }//while
    return 0;
}
