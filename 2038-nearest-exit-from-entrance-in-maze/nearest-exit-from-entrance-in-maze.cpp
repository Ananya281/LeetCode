class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]]='+';
        int levels=0;
        int row[4]={-1,0,+1,0};
        int col[4]={0,+1,0,-1};
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int r=q.front().first;
                int c=q.front().second;
                q.pop();
                if(!(r==entrance[0] && c==entrance[1]) && (r==0 || r==n-1 || c==0 || c==m-1))
                {
                    return levels;
                }
                for(int j=0;j<4;j++)
                {
                    int nrow=r+row[j];
                    int ncol=c+col[j];
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && maze[nrow][ncol]=='.')
                    {
                        q.push({nrow,ncol});
                        maze[nrow][ncol]='+';
                    }
                }
            }
            levels++;
        }
        return -1;
    }
};