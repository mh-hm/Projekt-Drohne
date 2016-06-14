#include <SPI.h>

#define  SPI_CMD_EULER_COORD 0x01
#define  SPI_CMD_EULER_COORD_NUM_BYTES 7
#define  SPI_CMD_SET_WRITE 0x02
#define  SPI_CMD_SET_WRITE_NUM_BYTES 5

signed int euler[3];
signed int euler_app[3];
  
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
  read_and_send_Euler();
  Serial.print("H: \t");
  Serial.print(euler[0], DEC);
  Serial.print("R: \t");
  Serial.print(euler[1], DEC);
  Serial.print("P: \t");
  Serial.print(euler[2], DEC);
  Serial.println();

  delay(10);  
}

void read_and_send_Euler()
{

  SPI.transfer(SPI_CMD_EULER_COORD);
  delay(5);
  euler[0]  = SPI.transfer(0xff & (euler_app[0] << 8)) << 8;
  delay(5);
  euler[0] |= SPI.transfer(0xff & (euler_app[0]));
  delay(5);
  euler[1]  = SPI.transfer(0xff & (euler_app[1] << 8)) << 8;
  delay(5);
  euler[1] |= SPI.transfer(0xff & (euler_app[1]));
  delay(5);
  euler[2]  = SPI.transfer(0xff & (euler_app[2] << 8)) << 8;
  delay(5);
  euler[2] |= SPI.transfer(0xff & (euler_app[2]));
  delay(5);
}
