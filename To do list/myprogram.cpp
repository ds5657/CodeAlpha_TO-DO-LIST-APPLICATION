#include <iostream>
#include <vector>
#include <string>

class ToDoList {
private:
    std::vector<std::string> tasks;

public:
    void addTask(const std::string& task) {
        tasks.push_back(task);
        std::cout << "Task '" << task << "' added to the list." << std::endl;
    }

    void displayTasks() {
        if (tasks.empty()) {
            std::cout << "No tasks in the list." << std::endl;
        } else {
            std::cout << "Tasks in your to-do list:" << std::endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                std::cout << i + 1 << ". " << tasks[i] << std::endl;
            }
        }
    }
};

int main() {
    ToDoList todoList;

    while (true) {
        std::cout << "\nTo-Do List Application" << std::endl;
        std::cout << "1. Add a task" << std::endl;
        std::cout << "2. View tasks" << std::endl;
        std::cout << "3. Exit" << std::endl;

        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::string task;
                std::cout << "Enter the task you want to add: ";
                std::cin.ignore(); // Clear newline character from buffer
                std::getline(std::cin, task);
                todoList.addTask(task);
                break;
            }
            case 2:
                todoList.displayTasks();
                break;
            case 3:
                std::cout << "Exiting the application." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;
}
