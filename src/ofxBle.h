//
//  ofxBLE.h
//
//  Created by Andikan on 11/11/2014.
//
//

#pragma once

#import "ofApp.h"
#import "BLE.h"

#include "ofMain.h"

class ofApp;

@interface ofxBLEDelegate : NSObject <BLEDelegate>
{
    BLE *ble;
}

@property (assign, atomic) ofApp *dataDelegate;
@property (strong, nonatomic)   BLE *ble;
@property unsigned char * receivedDATA;
@property int lengthOfDATA;

@end


class ofxBLE{
protected:
    ofxBLEDelegate *dongle;

public:
    //constructor
    ofxBLE();
    //destructor
    ~ofxBLE();
    
    void update();
    void scanPeripherals();
    void sendDigitalOut(bool bState);
    void setAnalogInput(bool bState);
    void setDataDelegate(ofApp *delegate);
    //void getData();
    void sendServo(float _val);
    void sendData(UInt8 _b);
    
    int analogVAL;
    unsigned char * receivedDATA;
    int lengthOfDATA;
    
    bool isConnected();
};


