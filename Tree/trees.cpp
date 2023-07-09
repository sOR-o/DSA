#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;
    
    Node(int data) {
        this-> data = data;
        this-> left = NULL;
        this-> right = NULL;
    }
};

Node* buildTree(Node* root) {

    cout << "enter the data :";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) return NULL;

    cout << "enter data for inserting in left of " << data << endl;
    root-> left = buildTree(root-> left);
    cout << "enter data for inserting in right of " << data << endl;
    root-> right = buildTree(root-> right);

    return root;

}
void deleteTree(Node* root) {
    if (root == NULL)
        return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

 void print(Node* root) {
    if(root == NULL) return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* curr = q.front();
        q.pop();

        cout << curr-> data << " ";
        if(curr-> left != NULL) q.push(curr-> left);
        if(curr-> right != NULL) q.push(curr-> right);
    }
 }

int main() {
    Node* root = NULL;

    root = buildTree(root);
    print(root);

    deleteTree(root);
    root = NULL;

    return 0;
}