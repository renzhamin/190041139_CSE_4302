#include <bits/stdc++.h>
using namespace std;

class SegmentTreeBase{
public:
    int *tree=NULL;
    void alloc(int n){
        tree = new int[n*4];
    }
    int leftNode(int node){
        return node*2;
    }
    virtual int merge(int a,int b) = 0;
    virtual int query(int node,int b,int e,int i,int j) = 0;
    virtual void init(int node,int b,int e,int *arr);
};

class SumSegmentTree : public SegmentTreeBase{
public:
    int merge(int a,int b) { return a+b; }
    int query(int node,int b,int e,int i,int j);
};

class MinSegmentTree : public SegmentTreeBase{
public:
    int merge(int a,int b) { return min(a,b); }
    int query(int node,int b,int e,int i,int j);
};

class EvensSegmentTree : public SegmentTreeBase{
public:
    int merge(int a,int b) { return a+b; }
    int query(int node,int b,int e,int i,int j);
    void init(int node,int b,int e,int *arr);
};



int main(){
    int arr[] = {1,2,4,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    SegmentTreeBase *segTrees[3];
    segTrees[0] = new SumSegmentTree();
    segTrees[1] = new MinSegmentTree();
    segTrees[2] = new EvensSegmentTree();

    for(int i=0;i<3;i++){
        segTrees[i]->init(1,0,n-1,arr);
    }

    for(int i=0;i<3;i++){
        cout<<segTrees[i]->query(1,0,n-1,0,2)<<'\n';
    }
}


void SegmentTreeBase::init(int node,int b,int e,int *arr){
    if(!tree){
        alloc(e+1);
    }

	if(b==e){ 
		tree[node]=arr[b];
		return;
	}

	int left=leftNode(node), right=left+1, mid=(b+e)/2;

	init(left,b,mid,arr);
	init(right,mid+1,e,arr);
	tree[node]=merge(tree[left],tree[right]);
}



void EvensSegmentTree::init(int node,int b,int e,int *arr){
    if(!tree){
        alloc(e+1);
    }

	if(b==e){ 
		tree[node]=(arr[b]%2==0 ? 1:0);
		return;
	}

	int left=leftNode(node), right=left+1, mid=(b+e)/2;

	init(left,b,mid,arr);
	init(right,mid+1,e,arr);
	tree[node]=merge(tree[left],tree[right]);
}

int SumSegmentTree::query(int node,int b,int e,int i,int j){
    if(i>e || j<b) 
        return 0;

    if(b>=i && e<=j) 
        return tree[node];

    int left=leftNode(node), right=left+1, mid=(b+e)/2;
    int p1=query(left,b,mid,i,j),
        p2=query(right,mid+1,e,i,j);

    return merge(p1,p2);
}



int MinSegmentTree::query(int node,int b,int e,int i,int j){
    if(i>e || j<b) 
        return INT_MAX;
 
    if(b>=i && e<=j) 
        return tree[node];

    int left=leftNode(node), right=left+1, mid=(b+e)/2;
    int p1=query(left,b,mid,i,j),
        p2=query(right,mid+1,e,i,j);

    return min(p1,p2);
}

int EvensSegmentTree::query(int node,int b,int e,int i,int j){
    if(i>e || j<b) 
        return 0;

    if(b>=i && e<=j) 
        return tree[node];

    int left=leftNode(node), right=left+1, mid=(b+e)/2;
    int p1=query(left,b,mid,i,j),
        p2=query(right,mid+1,e,i,j);

    return merge(p1,p2);
}
