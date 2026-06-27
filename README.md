IR Remote Controlled Arduino Car with LED Matrix

An open-source Arduino Uno robotic car project controlled wirelessly via an Infrared (IR) remote. The car features a modular architecture with an integrated 8x16 LED matrix display that provides real-time visual feedback based on the vehicle's movement.

---

Features:

IR Remote Steering: Control the car's direction (forward, left, right, and stop) wirelessly using a standard infrared remote control.
Expressive LED Matrix Feedback (8x16): The car dynamically updates an I2C-driven LED matrix to show its status:
Displays a friendly smiley face when moving straight or idling.
Displays animated directional arrows indicating the exact turning path when steering left or right.
Hardware Expansion Support: The codebase includes integrated support for an HC-SR04 ultrasonic distance sensor and a micro servo for obstacle avoidance tracking.

---

Hardware Pinout Configuration:

HCtrig_pin = YOUR_TRIG_PIN
HCecho_pin = YOUR_ECHO_PIN 
IRrecv_Pin = YOUR_IR_SENSOR_PIN
#define SCL_Pin    YOUR_DISPLAY_CLOCK_PIN   
#define SDA_Pin    YOUR_DISPLAY_DATA_PIN  
car_motors motors(, , , );  //set pins of your motors

---

Installation & Setup:

1. Clone the Repository
Open your terminal or command prompt and run:

```
git clone [https://github.com/deniska-design/car_controlling.git](https://github.com/deniska-design/car_controlling.git)
```
```
cd car_controlling
```

2. Open and Configure the Project

Launch the Arduino IDE.

Open the main sketch file: sketch_may19a.ino.

Make sure you have installed the required libraries for your IR remote (e.g., IRremote.h) in the IDE Library Manager.

3. Upload the Code
Connect your Arduino Uno to your PC using a USB cable.

In the top menu, navigate to
```
Tools -> Board -> Arduino AVR Boards -> Arduino Uno.
```

Select the correct serial port under 
```
Tools -> Port.
```

Click the Upload button.

---

Execution:

https://github.com/user-attachments/assets/9c3cabdb-6468-4d2a-9213-bb52d6fbe9cb

---

License:
This project is open-source. Anyone is completely free to download, modify, use, and distribute this software for personal or educational purposes.
