#include <SPI.h>

#define  SPI_CMD_EULER_COORD 0x01
#define SPI_CMD_EULER_COORD_NUM_BYTES 6
#define SPI_CMD_SET_WRITE 0x02
#define SPI_CMD_SET_WRITE_NUM_BYTES 5
#define SPI_CMD_MOTOR_DEBUG 0x99
#define SPI_CMD_MOTOR_DEBUG_NUM_BYTES 8

#define DELAY 3

signed int euler[3];
signed int euler_app[3];

signed int motor[4];
signed int motor_app[4]  = {0,1,2,3};

void setup() {
  // put your setup code here, to run once:
  SPI.begin();
  SPI.setDataMode(SPI_MODE0);

  euler_app[0] = 5;
  euler_app[1] = 6;
  euler_app[2] = 7;
  delay(500);
  Serial1.begin(9600);
  
  //Serial1.println("Read Euler Coordinates from the regler! \n");
}

void loop() {
  // put your main code here, to run repeatedly:

  //read MSB and LSB from the three euler coordinates
 
  //{
  //if(Serial.available()) Serial.write(Serial.read());
  while(Serial1.read() != 'a');
//  read_and_send_Motorspeed();
//  //Serial.print("H: \t");
//  Serial1.print(motor[0], DEC);
//  Serial1.print("\t");
//  Serial1.print(motor[1], DEC);
//  Serial1.print("\t");
//  Serial1.print(motor[2], DEC);
//  Serial1.print("\t");
//  Serial1.print(motor[3], DEC);
//  Serial1.println();
  read_and_send_Euler();
  //Serial1.print("H: \t");
  Serial1.print(euler[0], DEC);
  Serial1.print("\t");
  Serial1.print(euler[1], DEC);
  Serial1.print("\t");
  Serial1.print(euler[2], DEC);
  Serial1.println();
  //}
}

void read_and_send_Motorspeed()
{

  SPI.transfer(SPI_CMD_MOTOR_DEBUG);
  delay(DELAY);
  motor[0]  = SPI.transfer(0xff & (motor_app[0] << 8)) << 8;
  delay(DELAY);
  motor[0] |= SPI.transfer(0xff & (motor_app[0]));
  delay(DELAY);
  motor[1]  = SPI.transfer(0xff & (motor_app[1] << 8)) << 8;
  delay(DELAY);
  motor[1] |= SPI.transfer(0xff & (motor_app[1]));
  delay(DELAY);
  motor[2]  = SPI.transfer(0xff & (motor_app[2] << 8)) << 8;
  delay(DELAY);
  motor[2] |= SPI.transfer(0xff & (motor_app[2]));
  delay(DELAY);
  motor[3]  = SPI.transfer(0xff & (motor_app[3] << 8)) << 8;
  delay(DELAY);
  motor[3] |= SPI.transfer(0xff & (motor_app[3]));
  delay(10);
}

void read_and_send_Euler()
{

  SPI.transfer(SPI_CMD_EULER_COORD);
  delay(DELAY);
  euler[0]  = SPI.transfer(0xff & (euler_app[0] << 8)) << 8;
  delay(DELAY);
  euler[0] |= SPI.transfer(0xff & (euler_app[0]));
  delay(DELAY);
  euler[1]  = SPI.transfer(0xff & (euler_app[1] << 8)) << 8;
  delay(DELAY);
  euler[1] |= SPI.transfer(0xff & (euler_app[1]));
  delay(DELAY);
  euler[2]  = SPI.transfer(0xff & (euler_app[2] << 8)) << 8;
  delay(DELAY);
  euler[2] |= SPI.transfer(0xff & (euler_app[2]));
  delay(10);
}
