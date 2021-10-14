#include <bits/stdc++.h>
#include<iostream>
using namespace std;


int allocate[50][50], maximum[50][50], need[50][50], available[50], resource[50];
int p,r;
queue<int>proc;


int main()
{
    cout<<" Enter the number of process"<<endl;
    cin>>p;
    cout<<" Enter the number of resource"<<endl;
    cin>>r;

      cout<<" Enter the  resource value"<<endl;
       for(int i=0; i<r;i++)
       {
           cin>>resource[i];
       }



    for(int i=0; i<p;i++)
    {
        cout<<"Process "<<i+1<<endl;
        for(int j=0; j<r;j++)
           {
               cout<<"Maximum value for resource "<<j+1<<":";
               cin>> maximum[i][j];
               cout<<endl;

           }
           for(int j=0; j<r;j++)
           {
               cout<<"Allocated from resource "<<j+1<<":";
               cin>> allocate[i][j];
               cout<<endl;

           }
           for(int j=0; j<r;j++)
           {

             need [i][j]= maximum[i][j]- allocate[i][j];

           }

    }

    int sum[50]={0};
    int execution[50]={0};
    int cmp=0 , n=0, m=-1;

    for(int j=0; j<r;j++)
    {
        for(int i=0; i<p;i++)
        {
            sum[j]+=allocate[i][j];
        }


    }


 cout<<endl;
 cout<<endl;
    cout<<"Allocated Table:"<<endl;
    for(int i=0; i<p;i++)
    {
        for(int j=0; j<r;j++)
        {
            cout<<allocate[i][j]<<" ";
        }
        cout<<endl;

    }

    cout<<"Maximum Table:"<<endl;
    for(int i=0; i<p;i++)
    {
        for(int j=0; j<r;j++)
        {
            cout<<maximum[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<"Need Table:"<<endl;
    for(int i=0; i<p;i++)
    {
        for(int j=0; j<r;j++)
        {
            cout<< need [i][j]<<" ";
        }
        cout<<endl;

    }
    cout<< "Available at first = ";
     for(int j=0; j<r;j++)
     {
         available[j]=resource[j]- sum[j];
         cout<<available[j]<<" ";
     }
     cout<<endl;



     while(n<=r && m!=0 )
     {

     for(int i=0; i<p;i++)
    {
        cmp=0;

        for(int j=0; j<r;j++)
        {
            if(need [i][j]<=available[j] && execution[i]==0)
            {
                cmp=cmp+1;
            }
        }

        if(cmp==r)
        {
            proc.push(i);
            cout<<"After process "<<i+1<<"Executed, New available is= ";
            execution[i]=1;
            for(int j=0; j<r;j++)
            {

                available[j]+= allocate[i][j];
                 cout<<available[j]<<" ";
            }
            cout<<endl;
            n=n+1;
        }


    }

    m=n;
   }

   if(m==0)
   {
       cout<<"The System is currently in unsafe state"<<endl;
   }
   else{
    cout<<"The System is currently in safe state and <";
    while(!proc.empty())
    {
       cout<<"p"<<proc.front()+1<<" ";
           proc.pop();
    }
    cout<<"> is the safe sequence"<<endl;

  }


}
