 /*Yatin plays PUBG
Yatin is playing PUBG and he has reached a place with a large staircase in front of him.
And there is an enemy at each landing of the staircase.
The staircase is analogous to a binary tree with each of its nodes as a landing of the
staircase and each of its edges as stairs from one landing to another.

Yatin wants to kill the maximum possible number of enemies. He can kill every person
he can see from his position with his suppressed sniper gun. But he can see only the
persons at the leftmost standing at each level and cannot see the rest.
Before starting shooting them, he wants to know how many persons he can kill. He is
busy keeping an eye on the enemies. So he wants you to find out the maximum
number of people he can kill from that location by providing you with the analogous
a binary search tree.
[ Note: Players do not change their position after one player has died, i.e. the leftmost
node remains the same even after player on that node has died. Or we can say that
the nodes are not removed after the player on that node has died.]

// Warning: Printing unwanted or ill-formatted data to output will cause the test cases to fail
*/
 
// Write your code here
#include<iostream>
#include<cmath>
using namespace std;
struct bst{
    int data;
    bst *left;
    bst *right;
};
bst* insert(bst *root, int x){
    if(root==0){
        bst *root=new bst();
        root->data=x;
        root->left=root->right=0;
        return root;
    }
    if(x<=root->data)
    root->left=insert(root->left,x);
    else if(x>root->data)
    root->right=insert(root->right,x);
    return root;
}
int max_kill(bst *root){
    if(root==0)
    return -1;
    return max(max_kill(root->left),max_kill(root->right))+1;
}
int main(){
    int t,n,x;
    cin>>t;
    for(int j=1; j<=t; j++){
    cin>>n;
      bst *root=0;
    for(int i=1; i<=n; i++){
        cin>>x;
        root=insert(root,x);
    }
    int result=max_kill(root)+1;
    if(result==-1)
    cout<<"0";
    else
    cout<<result;
    cout<<endl;
    }
    return 0;
/*
Input:
1
9
8 3 10 1 6 14 4 7 13

Output:
4
