class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // calculating indegree
	    vector<int> inDeg(V , 0);
	    for(int i = 0; i < V; i++){
	        for(auto it : adj[i]){
	            inDeg[it]++;
	        }
	    }
	    
	    vector<int> ans;
	    queue<int> q;
	    for(int i = 0; i < V; i++){
	        if(inDeg[i] == 0) q.push(i);
	    }
	    
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        ans.push_back(node);
	        for(auto it : adj[node]){
	            if(inDeg[it] > 0){
	                inDeg[it]--;
	                if(inDeg[it] == 0) q.push(it);
	            }
	        }
	    }
	    return ans;
	}
};