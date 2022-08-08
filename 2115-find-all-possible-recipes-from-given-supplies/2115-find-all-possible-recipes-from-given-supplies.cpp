class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>> mp;
        unordered_map<string,int> indegree;
        queue<string> q;
        for(auto it:supplies){
            indegree[it] = 0;
            q.push(it);
        }
        for(int i = 0;i<ingredients.size();i++){
            for(auto s:ingredients[i]){
                mp[s].push_back(recipes[i]);
                indegree[recipes[i]]++;
            }
        }
        while(!q.empty()){
        string t = q.front();q.pop();
            for(auto it:mp[t]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
        vector<string> ans;
        for(auto it:recipes){
            if(indegree[it] == 0) ans.push_back(it);
        }
        return ans;
    }
};