#ifndef POSTUREDETECTOR_h
#define POSTUREDETECTOR_h

#include "Arduino.h"

enum ElevationType {LOW_ELEV, MODERATE_ELEV, HIGH_ELEV, UNKNOWN_ELEV};
enum TwistType {TWIST, NONE};
enum BackTiltType {STRAIGHT, PARTIALLY_BENT, FULLY_BENT, UNKNOWN_TILT};

class PostureDetector{
  public:
    PostureDetector();
    ElevationType checkArmElevation(int wristAccelX, int wristAccelY, int wristAccelZ);
    TwistType checkImpulse(int wristAccelX, int wristAccelY, int wristAccelZ);
    BackTiltType checkBackTilt(int tiltUpperBack, int tiltLowerBack);
    void clearImpulseState();
    void clearBackTiltState();

  private:
    const int UPPER_BACK_MEDIAN_THRESHOLD = 300; // range - 30-550
    const int LOWER_BACK_MEDIAN_THRESHOLD = 175; // range - 1- 300
    bool upperTilted;
    bool lowerTilted;    

    const float ACCELERATION_THRESHOLD = 0.20; //sensitivity of twist detection
    const int ACCELERATION_BUFFER_SIZE = 10; //affects the lenght of twists
    int accel_x [10];
    int accel_y [10];
    int accel_z [10];
    float x_avg;
    float y_avg;
    float z_avg;
    int start_index;
    int accel_index;

    int value_x;
    int value_y;
    int value_z;
};

#endif

