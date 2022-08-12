class Solution {
public:
    //approach 1- uaing paretnts of nodes
    /*
    unordered_map<int,TreeNode*> valToNode;
    unordered_map<TreeNode*,TreeNode *> parent;
    void travel(TreeNode *node, TreeNode*prev){
        if(node==NULL) return;
        valToNode[node->val]=node;
        parent[node]=prev;
        travel(node->left,node);
        travel(node->right,node);
    }
    */
  
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        
        /*
        travel(root,NULL);
        unordered_set<TreeNode*> forest;
        forest.insert(root);
        
        //if the value to be deleted is the root of some disjoint forest, then you need to erase that node from forest
        //and put  its left and child subtree as two new disjoints in forest
        
        //if the value is not root , then in thhis case you dont need to remove root of the subtree.. just put 2 new subtrees of this node in 
        //forest ..also make this node as NULL 
        for(int val:to_delete){
            auto node=valToNode[val];
            if(forest.find(node)!=forest.end()){
                if(node->left) forest.insert(node->left);
                if(node->right) forest.insert(node->right);
                forest.erase(node);
            }
            else{
                if(node->left) forest.insert(node->left);
                if(node->right) forest.insert(node->right);
                auto p=parent[node];
                if(p->left==node) p->left=NULL;
                if(p->right==node) p->right=NULL;
            }
        }
        
        vector<TreeNode*> result(forest.begin(), forest.end());
        return result;
        */
        unordered_set<int> todelete(to_delete.begin(), to_delete.end());
        vector<TreeNode*> res;
        TreeNode* a= helper(root,res,todelete);
        //if root was to be deleted then a would be null and we wont do anything
        //if root was not to be deleted then a wil contains the trimmed tree that starts at root..so include that as well
        if(a!=NULL) res.push_back(a);
        return res;
    }
    //post order solution..we form forests to left and right of a node and then check if the node needs too be removed
    //if need to be removed, push left and right to solution ..also we need to notify its parent that i am removed ..so the return type
    //of recursive function will b Treenode*
    
    TreeNode *helper(TreeNode *node, vector<TreeNode*> &res, unordered_set<int> &todelete){
        if(node==NULL) return NULL;
        node->left=helper(node->left,res,todelete);
        node->right=helper(node->right,res,todelete);
        
        if(todelete.find(node->val)!=todelete.end()){
            if(node->left) res.push_back(node->left);
            if(node->right) res.push_back(node->right);
        
            //now parent of this node will receive NULL so it needs to set its child that returned null to null
            //that is done in first 2 lines of recursive postorder
            return NULL;
        }
        
        //now node is not to be deleted ... then return node instead of null
        return node;
    }
};