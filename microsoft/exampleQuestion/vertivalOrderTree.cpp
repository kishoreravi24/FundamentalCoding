class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        std::vector<int> res;
        std::queue<std::pair<Node*,int>> q;
        std::map<int,std::vector<int>> hashMap;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                auto it = q.front();
                q.pop();
                Node* curr = it.first;
                int val = it.second;
                hashMap[val].push_back(curr->data);
                if(curr->left!=NULL){
                    q.push({curr->left,val-1});
                }
                if(curr->right!=NULL){
                    q.push({curr->right,val+1});
                }
            }
        }
        for(auto it:hashMap){
            res.insert(res.end(),it.second.begin(),it.second.end());
        }
        return res;
    }
};