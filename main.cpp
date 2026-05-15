#include <iostream>
#include <string>
class Task{
    public:
    int id;
    std::string text;
    std::string status;
};
int main(){
    int choice;
    while(true){
        std::cout<<"1. Показать задачи"<<std::endl<<"2. Добавить задачу"<<std::endl<<"3. Выйти"<<std::endl;
        std::cin>>choice;
        switch (choice){
            case 1:
                std::cout<<"Вывод списка задач:"<<std::endl;
                break;
            case 2:
                std::cout<<"Добавление новой задачи."<<std::endl;
                break;
            case 3:
                std::cout<<"Выход из программы..."<<std::endl;
                return 0;
                break;
            default:
                std::cout<<"Неверный пункт меню, попробуйте снова."<<std::endl;
                break;
        }
    }

}