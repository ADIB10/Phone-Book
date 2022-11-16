#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>
#include <conio.h>
#include <windows.h>

using namespace std;

int main()
{
    int f=-1,s=0,t=1,x=0,y=0,g,B;
    string name,num,d,c,fnd="";
    fstream file;

    ///MAIN POINT="1 ADDING LOT OF NUMBER AT ONE TIME" "2 ACCESSING THEM" "3 FINDING NUMBER" "4 DELETING A CERTAIN NUMBER"
    while(t!=0)
{
    g=0;//resets;
    system("cls");
    file.open("contractinfo.txt", ios::in);//mode read
    if(file.is_open())
    {
        getline(file,c);
        file.close();
    }
    cout<<"1:ADD"<<endl<<"2:FIND"<<endl<<"3:SEE"<<endl<<"4:DELEL"<<endl;
    cout<<">";cin>>y;

    ///input
    if(y==1)
    {t=1;
    while(t!=-1)
    {
        name="";num="";
        cout<<"NAME: ";cin>>name;if(name=="Q"){break;}cout<<"NUMBER: ";cin>>num;
        s=12-name.size();
        if(name.size()<=12&&name.size()!=0){for(int i=0;i<=s;i++){name=name+' ';}}
        if(name.size()>12&&name.size()!=0){name=name.substr(0,12);}
        file.open("contractinfo.txt", ios::app);//mode edit
        if(file.is_open()&&num.size()==11)
        {
            file<<name<<num;
            file.close();
            cout<<"NUMBER ADDED"<<endl;
        }

    }
    }

    ///output
    if(y==3)
    {
    file.open("contractinfo.txt", ios::in);//mode read
    if(file.is_open())
    {
        getline(file,c);
        cout<<"0  :";
        for(B=0;B<c.size();B++)
        {if(B%23==0&&B>0)
        {
            cout<<endl;g++;
            if(g<=9){cout<<g<<"  ";}
            if(g<=99&&g>9){cout<<g<<" ";}
            if(g>99){cout<<g;}
            cout<<':';
        }cout<<c[B];}
        file.close();
    }
    }

    ///finding number
    if(y==2)
    {
    cout<<"SEARCH: ";cin>>fnd;
    do
    {
       f=c.find(fnd,f+1);
        if(f!=-1&&f%23==0)
        {
            for(int n=f;n<(f+23);n++)
            {cout<<c[n];}cout<<endl;
        }
    }while(f!=-1);
    }

    ///deleting number
    if(y==4)
    {
        x=0;
        cout<<"NUMBER: ";cin>>x;
        x=x*23;
        string del=c.substr(x,23);
        c.erase(x,23);
        file.close();
        cout<<"DELETED NUMBER"<<endl<<del;
    file.open("contractinfo.txt",ios::out);
    if(file.is_open())
    {
        file<<c;
        file.close();
    }
    }

    fnd=" ";system("pause>nul");
}
    return 0;
}
