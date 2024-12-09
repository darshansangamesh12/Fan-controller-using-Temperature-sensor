
# Temperature-Controlled Fan System 🌡️ 

This project is a **Temperature-Controlled Fan System** designed to automatically adjust fan speed based on ambient temperature. It optimizes energy usage and enhances user convenience by dynamically controlling fan speed in real-time.  

## Features  
- **Automatic Fan Speed Control**:  
  - Fan speed increases with higher ambient temperature.  
  - Provides energy efficiency by running the fan only when needed.  
- **Real-Time Temperature Display**:  
  - Displays temperature readings on a **16x2 LCD display**.  

## Components Used  
1. **LM35 Temperature Sensor**  
2. **Arduino Nano**  
3. **ESP32 Microcontroller**  
4. **12V DC Fan**  
5. **16x2 LCD Display** with I2C Module  
6. **Power Supply**  
7. **Resistors and Connecting Wires**  

## Working Principle  
1. The **LM35 temperature sensor** measures the ambient temperature and outputs an analog voltage.  
2. The **Arduino Nano** processes this data to calculate the temperature.  
3. Based on the temperature:  
   - Fan speed is adjusted using a **PWM signal**.  
   - The temperature is displayed on the LCD screen.  
4. The system ensures optimal energy usage and user comfort by adjusting the fan's operation.  

## Code  
The Arduino code for this project is available in the **`code/`** directory of this repository.  

### Steps to Run the Code  
1. Assemble the circuit as per the diagram.  
2. Connect the system to a power source.  
3. Upload the Arduino code to the **Arduino Nano** using the Arduino IDE.  
4. Observe the fan's behavior and temperature readings on the LCD.  

## Applications  
- Home and office environments for energy-efficient cooling.  
- Temperature-sensitive areas like server rooms or laboratories.  

## Future Enhancements  
- Add an IoT feature for remote monitoring and control via a mobile app.  
- Replace the LM35 sensor with a digital sensor for higher accuracy.  
- Implement a user interface to manually override fan speed.  
