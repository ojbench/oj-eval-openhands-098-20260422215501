#include <bits/stdc++.h>
using namespace std;

struct Node{
    long long val;
    Node* left;
    Node* right;
    Node(long long v): val(v), left(nullptr), right(nullptr) {}
};

void insert_bst(Node*& root, long long v){
    if(!root){ root = new Node(v); return; }
    if(v < root->val) insert_bst(root->left, v);
    else insert_bst(root->right, v);
}

void destroy(Node* root){
    if(!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<long long> vals(7);
    for(int i=0;i<7;i++){
        if(!(cin>>vals[i])) return 0;
    }
    int cnt; if(!(cin>>cnt)) return 0;

    Node* root = nullptr;
    for(long long v: vals) insert_bst(root, v);

    int k = cnt;
    long long ans = -1;
    function<void(Node*)> rev_in = [&](Node* cur){
        if(!cur || k==0) return;
        rev_in(cur->right);
        if(--k==0){ ans = cur->val; return; }
        rev_in(cur->left);
    };
    rev_in(root);
    if(ans != -1) cout << ans << '\n';
    destroy(root);
    return 0;
}
