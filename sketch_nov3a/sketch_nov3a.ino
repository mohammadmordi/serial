 int pin = 2;    

void setup() {
  Serial.begin(115200); 
  pinMode(pin, OUTPUT);  
}

void loop() {
  if (Serial.available() > 0) {
      String command = Serial.readStringUntil('\n');
     command.trim();

    if (command == "on") {
      digitalWrite(pin, HIGH); 
      Serial.println("led on.");
    } 
    else if (command == "off") {
      digitalWrite(pin, LOW); 
      Serial.println("led off.");
    } 
  }
}