#include "../inc/command.hpp"


std::unordered_map<uint8_t,std::string> commandList{
    {WIFI_STAT, "nmcli radio wifi"},
    {WIFI_ON, "nmcli radio wifi on"},
    {WIFI_OFF, "nmcli radio wifi off"},
    {AVAILABLE_WIFI, "nmcli device wifi list"},
    {SAVED_WIFI, "nmcli connection show"},
    {WIFI_CONNECT_SAVED,"nmcli connection up"},
    {WIFI_CONNECT_NEW, "nmcli device wifi connect"},
    {BLUETOOTH_STAT, "bluetoothctl show"},
    {BLUETOOTH_ON, "bluetoothctl power on"},
    {BLUETOOTH_OFF, "bluetoothctl power off"},
    {BLUETOOTH_PAIR, "bluetoothctl pair"},
    {BLUETOOTH_CONNECT, "bluetoothctl connect"}
};

std::string execCommand(std::string Command){
    std::array<char,128> buffer;
    std::string result;
    auto deleter = [](FILE* fp) { pclose(fp); };
    std::unique_ptr<FILE,decltype(deleter)> output_ptr(popen(Command.c_str(),"r"),deleter);
    if (!output_ptr) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(),buffer.size(),output_ptr.get())!= nullptr)
    {
       
        result+=buffer.data();
    }
    return result;
    

}
