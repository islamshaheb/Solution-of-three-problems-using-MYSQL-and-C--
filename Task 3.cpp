#include<bits/stdc++.h>
using namespace std;
#define fr(i,frm,fornn)for(int i=frm; i<=fornn; i++)
typedef vector <int> ve;
#define E "\n"
#define F first
#define S second

map<string,string> mp; // map to hold subject with teacher 
map<int,string> subject; // subject id
multimap<int, pair<int,int>> routine;  // for saving routine's information


void A()
{
    int t = 0;
    cout<<"All subject \n"<<E;
    for(auto it = mp.begin();  it != mp.end(); it++)
        cout<<++t<<"."<<it->F<<E;

    cout<<"Enter dayIndex(0 - 4)  hourIndex(0 - 3)  courseIndex for making routine\n";
    int a,b,c;
    while(1)
    {
        cout<<"Enter \"9\" to stop inserting number "<<E;
        cin>>a;
        if(a == 9)break;
        cin>>b>>c;
        routine.insert({a,{b,c}});
    }

}

void B()
{
    for(auto it = routine.begin(); it != routine.end(); it++)
    {
        cout<<it->F<<" "<< it->S.F<<" "<<subject[it->S.S]<<E;
    }
}

void C()
{
    cout<<"Subject  Teacher\n"<<E;
    for(auto it = mp.begin();  it != mp.end(); it++)
        cout<<it->F<<","<<it->S<<E;
}


int main()
{
    ifstream iFile("input.txt");
    string st;
    int t = 0;
    while (getline(iFile,st))
    {
        int len = st.length();
        string temp;
        st+=','; // inserting "," end of the string so that we can separate subject and teacher name easily
        string sub = " ",teacher;

        fr(i,3,len)
        {
            if(st[i]==',')
            {
                if(sub.compare(" ")==0)sub = temp,temp="";
                else teacher = temp;
            }
            else temp+=st[i];
        }

        subject[t++] = sub;
        mp[sub]=teacher;
        cout<<sub<<E;

    }

    while(1)
    {
        char check;
        cout<<"\n\n Enter 'A' to Create Routine \n Enter 'B' to Show Routine \n Enter 'C' to List Courses with Teachers Name \n Enter '0' to terminate this program"<<E;
        cout<<" Want to Reset Routine? Enter 'R' "<<E;
        cin>>check;

        if(check == 'A') A();
        else if(check == 'B') B();
        else if( check == 'C') C();
        else if( check == '0') exit(0);
        else if( check == 'R') routine.clear();

    }
}


