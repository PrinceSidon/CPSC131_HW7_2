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
    
    int bfs(int bid, int len, vector<vector<int>> adj)    // Breadth-first search implementation
    {
        int val = 1;
        vector<int> blasted(len, 0);                      // The vector stores the bombs that have been
                                                          // blasted
      
        queue<int> q;                                     // The queue stores the bombs that haven't been
                                                          // blasted yet
      
        q.push(bid);      
        blasted[bid]=1;
        int blastedTillNow = 1;                           // Stores the number of bombs that have exploded
      
        while(!q.empty())                                 // BFS ends when all adjacent bombs are found
        {
            int f = q.front();
            q.pop();
            for(auto k : adj[f])
            {
                if(!blasted[k])                           // Makes sure this bomb hasn't already exploded
                {
                    q.push(k);
                    blasted[k]=1;
                    blastedTillNow++;
                    val = max(val, blastedTillNow);       // At least one bomb must explode
                    
                    
                }
            }
        }
        return val;                                       // Returns the number of blasted bombs
    }
        
    int maximumDetonation(vector<vector<int>>& bombs) {   // Returns the max number of bombs that
                                                          // can be blasted at once
        
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

        for(int i=0; i<bombs.size(); i++)                  // Loops through the adjacency list
                                                           // and calls BFS for each bomb
        {
            int x = bfs(i, bombs.size(), adj);
            ans = max(ans, x);
        }
        
        return ans;                                        // Returns the max number
        
      
    }
};