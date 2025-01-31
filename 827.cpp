class Solution {
public:
    int func(vector<vector<int>>& grid,int i,int j,int n,int m,vector<vector<int>>&visited,int num){
       int ans=0;

       int row[]={-1,1,0,0};
       int col[]={0,0,-1,1};

       queue<pair<int,int>>q;
       visited[i][j]=num;
       q.push({i,j});
       while(!q.empty()){
        int r=q.front().first;
        int c=q.front().second;
        
        q.pop();
        ans++;
        for(int x=0;x<4;++x){
           int new_r=r+row[x];
           int new_c=c+col[x];
           if(new_r>=0 && new_r<n && new_c>=0 && new_c<m && visited[new_r][new_c]==0 && grid[new_r][new_c]==1){
            visited[new_r][new_c]=num;
            q.push({new_r,new_c});
            
           }
        }
       }
       return ans;

    }
    int largestIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int num=1;
        vector<vector<int>>visited(n,vector<int>(m,0));
        map<int,int>ma;
        vector<pair<int,int>>p;
        for(int i=0;i<n;++i){
            for(int j=0;j<m;++j){
                if(grid[i][j]==1 && visited[i][j]==0){      
                int a=func(grid,i,j,n,m,visited,num);
                ma[num]=a;
                num++;
                }
                else if(grid[i][j]==0){
                   p.push_back({i,j});
                }
            }
        }
         if(p.size()==0)return n*m;
        int ans=0;
        int row[]={-1,1,0,0};
        int col[]={0,0,-1,1};
        for(auto it:p){
            int answer=1;
            set<int>s;
            for(int i=0;i<4;++i){
                int new_r=it.first+row[i];
                int new_c=it.second+col[i];
                if(new_r>=0 && new_r<n && new_c>=0 && new_c<m){
                  int ele=visited[new_r][new_c];
                  s.insert(ele);
                }
            }
            for(auto it:s){
                answer+=ma[it];
            }
            ans=max(ans,answer);
        }

        
        return ans;
    }
};


