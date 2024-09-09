#pragma once
#include "command.hpp"
std::string get_Wifi_status();
std::string set_wifi(bool stat);
void save_wifi_networks();
void get_saved_network();
void get_available_network();
bool connect_to_wifi(const std::string &ssid);
void connect_to_wifi(const std::string &ssid,const std::string &password);






