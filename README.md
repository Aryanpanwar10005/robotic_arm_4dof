# Robotic Arm Project

## 📋 Overview
A simple 4-DOF robotic arm built as a learning project to understand basics of servo motor control and mechanical movement. This is a beginner-level project for picking up lightweight objects.

## ✨ Features
- 4 servo motors for basic movement
- Simple gripper to hold small items
- Manual control using buttons
- Arduino-based controller
- Basic safety limits

## 🛠️ Components Used
- Arduino Uno
- 4x Servo motors
- 5V Power supply
- Arm structure (basic frame)
- Gripper parts
- Jumper wires
- Breadboard
- Push buttons

## 📦 Software Requirements
- Arduino IDE
- Servo Library (already included in Arduino IDE)

## 🚀 Getting Started

### Installation

1. Clone this repository
```bash
git clone https://github.com/Aryanpanwar10005/robotic_arm_4dof.git
```

2. Open `robotic_arm_4dof.ino` file in Arduino IDE
3. Select your Arduino board from Tools menu
4. Select the correct COM port
5. Click Upload

### Hardware Setup
1. Connect servos to Arduino pins (base: pin 9, shoulder: pin 10, elbow: pin 11, gripper: pin 6)
2. Connect power supply (make sure it can handle all servos)
3. Wire up control buttons if using
4. Double-check all connections

### Usage
1. Turn on the power
2. Arm moves to starting position
3. Use buttons or serial commands to control
4. Test each joint slowly first
5. Try picking up light objects like small boxes or plastic items

## 📊 Basic Specs
- **Movement:** 4 joints with basic rotation
- **Power:** 5-6V
- **Objects:** Only very light items (under 100g)
- **Range:** About 20-30cm reach
- **Control:** Manual buttons or serial commands

## 🔧 How It Works
Simple servo control:
- **Base servo:** Rotates left and right
- **Shoulder servo:** Moves arm up and down
- **Elbow servo:** Bends the arm
- **Gripper servo:** Opens and closes to grab things

Arduino sends angle commands to each servo. That's it!

## 📚 What I Learned
- How to control servo motors with Arduino
- Basic mechanical assembly
- Simple programming for robotics
- Powering multiple motors
- Why weight and balance matter

## 🔮 Future Ideas
- Add better gripper design
- Make it wireless
- Add sensors
- Increase strength
- Learn inverse kinematics

## 🛡️ Safety Features
- Angle commands outside 0-180° are rejected
- The arm moves to a known home position (all joints at 90°) at power-up
- The home move steps one joint at a time, with a short pause between joints
- No software emergency stop yet: switch off the servo supply to stop the arm

## ⚠️ Limitations
- **Only for light objects** - cannot lift heavy things
- **Basic movements** - no fancy automated paths
- **Manual control only** - you have to tell it what to do
- **Not very precise** - it's a learning project
- **Small working area** - limited reach
- **Needs stable power** - won't work well with weak batteries

## 📝 Note
This is my first robotics project made for learning. It's simple and has limitations, but it helped me understand how robotic arms work. Not meant for any real applications, just for practicing and learning!

## 👤 Author
**Aryan Panwar**  
Electronics & Communication Engineering Student  
MIET Meerut (2022-2026)

📧 [aryanpanwar12311@gmail.com](mailto:aryanpanwar12311@gmail.com)  
💼 [LinkedIn](https://www.linkedin.com/in/aryan-panwar-b5322b269)  
🐙 [GitHub](https://github.com/Aryanpanwar10005)

## 📞 Contact
Questions or suggestions? Feel free to reach out via email or LinkedIn.

## 🌟 Show Your Support
If you found this project interesting or helpful:
- ⭐ Star this repository
- 🔄 Share with others interested in robotics
- 🐛 Report bugs or suggest improvements
- 🤝 Contribute to the project

---

**Project Year:** 2024  
**Tech Used:** Arduino, Servo Motors, Basic Mechanics  
**Status:** Learning Project ✅

---

*A simple project for learning robotics basics*
