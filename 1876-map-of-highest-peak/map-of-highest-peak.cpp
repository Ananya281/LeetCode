class Solution {
public:
void bfs(queue<pair<int,pair<int,int>>>&q,vector<vector<int>>&vis,vector<vector<int>>&height,vector<vector<int>>& isWater)
{
    int n=isWater.size();
    int m=isWater[0].size();
    int drow[4]={-1,0,+1,0};
    int dcol[4]={0,+1,0,-1};
    while(!q.empty())
    {
        int row=q.front().second.first;
        int col=q.front().second.second;
        int h=q.front().first;
        q.pop();
        height[row][col]=h;
        for(int i=0;i<4;i++)
        {
            int nrow=row+drow[i];
            int ncol=col+dcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && vis[nrow][ncol]==0)
            {
                vis[nrow][ncol]=1;
                q.push({h+1,{nrow,ncol}});
            }
        }
    }
}
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n=isWater.size();
        int m=isWater[0].size();
        vector<vector<int>>height(n,vector<int>(m));
        vector<vector<int>>vis(n,vector<int>(m,0));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(isWater[i][j]==1 && !vis[i][j])//check if it is water
                {
                    vis[i][j]=1;
                    q.push({0,{i,j}});//height,row,col
                }
            }
        }
        bfs(q,vis,height,isWater);
        return height;
    }
};
//0 - land
// 1 - water  ->height=0
// mere neigh mei ya water ya land with +- of my height 
// mei agar 1 heigh to side vala with 2 only ---> land
// return height matrix 