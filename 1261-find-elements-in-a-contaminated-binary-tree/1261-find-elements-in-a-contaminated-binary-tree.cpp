/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    set<int> st;
    
    FindElements(TreeNode* root) {
        create(root,0);
    }
    void create(TreeNode* root,int val){
        if(root == NULL) return;
        st.insert(val);
        create(root->left,2*val+1);
        create(root->right,2*val+2);
    }
    bool find(int target) {
        if(st.find(target) == st.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */