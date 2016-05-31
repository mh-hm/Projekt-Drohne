#include <SPI.h>

signed int euler[3];
  
void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);

  Serial.begin(9600);
  Serial.println("Read Euler Coordinates from the regler! \n");
}

void loop() {
  // put your main code here, to run repeatedly:

  //read MSB and LSB from the three euler coordinates
  readEuler(euler);
  Serial.print("H: \t");
  Serial.print(euler[0], DEC);
  //Serial.print("R: \t");
//  Serial.print(euler[1], DEC);
 // Serial.print("P: \t");
 // Serial.print(euler[2], DEC);
  Serial.println();

  delay(10);  
}

void readEuler(signed int *euler)
{
  signed int euler_h = 0;   // result to return
  signed int euler_r = 0;
  signed int euler_p = 0;


  euler_h = (SPI.transfer(0x40));//|(SPI.transfer(0x01)<<8);
//  euler_r = (SPI.transfer(0x05));//|(SPI.transfer(0x03)<<8);
 // euler_p = (SPI.transfer(0x10));//|(SPI.transfer(0x05)<<8);

  euler[0] = euler_h;
 // euler[1] = euler_r;
 // euler[2] = euler_p;
}
