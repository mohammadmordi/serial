 int pin = 2;    

void setup() {
  Serial.begin(115200); 
  pinMode(pin, OUTPUT);  
}

void loop() {
  if (Serial.available() > 0) {
    char i = Serial.read(); 

    if (i == '1') {
      digitalWrite(pin, HIGH); 
      Serial.println("led on.");
    } 
    else if (i == '0') {
      digitalWrite(pin, LOW); 
      Serial.println("led off.");
    } 
  }
}