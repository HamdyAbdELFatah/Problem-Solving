#include <bits/stdc++.h>
using namespace std;
int main()
{
    char arr[6];string y;
    for (int i=0; i<6 ; i+=2 )
    {
        cin>>y;
        if(y[1]=='<')
        {
            arr[i]=y[0];
            arr[i+1]=y[2];
        }
        else
        {
            arr[i]=y[2];
            arr[i+1]=y[0];
        }
    }
    char a,b,c;
    if(arr[1]==arr[3]||arr[3]==arr[5])
    {
        a=arr[3];
        b=(arr[1]==arr[3])?arr[5]:arr[1];
     }
    else if(arr[1]==arr[5])
    {
        a=arr[1];
        b=arr[3];
    }else{
        cout<<"Impossible"<<endl;
        return 0;
    }

    if(arr[0]==arr[2]||arr[2]==arr[4])
        c=arr[2];
    else if(arr[0]==arr[4])
        c=arr[0];
    else{
        cout<<"Impossible"<<endl;
        return 0;}

    if(a==b||a==c||b==c)
        cout<<"Impossible"<<endl;
    else
        cout<<c<<b<<a<<endl;

    return 0;
}