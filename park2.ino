#include "Wire.h"
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Servo.h"

MPU6050 mpu;
int16_t ax, ay, az;
int16_t gx, gy, gz;
Servo servo1;
Servo servo2;


int va11;
int va12;

int r;
int preVa11;
int preVa12;



void setup()
{
  Wire.begin();
  Serial.begin(115200);
  Serial.println("Initialize MPU");
  mpu.initialize();
  Serial.println(mpu.testConnection() ? "Connected" : "Connection failed");
  servo1.attach(5);
  servo2.attach(6);
  servo1.write(50);
}


void loop()
{
  mpu.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
  va11 = map(ax, -17000, 17000, 0, 179);
  if (va11 != preVa11)
  {
    servo1.write(va11);
    preVa11 = va11;
  }
  va12 = map(ay, -17000, 17000, 0, 179);
  if (va12 != preVa12);
  { 
    servo2.write(va12);
    preVa12 = va12;
  }
  Serial.print(va11);
  Serial.print(",");
  Serial.println(va12);
  delay(100);
}