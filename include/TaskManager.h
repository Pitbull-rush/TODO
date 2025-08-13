#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>

enum class Status {
    TODO,
    IN_PROGRESS,
    DONE
};

enum class Priority {
    LOW,
    MEDIUM,
    HIGH
};

class Task {
private:
    int id;
    std::string title;
    Status status;
    Priority priority;

public:
    Task(int id, const std::string& title, Status status, Priority priority)
        : id(id), title(title), status(status), priority(priority) {}

    int getId() const { return id; }
    Status getStatus() const { return status; }
    Priority getPriority() const { return priority; }
    const std::string& getTitle() const { return title; }

    void setStatus(Status newStatus) { status = newStatus; }
    void setPriority(Priority newPriority) { priority = newPriority; }

    void display() const;

    std::string toFileString() const;
};

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const std::string& title, Status status, Priority priority);
    void deleteTaskByID(int id);
    void updateTask(int id, Status status, Priority priority);
    void filterByStatus(Status status) const;
    void displayTasks() const;

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

