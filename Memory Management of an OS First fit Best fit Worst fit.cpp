#include <iostream>
using namespace std;
int main()
{
  int c,i,j,k,n,l,m[10],p[10],po[20],flag,z,y,temp,temp1,sum=0;
  int f1=0,f2=0,f3=0;
      cout<<"Enter memory total partitions:\t";
      cin>>n;
      cout<<"\nEnter memory size for\n";
      for(i=1;i<=n;i++)
      {
        cin>>m[i];
        po[i]=i;
      }
      cout<<"\nEnter total number of process:\t";
      cin>>j;
      cout<<"\nEnter memory size for\n";
      for(i=1;i<=j;i++)
      {
        cin>>p[i];
      }
      cout<<"\n**Menu**\n1.first fit\n2.best fit\n3.worst fit\nenter choice:\t";
      cin>>c;
      switch(c)
      {
      case 1:
            for(i=1;i<=j;i++)
      {
          flag=1;
          for(k=1;k<=n;k++)
      {
          if(p[i]<=m[k])
          {
             cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
             m[k]=m[k]-p[i];
             break;
          }
          else
         {
            flag++;
          }
      }
      if(flag>n)
      {
          f1=1;
         cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";

      }

      }
      if(f1==1){

        for(i=1;i<=n;i++){
         sum= sum+ m[i];
      }
      cout<<"\nExternal Fragmentation "<< sum;
      }
      else
        cout<<"\n No External Fragmentation "<< sum;

      break;
      case 2:
       for(y=1;y<=n;y++)
          {
          for(z=y;z<=n;z++)
          {
          if(m[y]>m[z])
          {
          temp=m[y];
          m[y]=m[z];
          m[z]=temp;
          temp1=po[y];
          po[y]=po[z];
          po[z]=temp1;
          }
          }
          }
          for(i=1;i<=j;i++)
      {
          flag=1;
          for(k=1;k<=n;k++)
      {
          if(p[i]<=m[k])
          {
             cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
             m[k]=m[k]-p[i];
             break;
          }
          else
         {
            flag++;
          }
      }
      if(flag>n)
      {
          f2=1;
         cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";
      }
      }
      if(f2==1){

        for(i=1;i<=n;i++){
         sum= sum+ m[i];
      }
      cout<<"\nExternal Fragmentation "<< sum;
      }
      else
        cout<<"\n No External Fragmentation ";

          break;
          case 3:
          for(y=1;y<=n;y++)
          {
          for(z=y;z<=n;z++)
          {
          if(m[y]<m[z])
          {
          temp=m[y];
          m[y]=m[z];
          m[z]=temp;
          temp1=po[y];
          po[y]=po[z];
          po[z]=temp1;
          }
          }
          }
          for(i=1;i<=j;i++)
      {
          flag=1;
          for(k=1;k<=n;k++)
      {
          if(p[i]<=m[k])
          {
             cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB allocated at memory partition:\t"<<po[k];
             m[k]=m[k]-p[i];
             break;
          }
          else
         {
            flag++;
          }
      }
      if(flag>n)
      {
          f3=1;
         cout<<"\nProcess "<<i<<" whose memory size is "<<p[i]<<"KB can't be allocated";
      }
      }
      if(f3==1){

        for(i=1;i<=n;i++){
         sum= sum+m[i];
      }
      cout<<"\nExternal Fragmentation "<< sum;
      }
      else
        cout<<"\n No External Fragmentation "<< sum;

          break;
          }
      return 0;
}
