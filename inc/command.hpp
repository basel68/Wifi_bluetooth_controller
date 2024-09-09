#pragma once
#include <iostream>
#include <string>
#include <unordered_map>
#include <cstdio>   
#include <cctype>
#include <memory>   
#include <array>
#include <vector>
#include <fstream>

//conditions
constexpr uint8_t OFF=0;
constexpr uint8_t ON=1;

//commands
constexpr uint8_t WIFI_STAT                =   0;
constexpr uint8_t WIFI_ON                  =   1;
constexpr uint8_t WIFI_OFF                 =   2;
constexpr uint8_t AVAILABLE_WIFI           =   3;
constexpr uint8_t SAVED_WIFI               =   4;
constexpr uint8_t WIFI_CONNECT_SAVED       =   5;
constexpr uint8_t WIFI_CONNECT_NEW         =   6;
constexpr uint8_t BLUETOOTH_STAT           =   7;
constexpr uint8_t BLUETOOTH_ON             =   8;
constexpr uint8_t BLUETOOTH_OFF            =   9;
constexpr uint8_t BLUETOOTH_PAIR           =   10;
constexpr uint8_t BLUETOOTH_CONNECT        =   11;

extern std::unordered_map<uint8_t,std::string> commandList;
std::string execCommand(std::string Command);
