/************************************************************************/
// File:            functions.h                                         //
// Author:          Arild Stenset, NTNU Spring 2020                     //
// Purpose:         Arrange useful functions                            //
//                                                                      //
/************************************************************************/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include <stdint.h>
#include <stdbool.h>

/* Take any angle and put it inside -PI, PI */
void vFunc_Inf2pi(float *angle_in_radians);

/* Calculates the distance in x direction to a measured object */
int16_t distObjectX(int16_t x, int16_t theta, int8_t servoAngle, int16_t* sensorData, uint8_t sensorNumber);

/* Same as above but for local coordinate system */
int16_t distObjectXlocal(int16_t theta, int8_t servoAngle, int16_t* sensorData, uint8_t sensorNumber);

/* Calculates the distance in y direction to a measured object */
int16_t distObjectY(int16_t y, int16_t theta, int8_t servoAngle, int16_t* sensorData, uint8_t sensorNumber);

/* Same as above but for local coordinate system */
int16_t distObjectYlocal(int16_t theta, int8_t servoAngle, int16_t* sensorData, uint8_t sensorNumber);

/* Arranges the message with robot positons, object positions and returns an array (Used from February 2020) */
/*  */
void sendNewPoseMessage(int16_t x, int16_t y, int16_t theta, int8_t servoAngle, int16_t* sensorData);

/* Arranges the message with robot positons, object positions and returns an array) */
/* Has to be used if using the Grindviks server version */
void sendOldPoseMessage(int16_t x, int16_t y, int16_t theta, int8_t servoAngle, int16_t* sensorData);

/* Increases limits for collision sectors when distance to object is below collision threshold */
void increaseCollisionSector(int16_t angle, uint8_t sensor);

/* Returns the detection angle between -179 and 180 degrees */
int16_t getDetectionAngle(uint8_t servoAngle, uint8_t sensor);

/* Decreases limits for collision sectors when distance to object is above collision threshold */
void decreaseCollisionSector(int16_t angle, uint8_t sensor);

/* Prints the collision sectors */
void printCollisionSectors(void);

/* Checks if the new waypoint is inside a blocked sector where collision is detected */
bool validWaypoint(int16_t waypointAngle);

#endif /* FUNCTIONS_H_ */