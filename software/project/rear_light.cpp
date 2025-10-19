#include <Adafruit_NeoPixel.h>
#include "config.h"
#include "line_api.h"

uint32_t RearLight_BlinkTimer = 0;
bool RearLight_BlinkState = false;
Adafruit_NeoPixel RearLight_Pixels(1, REAR_LIGHT_PIN, NEO_GRB + NEO_KHZ800);

void RearLight_Init() {
    RearLight_Pixels.begin();
}

void RearLight_Update() {
    uint8_t targetBrightness = map(LINE_Request_LightSynchronization_data.fields.TargetBrightness, 0, 100, 0, REAR_LIGHT_MAX_BRIGHTNESS);

    if (LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Off) {
        targetBrightness = 0;
    }
    else if(LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Adaptive) {
        // nothing
    }
    else if(LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Standard) {
        targetBrightness = targetBrightness > REAR_LIGHT_MIN_BRIGHTNESS ? targetBrightness : REAR_LIGHT_MIN_BRIGHTNESS;
    }
    else if(LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Emergency) {
        
    }

    if (LINE_Request_RearLightSetting_data.fields.Behavior == LINE_ENCODER_LightBehaviorEncoder_Blink) {
        if (millis() - RearLight_BlinkTimer > REAR_BLINK_RATE) {
            RearLight_BlinkTimer = millis();
            RearLight_BlinkState = !RearLight_BlinkState;
            if (RearLight_BlinkState) {
                RearLight_Pixels.setPixelColor(0, RearLight_Pixels.Color(targetBrightness, 0, 0));
            }
            else {
                RearLight_Pixels.setPixelColor(0, RearLight_Pixels.Color(REAR_LIGHT_STROBE_LOW, 0, 0));
            }
        }
    }
    else {
        RearLight_Pixels.setPixelColor(0, RearLight_Pixels.Color(targetBrightness, 0, 0));
    }
    RearLight_Pixels.show();
}