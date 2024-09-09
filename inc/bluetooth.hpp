#pragma once
#include "command.hpp"
std::string get_bluetooth_status();
bool set_bluetooth(bool stat);
bool ConnectBluetoothDevice(std::string deviceAddress, bool pairing);