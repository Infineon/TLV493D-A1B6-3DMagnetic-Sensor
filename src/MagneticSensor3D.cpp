/*********************************************************************************************************************
 * @file     MagneticSensor3D.cpp
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


#include "MagneticSensor3D.h"
#include "util/MagneticSensor3Dutil.h"
#include <math.h>


MagneticSensor3d magnetic3dSensor = MagneticSensor3d(Wire);


MagneticSensor3d::MagneticSensor3d(TwoWire &bus) : MagneticSensor3d(bus, MSENS3D_DEFAULTADDRESS)
{
}


MagneticSensor3d::MagneticSensor3d(TwoWire &bus, uint8_t slaveAddress)
{
	mBus = &bus;
	mSlaveAddress = slaveAddress;
}


MagneticSensor3d::~MagneticSensor3d(void)
{
	end();
}


void MagneticSensor3d::begin(void)
{
	delay(MSENS3D_STARTUPDELAY);
	mBus->begin(); 
	mBus->beginTransmission(mSlaveAddress); 
	mBus->write(0x00);
	mBus->write(MSENS3D_LOWPOWERMODECONFIG);
	mBus->endTransmission(TRUE);
	delay(MSENS3D_STARTUPDELAY);
	updateData();
}


void MagneticSensor3d::end(void)
{
	mBus->beginTransmission(mSlaveAddress); 
	mBus->write(0x00);
	mBus->write(MSENS3D_POWERDOWNMODECONFIG);
	mBus->endTransmission(TRUE);
}


void MagneticSensor3d::updateData()
{
	int8_t registers[MSENS3D_UPDATEBLOCKSIZE];
	do
	{
		uint8_t len = Wire.requestFrom(mSlaveAddress, MSENS3D_UPDATEBLOCKSIZE);    //Request data from the Sensor
		for(uint8_t i=0; i<len; i++)
		{
			registers[i] = Wire.read();
		}
		Wire.endTransmission(TRUE);
	} while( (registers[MSENS3D_CHANNEL_REGADR] & MSENS3D_CHANNEL_REGMASK != 0x00)
		||   (registers[MSENS3D_POWERDOWN_REGADR] & MSENS3D_POWERDOWN_REGMASK != 0x00) );
	
	mXdata = (static_cast<int16_t>(registers[MSENS3D_XUPPER_REGADR] & MSENS3D_XUPPER_REGMASK)) << MSENS3D_XUPPER_REGSHIFT;
	mXdata |= static_cast<uint16_t>((registers[MSENS3D_XLOWER_REGADR] >> MSENS3D_XLOWER_REGSHIFT) & MSENS3D_XLOWER_REGMASK);
	if(mXdata > MSENS3D_12BITMSB)
	{
		mXdata -= MSENS3D_13BITMSB;
	}
	
	mYdata = (static_cast<int16_t>(registers[MSENS3D_YUPPER_REGADR] & MSENS3D_YUPPER_REGMASK)) << MSENS3D_YUPPER_REGSHIFT;
	mYdata |= static_cast<uint16_t>((registers[MSENS3D_YLOWER_REGADR] >> MSENS3D_YLOWER_REGSHIFT) & MSENS3D_YLOWER_REGMASK);
	if(mYdata > MSENS3D_12BITMSB)
	{
		mYdata -= MSENS3D_13BITMSB;
	}
	
	mZdata = (static_cast<int16_t>(registers[MSENS3D_ZUPPER_REGADR] & MSENS3D_ZUPPER_REGMASK)) << MSENS3D_ZUPPER_REGSHIFT;
	mZdata |= static_cast<uint16_t>((registers[MSENS3D_ZLOWER_REGADR] >> MSENS3D_ZLOWER_REGSHIFT) & MSENS3D_ZLOWER_REGMASK);
	if(mZdata > MSENS3D_12BITMSB)
	{
		mZdata -= MSENS3D_13BITMSB;
	}
	
	mTempdata = (static_cast<int16_t>(registers[MSENS3D_TUPPER_REGADR] & MSENS3D_TUPPER_REGMASK)) << MSENS3D_TUPPER_REGSHIFT;
	mTempdata |= static_cast<uint16_t>((registers[MSENS3D_TLOWER_REGADR] >> MSENS3D_TLOWER_REGSHIFT) & MSENS3D_TLOWER_REGMASK);
	if(mTempdata > MSENS3D_12BITMSB)
	{
		mTempdata -= MSENS3D_13BITMSB;
	}
}


float MagneticSensor3d::getX(void)
{
	return static_cast<float>(mXdata) * MSENS3D_B_MULT + MSENS3D_B_OFFSET;
}


float MagneticSensor3d::getY(void)
{
	return static_cast<float>(mYdata) * MSENS3D_B_MULT + MSENS3D_B_OFFSET;
}


float MagneticSensor3d::getZ(void)
{
	return static_cast<float>(mZdata) * MSENS3D_B_MULT + MSENS3D_B_OFFSET;
}


float MagneticSensor3d::getTemp(void)
{
	return static_cast<float>(mTempdata) * MSENS3D_TEMP_MULT + MSENS3D_TEMP_OFFSET;
}


float MagneticSensor3d::getAmount(void)
{
	// sqrt(x^2 + y^2 + z^2)
	return MSENS3D_B_MULT * sqrt(pow(static_cast<float>(mXdata), 2) + pow(static_cast<float>(mYdata), 2) + pow(static_cast<float>(mZdata), 2));
}


float MagneticSensor3d::getAzimuth(void)
{
	// arctan(y/x)
	return atan2(static_cast<float>(mYdata), static_cast<float>(mXdata));
}


float MagneticSensor3d::getPolar(void)
{
	// arctan(z/(sqrt(x^2+y^2)))
	return atan2(static_cast<float>(mZdata), sqrt(pow(static_cast<float>(mXdata), 2) + pow(static_cast<float>(mYdata), 2)));
}

