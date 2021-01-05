#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

//Function to find the lowest common multiple
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
//Function to find the priority
//In this case because it is EDF the priority is dynamic and determined by the task closest to the deadline
vector <int> find_priority(vector <int> p){
    vector <int> priority;
    vector <int> index;
    bool flag;
    
    int temp,indextemp;

    for(size_t n = 0; n<p.size();n++)index.push_back(n);
    //Rearrange using bubblesort
    for (size_t n = 0; n<p.size()-1;n++){
        for(size_t m = 0; m<p.size()-n-1;m++){
            if (p[n] > p[n+1]){ 
                temp = p[n];
                p[n] = p[n+1];
                p[n+1]=temp;
                indextemp=index[n];
                index[n]=index[n+1];
                index[n+1]=indextemp;
                /*for (size_t x=0; x<index.size();x++){
                    cout<< index[x]<< " ";
                }
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
    //Defining all Parameters
    string line ;
    string fun ;
    int numtask;
    int temp_extime;
    int temp_period;
    int T_step = 0;
    int lcm;

    //Opening the input and output files    
    ifstream file("testcase.txt");
    ofstream outfile("output.txt");


    file >> fun >> numtask;
    cout<<"Number of Task "<<numtask<<"\n";
    outfile<<"Number of Task "<<numtask<<"\n";
    vector <int> extime;
    vector <int>period;
    vector <int> prior;
    vector <int> current_execution;
    vector <int> current_deadline;
    int active_task;
    int temp=0;

    //Getting the execution time and period into lists
    while(numtask>0){
        
        file>>fun>>temp_extime>>temp_period;
        numtask--;
        extime.push_back(temp_extime);
        period.push_back(temp_period);
    }
    //Setting up the lowest common multiple and the starting priority
    lcm = lowest_common_multiple(period);
    prior=find_priority(period);
    

    outfile<< "---------------------------------------------------------------------------\n";
    cout<< "---------------------------------------------------------------------------\n";
    current_execution = extime;
    current_deadline = period;
    bool no_task=false;
    int misses=0;

    while (T_step < lcm){

        //Updating the deadline to get a dynamic deadline
        for(size_t n = 0; n < period.size();n++){
            current_deadline[n] = period[n] - (T_step % period[n]);
        }
        // updating priority based on current deadline
        prior = find_priority(current_deadline);

        //get active task
        for(size_t n = prior.size(); n>0; n--){
            if (current_execution[prior[n-1]]>0){
                active_task = prior[n-1];
            }    


        }
        //Checking if a there is a timestep where no task is executed
        no_task=true;
        for( auto m:current_execution){

            if (m>0){
                no_task=false;
            }
        }

        if (!no_task){
            //Executes task
            outfile<<T_step<<" Task " << active_task+1 << " executes \n";
            cout<<T_step<<" Task " << active_task+1 << " executes \n";
            current_execution[active_task]--;
            //Completes task
            if(current_execution[active_task]==0){
                outfile<<T_step<<" Task " << active_task+1 << " completed \n";
                cout<<T_step<<" Task " << active_task+1 << " completed \n";
            }
            
        }
        else if(no_task)outfile<<T_step<<" No task \n";
        T_step++;
         //adding the execution time every period reached
        for(size_t n = 0; n<period.size();n++){
            if(T_step % period[n]==0){
                //Checking If there are any deadline misses
                if(current_execution[n]!=0){
                    outfile<<T_step<<" Task " << n+1 << " misses \n";
                    cout<<T_step<<" Task " << n+1 << " misses \n";
                    //Keeping track of total misses
                    misses++;
                }
                //Reequate execution time at the end of a period
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
