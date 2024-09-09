#include "../inc/main.hpp"
int main(){
    int choice;
    while(true)
    {
        system("clear");
        std::cout << "Main Menu \n-----------------------"<<std::endl;
        std::cout << "1- Wifi Control" <<  std::endl;
        std::cout << "2- Bluetooth Control" << std::endl;
        std::cout << "3- Exit" << std::endl;
        std::cout << "Choice: ";
        std::cin >> choice;
        
        switch(choice)
        {
            case 1: wifiMenu();
                    break;
            case 2: bluetoothMenu();
                    break;
            case 3: exit(0);
            default: break;
        }
        system("clear");
    }
    return 0;
}