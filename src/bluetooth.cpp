#include "../inc/bluetooth.hpp"
std::string get_bluetooth_status(){
    std::string result = execCommand(commandList[BLUETOOTH_STAT]);
    if(result.find("Powered: yes") != std::string::npos)
    {
        return "Enabled";
    } 
    else if (result.find("Powered: no") != std::string::npos)
    {
        return "Disabled"; 
    }
    return "bluetooth not responding";
}

bool set_bluetooth(bool stat){
    stat==ON?execCommand(commandList[BLUETOOTH_ON]):execCommand(commandList[BLUETOOTH_OFF]);
    std::string res=get_bluetooth_status();
    if(stat){
        if(res=="enabled")
            return true;
        else
            return false;
    }
    else{
        if(res=="disabled")
            return true;
        else
            return false;
    }
}

bool ConnectBluetoothDevice(std::string deviceAddress, bool pairing){    
    std::string result;
    if (pairing)
    {
        result = execCommand((commandList[BLUETOOTH_PAIR] + " " +deviceAddress).c_str());
        if (result.find("Pairing successful") != std::string::npos)
        return true;
    }else{
        result = execCommand((commandList[BLUETOOTH_CONNECT] + " " + deviceAddress).c_str());
        if (result.find("Connection successful") != std::string::npos)
        {
            return true;
        }
    }
    return false;
}