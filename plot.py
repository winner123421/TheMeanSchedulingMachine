from matplotlib import pyplot as plt
import numpy as np

f = open("output.txt","r")
temp = f.read()
print(temp)

output = temp.split('\n')[1:-2]
timestep=[]
task=[]
action=[]



for n in output:
    row = n.split(" ")


    if(row[2]!="task"):
        task.append(int(row[2]))
        timestep.append(int(row[0]))
        action.append(row[3])
    else:
        task.append(0)
        timestep.append(int(row[0]))
        action.append("no")

for n in range(len(timestep)):
    if (action[n] =="executes"):
        for x in range(50):
            plt.scatter(timestep[n]+x/50,task[n],c='b',marker='|',s=200)

    elif(action[n]=="completed"):
        plt.scatter(timestep[n]+1,task[n],c='#ace685',marker='^',s=50)

    elif(action[n]=="misses"):
        plt.scatter(timestep[n],task[n],c='#ff1c03',marker='o',s=50)

    elif(action[n]=="no"):
        continue
plt.xlabel('TIME')

plt.xticks(range(0,max(timestep)+2))
plt.yticks(range(0,max(task)+2))

plt.ylabel('TASK')
plt.title('Scheduling Results')
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