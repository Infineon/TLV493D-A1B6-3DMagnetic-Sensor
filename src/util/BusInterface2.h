#ifndef TLV493D_BUSIF_2_H_INCLUDED
#define TLV493D_BUSIF_2_H_INCLUDED

#include "BusInterface.h"

#define BUS_ERROR 	1
#define BUS_OK 		0

namespace tlv493d
{
	
void initInterface(BusInterface_t *interface, TwoWire *bus, uint8_t adress);
bool readOut(BusInterface_t *interface);
bool readOut(BusInterface_t *interface, uint8_t count);
bool writeOut(BusInterface_t *interface);
bool writeOut(BusInterface_t *interface, uint8_t count);

}

#endif
