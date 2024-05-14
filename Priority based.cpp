#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main()
{
    int et[20],art[10],n,i,j,temp,p[10],st[10],ft[10],wt[10],ta[10];

    int totwt=0,totta=0;
    float awt,ata;
    char pn[10][10],t[10];

    cout<<"Enter the number of process: ";
    cin>>n;
    for(i=0; i<n; i++)
    {
        cout<<"Enter process name,arrival_time,execution time & priority:" ;

        cin>>pn[i]>>art[i]>>et[i]>>p[i];
    }
    for(i=0; i<n; i++)
        for(j=0; j<n; j++)
        {
            if(p[i]<p[j])
            {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
                temp=art[i];
                art[i]=art[j];
                art[j]=temp;
                temp=et[i];

                et[i]=et[j];
                et[j]=temp;
                strcpy(t,pn[i]);
                strcpy(pn[i],pn[j]);
                strcpy(pn[j],t);
            }
        }
    for(i=0; i<n; i++)
    {
        if(i==0)
        {
            st[i]=art[i];
            wt[i]=st[i]-art[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-art[i];
        }
        else
        {
            st[i]=ft[i-1];
            wt[i]=st[i]-art[i];
            ft[i]=st[i]+et[i];
            ta[i]=ft[i]-art[i];
        }
        totwt+=wt[i];
        totta+=ta[i];
    }
    awt=(float)totwt/n;
    ata=(float)totta/n;
    cout<<"\nPname\tarrivaltime\texecutiontime\tpriority\twaitingtime\ttatime";
    for(i=0; i<n; i++)
        cout<<"\n"<<pn[i]<<"\t"<<art[i]<<"\t\t"<<et[i]<<"\t\t"<<p[i]<<"\t\t"<<wt[i]<<"\t\t"<<ta[i];
    cout<<"\nAverage waiting time is: "<<awt;
    cout<<"\nAverage turn around time is: "<<ata;
    return 0;
}
