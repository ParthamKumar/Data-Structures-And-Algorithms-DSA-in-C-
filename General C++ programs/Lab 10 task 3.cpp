#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

struct Task{
    string name;
    int priority;
};

struct ComparePriority{
    bool operator()(Task const&t1,Task const&t2){
        return t1.priority<t2.priority;
    }
};

int main(){
    int n;
    cout<<"Enter the number of tasks to schedule:";
    cin>>n;

    priority_queue<Task,vector<Task>,ComparePriority> taskQueue;

    for(int i=1;i<=n;i++){
        Task task;
        cout<<"Enter name of task "<<i<<":";
        cin>>task.name;
        task.priority=rand()%10+1;
        taskQueue.push(task);
    }

    while(!taskQueue.empty()){
        Task task=taskQueue.top();
        cout<<task.name<<" ";
        taskQueue.pop();
    }

    return 0;
}
