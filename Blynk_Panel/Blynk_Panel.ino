#include <SoftwareSerial.h>          
SoftwareSerial PZEMSerial; 

#define BLYNK_TEMPLATE_ID "TMPLayFMMsld"
#define BLYNK_DEVICE_NAME "Flaxibel Axis Panel Surya"
#define BLYNK_AUTH_TOKEN "ZXnkN22UwU67LX-TDdYDNKCN0IDxIqOw"

#include <ESP8266WiFi.h>                        
#include <BlynkSimpleEsp8266.h>                       
char auth[] = BLYNK_AUTH_TOKEN;    
//char ssid[] = "AIRLANGGA-HOTSPOT";  
//char pass[] = "@irlangg@";                           
char ssid[] = "Playmedia";  
char pass[] = "fahmiayu";  

#include <ModbusMaster.h>
#define MAX485_DE  16 
#define MAX485_RE  5 
      
static uint8_t pzemSlaveAddr = 0x01;       
static uint16_t NewshuntAddr = 0x0003;  
ModbusMaster node;       
        
float PZEMVoltage =0; 
float PZEMCurrent =0; 
float PZEMPower =0; 
float PZEMEnergy=0;
 
unsigned long startMillisPZEM; 
unsigned long currentMillisPZEM;
const unsigned long periodPZEM = 1000;    

unsigned long startMillisReadData;  
unsigned long currentMillisReadData;
const unsigned long periodReadData = 1000;   
int ResetEnergy = 0;   
int a = 1;
unsigned long startMillis1;

#include <TimeLib.h>
#include <WidgetRTC.h> 
BlynkTimer timer;  
WidgetRTC rtc; 
   
unsigned long startMillis; 
unsigned long currentMillis;  
const unsigned long period = 1000; 

BLYNK_CONNECTED(){rtc.begin();}

void setup() {
  startMillis1 = millis();
        
  Serial.begin(9600); 
  PZEMSerial.begin(9600,SWSERIAL_8N2,4,0);    
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

  startMillisPZEM = millis();
  pinMode(MAX485_RE, OUTPUT); 
  pinMode(MAX485_DE, OUTPUT);  
  digitalWrite(MAX485_RE, 0); 
  digitalWrite(MAX485_DE, 0);  

  node.preTransmission(preTransmission);
  node.postTransmission(postTransmission);
  node.begin(pzemSlaveAddr,PZEMSerial); 
  delay(1000);         

  setSyncInterval(1);  
  while (Blynk.connect() == false ) {}  
  setSyncInterval(10*60);

  startMillis = millis();
  startMillisReadData = millis(); 
  
}

void loop() {
  Blynk.run();
  timer.run();
  
  if ((millis()- startMillis1 >= 10000) && (a ==1)){
  setShunt(pzemSlaveAddr); 
  changeAddress(0XF8, pzemSlaveAddr);  
  a = 0;
  }  
    
  currentMillisPZEM = millis(); 
        
  if (currentMillisPZEM - startMillisPZEM >= periodPZEM){    
    uint8_t result;                
    result = node.readInputRegisters(0x0000, 6); 
    if (result == node.ku8MBSuccess) {
      uint32_t tempdouble = 0x00000000; 
      PZEMVoltage = node.getResponseBuffer(0x0000) / 100.0;                     
      PZEMCurrent = node.getResponseBuffer(0x0001) / 100.0;                     
      tempdouble =  (node.getResponseBuffer(0x0003) << 16) + node.getResponseBuffer(0x0002);
      PZEMPower = tempdouble / 10.0;                             
      tempdouble =  (node.getResponseBuffer(0x0005) << 16) + node.getResponseBuffer(0x0004);
      PZEMEnergy = tempdouble;                   
      if (pzemSlaveAddr==2){}
      } 
    else{}
    startMillisPZEM = currentMillisPZEM ;  
  }

  currentMillisReadData = millis();  
  if (currentMillisReadData - startMillisReadData >= periodReadData){
    Serial.print("Vdc : "); Serial.print(PZEMVoltage); Serial.println(" V ");
    Serial.print("Idc : "); Serial.print(PZEMCurrent); Serial.println(" A ");
    Serial.print("Power : "); Serial.print(PZEMPower); Serial.println(" W ");
    Serial.print("Energy : "); Serial.print(PZEMEnergy); Serial.println(" Wh ");
    Blynk.virtualWrite(V1,PZEMVoltage);
    Blynk.virtualWrite(V2,PZEMCurrent);
    Blynk.virtualWrite(V3,PZEMPower);
    Blynk.virtualWrite(V4,PZEMEnergy);
    
    startMillisReadData = millis();
    }

  currentMillis = millis();   
  if(currentMillis - startMillis > period)  {
    String currentTime = String(hour()) + ":" + minute() + ":" + second(); 
    String currentDate = String(day()) + " " + month() + " " + year(); 
    Serial.print("Current time: ");  
    Serial.print(currentTime);
    Serial.print(" ");
    Serial.print(currentDate);
    Serial.println();

//    Blynk.virtualWrite(V1, currentTime);
//    Blynk.virtualWrite(V2, currentDate); 
                                                                              
    startMillis = millis();  
    }

}


void preTransmission() {
  if(millis() - startMillis1 > 5000){
    digitalWrite(MAX485_RE, 1);                                                                     
    digitalWrite(MAX485_DE, 1);                                                                     
    delay(1);                                                                                       
    }
}

void postTransmission(){
  if(millis() - startMillis1 > 5000) {                                                               
    delay(3);                                                                                      
    digitalWrite(MAX485_RE, 0);                                                                     
    digitalWrite(MAX485_DE, 0);                                                                     
    }
}

void setShunt(uint8_t slaveAddr){ 
  static uint8_t SlaveParameter = 0x06;                                                           
  static uint16_t registerAddress = 0x0003;                                                       
          
  uint16_t u16CRC = 0xFFFF;                                                                        
  u16CRC = crc16_update(u16CRC, slaveAddr);                                                        
  u16CRC = crc16_update(u16CRC, SlaveParameter);
  u16CRC = crc16_update(u16CRC, highByte(registerAddress));
  u16CRC = crc16_update(u16CRC, lowByte(registerAddress));
  u16CRC = crc16_update(u16CRC, highByte(NewshuntAddr));
  u16CRC = crc16_update(u16CRC, lowByte(NewshuntAddr));
        
  preTransmission();                                                                              
  PZEMSerial.write(slaveAddr);                                                                      
  PZEMSerial.write(SlaveParameter);
  PZEMSerial.write(highByte(registerAddress));
  PZEMSerial.write(lowByte(registerAddress));
  PZEMSerial.write(highByte(NewshuntAddr));
  PZEMSerial.write(lowByte(NewshuntAddr));
  PZEMSerial.write(lowByte(u16CRC));
  PZEMSerial.write(highByte(u16CRC));
  delay(10);
  postTransmission();                                                                         
  delay(100);
}

BLYNK_WRITE(V4)  {                                            
  if(param.asInt()==1){ 
    uint16_t u16CRC = 0xFFFF;                         
    static uint8_t resetCommand = 0x42;              
    uint8_t slaveAddr = pzemSlaveAddr;                 
    u16CRC = crc16_update(u16CRC, slaveAddr);
    u16CRC = crc16_update(u16CRC, resetCommand);
    preTransmission();                                        
    PZEMSerial.write(slaveAddr);                    
    PZEMSerial.write(resetCommand);                   
    PZEMSerial.write(lowByte(u16CRC));               
    PZEMSerial.write(highByte(u16CRC));               
    delay(10);
    postTransmission();                               
    delay(100);
    }
}

void changeAddress(uint8_t OldslaveAddr, uint8_t NewslaveAddr)    {                                     
  static uint8_t SlaveParameter = 0x06;                                                           
  static uint16_t registerAddress = 0x0002;                                                     
  uint16_t u16CRC = 0xFFFF;                                                                       
  u16CRC = crc16_update(u16CRC, OldslaveAddr);                                                    
  u16CRC = crc16_update(u16CRC, SlaveParameter);
  u16CRC = crc16_update(u16CRC, highByte(registerAddress));
  u16CRC = crc16_update(u16CRC, lowByte(registerAddress));
  u16CRC = crc16_update(u16CRC, highByte(NewslaveAddr));
  u16CRC = crc16_update(u16CRC, lowByte(NewslaveAddr));
  preTransmission();                                                                               
  PZEMSerial.write(OldslaveAddr);                                                                  
  PZEMSerial.write(SlaveParameter);
  PZEMSerial.write(highByte(registerAddress));
  PZEMSerial.write(lowByte(registerAddress));
  PZEMSerial.write(highByte(NewslaveAddr));
  PZEMSerial.write(lowByte(NewslaveAddr));
  PZEMSerial.write(lowByte(u16CRC));
  PZEMSerial.write(highByte(u16CRC));
  delay(10);
  postTransmission();                                                                            
  delay(100);
}
