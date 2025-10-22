# ESP32 Provisioning: One-Click-Config <a href="https://www.ohioiot.com"><img src="https://www.ohioiot.com/images/logo.jpg" width="40" ></a>


## Overview
This code serves is an output from the YouTube video [ESP32 Provisioning - One-Click Config](https://youtu.be/ggkNcxTs2Pc).  👉 Subscribe to the [OhioIoT YouTube Channel](https://www.youtube.com/@OhioIoT?sub_confirmation=1) for more on All Things IoT: hardware, firmware, connectivity, cloud computing, and dev toolkit.



## Getting Started
```
git clone https://github.com/OhioIoT-ESP32-Provisioning-Examples/One-Click-Config.git
```

### Getting Started - PlatformIO
- compile and run

### Getting Started - Arduino IDE 
- copy ***/src/main.cpp*** into a new sketch ***one-click/one-click.ino*** (or whatever name you choose)
- copy all of the folders inside of ***lib/*** into the ***/libraries*** folder that holds all of your Arduino IDE libraries
- compile and run

### Run the One-Click Provisioner
- add the right SSID and password values to your .env_template file
- rename .env_template -> .env
- create a shortcut to call the bash script
- click on the shortcut



## About
*OhioIoT is an IoT platform designed for small-scale IoT projects (https://www.ohioiot.com).*


## Updates

**10/18/25** - WiFi.begin() will put the WiFi in WIFI_STA mode automatically if it comes from WIFI_OFF.  However, if the device is coming from WIFI_AP mode, WiFi.begin() will apparently put it in WIFI_AP_STA mode, and leave the DEVICE_PROVISIONING SSID active.  So, best to explicitly call WiFi.mode(WIFI_STA) before WiFi.begin() in _src/main.cpp_.  
