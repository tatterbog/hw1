#include <iostream>
#include <forward_list>
#include <utility>
#include <vector>
#include <cmath>

class TaskManager{
    private:
        std::vector<std::forward_list<std::string>> tasks;
        int priority;
    
    public:
        TaskManager(int p) : tasks(p), priority(p){}

        void addTask(int p, const std::string &task){
            if(p < 0 || p >= priority){
                std::cout << "it ain't that important pmo\n";
                return;
            }

            tasks[p].push_front(task);
            tasks[p].reverse();
        }

        std::string getNextTask(){
            for(int i = 0; i < priority; i++){
                if(!tasks[i].empty()){
                    std::string task = tasks[i].front();
                    tasks[i].pop_front();
                    return task;
                }
            }
            return "Bro lwk cooked everything";
        }

        void printAllTasks() const {
            for(int i = 0; i < priority; i++){
                std::cout << "Priority " << i + 1 << ":\n";
                for(const auto &task : tasks[i]){
                    std::cout << "- " << task << '\n';
                }
            }
        }
};

int main(){
    TaskManager tm(3); // 3 уровня приоритета
    tm.addTask(0, "Fix critical bug");
    tm.addTask(2, "Update documentation");
    tm.addTask(0, "Deploy to production");
    tm.addTask(1, "Review pull request");
    std::string task = tm.getNextTask(); // "Fix critical bug"
    std::cout << task << '\n';
    tm.printAllTasks();
}