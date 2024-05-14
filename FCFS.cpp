//fcfs
#include<iostream>
using namespace std;
int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    cout<<"Enter number of processes:";
    cin>>n;
    cout<<"\nEnter Process Burst Time:\n";
    for(i=0; i<n; i++)

    {
        cin>>bt[i];
    }
    wt[0]=0;
    for(i=1; i<n; i++)
    {
        wt[i]=0;
        for(j=0; j<i; j++)
            wt[i]+=bt[j];
    }
    cout<<"\nProcess\t\tBurst Time\tWaiting Time\tTurnaround Time";
    for(i=0; i<n; i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        cout<<"\n"<<i+1<<"\t\t"<< bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    }
    avwt/=i;
    avtat/=i;
    cout<<"\n\nAverage Waiting Time: "<<avwt;
    cout<<"\n\nAverage Turnaround Time: "<<avtat;
    cout<<endl;
    return 0;

}
