//shortest job first
#include<iostream>
using namespace std;
int main()
{
    int time,bt[10],art[10],sum_bt=0,smallest,n,i;
    int sumt=0,sumw=0;
    cout<<"No of processes : ";
    cin>>n;
    for(i=0; i<n; i++)
    {
    cout<<"Arrival time for process "<<i+1<<":";
    cin>>art[i];
    }
     for(i=0; i<n; i++)
    {
    cout<<"Burst time for process "<<i+1<<":"                                                               ;
    cin>>bt[i];
    sum_bt+=bt[i];
    }
    bt[9]=9999;
    for(time=0; time<sum_bt;)
    {
        smallest=9;
        for(i=0; i<n; i++)
        {
        if(art[i]<=time && bt[i]>0 && bt[i]<bt[smallest])
            smallest=i;
    }
        cout<<"P["<<smallest+1<<"]"<<"\t\t"<<bt[smallest]<<"\t\t"<<time+bt[smallest]-art[smallest]<<"\t\t"<<time-art[smallest]<<endl;
        sumt+=time+bt[smallest]-art[smallest];
        sumw+=time-art[smallest];
        time+=bt[smallest];
        bt[smallest]=0;
    }
    cout<<"\n\nAverage waiting time = "<<sumw*1.0/n;
    cout<<"\n\nAverage turnaround time = "<<sumt*1.0/n;
    return 0;
}
