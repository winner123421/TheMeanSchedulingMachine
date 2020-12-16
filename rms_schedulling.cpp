#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int lowest_common_multiple(vector <int> p){
    //chech biggest number
    int number1=0 ;
    for(size_t n=0;n<p.size();n++){
        if (number1<p[n])number1 = p[n];
    }
    
    bool found=false;
    bool pass;

    while (found == false){
        pass = true;
        for (size_t n = 0 ;n <p.size();n++){
            if (number1%p[n] !=0)pass=false;
        }
        if (pass==true){
            return number1;
            found =true;
        }
        else if (pass==false){
            number1++;

        }
    }

}

vector <int> find_priority(vector <int> p){
    vector <int> priority;
    vector <int> index;
    bool flag;
    
    int temp,indextemp;

    for(size_t n = 0; n<p.size();n++)index.push_back(n);

    for (size_t n = 0; n<p.size()-1;n++){
        for(size_t m = 0; m<p.size()-n-1;m++){
            if (p[n] > p[n+1]){ 
                temp = p[n];
                p[n] = p[n+1];
                p[n+1]=temp;
                indextemp=index[n];
                index[n]=index[n+1];
                index[n+1]=indextemp;
                for (size_t x=0; x<index.size();x++){
                    cout<< index[x]<< " ";
                }
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
    string line ;
    string fun ;
    int numtask;
    int temp_extime;
    int temp_period;
    int T_step = 0;
    int lcm;


   
    


    ifstream file("testcase.txt");


    file >> fun >> numtask;
    cout<<numtask<<"\n";
    vector <int> extime;
    vector <int>period;
    vector <int> prior;
    vector <int> current_execution;
    int active_task;

    int temp=0;


    while(numtask>0){
        
        file>>fun>>temp_extime>>temp_period;
        
        numtask--;
        extime.push_back(temp_extime);
        period.push_back(temp_period);
    }
    lcm = lowest_common_multiple(period);
    prior = find_priority(period);
    for (size_t n; n<prior.size();n++){
        cout<< prior[n]<< " ";
    }
    cout<<"\n";

    cout<< "---------------------------------------------------------------------------\n";
    current_execution = extime;
    bool no_task=false;

    while (T_step < lcm){


        //get active task
        for(size_t n = prior.size(); n>0; n--){
            if (current_execution[prior[n-1]]>0){
                active_task = prior[n-1];
            }    


        }
        no_task=true;
        for( auto m:current_execution){
            if (m>0){
                no_task=false;
            }

        }

        if (!no_task){


            cout<<T_step<<" Task " << active_task+1 << " executes \n";



       
            current_execution[active_task]--;
            if(current_execution[active_task]==0){
                cout<<T_step<<" Task " << active_task+1 << " completed \n";
            }
            
        }
        else if(no_task)cout<<T_step<<" No task \n";
        T_step++;
         //adding the execution time every period reached
        for(size_t n = 0; n<period.size();n++){
            if(T_step % period[n]==0){
                if(current_execution[n]!=0){
                    cout<<T_step<<" Task " << n+1 << " misses \n";
                }
                current_execution[n] = extime[n];

            }
        }


        


    }
    cout<< "---------------------------------------------------------------------------\n";
    return 0;



}
