#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

void result(int total)
{
    string a1,a2,a3;
    int n,r=0;
    ifstream fin("Output.txt");
    fin>>n;
    string spop;
    map<string,int> pop;
    int amount = (total-43)/3;
    cout<<"Pet_name: ";for(int i = 0; i < amount;i++)cout<<" ";
    cout<<"favourite_tv_series: ";for(int i = 0; i < amount;i++)cout<<" ";
    cout<<"street_name:\n";
    for(int i = 0;i<n*3;)
    {
    fin>>a1>>a2>>a3;
    pop[a3]++;
    //cout<<"amount = "<<amount<<endl;
    //cout<<"a1.length() = "<<a1.length()<<endl;
    if(9+amount>=a1.length())
    {
        cout<<a1;
        for(int i = 0; i <= 9+amount-a1.length();i++)cout<<" ";
    }
    else cout<<a1.substr(0,6+amount)<<"... ";
    if(20+amount>=a2.length())
    {
        cout<<a2;
        for(int i = 0; i <= amount-a2.length()+20;i++)cout<<" ";
    }
    else cout<<a2.substr(0,17+amount)<<"... ";
    if(12+amount>=a3.length())
    {
        cout<<a3;
        for(int i = 0; i <= amount-a3.length()+12;i++)cout<<" ";
    }
    else cout<<a3.substr(0,9+amount)<<"...";
    cout<<endl;
    i+=3;
    }
    for (auto [first, second] : pop)
    {
    if(second>r){r=second;spop=first;}
    }
    cout<<"The most popular answer for the third question is *"<<spop<<"*"<<endl;

}
int main()
{
    cout<<"Do you want to enter your answers or to get the previous Data? (1 or 2)?\n";
    int main_root;
    cin>>main_root;
    if(main_root==1){
    ifstream fin("Output.txt");
    ifstream finq("questions.txt");
    int n;
    fin>>n;
    vector<string> ss(n*3);
    for(int i = 0;i<n*3;i++)fin>>ss[i];
    n++;
    fin.close();
    ofstream fout("Output.txt");
    string q1, q2, q3, a1, a2, a3;
    finq>>q1>>q2>>q3;
    cout<<"Enter your "<<q1<<", "<<q2<<", "<<q3<<endl;
    cin>>a1>>a2>>a3;
    fout<<n<<" ";
    for(int i = 0;i<(n-1)*3;i++){fout<<ss[i]<<" ";if(i%3==0&&i!=0)fout<<endl;}
    fout<<a1<<" "<<a2<<" "<<a3<<endl;
    fout.close();
    }
    else if(main_root==2)
    {
        cout<<"Enter width of the table you want to see (min is 43):\n";
        int total;cin>>total;
            result(total);
    }
    else cout<<"-_-";
    return 0;
}

