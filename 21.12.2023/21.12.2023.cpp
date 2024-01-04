#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ranges>

using namespace std;

class Project {
public:
    string name;
    string description;
    string startDate;
    string endDate;
    vector<Task> tasks;

    Project() = default;

    Project(string name, string description, string startDate, string endDate) {
        this->name = name;
        this->description = description;
        this->startDate = startDate;
        this->endDate = endDate;
    }

    void addTask(Task task) {
        tasks.push_back(task);
    }

    void removeTask(int index) {
        tasks.erase(tasks.begin() + index);
    }

    void setTaskDeadline(int index, string deadline) {
        tasks[index].deadline = deadline;
    }

    string getStatus() {
        string status = "В розробці";
        for (const Task& task : tasks) {
            if (task.status == "Завершено") {
                status = "Завершено";
                break;
            }
        }
        return status;
    }
};

class Task {
public:
    string description;
    string status;
    string deadline;

    Task() = default;

    Task(string description, string status, string deadline) {
        this->description = description;
        this->status = status;
        this->deadline = deadline;
    }

    void setStatus(string status) {
        this->status = status;
    }

    string getInfo() {
        return "Опис: " + description + " Статус: " + status + " Термін виконання: " + deadline;
    }
};

class ProjectManager {
public:

    vector<Project> projects;

    ProjectManager() = default;

    Project createProject(string name, string description, string startDate, string endDate) {
        Project project(name, description, startDate, endDate);
        projects.push_back(project);
        return project;
    }

    void addTaskToProject(int projectIndex, Task task) {
        projects[projectIndex].addTask(task);
    }

    void removeTaskFromProject(int projectIndex, int taskIndex) {
        projects[projectIndex].removeTask(taskIndex);
    }

    void trackProjects() {
        for (const Project& project : projects) {
            cout << "Назва проекту: " << project.name << endl;
            cout << "Опис проекту: " << project.description << endl;
            cout << "Стан проекту: " << project.getStatus() << endl;
        }
    }

    void analyzeProjects() {
        for (const Project& project : projects) {
            cout << "Проект " << project.name << ":" << endl;
            cout << "Кількість завдань: " << project.tasks.size() << endl;
            cout << "Загальний статус: " << project.getStatus() << endl;

            double totalDeadline = 0;
            for (const Task& task : project.tasks) {
                totalDeadline += stoi(task.deadline);
            }
            double averageDeadline = totalDeadline / project.tasks.size();
            cout << "Середній термін виконання: " << averageDeadline << endl;
        }
    }
};

void showMenu() {
    cout << "1. Створити проект" << endl;
    cout << "2. Додати завдання до проекту" << endl;
    cout << "3. Видалити завдання з проекту" << endl;
    cout << "4. Відстежити стан проектів" << endl;
    cout << "5. Проаналізувати стан проектів" << endl;
    cout << "6. Вихід" << endl;
}
