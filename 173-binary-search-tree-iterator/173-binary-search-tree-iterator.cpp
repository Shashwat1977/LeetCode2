class BSTIterator {
public:
    vector<int> ans;
    int curr=-1;
    
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        ans.push_back(root->val);
        inorder(root->right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        curr++;
        return ans[curr];
    }
    
    bool hasNext() {
        if(curr+1 < ans.size()) return true;
        else return false;
    }
};
