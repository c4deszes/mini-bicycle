#include "line_protocol.h"
#include "line_api.h"

#include "rear_light.h"
#include "front_light.h"

void LINE_Transport_OnError(bool response, uint16_t request, line_transport_error error_type) {
  if (error_type == line_transport_error_timeout) {
    Serial.println("Timeout.");
  }
  else if (error_type == line_transport_error_header_invalid) {
    Serial.println("Header error.");
  }
  else if (error_type == line_transport_error_data_invalid) {
    Serial.println("Checksum error.");
  }
  else {
    Serial.println("Unknown error.");
  }
}

void LINE_Transport_WriteResponse(uint8_t channel, uint8_t size, uint8_t* payload, uint8_t checksum) {
  Serial1.write(size);
  for (int i=0;i<size;i++) {
    Serial1.write(payload[i]);
  }
  Serial1.write(checksum);
  Serial1.flush();
  Serial.println("Sent response.");
}

void setup() {
  Serial.begin(9600);
  //while(!Serial);

  Serial1.begin(19200);
  LINE_App_Init();

  RearLight_Init();
  FrontLight_Init();

  Serial.println("Initialized.");
}

uint32_t transport_timer = 0;

void loop() {
  while(Serial1.available() > 0) {
    uint8_t data = Serial1.read();
    // Serial.print("Received: ");
    // Serial.print(data, HEX);
    // Serial.println();
    LINE_Transport_Receive(0, data);
  }
  uint32_t currentTime = millis();
  uint32_t diff = currentTime - transport_timer;
  if (diff >= 1) {
    LINE_Transport_Update(0, diff);
    transport_timer = currentTime;
  }

  RearLight_Update();
  FrontLight_Update();
}