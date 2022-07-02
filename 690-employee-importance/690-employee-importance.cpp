class Solution {
unordered_map<int, vector<int> > graph;   
unordered_map<int, int> importanceOfNode;

private:
    
    int dfs(int source){
        
        int nodeImportanceAggregated = importanceOfNode[source];
        
        for(int adjacentNode : graph[source]){
            nodeImportanceAggregated += dfs(adjacentNode);
        }
        return nodeImportanceAggregated;
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        for(auto employee : employees){
            for(int adjacentNode : employee->subordinates){
                graph[employee->id].push_back(adjacentNode);
            }
            importanceOfNode[employee->id] = employee->importance;
            
        }
        
        return dfs(id);
    }
};