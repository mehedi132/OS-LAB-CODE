#include <iostream>
#include <queue>


using namespace std;



struct rr {
    int id;
    int ar_time;
    int cputime;
   int start_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
}s[50];


bool comp(rr a, rr b)
{
    return a.ar_time < b.ar_time;
}


int main() {
    queue<int> a;
     queue<int> t;
     queue<int>rr;

    int n,b=0;


      int is_qued[100]={0};
      int is_completed[100] = {0};

     float  avg_t_time;
     float avg_wait_time;
    int total_t_time = 0;
    int total_wait_time = 0;
    int cpu_rem[100];
    int qua, p;

    cout<<"Enter the number of processes: ";
    cin>>n;
    cout<<"Enter cpu time of process \n";
    for(int i = 0; i < n; i++) {

        cin>>s[i].cputime;
        s[i].id = i+1;

    }
 cout<<"Enter arrival time of process \n";
 for(int i = 0; i < n; i++) {

        cin>>s[i].ar_time;

    }
    cout<<"Enter time quantum of process \n";
    cin>>qua;

    int current_time = 0;
    int completed = 0;
//s.sort();
int temp,k,c;
for(int i = 0; i < n-1; i++) {
    if(s[i].ar_time> s[i+1].ar_time)
    {
      temp= s[i].ar_time;

        k=s[i].id;
        c=s[i].cputime;
        s[i].ar_time=s[i+1].ar_time;
        s[i+1].ar_time = temp;
        s[i].id=s[i+1].id;
        s[i+1].id=k;

       s[i].cputime=s[i+1].cputime;
    s[i+1].cputime=c;

    }
}
for(int i = 0; i < n; i++){
    cpu_rem[i] = s[i].cputime;
}

int w;
int y=0;


    while(completed != n) {

        for(int i = 0; i < n; i++) {
            if(s[i].ar_time <= current_time && is_qued[i] == 0) {
             rr.push(i);
             is_qued[i] =1;

            }
        }
        if(y>0 && cpu_rem[w]!=0 ){
            rr.push(w);
        }
          y=1;

            w=rr.front();

            rr.pop();
            if(cpu_rem[w]>=qua)
             {
                current_time=current_time+qua;
                 cpu_rem[w] = cpu_rem[w]-qua;
             }
             else{
                current_time=current_time+cpu_rem[w];
                 cpu_rem[w] -= cpu_rem[w];
             }
             a.push(w);
             t.push(current_time);

            if(cpu_rem[w] == 0) {
                s[w].completion_time = current_time;
                s[w].turnaround_time = s[w].completion_time - s[w].ar_time;
                s[w].waiting_time = s[w].turnaround_time - s[w].cputime;


                total_t_time += s[w].turnaround_time;
                total_wait_time += s[w].waiting_time;


                is_completed[w] = 1;
                completed++;
            }

    }

     t.push(current_time);
     cout<<"Gantt Chart:"<<endl;
     cout<<"0";
    while (!a.empty() &&! t.empty()) {

    cout<<"--p"<<s[a.front()].id;
            a.pop();
            cout<<"--"<<t.front();
            t.pop();
    }

 cout<<endl<<endl;



 for(int i = 0; i < n-1; i++) {
    if(s[i].id> s[i+1].id)
    {
      temp= s[i].waiting_time;

        k=s[i].id;
        c=s[i].turnaround_time;
        s[i].id=s[i+1].id;
        s[i+1].id = k;
        s[i].waiting_time=s[i+1].waiting_time;
        s[i+1].waiting_time=temp;

       s[i].turnaround_time=s[i+1].turnaround_time;
    s[i+1].turnaround_time=c;

    }
}


     for(int i = 0; i < n; i++) {



        cout<<"Process :"<<s[i].id<<" Waiting time :"<<s[i].waiting_time<<" Turnaround time : "<<s[i].turnaround_time<<endl;
    }

avg_t_time = total_t_time / (n*1.0);
    avg_wait_time = total_wait_time /(n*1.0) ;
     cout<<"Average Waiting Time = "<<avg_wait_time<<endl;
    cout<<"Average Turnaround Time = "<<avg_t_time<<endl;

}




