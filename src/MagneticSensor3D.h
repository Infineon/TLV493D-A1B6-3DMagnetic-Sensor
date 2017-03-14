/*********************************************************************************************************************
 * @file     MagneticSensor3D.h
 * @brief    Arduino library to control Infineon's Magnetic 3D Sensor TLV493D-A1B6
             Have a look at the datasheet for more information. 
 * @version  V1.0
 * @date     13/03/2017
 *
 * @cond
 *********************************************************************************************************************
 * Copyright (c) 2017, Infineon Technologies AG
 * All rights reserved.                        
 *                                             
 * Redistribution and use in source and binary forms, with or without modification, are permitted provided that the 
 * following conditions are met:   
 *                                                                              
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the following 
 * disclaimer.                        
 * 
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following 
 * disclaimer in the documentation and/or other materials provided with the distribution.                       
 * 
 * Neither the name of the copyright holders nor the names of its contributors may be used to endorse or promote 
 * products derived from this software without specific prior written permission.                                           
 *                                                                              
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE  
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE  FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR  
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY,OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.                                                  
 *                                                                              
 * To improve the quality of the software, users are encouraged to share modifications, enhancements or bug fixes with 
 * Infineon Technologies AG.                                                          
 *********************************************************************************************************************
 *
 **************************** Change history *********************************
 *****************************************************************************
*/

#ifndef MAGNETICSENSOR3D_H_INCLUDED
#define MAGNETICSENSOR3D_H_INCLUDED


#include <Arduino.h>
#include <Wire.h>

#ifndef FALSE
#define FALSE 0
#endif
#ifndef TRUE
#define TRUE 1
#endif



class MagneticSensor3d
{
public: 
	MagneticSensor3d(TwoWire &bus);
	MagneticSensor3d(TwoWire &bus, uint8_t address);
	~MagneticSensor3d(void);
	void begin(void);
	void end(void);
	
	//read data from sensor
	void updateData(void);
	
	// fieldvector in Cartesian coordinates
	float getX(void);
	float getY(void);
	float getZ(void);
	
	// fieldvector in spherical coordinates
	float getAmount(void);
	float getAzimuth(void);
	float getPolar(void);
	
	float getTemp(void);
private: 
	TwoWire *mBus;
	uint8_t mSlaveAddress;
	int16_t mXdata;
	int16_t mYdata;
	int16_t mZdata;
	int16_t	mTempdata;
};

extern MagneticSensor3d magnetic3dSensor;

#endif		/* MAGNETICSENSOR3D_H_INCLUDED */
