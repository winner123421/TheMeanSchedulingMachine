#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

// This function is meant to find the lowest common multiple to determine the superperiod
int lowest_common_multiple(vector <int> p){
    //check biggest number
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
    return 0;

}

// This function finds the priority of the execution for the schedulling
// Since this is RMS the priority is static and dependant on the period of the task
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
                //print to check priority for debugging
                /*for (size_t x=0; x<index.size();x++){
                    cout<< index[x]<< " ";
                }
                 cout<<"\n";
                for (size_t x=0; x<p.size();x++){
                    cout<< p[x]<< " ";
                }
                cout<<"\n";*/



            }
        }    
    }
    return index;
   
   
}


int main(){
    string line ;
    string fun ; //To temperorarily store in the irrelevant string in the input
    int numtask;
    int temp_extime;
    int temp_period;
    int T_step = 0;
    int lcm;
    string input;

//getting the input
cout<<" Enter the input file :- \n";
cin >> input;

//Defining the input and output file
    ifstream file(input);  //CHANGE THIS TO CHANGE
    ofstream outfile("output.txt");

//Get number of task and define parameters
    file >> fun >> numtask;
    cout<<"Number of Task = "<<numtask<<"\n";
    outfile<<"Number of Task = "<<numtask<<"\n";
    vector <int> extime;
    vector <int>period;
    vector <int> prior;
    vector <int> current_execution;
    int active_task;
    int temp=0;

//Getting the exectution time and period into a list
    while(numtask>0){
        
        file>>fun>>temp_extime>>temp_period;
        numtask--;
        extime.push_back(temp_extime);
        period.push_back(temp_period);
    }
//Find lowest common multiple
    lcm = lowest_common_multiple(period);

//Find the priority of the tasks
    prior = find_priority(period);
    
    /*for (size_t n; n<prior.size();n++){
        cout<< prior[n]<< " ";
    }
    cout<<"\n";*/

    
    outfile<< "---------------------------------------------------------------------------\n";
    cout<< "---------------------------------------------------------------------------\n";
    current_execution = extime;
    bool no_task=false;
    int misses=0;

    while (T_step < lcm){


        //get active task
        for(size_t n = prior.size(); n>0; n--){
            if (current_execution[prior[n-1]]>0){
                active_task = prior[n-1];
            }    


        }
        //Check in case no task is being executed
        no_task=true;
        for( auto m:current_execution){
            if (m>0){
                no_task=false;
            }

        }

        if (!no_task){
            
            //Execute task
            outfile<<T_step<<" Task " << active_task+1 << " executes \n";
            cout<<T_step<<" Task " << active_task+1 << " executes \n";         
            current_execution[active_task]--;
            //Complete task
            if(current_execution[active_task]==0){
                outfile<<T_step<<" Task " << active_task+1 << " completed \n";
                cout<<T_step<<" Task " << active_task+1 << " completed \n";

            }
            
        }
        //No task
        else if(no_task)outfile<<T_step<<" No task \n";
        T_step++;

        

        //Check for any deadline misses 
        for(size_t n = 0; n<period.size();n++){
            if(T_step % period[n]==0){
                if(current_execution[n]!=0){
                    outfile<<T_step<<" Task " << n+1 << " misses \n";
                    cout<<T_step<<" Task " << n+1 << " misses \n";
                    //keeps track with total deadline miss
                    misses++;
                }
                //Reequating the current execution after every period
                current_execution[n] = extime[n];

            }
        }


        


    }
    cout<<"  Schedulling Completed \n";
    outfile<< "---------------------------------------------------------------------------\n";
    cout<< "---------------------------------------------------------------------------\n\n";

    //Print total misses
    outfile<<" The total Deadline miss -----> "<< misses << "\n";
    cout<<" The total Deadline miss -----> "<< misses << "\n";
    outfile.close();
    return 0;



}
