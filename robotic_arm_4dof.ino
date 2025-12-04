/*
 * 4-DOF Robotic Arm Control
 * Author: Aryan Panwar
 * Project: Learning project for servo motor control
 * Year: 2024
 * 
 * Description: Simple manual control of 4-DOF robotic arm
 * Control via serial commands or buttons
 */

#include <Servo.h>

// Create servo objects
Servo baseServo;      // Pin 9
Servo shoulderServo;  // Pin 10
Servo elbowServo;     // Pin 11
Servo gripperServo;   // Pin 6

// Servo pin definitions
const int BASE_PIN = 9;
const int SHOULDER_PIN = 10;
const int ELBOW_PIN = 11;
const int GRIPPER_PIN = 6;

// Button pins (optional)
const int BASE_BUTTON = 2;
const int SHOULDER_BUTTON = 3;
const int ELBOW_BUTTON = 4;
const int GRIPPER_BUTTON = 5;

// Current servo positions
int basePos = 90;
int shoulderPos = 90;
int elbowPos = 90;
int gripperPos = 90;

// Movement step size
const int STEP = 10;

// Servo angle limits
const int MIN_ANGLE = 0;
const int MAX_ANGLE = 180;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  Serial.println("=================================");
  Serial.println("4-DOF Robotic Arm - Initialized");
  Serial.println("=================================");
  Serial.println();
  
  // Attach servos to pins
  baseServo.attach(BASE_PIN);
  shoulderServo.attach(SHOULDER_PIN);
  elbowServo.attach(ELBOW_PIN);
  gripperServo.attach(GRIPPER_PIN);
  
  // Initialize button pins (optional)
  pinMode(BASE_BUTTON, INPUT);
  pinMode(SHOULDER_BUTTON, INPUT);
  pinMode(ELBOW_BUTTON, INPUT);
  pinMode(GRIPPER_BUTTON, INPUT);
  
  // Move to home position
  moveToHome();
  
  // Print instructions
  printInstructions();
}

void loop() {
  // Check for serial commands
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    processCommand(command);
  }
  
  // Check button inputs (optional)
  checkButtons();
  
  delay(50); // Small delay for stability
}

void processCommand(String cmd) {
  cmd.toLowerCase();
  
  if (cmd.startsWith("b")) {
    // Base control: b90
    int angle = cmd.substring(1).toInt();
    moveBase(angle);
  }
  else if (cmd.startsWith("s")) {
    // Shoulder control: s45
    int angle = cmd.substring(1).toInt();
    moveShoulder(angle);
  }
  else if (cmd.startsWith("e")) {
    // Elbow control: e120
    int angle = cmd.substring(1).toInt();
    moveElbow(angle);
  }
  else if (cmd.startsWith("g")) {
    // Gripper control: g30
    int angle = cmd.substring(1).toInt();
    moveGripper(angle);
  }
  else if (cmd == "home") {
    // Return to home position
    moveToHome();
  }
  else if (cmd == "open") {
    // Open gripper fully
    moveGripper(180);
  }
  else if (cmd == "close") {
    // Close gripper
    moveGripper(30);
  }
  else if (cmd == "status") {
    // Print current positions
    printStatus();
  }
  else if (cmd == "help") {
    // Print instructions
    printInstructions();
  }
  else {
    Serial.println("Unknown command. Type 'help' for instructions.");
  }
}

void moveBase(int angle) {
  if (angle >= MIN_ANGLE && angle <= MAX_ANGLE) {
    basePos = angle;
    baseServo.write(basePos);
    Serial.print("Base moved to: ");
    Serial.println(basePos);
  } else {
    Serial.println("Error: Angle out of range (0-180)");
  }
}

void moveShoulder(int angle) {
  if (angle >= MIN_ANGLE && angle <= MAX_ANGLE) {
    shoulderPos = angle;
    shoulderServo.write(shoulderPos);
    Serial.print("Shoulder moved to: ");
    Serial.println(shoulderPos);
  } else {
    Serial.println("Error: Angle out of range (0-180)");
  }
}

void moveElbow(int angle) {
  if (angle >= MIN_ANGLE && angle <= MAX_ANGLE) {
    elbowPos = angle;
    elbowServo.write(elbowPos);
    Serial.print("Elbow moved to: ");
    Serial.println(elbowPos);
  } else {
    Serial.println("Error: Angle out of range (0-180)");
  }
}

void moveGripper(int angle) {
  if (angle >= MIN_ANGLE && angle <= MAX_ANGLE) {
    gripperPos = angle;
    gripperServo.write(gripperPos);
    Serial.print("Gripper moved to: ");
    Serial.println(gripperPos);
  } else {
    Serial.println("Error: Angle out of range (0-180)");
  }
}

void moveToHome() {
  Serial.println("Moving to home position...");
  
  basePos = 90;
  shoulderPos = 90;
  elbowPos = 90;
  gripperPos = 90;
  
  baseServo.write(basePos);
  delay(300);
  shoulderServo.write(shoulderPos);
  delay(300);
  elbowServo.write(elbowPos);
  delay(300);
  gripperServo.write(gripperPos);
  delay(300);
  
  Serial.println("Home position reached (all at 90°)");
}

void checkButtons() {
  // Base button - increment angle
  if (digitalRead(BASE_BUTTON) == HIGH) {
    basePos = constrain(basePos + STEP, MIN_ANGLE, MAX_ANGLE);
    baseServo.write(basePos);
    Serial.print("Base: ");
    Serial.println(basePos);
    delay(200); // Debounce delay
  }
  
  // Shoulder button - increment angle
  if (digitalRead(SHOULDER_BUTTON) == HIGH) {
    shoulderPos = constrain(shoulderPos + STEP, MIN_ANGLE, MAX_ANGLE);
    shoulderServo.write(shoulderPos);
    Serial.print("Shoulder: ");
    Serial.println(shoulderPos);
    delay(200);
  }
  
  // Elbow button - increment angle
  if (digitalRead(ELBOW_BUTTON) == HIGH) {
    elbowPos = constrain(elbowPos + STEP, MIN_ANGLE, MAX_ANGLE);
    elbowServo.write(elbowPos);
    Serial.print("Elbow: ");
    Serial.println(elbowPos);
    delay(200);
  }
  
  // Gripper button - toggle open/close
  if (digitalRead(GRIPPER_BUTTON) == HIGH) {
    if (gripperPos > 100) {
      gripperPos = 30; // Close
    } else {
      gripperPos = 180; // Open
    }
    gripperServo.write(gripperPos);
    Serial.print("Gripper: ");
    Serial.println(gripperPos);
    delay(200);
  }
}

void printStatus() {
  Serial.println("\n--- Current Position ---");
  Serial.print("Base: ");
  Serial.println(basePos);
  Serial.print("Shoulder: ");
  Serial.println(shoulderPos);
  Serial.print("Elbow: ");
  Serial.println(elbowPos);
  Serial.print("Gripper: ");
  Serial.println(gripperPos);
  Serial.println("------------------------\n");
}

void printInstructions() {
  Serial.println("\n=== Serial Commands ===");
  Serial.println("b<angle>  - Move Base (e.g., b90)");
  Serial.println("s<angle>  - Move Shoulder (e.g., s45)");
  Serial.println("e<angle>  - Move Elbow (e.g., e120)");
  Serial.println("g<angle>  - Move Gripper (e.g., g30)");
  Serial.println("home      - Return to home position (90°)");
  Serial.println("open      - Open gripper fully");
  Serial.println("close     - Close gripper");
  Serial.println("status    - Show current positions");
  Serial.println("help      - Show this menu");
  Serial.println("\nAngle range: 0-180 degrees");
  Serial.println("======================\n");
}
