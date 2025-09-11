#include <iostream> 
#include <queue>
#include <vector>
using namespace std;

int main(){
    int cnt = 1;
    while(true){
        int n;
        cin >> n;
        if(!n) break;
        int weights[125][125], visit[125][125], mins[125][125];
        for(int x = 0; x < n; x++){
            for(int y = 0; y < n; y++){
                cin >> weights[x][y];
                visit[x][y] = 0;
                mins[x][y] = 1000000;
            }
        }
    
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({weights[0][0], 0, 0});
        int dx[4] = {0, 0, -1, 1};
        int dy[4] = {1, -1, 0, 0};
        
        while(!pq.empty()){
            int w = pq.top()[0];
            int x = pq.top()[1];
            int y = pq.top()[2];
            pq.pop();
            if(visit[x][y]) continue;
            visit[x][y] = 1;
    
            for(int i = 0; i < 4; i++){
                int xx = x+dx[i], yy = y+dy[i];
                if(xx < 0 || xx >= n || yy < 0 || yy >= n) continue;
                if(!visit[xx][yy]){
                    if(mins[xx][yy] > w+weights[xx][yy]){
                        mins[xx][yy] = w+weights[xx][yy];
                        pq.push({mins[xx][yy], xx, yy});
                    }
                }
            }
        }
    
        cout << "Problem " << cnt++ << ": " << mins[n-1][n-1] << '\n';
    }


    return 0;
}