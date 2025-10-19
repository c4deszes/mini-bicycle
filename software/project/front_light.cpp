#include <Adafruit_NeoPixel.h>
#include <ButtonDebounce.h>
#include "config.h"
#include "line_api.h"

uint32_t FrontLight_BlinkTimer = 0;
bool FrontLight_BlinkState = false;
Adafruit_NeoPixel FrontLight_Pixels(1, FRONT_LIGHT_PIN, NEO_GRB + NEO_KHZ800);

ButtonDebounce FrontLight_Button(FRONT_LIGHT_BUTTON_PIN, FRONT_LIGHT_BUTTON_DEBOUNCE);
uint8_t FrontLight_CycleCounter = 0;

void FrontLight_ButtonCallback(const int state) {
    if (state == 0) {
        FrontLight_CycleCounter++;
        if (FrontLight_CycleCounter > 9) {
            FrontLight_CycleCounter = 0;
        }
    }
}

void FrontLight_Init() {
    FrontLight_Pixels.begin();
    FrontLight_Button.setCallback(FrontLight_ButtonCallback);
}

void FrontLight_Update() {
    FrontLight_Button.update();

    LINE_Request_FrontLightStatus_data.fields.ControlCycleCount = FrontLight_CycleCounter;

    uint8_t targetBrightness = map(LINE_Request_LightSynchronization_data.fields.TargetBrightness, 0, 100, 0, FRONT_LIGHT_MAX_BRIGHTNESS);

    if (LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Off) {
        targetBrightness = 0;
    }
    else if(LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Adaptive) {
        // nothing
    }
    else if(LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Standard) {
        targetBrightness = targetBrightness > FRONT_LIGHT_MIN_BRIGHTNESS ? targetBrightness : FRONT_LIGHT_MIN_BRIGHTNESS;
    }
    else if(LINE_Request_LightSynchronization_data.fields.LightMode == LINE_ENCODER_LightModeEncoder_Emergency) {
        targetBrightness = FRONT_LIGHT_MIN_BRIGHTNESS;
    }

    if (LINE_Request_FrontLightSetting_data.fields.Behavior == LINE_ENCODER_LightBehaviorEncoder_Blink) {
        if (millis() - FrontLight_BlinkTimer > FRONT_BLINK_RATE) {
            FrontLight_BlinkTimer = millis();
            FrontLight_BlinkState = !FrontLight_BlinkState;
            if (FrontLight_BlinkState) {
                FrontLight_Pixels.setPixelColor(0, FrontLight_Pixels.Color(targetBrightness, targetBrightness, targetBrightness));
            }
            else {
                FrontLight_Pixels.setPixelColor(0, FrontLight_Pixels.Color(FRONT_LIGHT_STROBE_LOW, FRONT_LIGHT_STROBE_LOW, FRONT_LIGHT_STROBE_LOW));
            }
        }
    }
    else {
        FrontLight_Pixels.setPixelColor(0, FrontLight_Pixels.Color(targetBrightness, targetBrightness, targetBrightness));
    }
    FrontLight_Pixels.show();
}