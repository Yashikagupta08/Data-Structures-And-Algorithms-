#include<bits/stdc++.h>
using namespace std;
struct tree
{
    int info;
    tree *LC;
    tree *RC;
};
tree* input_t()
{
    tree *root=NULL, *T1=NULL, *T2=NULL;
    root =new tree;
    root->LC=root->RC=NULL;
    cin>>root->info;
    int data;
    cin>>data;
    while(data!=-9999)
    {
        T1=root; T2=NULL;
        while(T1!=NULL)
        {
            if(T1->info >= data)
            {
                T2=T1;
                T1=T1->LC;
            }
            else
            {
                T2=T1;
                T1=T1->RC;
            }
        }
            T1=new tree;
            T1->LC=T1->RC=NULL;
            T1->info=data;
            if(T2->info>=data)
                T2->LC=T1;
            else
                T2->RC=T1;
        cin>>data;
    }
    return root;
}
void display_inorder(tree *n1)
{
    if(n1!=NULL)
    {
        display_inorder(n1->LC);
        cout<<n1->info<<" ";
        display_inorder(n1->RC);
    }
}
int height(tree *root)
{
    int l,r;
    if(root==NULL)
        return 0;
    else
    {
        l=height(root->LC);
        r=height(root->RC);
        if(l>r)
            return l+1;
        else
        return r+1;
    }
}
tree* find(tree *root, int p)
{
	if(root==NULL)
		return NULL;
	else
	{
		if(root->info==p)
			return root;
		else
		{
			find(root->LC,p);
			find(root->RC,p);
		}
	}
}
int main()
{
    tree *root=input_t();
    cout<<height(root);
    int m;
    cin>>m;
    cout<<find(root,m)->info;
}
