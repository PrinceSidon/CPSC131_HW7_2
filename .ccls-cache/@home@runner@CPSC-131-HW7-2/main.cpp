class Solution {
  public:
    
    int insideRange(vector<int> a, vector<int> b)         // Returns true if bomb b is in range of bomb a
    {
        long long x = abs((a[0]-b[0]));
        long long y = abs((a[1]-b[1]));
        long long r = a[2];
        long long dis = x*x + y*y;                        // Calculates the distance between the bombs
        return  r*r >= dis ;                              // Bomb b is in range if the distance is less than
                                                          // or equal to bomb a's blast radius squared
    }
    
    int bfs(int bid, int len, vector<vector<int>> adj)
    {
        int val = 1;
        vector<int> blasted(len, 0);
        queue<int> q;
        q.push(bid);
        blasted[bid]=1;
        int blastedTillNow = 1;
        while(!q.empty())
        {
            int f = q.front();
            q.pop();
            for(auto k : adj[f])
            {
                if(!blasted[k])
                {
                    q.push(k);
                    blasted[k]=1;
                    blastedTillNow++;
                    val = max(val, blastedTillNow);
                    
                    
                }
            }
        }
        return val;
    }
        
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        vector<vector<int>> adj(bombs.size());            // The adjacency list of all the bombs
                                                          
        for(int i=0; i<bombs.size(); i++)
        {
            for(int j=0; j<bombs.size(); j++)
            {
                if(i!=j)
                {
                    if(insideRange(bombs[i], bombs[j]))   // Two bombs are adjacent if one is in 
                                                          // range of another
                    {
                        adj[i].push_back(j);              
                    }
                }
            }
        }
        
        
        int ans = 0;
        // perform bfs considering every bomb as source , find the max ans
        for(int i=0; i<bombs.size(); i++)
        {
            int x = bfs(i, bombs.size(), adj);
            ans = max(ans, x);
        }
        
        return ans;
        
      
    }
};