#include <bits/stdc++.h>

using namespace std;



int main()
{
    int n , nf,i,j,k,h,a=0, hit=0, data,c=0, ind;
    int w,x,y,z;
    float fault=0;
    int in[100];
      int out[5][30];
 stack<int>s;
  stack<int>t;


 printf("\nEnter length of page reference sequence:");
    scanf("%d",&n);
    printf("\nEnter the page reference sequence:");
    for(i=0; i<n; i++)
        scanf("%d",&in[i]);

    printf("\nEnter no of frames:");
    scanf("%d",&nf);


      for(i=0; i<n; i++)
      {
           hit=0;
          if (a!=nf)
          {
              s.push(in[i]);


                   if(a==0)

                     {

                       x=s.top();
                      out[0][i]=x;
                      out[1][i]=0;
                      out[2][i]=0;


                      t.push(x);
                      s.pop();
                     }

                      if(a==1)

                     {

                       x=s.top();
                      out[0][i]=x;




                      t.push(x);
                      s.pop();
                       x=s.top();
                      t.push(x);
                      s.pop();

                        out[1][i]=x;
                      out[2][i]=0;

                     }

                      if(a==2)

                     {

                       x=s.top();
                     out[0][i]=x;


                     t.push(x);
                      s.pop();
                       x=s.top();
                      t.push(x);
                      s.pop();

                        out[1][i]=x;
                       x=s.top();
                      out[2][i]=x;
                      t.push(x);
                      s.pop();



                     }



             while(!t.empty())
             {
                 x=t.top();

                      s.push(x);
                      t.pop();
             }

              a++;

              continue;

          }









          for(j=0;j<nf;j++)
          {
              y=s.top();
              s.pop();
              t.push(y);
              if(y== in[i])
              {
                 data=in[i];
                 ind=j;

                  hit=1;
                  c++;
                  break;

              }


          }


          if(hit==1)
          {

              t.pop();
             for(j=ind;j>0;j--)
             {

             x=t.top();
             s.push(x);
              t.pop();
             }
             s.push(data);

          }


          else{
            t.pop();
            for(j=0; j<nf-1;j++)
             {

                x=t.top();
             s.push(x);
              t.pop();
             }
              s.push(in[i]);
          }


          for(k=0; k<nf; k++)
                  {
                      x=s.top();
                      out[k][i]=x;
                      t.push(x);
                      s.pop();
                  }
             while(!t.empty())
             {
                 x=t.top();

                      s.push(x);
                      t.pop();
             }




     }

     for(i=0;i<nf;i++)
     {
         for(k=0; k<n; k++)
         { if(i==1 && k==0 || i==2 && k==0 || i==2 && k==1  )
             {
              cout<<" ";
              }
             else{
                cout<<out[i][k]<<" ";
             }


         }
         cout<<endl;
     }


     cout<<"C="<<c<<endl;
      z=n-c;
          cout<<"Page fault:"<<z<<endl;
          fault=(float)z/n *100;
    printf("\nPage fault rate %d" , (int)round(fault));




}
