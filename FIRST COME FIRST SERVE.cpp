#include<bits/stdc++.h>
using namespace std;

struct process
{
    int id ;
    int cpuTime ;
    int waitTime;
    int serviceTime;
    int turnAroundTime;
};





int main()
{

    int n;

    cout << "Enter the number of process : ";
    cin >> n;

    vector<process> v (n);

    int x;

    cout << "Enter the CPU times :\n";

    for(int i =0;i<n;i++)
    {
        cin >> x;
        v[i].cpuTime = x;
        v[i].id = i+1;
    }



    v[0].waitTime = 0;
    v[0].serviceTime = 0;

    int totalWaitTime = 0;
    int totalTurnAroundTime = 0;

    for(int i =1;i<n;i++)
    {
        v[i].serviceTime = v[i-1].cpuTime + v[i-1].serviceTime;
           v[i].waitTime= v[i].serviceTime;
        totalWaitTime += v[i].waitTime;
        cout<<"waiting time: "<<v[i].waitTime<< endl;
    }

    for(int i =0;i<n;i++)
    {
        v[i].turnAroundTime = v[i].waitTime + v[i].cpuTime;
        totalTurnAroundTime += v[i].turnAroundTime;
    }
    int a=0;
    int c=0;






    vector<process> :: iterator it;





    for(it = v.begin(); it!=v.end();it++)
    {
        cout << "Process " << it->id << ": Waiting Time: " << it->waitTime << " Turnaround Time: " << it->turnAroundTime << endl;
    }

    cout << "Average waiting time: " << totalWaitTime/(n*1.0) << endl;
    cout << "Average turnaround time: " << totalTurnAroundTime/(n*1.0) << endl;
cout<<"0";
    for(int i =0;i<n;i++)
     {
         a=v[i].cpuTime;
         c+=a;

          for(int j =0;j<a;j++)
          {
              if(j==a/2)
              {
                  cout<<"p"<<i+1;
              }

             cout<<"-"  ;
          }
          cout<<c  ;


     }


    return 0;
}
