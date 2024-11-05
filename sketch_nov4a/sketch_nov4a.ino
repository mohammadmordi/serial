#include "BluetoothSerial.h"
#define led 2
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif
BluetoothSerial SerialBT;
char data_;
void setup() {
Serial.begin(115200);
pinMode(led,OUTPUT);
SerialBT.begin("ESP32"); //Bluetooth device name
Serial.println("The device started, now you can pair it with bluetooth!");
}
void loop()
{
if (SerialBT.available())
{
data_ = SerialBT.read();
Serial.println(data_);
if (data_ == 'H')
{
digitalWrite(led, HIGH);
Serial.println("LED HIGH");
}
else if (data_ == 'L')
{
digitalWrite(led, LOW);
Serial.println("LED OFF");
}
}
}