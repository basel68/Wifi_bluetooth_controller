# Wi-Fi and Bluetooth Control Program

This robust C++ application is designed for Linux systems, simplifying the management of Wi-Fi and Bluetooth connections. It interfaces seamlessly with `nmcli` for Wi-Fi functionalities and `bluetoothctl` for Bluetooth operations, providing a comprehensive suite of wireless device management tools.

## Features

### Wi-Fi Control
- **Display Wi-Fi Status**: Check the current state of Wi-Fi (on/off).
- **Toggle Wi-Fi**: Easily enable or disable Wi-Fi connectivity.
- **Network Management**:
  - **Connect to Saved Networks**: Connect quickly to previously configured Wi-Fi networks.
  - **Set Up New Wi-Fi Networks**: Add and connect to new networks by providing the SSID and password.

### Bluetooth Control
- **Display Bluetooth Status**: View whether Bluetooth is enabled or disabled.
- **Toggle Bluetooth**: Switch Bluetooth functionality on or off with ease.
- **Device Interaction**:
  - **Scan for Devices**: Detect and list nearby Bluetooth devices.
  - **Pair and Connect**: Start pairing and establish connections with Bluetooth devices.

## Getting Started

### Prerequisites
Ensure `nmcli` and `bluetoothctl` are installed on your Linux system, as the application relies on these utilities.

### Installation
1. Clone the repository:
   ```bash
   git clone https://github.com/basel68/Wifi_bluetooth_controller.git
2. Navigate to the dir
   ```bash
   cd Wifi_bluetooth_controller/src
3. Compile
   ```bash
   g++ -std=c++17 -o wifi-bluetooth-control *.cpp
4. Run
   ```bash
   ./wifi-bluetooth-control


