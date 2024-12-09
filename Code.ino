{\rtf1\ansi\ansicpg1252\cocoartf2820
\cocoatextscaling0\cocoaplatform0{\fonttbl\f0\fswiss\fcharset0 Helvetica;}
{\colortbl;\red255\green255\blue255;}
{\*\expandedcolortbl;;}
\paperw11900\paperh16840\margl1440\margr1440\vieww11520\viewh8400\viewkind0
\pard\tx566\tx1133\tx1700\tx2267\tx2834\tx3401\tx3968\tx4535\tx5102\tx5669\tx6236\tx6803\pardirnatural\partightenfactor0

\f0\fs24 \cf0 // Include necessary libraries for I2C communication and LCD\
#include <Wire.h>\
#include <LiquidCrystal_I2C.h>\
// Define pin connections and threshold values\
#define LM35_PIN 39 // Pin connected to LM35 sensor\
#define PWM_PIN 5 // Pin connected to the PWM fan control\
#define FAN_ON_THRESHOLD 25\
// Initialize the LCD with I2C address, columns, and rows\
LiquidCrystal_I2C lcd(0x27, 16, 2);\
// Custom character for the degree symbol\
byte degree[8] = \{\
0b00011,\
0b00011,\
0b00000,\
0b00000,\
0b00000,\
0b00000,\
0b00000,\
0b00000\
\};\
// Setup function - runs once at the beginning\
void setup() \{\
// Start serial communication with a baud rate of 9600\
Serial.begin(9600);\
delay(1000); // Let the serial console settle\
// Initialize and configure the LCD\
lcd.init();\
lcd.backlight();\
lcd.createChar(1, degree); // Load the degree symbol\
lcd.clear();\
lcd.print(" Fan Speed ");\
lcd.setCursor(0, 1);\
lcd.print(" Controlling ");\
delay(2000);\
// Setup the PWM pin for fan control and start with the fan off\
pinMode(PWM_PIN, OUTPUT);\
analogWrite(PWM_PIN, 0);\
lcd.clear();\
lcd.print("Using LM35 Sensor");\
lcd.setCursor(0, 1);\
lcd.print("The IoT Projects");\
delay(2000);\
lcd.clear();\
\}\
// Loop function - runs repeatedly\
void loop() \{\
delay(2000); // Wait a few seconds between measurements\
// Read voltage from LM35 sensor\
int sensorValue = analogRead(LM35_PIN);\
// Convert the analog value to temperature (in Celsius)\
float temperature = ((sensorValue * 5.0) / 1024.0 * 100.0) / 10;\
// Print temperature to Serial monitor\
Serial.print("Temperature: ");\
Serial.print(temperature);\
Serial.println(" *C");\
// Update LCD with real-time temperature\
lcd.clear();lcd.setCursor(0, 0);\
lcd.print("Temp: ");\
lcd.print(temperature);\
lcd.print(" *C");\
lcd.setCursor(0, 1);\
// Control fan speed based on temperature\
if (temperature > FAN_ON_THRESHOLD) \{\
analogWrite(PWM_PIN, 255); // Turn on fan at maximum speed\
lcd.print("Fan ON ");\
\} else \{\
analogWrite(PWM_PIN, 0); // Turn off the fan\
lcd.print("Fan OFF ");\
\}\
delay(3000);\
\}}