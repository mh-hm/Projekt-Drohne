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
  Serial.begin(9600);
  
  Serial.println("Read Euler Coordinates from the regler! \n");
}

void loop() {
  // put your main code here, to run repeatedly:

  //read MSB and LSB from the three euler coordinates
 
  //{
  //if(Serial.available()) Serial.write(Serial.read());
  while(Serial.read() != 'a');
  read_and_send_Motorspeed();
  //Serial.print("H: \t");
  Serial.print(motor[0], DEC);
  Serial.print("\t");
  Serial.print(motor[1], DEC);
  Serial.print("\t");
  Serial.print(motor[2], DEC);
  Serial.print("\t");
  Serial.print(motor[3], DEC);
  Serial.println();
  //read_and_send_Euler();
  //Serial.print("H: \t");
//  Serial.print(euler[0], DEC);
//  Serial.print("\t");
//  Serial.print(euler[1], DEC);
//  Serial.print("\t");
//  Serial.print(euler[2], DEC);
//  Serial.println();

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
