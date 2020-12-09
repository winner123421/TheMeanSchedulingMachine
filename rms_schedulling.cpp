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






   
   
   /*while (priority.size()<p.size()){
       for(size_t n ; n<p.size();n++){
           for(size_t m ; m<p.size();m++){
               if (p[n]<p[m]){
                   for(size_t b; b<priority.size(); b++){
                       if (n == prior[b]){
                           break;
                       }
                   }
               }
           }
       }
   }*/
   
   /* while(true){
        

        if (unsorted >0){
            
            for (size_t n=0; n<p.size();n++){
                flag = true;
               for (size_t m=0; m<p.size();m++){
                   
                   for(size_t c=0; c<priority.size();c++){
                            if (n==priority[c]){
                                flag=false;
                            }

                        }
                    if (flag == false)break;
                    else if(p[n]>p[m]){
                        cout<<"here  \n";

                        flag = false;
                        for(size_t b=0; b<priority.size();b++){
                            if (n==priority[b])flag = true;
                        }

                    }
                }
                if (flag==true){
                    priority.push_back(n);
                    cout<<n <<"  enter  \n";
                    unsorted--;
                }


            }
            
            
        }
        else {
            return priority;
            break;
        }
    }*/


    /*for (size_t n = 0;n<p.size();n++){
        flag = true;
        for (size_t c = 0 ;c<p.size();c++){
            if (p[c]>p[n]){
                flag = false;
                for(size_t m; m<priority.size();m++)

            }
        }

        
    }*/
}

int main(){
    string line ;
    string fun ;
    int numtask;
    int temp_extime;
    int temp_period;

   
    


    ifstream file("testcase.txt");


    file >> fun >> numtask;
    cout<<numtask<<"\n";
    vector <int> extime;
    vector <int>period;
    vector <int> prior;

    int temp=0;


    while(numtask>0){
        
        file>>fun>>temp_extime>>temp_period;
        
        numtask--;
        extime.push_back(temp_extime);
        period.push_back(temp_period);
    }
    lowest_common_multiple(period);
    prior = find_priority(period);
    for (size_t n; n<prior.size();n++){
        cout<< prior[n]<< " ";
    }
    cout<<"\n";
    return 0;



}
