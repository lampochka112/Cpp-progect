#include <iostream>
#include <vector>
#include <string>
#include <limits>

// Структура задачи
struct Task {
    int id;
    std::string description;
    bool completed;
};

// Глобальный список задач
std::vector<Task> tasks;
int nextId = 1;

// Функция добавления задачи
void addTask() {
    std::cout << "Введите описание задачи: ";
    std::string desc;
    std::getline(std::cin, desc);
    Task newTask{nextId++, desc, false};
    tasks.push_back(newTask);
    std::cout << "Задача добавлена.\n";
}

// Функция отображения всех задач
void showTasks() {
    if (tasks.empty()) {
        std::cout << "Список задач пуст.\n";
        return;
    }
    for (const auto& task : tasks) {
        std::cout << "ID: " << task.id
                  << " | " << (task.completed ? "[Выполнено]" : "[Не выполнено]")
                  << " | " << task.description << "\n";
    }
}

// Функция редактирования задачи
void editTask() {
    std::cout << "Введите ID задачи для редактирования: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (auto& task : tasks) {
        if (task.id == id) {
            std::cout << "Текующее описание: " << task.description << "\n";
            std::cout << "Введите новое описание: ";
            std::string newDesc;
            std::getline(std::cin, newDesc);
            if (!newDesc.empty()) {
                task.description = newDesc;
                std::cout << "Описание обновлено.\n";
            } else {
                std::cout << "Описание не изменено.\n";
            }
            return;
        }
    }
    std::cout << "Задача с ID " << id << " не найдена.\n";
}

// Функция удаления задачи
void deleteTask() {
    std::cout << "Введите ID задачи для удаления: ";
    int id;
    std::cin >> id;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->id == id) {
            tasks.erase(it);
            std::cout << "Задача удалена.\n";
            return;
        }
    }
    std::cout << "Задача с ID " << id << " не найдена.\n";
}

// Основное меню
void menu() {
    while (true) {
        std::cout << "\nМеню:\n";
        std::cout << "1. Добавить задачу\n";
        std::cout << "2. Просмотр задач\n";
        std::cout << "3. Редактировать задачу\n";
        std::cout << "4. Удалить задачу\n";
        std::cout << "5. Выход\n";
        std::cout << "Выберите действие: ";

        int choice;
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                showTasks();
                break;
            case 3:
                editTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                std::cout << "Выход из программы.\n";
                return;
            default:
                std::cout << "Некорректный выбор, попробуйте снова.\n";
        }
    }
}

int main() {
    std::cout << "Добро пожаловать в менеджер задач!\n";
    menu();
    return 0;
}