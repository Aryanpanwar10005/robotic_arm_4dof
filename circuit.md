# Circuit Connections

Simple wiring guide for the 4-DOF robotic arm project.

---

## 🔌 What You Need

- Arduino Uno
- 4 servo motors
- 5V power supply (must provide at least 2A)
- Jumper wires
- Breadboard
- 4 buttons (optional)

---

## ⚡ Power Connections

**IMPORTANT:** Don't power servos from Arduino's 5V pin! Use external power supply.

```
Power Supply (5V)
    |
    +--- Red wires of all 4 servos
    |
    +--- Arduino GND (connect grounds together!)
```

Simple rule: 
- All servo RED wires → External 5V power
- All servo BLACK wires → Ground
- Connect power supply ground to Arduino ground

---

## 🎯 Servo Wiring

Each servo has 3 wires:
- **RED** = Power (connect to external 5V)
- **BROWN/BLACK** = Ground
- **ORANGE/YELLOW** = Signal (connect to Arduino pin)

### Connect signal wires to Arduino:

| Servo | Arduino Pin | What it does |
|-------|-------------|--------------|
| Base | 9 | Rotates left/right |
| Shoulder | 10 | Moves up/down |
| Elbow | 11 | Bends the arm |
| Gripper | 6 | Opens/closes |

---

## 📐 Simple Diagram

```
        5V Power Supply
             |
        +----+----+
        |         |
       5V        GND
        |         |
    All Servo     |
    RED wires     |
                  |
    All Servo     |
    BLACK wires   +--- Arduino GND
        
    
    Servo Signal Wires:
    
    Base (Orange) -----> Arduino Pin 9
    Shoulder (Orange) -> Arduino Pin 10
    Elbow (Orange) ----> Arduino Pin 11
    Gripper (Orange) --> Arduino Pin 6
```

---

## 🎮 Button Connections (Optional)

If you want to use buttons:

```
Each button connects like this:

Arduino 5V --- Button --- Arduino Pin --- 10kΩ Resistor --- GND
```

Button pins:
- Button 1 → Pin 2 (controls base)
- Button 2 → Pin 3 (controls shoulder)
- Button 3 → Pin 4 (controls elbow)
- Button 4 → Pin 5 (controls gripper)

---

## 🔧 Step by Step

### Step 1: Connect Power
1. Plug external 5V power supply into breadboard
2. Connect all servo RED wires to breadboard + rail
3. Connect all servo BLACK wires to breadboard - rail
4. **Important:** Connect breadboard ground to Arduino GND pin

### Step 2: Connect Servos
1. Base servo orange wire → Arduino pin 9
2. Shoulder servo orange wire → Arduino pin 10
3. Elbow servo orange wire → Arduino pin 11
4. Gripper servo orange wire → Arduino pin 6

### Step 3: Power Arduino
- Connect Arduino to computer with USB cable
- This is for both power and programming

### Step 4: Check Everything
Before turning on:
- All servo red wires connected to 5V? ✓
- All servo black wires connected to ground? ✓
- Ground connected between power supply and Arduino? ✓
- Signal wires connected to right pins? ✓

---

## ⚠️ Important Rules

1. **Never** connect servos to Arduino 5V pin (will break Arduino!)
2. **Always** connect grounds together (power supply GND + Arduino GND)
3. **Use** a power supply that can give at least 2A
4. **Check** all wires before turning power on

---

## 🧪 Quick Test

After connecting everything:

1. Upload the code to Arduino
2. Open Serial Monitor (set to 9600)
3. Type `home` and press Enter
4. All servos should move to middle position
5. Try commands like `b90` or `s45` to test each servo

---

## 🐛 Problems?

**Servos not moving:**
- Check if external power supply is on
- Make sure grounds are connected
- Check signal wires are in correct pins

**Arduino keeps restarting:**
- You probably connected servos to Arduino 5V
- Use external power supply instead

**One servo doesn't work:**
- Check if that servo's signal wire is plugged in
- Try swapping it with another servo to test

---

## 📦 Wire Color Guide

Most servos use these colors:
- 🔴 Red = Power (5V)
- 🟤 Brown or Black = Ground
- 🟠 Orange or Yellow = Signal

Some servos might have different colors, but the position is always the same.

---

## 💡 Tips

- Keep wires neat and organized
- Label wires if you get confused
- Test one servo at a time if having problems
- Make sure power supply can handle all 4 servos
- Don't force servos by hand when powered on

---

**That's it! Simple connections for a learning project.**

---

*Need help? Check the main README or ask questions!*
