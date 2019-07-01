#include <iostream>
using namespace std;
#include<vector>
#include <map>



void printessentials()
{
    vector<int> stored = store;
    vector<Reps> E;
    map <int,int> Mapp;
    vector<int> A;
    vector <int> X;
    int x = stored[0];
    int t =0;
    int c = (char)'a';
    bool flag = false;
    cout << "Essential Prime Implicants are:" << endl;
    cout << "_________________________" << endl;
    for (int i = 0; i < x;  i++)
    
        A[i] = stored[i+1];
    
    for (int i = 0; i < E.size();  i++)
        for (int j =0; j< E[i].comb.size(); j++)
            for (int m = 0; m < x; m++)
            
                if (A[m] == E[i].comb[j])
                
                     if(Mapp.find(E[i].comb[j]) != Mapp.end())
                            Mapp[E[i].comb[j]]++;
                     else
                            Mapp[E[i].comb[j]] =1;
                    break;
                
            
    for (it = Mapp.begin(); it != Mapp.end(); ++it )
    
        if (it->second == 1)
            X[t]=it->first;
        t = 0;
    
    for (int k =0; k <t; k++)
        for (int i = 0; i < E.size();  i++)
        
            for (int j =0; j< E[i].comb.size(); j++)
            
                while (!flag)
                    if (X[k]== E[i].comb[j])
                    
                        flag = true;
                        j = 0;
                    
                while ((flag) && (j <= E[i].comb.size() -1))
                
                    c+= E[i].comb[j];
                    cout << (char) c << setw(3);
                    c = (char)'a';
                
            
            
            flag = false;
            cout << endl;
        
    
}
void printprime ()
{
    vector<Reps> essential = essentials ;
    string x;
    int c = (char)'a';
    cout << "Prime Implicants are:" << endl;
    cout << "_________________" << endl;
    for (int i=0; i < essential.size(); i++)
    
        x = essential[i].binary;
        for (int j =0; j < x.length(); j++)
        
            if (x[j]== '0')
                cout << setw(3)<< char (c+j) << "'";
            else if (x[j] == '1')
                cout << setw(3) <<char (c+j) ;
            c = (char)'a';
        
        cout << endl;
    
    printessentials();
}




int main()
{
}
