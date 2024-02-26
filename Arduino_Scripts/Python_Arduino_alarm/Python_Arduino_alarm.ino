// Define variables for LED pins and buzzer pin
int led_red1 = 12;  // Pin for red LED 1
int led_red2 = 11;  // Pin for red LED 2
int led_red3 = 10;  // Pin for red LED 3
int led_red4 = 9;   // Pin for red LED 4
int buzzer = 2;     // Pin for the buzzer
int sleep = 1000;   // Delay time in milliseconds

void setup() {
  // Set LED and buzzer pins as outputs
  pinMode(led_red1, OUTPUT);
  pinMode(led_red2, OUTPUT);
  pinMode(led_red3, OUTPUT);
  pinMode(led_red4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Initialize serial communication
  Serial.begin(9600);
}

void loop() {
  // Check if data is available on serial port
  if (Serial.available() > 0) {
    // Read the incoming byte
    char signal = Serial.read();
    
    // Check if the signal is '1'
    if (signal == '1') {
      // If signal is received, execute the main functionality
      // Turn on red LED 1 and LED 4, and turn off LED 2 and LED 3
      digitalWrite(led_red1, HIGH);
      digitalWrite(led_red2, LOW);
      digitalWrite(led_red3, LOW);
      digitalWrite(led_red4, HIGH);

      // Turn on a buzzer
      digitalWrite(buzzer, HIGH);
      
      // Play tone at a frequency of 10 Hz
      tone(buzzer, 500);

      // Delay for a specified time
      delay(sleep);

      // Turn off red LED 1 and LED 4, and turn on LED 2 and LED 3
      digitalWrite(led_red1, LOW);
      digitalWrite(led_red2, HIGH); 
      digitalWrite(led_red3, HIGH);
      digitalWrite(led_red4, LOW);

      // Stop tone
      noTone(buzzer);
     

      // Turn off the buzzer
      digitalWrite(buzzer, LOW);

      // Delay for a specified time
      delay(sleep);
    } else if (signal == '0') {
      // If signal is '0', turn off all lights and the buzzer
      digitalWrite(led_red1, LOW);
      digitalWrite(led_red2, LOW);
      digitalWrite(led_red3, LOW);
      digitalWrite(led_red4, LOW);
      digitalWrite(buzzer, LOW);
    }
  }
}
