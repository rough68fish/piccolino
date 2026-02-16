#include "Arduino.h"
#include <SoftwareSerial.h>
#include <Piccolino_RAM.h>

#ifndef _PICCOLINO_WIFI_H
#define _PICCOLINO_WIFI_H

#define STATION 0
#define AP 1

#define ADDR_SERIALBUFF	0x7400 // 2K of buffer since video buffer stars at 0x7c00

class Piccolino_WIFI {
public:

  Piccolino_WIFI();
  ~Piccolino_WIFI();
  void begin(); 
  void enable();
  void disable();
  void startServer();
  char Connect(char *SSID, char *PWD);
  void setIP(char *IP, char *MASK, char *GW);
  void load(char *fname);
  void getIP();
  void getResponse();
  void disconnect();
  
  virtual size_t write(uint8_t byte);
  virtual int read();
  virtual int available();
  virtual void flush();
  
private:
	void _flush();
  void _wait(int len);
  byte local_buff[17];
};

#endif