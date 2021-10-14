#include <iostream>
#include <queue>


using namespace std;



struct srtn {
    int id;
    int ar_time;
    int cputime;
   int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
}s[50];


int main() {
    queue<int> a;
     queue<int> t;

    int n,b=0;

      int is_completed[100]={0};

     float  avg_t_time;
     float avg_wait_time;
    int total_t_time = 0;
    int total_wait_time = 0;
    //int cpu_rem[100];

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter cpu time of process \n";
    for(int i = 0; i < n; i++) {

        cin>>s[i].cputime;
        s[i].id = i+1;
        //cpu_rem[i] = s[i].cputime;

    }
 cout<<"Enter arrival time of process \n";
 for(int i = 0; i < n; i++) {

        cin>>s[i].ar_time;

    }

    int current_time = 0;
    int completed = 0;


    while(completed != n) {
        int x = 0;
        int mini = 999;
        for(int i = 0; i < n; i++) {
            if(s[i].ar_time <= current_time && is_completed[i] == 0) {
                if(s[i].cputime < mini) {
                    mini = s[i].cputime;
                    x = i;
                }
                if(s[i].cputime == mini) {
                    if(s[i].ar_time < s[x].ar_time) {
                        mini = s[i].cputime;
                        x = i;
                    }
                }
            }
        }

            current_time+=s[x].cputime;

                a.push(x);
                t.push(current_time);



                s[x].completion_time = current_time;
                s[x].turnaround_time = s[x].completion_time - s[x].ar_time;
                s[x].waiting_time = s[x].turnaround_time - s[x].cputime;


                total_t_time += s[x].turnaround_time;
                total_wait_time += s[x].waiting_time;


                is_completed[x] = 1;
                completed++;

    }

     t.push(current_time);
     cout<<"Gantt Chart:"<<endl;
     cout<<"0";
    while (!a.empty() &&! t.empty()) {

    cout<<"--p"<<a.front()+1;
            a.pop();
            cout<<"--"<<t.front();
            t.pop();
    }

 cout<<endl<<endl;


     for(int i = 0; i < n; i++) {
        cout<<"Process :"<<s[i].id<<" Waiting time :"<<s[i].waiting_time<<" Turnaround time : "<<s[i].turnaround_time<<endl;
    }
avg_t_time = total_t_time / (n*1.0);
    avg_wait_time = total_wait_time /(n*1.0) ;
     cout<<"Average Waiting Time = "<<avg_wait_time<<endl;
    cout<<"Average Turnaround Time = "<<avg_t_time<<endl;
}




