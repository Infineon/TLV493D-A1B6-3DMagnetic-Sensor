/*********************************************************************************************************************
 * @file     MagneticSensor3Dutil.h
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

#ifndef MAGNETICSENSOR3D_UTIL_H_INCLUDED
#define MAGNETICSENSOR3D_UTIL_H_INCLUDED



#define MSENS3D_DEFAULTADDRESS			0x5EU
#define MSENS3D_STARTUPDELAY			500U

#define MSENS3D_UPDATEBLOCKSIZE			7U

#define MSENS3D_POWERDOWNMODECONFIG		0x00U
#define MSENS3D_LOWPOWERMODECONFIG		0x01U
#define MSENS3D_FASTMODECONFIG			0x02U

#define MSENS3D_CHANNEL_REGADR			3U
#define MSENS3D_CHANNEL_REGMASK			0x03U

#define MSENS3D_POWERDOWN_REGADR		5U
#define MSENS3D_POWERDOWN_REGMASK		0x10U

#define MSENS3D_XUPPER_REGADR			0U
#define MSENS3D_XUPPER_REGMASK			0xFFU
#define MSENS3D_XUPPER_REGSHIFT			4U
#define MSENS3D_XLOWER_REGADR			4U
#define MSENS3D_XLOWER_REGMASK			0x0FU
#define MSENS3D_XLOWER_REGSHIFT			4U

#define MSENS3D_YUPPER_REGADR			1U
#define MSENS3D_YUPPER_REGMASK			0xFFU
#define MSENS3D_YUPPER_REGSHIFT			4U
#define MSENS3D_YLOWER_REGADR			4U
#define MSENS3D_YLOWER_REGMASK			0x0FU
#define MSENS3D_YLOWER_REGSHIFT			0U

#define MSENS3D_ZUPPER_REGADR			2U
#define MSENS3D_ZUPPER_REGMASK			0xFFU
#define MSENS3D_ZUPPER_REGSHIFT			4U
#define MSENS3D_ZLOWER_REGADR			5U
#define MSENS3D_ZLOWER_REGMASK			0x0FU
#define MSENS3D_ZLOWER_REGSHIFT			0U

#define MSENS3D_TUPPER_REGADR			3U
#define MSENS3D_TUPPER_REGMASK			0xF0U
#define MSENS3D_TUPPER_REGSHIFT			4U
#define MSENS3D_TLOWER_REGADR			6U
#define MSENS3D_TLOWER_REGMASK			0xFFU
#define MSENS3D_TLOWER_REGSHIFT			0U

#define MSENS3D_12BITMSB				0x800U
#define MSENS3D_13BITMSB				0x1000U
#define MSENS3D_RADTODEG				(180.0 / PI)
#define MSENS3D_B_MULT					0.098
#define MSENS3D_B_OFFSET				0
#define MSENS3D_TEMP_MULT				1.1
#define MSENS3D_TEMP_OFFSET				-340	



#endif		/* MAGNETICSENSOR3D_UTIL_H_INCLUDED */


