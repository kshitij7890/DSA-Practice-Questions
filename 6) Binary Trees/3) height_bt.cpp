 int height(struct Node* node){
        if(node==NULL) return NULL;
        else 
        {
           return 1 + max(height(node->left),height(node->right));
        }  
    }