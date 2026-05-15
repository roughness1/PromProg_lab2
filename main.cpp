#include <iostream>
#include <string>
#include <vector>
class Task{
    public:
    int id;
    std::string text;
    std::string status;
};
int main(){
    std::vector<Task> tasks;
    int next_id=1;
    int choice;
    while(true){
        std::cout<<"1. Показать задачи"<<std::endl<<"2. Добавить задачу"<<std::endl<<"3. Выйти"<<std::endl<<"4. Отметить задачу как выполненную"<<std::endl;
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"\n--- Список задач ----"<<std::endl;
                if (tasks.empty()){
                    std::cout<<"Список пуст."<<std::endl;
                }
                else{
                    for (const auto& task : tasks) {
                        std::cout << "[" << task.id << "] " << task.text 
                                  << " (" << task.status << ")" << std::endl;
                        }
                }
            
                break;
            case 2:{
                std::cout << "\nВведите текст задачи: ";
                std::string task_text;
                std::cin.ignore(); 
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
                std::cout<<"\nВыход из программы..."<<std::endl;
                return 0;
                break;
            case 4: {
                std::cout << "\nВведите ID задачи, которую вы выполнили: ";
                int target_id;
                std::cin >> target_id;
                bool found = false;
                for (auto& task : tasks) {
                    if (task.id == target_id) {
                        task.status = "Выполнено";
                        found = true;
                        std::cout << "Отлично! Задача #" << target_id << " отмечена как выполненная." << std::endl;
                        break; 
                    }
                }
                if (!found) {
                    std::cout << "Ошибка: Задача с ID " << target_id << " не найдена." << std::endl;
                }
                break;
            }
            default:
                std::cout<<"\nНеверный пункт меню, попробуйте снова."<<std::endl;
                break;
        }
    }

}