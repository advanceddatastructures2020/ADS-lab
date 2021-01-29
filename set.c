#include<stdio.h>
struct DisjSet
{
    int parent[10];
    int rank[10]; //rank[i] is the height of the tree representing the set
    int n;
}
dis;
    //Creates n single item sets
    void makeSet()
    {
        int i;
        for(i=0;i<dis.n;i++)
        {
        dis.parent[i]=i;
        dis.rank[i]=0;
    }
}
     //Displays Disjoint set
void displaySet()
{
    int i;
     printf("\nParent Array\n");
     for(i=0;i<dis.n;i++)
     {
         printf("%d",dis.parent[i]);
         }
         printf("\nRankArray\n");
         for(int i=0;i<dis.n;i++)
         {
             printf("%d",dis.rank[i]);
             }
             printf("\n");
}


        //Find set of given item x
int find(int x)
{
        //Find the representative of the set 
        //that is an element of
    if(dis.parent[x]!=x)
    {
dis.parent[x]=find(dis.parent[x]);

        //if x is not the parent of itself
        //and move is not directly under the
        //representative of this set
    }
    return dis.parent[x];
}
        //Do  Union of two sets represented
        //by x and y
void Union()
{
        //Find current sets of x and y
        int x,y,xset,yset;
     xset=find(x);
     yset=find(y);

        //if they are already in same set
    if(xset==yset)
    return;

        //put smaller ranked item under
        //bigger ranked item if ranks are
        //different

    if(dis.rank[xset]<dis.rank[yset])
    {
        dis.parent[xset]=yset;
        dis.rank[xset]=-1;
    }
    else if(dis.rank[xset]>dis.rank[yset]) 
    {
        dis.parent[yset]=xset;
        dis.rank[yset]=-1;
  }
         //if ranks are same,then increment
         //rank
else
{
    dis.parent[yset]=xset;
    dis.rank[xset]=dis.rank[xset]+1;
    dis.rank[yset]=-1;
}
}

int main()
{ 
    int n,x,y,wish,ch;
printf("How many elements?");
scanf("%d",&dis.n);
makeSet();


do
{
    printf("\n___MENU___\n");
    printf("\n1.Union\n2.Find\n3.Display\n");
printf("Enter choice\n");
scanf("%d",&ch);


switch(ch)
{
    case1:printf("enter the elements to perform Union");
    scanf("%d%d",&x,&y);
    Union(x,y);
    break;
    case2:printf("Enter elements to check connected components\n");
    scanf("%d%d",&x,&y);
    if(find(x)==find(y))
    printf("Connected componence\n");
    else
    printf("Not connected components\n");
    break;
case3:displaySet();
break;
}
printf("\nDo you wish to continue?(1/10)\n");
}while(wish==1);
return 0;
}



