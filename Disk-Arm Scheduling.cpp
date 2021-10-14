#include <bits/stdc++.h>
using namespace std;

int n, m;

void FCFS(vector <int> a, int h )
{
	int temp=h, sum=0;
	cout<<"Cylinder Serving Order in FSCS: ";
    cout<<temp;
    for(int i=0; i<n; i++){
        cout<<" -> "<<a[i]<<' ';

        sum += abs(a[i]-temp);

        temp = a[i];
    }
    cout<<'\n';
    cout<<"Total head movements in FCFS: "<< sum<<'\n';
}



void SSTF(vector <int> a, int h)
{

 int i,j;
	vector <int> b,c;
	int p=0, temp=0;
	for(i=0;i<a.size();i++){

     int x=abs(h-a[i]);
    c.push_back(x);

    }

     cout<<endl;
     b.push_back(h);

     while(p<n)
     {

int l=0;

     for(i=1;i<c.size();i++){

         if(c[l]>c[i])
         {
            l=i;

         }
     }
     c[l]=999;
     b.push_back(a[l]);
     p++;

     }


cout<<"Cylinder Serving Order in SSTF: ";
    temp=b[0];

    int sum=0;
    for(i=0;i<b.size();i++){
            if(i==0)
            {
                cout<<b[i];
                sum+=abs(b[i]-temp);
             temp=b[i];

            }
            else{
                cout<<" -> "<<b[i];

            sum+=abs(b[i]-temp);
             temp=b[i];
            }




    }
    cout<<'\n';
    cout<<"Total head movements in SSTF = "<< sum<<'\n';





}


int main()
{
    int h;

	cout<<"Number of heads: ";
    cin>>m;
    cout<<"Number of requests: ";
    cin>>n;
     vector <int> a(n),b,c;
    cout<<"Cylinder requests: ";
	for(int i=0; i<n; i++) {
        cin>>a[i];
	}
	for(int i=0; i<n; i++) {
        if(a[i] > m) {
            cout<<"Error, Unknown position "<<a[i]<<"\n";
            return 0;
        }
    }
	printf("Current head position: ");
	cin>>h;

	FCFS(a, h);
	SSTF(a, h);

	int i,j,k,sum=0,x,y;


    int temp=h;
    a.push_back(h);
    a.push_back(m-1);
    a.push_back(0);
    sort(a.begin(),a.end());
    for(i=0;i<a.size();i++){
        if(h==a[i])
            break;
    }


     cout<<endl;


    k=i;

    if(k<n/2){
        for(i=k;i<a.size();i++){
            b.push_back(a[i]);
        }
       for(i=0;i<k;i++){
            b.push_back(a[i]);
        }
    }
    else{
        for(i=k;i>=0;i--){
            b.push_back(a[i]);
        }
        for(i=k+1;i<a.size();i++){
            b.push_back(a[i]);
        }
    }

     cout<<"Cylinder Serving Order in SCAN: ";
    temp=b[0];
    cout<<temp;
    for(i=1;i<b.size();i++){
        cout<<" -> "<<b[i];
        if(temp!=m-1)
        {
            sum+=abs(b[i]-temp);

        }
        temp=b[i];

    }
    cout<<'\n';
    cout<<"Total head movements in SCAN = "<< sum<<'\n';

	return 0;
}
