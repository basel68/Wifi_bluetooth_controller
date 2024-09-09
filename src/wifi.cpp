#include "../inc/wifi.hpp"
std::unordered_map<std::string, std::string> networkCrendentials;
static bool CheckIFNetworkExist(const std::string &ssid);
static std::vector<std::string> extract_files();
static std::unordered_map<std::string, std::string> get_net_plans();
std::string get_Wifi_status(){
    return "wifi status:"+ execCommand(commandList[WIFI_STAT]);
}

std::string set_wifi(bool stat){
    return stat==ON?execCommand(commandList[WIFI_ON]):execCommand(commandList[WIFI_OFF]);
}
bool connect_to_wifi(const std::string &ssid)
{
    if(CheckIFNetworkExist(ssid))
    {
        execCommand((commandList[WIFI_CONNECT_SAVED] + " '" + ssid + "'"));
        return true;
    }
    return false;
}
void connect_to_wifi(const std::string &ssid,const std::string &password)
{
    
    execCommand((commandList[WIFI_CONNECT_NEW] + " '" + ssid + "'" + " password '" + password + "'"));
    
}

static std::unordered_map<std::string, std::string> get_net_plans() {
    std::vector<std::string> files = extract_files();
    
   
    for (const auto& file : files) {
        std::string command = "sudo cat /etc/netplan/" + file;
        std::string returned = execCommand(command);

        size_t pos = 0;
        pos = returned.rfind("name: ");
        size_t start = returned.find("\"", pos) + 1;
        size_t end = returned.find("\"", start);
        std::string ssid = returned.substr(start, end - start);

        pos = returned.find("password: ");
        if (pos != std::string::npos) {
            start = returned.find("\"", pos) + 1;
            end = returned.find("\"", start);
            std::string password = returned.substr(start, end - start);
            networkCrendentials[ssid] = password;
        }
    }
    return networkCrendentials;
}
void save_wifi_networks(){
    get_net_plans();
}
void get_saved_network(){
    std::cout << execCommand((commandList[SAVED_WIFI] + "| grep wifi"));
}

void get_available_network(){
    std::cout << execCommand(commandList[AVAILABLE_WIFI]);
}
static std::vector<std::string> extract_files(){
    std::string result=execCommand("ls /etc/netplan");
    char delimiter='\n';
    size_t start=0;
    size_t end=result.find(delimiter);
   std::vector<std::string> files;
    while(end!=std::string::npos){
        files.emplace_back(result.substr(start,end-start));
        start=end+1;
        end=result.find(delimiter,start);
    }
    files.emplace_back(result.substr(start));
    return files;
}


static bool CheckIFNetworkExist(const std::string &ssid){

    std::string saved_Wifi=execCommand((commandList[WIFI_CONNECT_SAVED]+" "+"| grep wifi"));
    if(saved_Wifi.find(ssid)!=std::string::npos){
        return true; 
    }
    return false;
}




