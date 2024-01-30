#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Task {
    string description;
    bool completed;
    Task(const string& desc) : description(desc), completed(false) {}
};
void addTask(vector<Task>& todoList, const string& description) {
    todoList.push_back(Task(description));
    cout << "Task added: " << description << endl;
}
void viewTasks(const vector<Task>& todoList) {
    if (todoList.empty()) {
        cout << "No tasks in the to-do list." << endl;
    } else {
        cout << "To-Do List:" << endl;
        for (size_t i = 0; i < todoList.size(); ++i) {
            cout << i + 1 << ". " << (todoList[i].completed ? "[X] " : "[ ] ") << todoList[i].description << endl;
        }
    }
}
void markCompleted(vector<Task>& todoList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(todoList.size())) {
        todoList[taskIndex].completed = true;
        cout << "Task marked as completed: " << todoList[taskIndex].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}
void removeTask(vector<Task>& todoList, int taskIndex) {
    if (taskIndex >= 0 && taskIndex < static_cast<int>(todoList.size())) {
        cout << "Task removed: " << todoList[taskIndex].description << endl;
        todoList.erase(todoList.begin() + taskIndex);
    } else {
        cout << "Invalid task index." << endl;
    }
}
int main() {
    vector<Task> todoList;
    cout << "Simple To-Do List Manager" << endl;
    while (true) {
        cout << "\nOptions:" << endl;
        cout << "1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Quit" << endl;
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter the task description: ";
                cin.ignore();  
                getline(cin, taskDescription);
                addTask(todoList, taskDescription);
                break;
            }
            case 2:
                viewTasks(todoList);
                break;
            case 3: {
                int taskIndex;
                cout << "Enter the task index to mark as completed: ";
                cin >> taskIndex;
                markCompleted(todoList, taskIndex - 1);
                break;
            }
            case 4: {
                int taskIndex;
                cout << "Enter the task index to remove: ";
                cin >> taskIndex;
                removeTask(todoList, taskIndex - 1);
                break;
            }
            case 5:
                cout << "Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }
    return 0;
}
