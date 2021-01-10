from matplotlib import pyplot as plt
import numpy as np

#Reading the output file from the C code
f = open("output.txt","r")
temp = f.read()
#print(temp)

#Splitting the output into list based on lines
output = temp.split('\n')[2:-3]
timestep=[]
task=[]
action=[]
missflag=0


#splitting the rows into single elements based onspaces
for n in output:
    row = n.split(" ")

    # putting in the timestep, action, and task number into their own list
    #this also checks if there is no task being executed in a timestep
    if(row[2]!="task"):
        task.append(int(row[2]))
        timestep.append(int(row[0]))
        action.append(row[3])
    else:
        task.append(0)
        timestep.append(int(row[0]))
        action.append("no")

#Plotting the Graph
for n in range(len(timestep)):
    #Plotting Executes
    if (action[n] =="executes"):
        for x in range(50):
            plt.scatter(timestep[n]+x/50,task[n],c='b',marker='|',s=200)
    #Plotting Completes
    elif(action[n]=="completed"):
        com = plt.scatter(timestep[n]+1,task[n],c='#ace685',marker='^',s=50)
    #Plotting Misses
    elif(action[n]=="misses"):
        miss = plt.scatter(timestep[n],task[n],c='#ff1c03',marker='o',s=50)
        missflag=1
    #Dealing with no task
    elif(action[n]=="no"):
        continue

#Setting the scales for the axes
plt.xticks(range(0,max(timestep)+2))
plt.yticks(range(0,max(task)+2))

plt.xlabel('TIME')
plt.ylabel('TASK')
plt.title('Scheduling Results')
com.set_label('Complete')
if (missflag==1):
	miss.set_label('Miss')
plt.legend()
plt.grid()

plt.show()

'''numtask=[]

for n in task:
    if(n!=0):
        sametask=False
        for x in numtask:
            if (x==n):
                sametask=True
        if (sametask == False):
            numtask.append(n)'''





#print(task)
    
    #print(line)
    
#print(output)
#print(f.read())
