#include <iostream>
#include <string>
#include <vector>
#include <limits> 

class Task {
public:
    int id;
    std::string text;
    std::string status;
};

int main() {
    std::vector<Task> tasks;
    int next_id = 1;
    int choice;

    while (true) {
        std::cout << "\n--- МЕНЕДЖЕР ЗАДАЧ ---" << std::endl;
        std::cout << "1. Просмотр текущих задач"<<std::endl;
        std::cout << "2. Добавить задачу" << std::endl;
        std::cout << "3. Выйти" << std::endl;
        std::cout << "4. Отметить задачу как выполненную" << std::endl;
        std::cout << "Выберите пункт: ";

        if (!(std::cin >> choice)) {
            std::cout << "\n[Ошибка]: Введите числовое значение!" << std::endl;
            std::cin.clear(); 
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
            continue; 
        }

        switch (choice) {
            case 1:
                std::cout << "\n--- Список задач ---" << std::endl;
                if (tasks.empty()) {
                    std::cout << "Список пуст." << std::endl;
                } else {
                    for (const auto& task : tasks) {
                        std::cout << "[" << task.id << "] " << task.text 
                                  << " (" << task.status << ")" << std::endl;
                    }
                }
                break;

            case 2: {
                std::cout << "\nВведите текст задачи: ";
                std::string task_text;
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); 
                std::getline(std::cin, task_text);

                Task new_task;
                new_task.id = next_id++;
                new_task.text = task_text;
                new_task.status = "В процессе";
                tasks.push_back(new_task);
                std::cout << "Задача успешно добавлена!" << std::endl;
                break;
            }

            case 3:
                std::cout << "\nВыход из программы..." << std::endl;
                return 0;

            case 4: {
                std::cout << "\nВведите ID задачи: ";
                int target_id;
                if (!(std::cin >> target_id)) {
                    std::cout << "Ошибка: ID должен быть числом." << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    break;
                }
                
                bool found = false;
                for (auto& task : tasks) {
                    if (task.id == target_id) {
                        task.status = "Выполнено";
                        found = true;
                        std::cout << "Задача #" << target_id << " завершена!" << std::endl;
                        break; 
                    }
                }
                if (!found) std::cout << "Задача с таким ID не найдена." << std::endl;
                break;
            }

            default:
                std::cout << "\nНеверный пункт меню, попробуйте снова." << std::endl;
                break;
        }
    }
    return 0;
}