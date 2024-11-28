class Node{
    public:
    int x,y,dist;
    Node(int x,int y,int dist):x(x),y(y),dist(dist){}
    bool operator<(const Node& other) const {
        return dist > other.dist;
    }
};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int M = grid.size();
        int N = grid[0].size();
        vector<int> dr(N,M*N);
        vector<vector<int>> distance(M,dr);

        distance[0][0] = 0;

        priority_queue<Node> pq;

        pq.emplace(0,0,0);

        while(distance[M-1][N-1]==M*N){
            Node best = pq.top();

            pq.pop();


            if(best.x>0){
                if((grid[best.x-1][best.y] + distance[best.x][best.y])<distance[best.x-1][best.y]){
                    distance[best.x-1][best.y] = grid[best.x-1][best.y] + distance[best.x][best.y];
                    pq.emplace(best.x-1,best.y,distance[best.x-1][best.y]);
                }
            }
            if(best.y>0){
                if((grid[best.x][best.y-1] + distance[best.x][best.y])<distance[best.x][best.y-1]){
                    distance[best.x][best.y-1] = grid[best.x][best.y-1] + distance[best.x][best.y];
                    pq.emplace(best.x,best.y-1,distance[best.x][best.y-1]);
                }
            }
            if(best.x<M-1){
                if((grid[best.x+1][best.y] + distance[best.x][best.y])<distance[best.x+1][best.y]){
                    distance[best.x+1][best.y] = grid[best.x+1][best.y] + distance[best.x][best.y];
                    pq.emplace(best.x+1,best.y,distance[best.x+1][best.y]);
                }
            }
            if(best.y<N-1){
                if((grid[best.x][best.y+1] + distance[best.x][best.y])<distance[best.x][best.y+1]){
                    distance[best.x][best.y+1] = grid[best.x][best.y+1] + distance[best.x][best.y];
                    pq.emplace(best.x,best.y+1,distance[best.x][best.y+1]);
                }
            }
        }

        return distance[M-1][N-1];
    }
};