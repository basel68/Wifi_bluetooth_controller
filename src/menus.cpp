#include "../inc/menus.hpp"
 void wifiMenu()
{
    int Choice = 0;
    std::string ssid = "";
    std::string password = "";


    while(true)
    {
        system("clear");
        std::cout << "Wifi Menu \n-----------------------"<<std::endl;
        std::cout << "1- Display wifi status" << std::endl;
        std::cout << "2- Turn wifi on" << std::endl;
        std::cout << "3- Turn wifi off" << std::endl;
        std::cout << "4- Connect to wifi" << std::endl;
        std::cout << "5- Back to main menu" << std::endl;
        std::cout << "Choose a number: ";
        std::cin >> Choice;
        system("clear");

        switch (Choice) {
            case 1: 
                    std::cout << get_Wifi_status() << std::endl;
                    break;

            case 2: 
                    
                    std::cout <<set_wifi(ON) << std::endl;
                    break; 

            case 3: 
                    
                    std::cout << set_wifi(OFF) << std::endl;
                    break; 

            case 4: 
                    std::cout << "1- Saved Network" << std::endl;
                    std::cout << "2- New Network" << std::endl;
                    std::cin >> Choice;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer
                    switch (Choice) {
                        case 1: 
                                get_saved_network();
                                std::cout << "Please Enter SSID: " << std::endl;
                                std::getline(std::cin, ssid);  
                                std::cout << "Connecting to " << ssid << std::endl;
                                if(connect_to_wifi(ssid)) 
                                    std::cout << "Connected to " << ssid << std::endl;
                                else 
                                    std::cout << "Failed to Connect to " << ssid << std::endl;
                                break;

                        case 2: 
                                get_available_network();
                                std::cout << "Please Enter SSID: " << std::endl;
                                std::getline(std::cin, ssid); 
                                std::cout << "Please Enter Password: " << std::endl;
                                std::getline(std::cin, password);  
                                std::cout << "Trying to connect to " << ssid << std::endl;
                                connect_to_wifi(ssid, password);
                                std::cout << ssid << password;
                                break;

                        default: 
                                break;
                    }
                    break;

           
            case 5:return;
            
            default:std::cout << "enter a valid choice" << std::endl;
                    break;
        }

        // Wait for the user to press Enter before continuing
        std::cout << "Press Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover input max or until finding a new line
        std::cin.get(); // Wait for Enter key
    }
}

void bluetoothMenu()
{
    int Choice = 0;
    std::string Address = "";
    while(true)
    {
        system("clear");
        std::cout << "Bluetooth Menu \n-----------------------"<<std::endl;
        std::cout << "1- Display bluetooth status" << std::endl;
        std::cout << "2- Turn bluetooth on" << std::endl;
        std::cout << "3- Turn bluetooth off" << std::endl;
        std::cout << "4- Connect to bluetooth" << std::endl;
        std::cout << "5- Back to main menu" << std::endl;
        std::cout << "Choose a number: ";
        std::cin >> Choice;
        system("clear");
        switch (Choice) {
            case 1: std::cout << get_bluetooth_status() << std::endl;
                    break;
            case 2: if(set_bluetooth(ON)) std::cout << "Turned On" << std::endl;
                    else std::cout << "Can't Turn bluetooth On" << std::endl;
                    break;
            case 3: if(set_bluetooth(OFF)) std::cout << "Turned Off" << std::endl;
                    else std::cout << "Can't Turn bluetooth Off" << std::endl;
                    break; 
            case 4: std::cout << "Please Wait until Scan is finished" << std::endl;
                    system("hcitool scan");
                    std::cout << "Please Enter Device Address" << std::endl;
                    std::cin >> Address;
                    std::cout << std::endl;
                    std::cout << "1- Pair To device" << std::endl;
                    std::cout << "2- Connect To device" << std::endl;
                    std::cout << "3- Go Back to Bluetooth Menu" << std::endl;
                    std::cout << "Choice: ";
                    std::cin >> Choice;
                    switch (Choice) {
                        case 1: if(ConnectBluetoothDevice(Address, true)) 
                                    std::cout << "Paired Success!" <<std::endl;
                                else 
                                    std::cout << "Can't Pair Device" << std::endl; 
                                break;
                        case 2: if(ConnectBluetoothDevice(Address,false)) 
                                    std::cout << "Connection Success!" <<std::endl;
                                else 
                                    std::cout << "Can't Connect Device" << std::endl;
                                break;
                        case 3: break;
                        default:std::cout << "enter a valid choice " << std::endl;
                                break;
                    }
                    break;
                    
            case 5: return;
            default: 
                    std::cout << "enter a valid choice" << std::endl;
                    break;
        }
        
        std::cout << "Press enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover input max or until finding a new line
        std::cin.get(); // Wait for Enter 
    }
}