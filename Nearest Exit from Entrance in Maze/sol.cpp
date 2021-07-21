class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        const int dx[4] = {-1, 1, 0, 0};
        const int dy[4] = {0, 0, -1, 1}; 
        int H = maze.size(); 
        int W = maze[0].size(); 
        int e_row = entrance[0]; 
        int e_col = entrance[1]; 
        vector<pair<int,int>> q; 
        vector<vector<int>> d(H, vector<int>(W,-1)); //  initializing the visited vector
        d[e_row][e_col] = 0; 
        q.emplace_back(e_row, e_col);
        for(int i = 0;i< (int)q.size();i++){
            int row = q[i].first; 
            int col = q[i].second;
            if(d[row][col] != 0){
                if(row == 0 || row == H - 1|| col == 0 || col == W - 1){
                    return d[row][col]; 
                }
            }
            for(int dir = 0;dir < 4;dir++){
                int r2 = row + dx[dir];
                int c2 = col + dy[dir]; 
                if( r2 >= 0 && r2 < H && c2 < W && 0 <= c2 &&  maze[r2][c2] == '.' &&  d[r2][c2] == -1){
                    q.emplace_back(r2, c2); 
                    d[r2][c2] = d[row][col] + 1 ;   
                }
            }
        }
        
        return -1; 
    }
};