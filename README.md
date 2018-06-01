# 3D-Magnetic-Sensor-2GO
<img src="https://github.com/Infineon/Assets/blob/master/Pictures/3D%20Magnetic%20Sensor%202Go.jpg">

Library of Infineon's [3D magnetic sensor 2GO evaluation board](https://www.infineon.com/cms/en/product/sensor/magnetic-position-sensor/3d-magnetic-sensor/TLV493D-A1B6+2+GO+KIT/productType.html?productType=5546d4624e24005f014e6775d0177011) for Arduino. 

## Summary
The 3D Magnetic Sensor 2GO is a budget-priced evaluation board equipped with the magnetic sensor [TLV493D-A1B6](https://www.infineon.com/cms/de/product/sensor/magnetic-position-sensor/3d-magnetic-sensor/TLV493D-A1B6/productType.html?productType=5546d462525dbac401529cebc74f07b7) for three dimensional measurement combined with an ARM® Cortex™-M0 CPU. The 3D Magnetic Sensor 2GO has a complete set of on-board devices, including an on-board debugger. Build your own application and gadget with the 3D Magnetic Sensor 2GO.

## Key Features and Benefits
* TLV493D-A1B6 (three dimensional magnetic sensor)
* XMC1100 (ARM® Cortex™-M0 based)
* On-board J-Link Lite Debugger (Realized with XMC4200 Microcontroller)
* Power over USB (Micro USB), ESD and reverse current protection
* [GUI](https://www.infineon.com/cms/en/product/sensor/magnetic-position-sensor/3d-magnetic-sensor/TLV493D-A1B6+2+GO+KIT/productType.html?productType=5546d4624e24005f014e6775d0177011#ispnTab12) for free download as well as integration in Arduino IDE by this repository

## Installation
### Integration of XMC in Arduino IDE
Please note that base of the Sensors 2GO is the XMC 2Go from Infineon. Therefore, please install (if not already done) also the [XMC-for-Arduino](https://github.com/Infineon/XMC-for-Arduino) implementation and choose afterwards **XMC2Go** from the **Tools**>**Board** menu in the Arduino IDE if working with this evaluation board.

### Integration of Library
Please download this repository from GitHub by clicking on the following field in the [releases](https://github.com/Infineon/3D-Magnetic-Sensor-2GO/releases) of this repository or directly [here](https://github.com/Infineon/3D-Magnetic-Sensor-2GO/releases/download/V1.0.0/IFX-3D-Magnetic-Sensor-2GO.zip):

![Download Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/DL_3DMag_Rel.png)

To install the 3D magnetic sensor 2GO library in the Arduino IDE, please go now to **Sketch** > **Include Library** > **Add .ZIP Library...** in the Arduino IDE and navigate to the downloaded .ZIP file of this repository. The library will be installed in your Arduino sketch folder in libraries and you can select as well as include this one to your project under **Sketch** > **Include Library** > **MagneticSensor3D**. 

![Install Library](https://raw.githubusercontent.com/infineon/assets/master/Pictures/Library_Install_ZIP.png)

## Usage
Please follow the example sketches in the /examples directory in this library to learn more about the usage of the library.

## Processing
This library supports the open-source software [Processing](https://processing.org/) for creating GUIs. It allows you to connect your evaluation board to a PC over serial communication and visualisation of the embedded system. Find out more on the Arduino homepage [here](http://playground.arduino.cc/Interfacing/Processing). The respective files are stored in the /processing folder of this repository. 

## Board Information, Datasheet and Additional Information
A PDF summarizing the features and layout of the 3D magnetic sensor 2GO board is stored on the Infineon homepage [here](https://www.infineon.com/dgdl/Infineon-3D-Magnetic-Sensor_EvalKit_UM-UM-v01_01-EN.pdf?fileId=5546d462525dbac40152ac4ca1d318c2).
The datasheet for the TLV493D-A1B6 can be found here [TLV493D-A1B6 Datasheet](https://www.infineon.com/dgdl/Infineon-TLV493D-A1B6-DS-v01_00-EN.pdf?fileId=5546d462525dbac40152a6b85c760e80) while respective application notes are located here [Application Notes](https://www.infineon.com/cms/de/product/sensor/magnetic-position-sensor/3d-magnetic-sensor/TLV493D-A1B6+2+GO+KIT/productType.html?productType=5546d4624e24005f014e6775d0177011#ispnTab4).

