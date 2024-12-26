
/*
  Segment Tree for querry sum , prefix sum.........
*/


#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
int segTree[N];
int ar[N];
int n;

void buildTree(int i, int l, int r) {
    if(l==r) {
        segTree[i] = ar[l];
        return;
    }
    int mid = (l+r)/2;
    //for left node
    buildTree(2*i+1,l,mid);
    //for right node
    buildTree(2*i+2,mid+1,r);
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}

int segSum(int st, int end, int i , int l, int r) {
    if(st > r or end < l) return 0;
    if(l >= st and r <= end) return segTree[i];
    else {
        int mid = (l+r)/2;
        return segSum(st,end,2*i+1,l,mid)
               + segSum(st,end,2*i+2,mid+1,r);
    }
}

int main() {
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> ar[i];
    }
    buildTree(0,0,n-1);
    int q; cin >> q;
    while(q--) {
        int l,r; cin >> l >> r;
        cout << segSum(l,r,0,0,n-1) << endl;
    }
}