#include <iostream>
#include <algorithm>

using namespace std;

struct booking
{
    int start,end,amount;
};

bool check(booking s1,booking s2)
{
    return (s1.end<s2.end);
}

int noconflict_job(booking arr[],int i)
{
    for(int j=i-1;j>=0;j--)
    {
        if(arr[j].end<=arr[i].start)
        {
            return j;
        }
    }
    return -1;
}

int FindMaxAmount(booking arr[],int n)
{
    sort(arr,arr+n,check);
    int *table=new int[n];
    table[0]=arr[0].amount;
    for(int i=1;i<n;i++)
    {
        int inclProf=arr[i].amount;
        int l=noconflict_job(arr,i);
        if(l!=-1)
        {
            inclProf+=table[l];
        }
        table[i]=max(inclProf,table[i-1]);
    }
    int result=table[n-1];
    delete[] table;
    return result;
}

int main()
{
    int t,n;
    booking arr[2000];
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i].start>>arr[i].end>>arr[i].amount;
        }
        cout<<FindMaxAmount(arr,n)<<endl;
    }
    return 0;
}
