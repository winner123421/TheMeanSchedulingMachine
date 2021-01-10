#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Function to find the priority
//In this case because it is EDF the priority is dynamic and determined by the task closest to the deadline
vector <int> find_priority(vector <int> p){
    vector <int> priority;
    vector <int> index;
    bool flag;
    
    int temp,indextemp;

    for(size_t n = 0; n<p.size();n++)index.push_back(n);
    //Rearrange using bubblesort
    for (size_t n = 0; n<p.size();n++){
        for(size_t m = n+1; m<p.size();m++){
            if (p[m] < p[n]){ 
                temp = p[n];
                p[n] = p[m];
                p[m]=temp;
                indextemp=index[n];
                index[n]=index[m];
                index[m]=indextemp;
                for (size_t x=0; x<index.size();x++){
                    cout<< index[x]<< " ";
                }
                 cout<<"\n";
                for (size_t x=0; x<p.size();x++){
                    cout<< p[x]<< " ";
                }
                cout<<"\n";



            }
        }    
    }
    return index;
   
}

int main(){
    vector <int> test{9,6,4,5,7,9};
    
    find_priority(test);
    return 0;
}