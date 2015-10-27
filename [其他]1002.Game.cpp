#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int Max(vector<vector<int> > matrix,int x,int y){
        int row = matrix.size();
        if(row == 0){
            return 0;
        }//if
        int col = matrix[0].size();
        if(col == 0){
            return 0;
        }//if
        vector<vector<bool> > visited(row,vector<bool>(col,false));
        int result = 0;
        DFS(matrix,x,y,row,col,visited,0,result);
        return result;
    }
private:
    void DFS(vector<vector<int> > &matrix,int x,int y,int row,int col,vector<vector<bool> > &visited,int cur,int &result){
		// 越界
		if(x < 0 || x >= row || y < 0 || y >= col){
            return;
        }//if
        // 已访问过
		if(visited[x][y]){
			return;
		}//if
        visited[x][y] = true;
        int tmp = 0;
        // 遇到障碍物 得分清零
        if(matrix[x][y] != -1){
            tmp = cur + matrix[x][y];
        }//if
        // 到达最右边 更新最大值
        if(y == col-1 && tmp > result){
            result = tmp;
        }//if
        // up
        DFS(matrix,x-1,y,row,col,visited,tmp,result);
        // down
        DFS(matrix,x+1,y,row,col,visited,tmp,result);
        // 最右边只能上下移动
        if(y != col-1){
            // right
            DFS(matrix,x,y+1,row,col,visited,tmp,result);
        }//if
        visited[x][y] = false;
    }
};

int main(){
    Solution s;
    int row,col,num;
    //freopen("C:\\Users\\Administrator\\Desktop\\acm.txt","r",stdin);
    while(cin>>row>>col){
        vector<int> line;
        vector<vector<int> > matrix;
        for(int i = 0;i < row;++i){
            line.clear();
            for(int j = 0;j < col;++j){
                cin>>num;
                line.push_back(num);
            }//for
            matrix.push_back(line);
        }//for
        cout<<s.Max(matrix,row-1,0)<<endl;
    }//while
    return 0;
}
