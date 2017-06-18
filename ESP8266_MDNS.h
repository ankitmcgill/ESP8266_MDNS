/****************************************************************
* ESP8266 MDNS (MULTICAST DNS) LIBRARY
*
* MACS HAVE THIS BUILT IN, FOR WINDOWS NEED TO INSTALL SAFARI
* BROWSER OR BONJOUR SERVICE SEPARATELY.
*
* FOR LINUX NEED TO INSTALL AVAHI
* sudo apt-get install avahi-daemon avahi-discover avahi-utils libnss-mdns mdns-scan
*
*
* JUNE 18 2017
*
* ANKIT BHATNAGAR
* ANKIT.BHATNAGARINDIA@GMAIL.COM
*
* REFERENCES
* ------------
* 	(1) https://en.wikipedia.org/wiki/Multicast_DNS
* 	(2) https://techtutorialsx.com/2016/11/20/esp8266-webserver-resolving-an-address-with-mdns/
****************************************************************/

#ifndef _ESP8266_MDNS_H_
#define _ESP8266_MDNS_H_

#include "osapi.h"
#include "mem.h"
#include "ets_sys.h"
#include "ip_addr.h"
#include "espconn.h"
#include "os_type.h"

//CUSTOM VARIABLE STRUCTURES/////////////////////////////
enum ESP8266_MDNS_SYSTEM_MODE
{
	ESP8266_MDNS_SYSTEM_MODE_STATION = 0,
	ESP8266_MDNS_SYSTEM_MODE_SOFTAP = 1
};
//END CUSTOM VARIABLE STRUCTURES/////////////////////////

//FUNCTION PROTOTYPES/////////////////////////////////////
//CONFIGURATION FUNCTIONS
void ICACHE_FLASH_ATTR ESP8266_MDNS_SetDebug(uint8_t debug_on);
void ICACHE_FLASH_ATTR ESP8266_MDNS_Initialize(char* host_name,
													char* server_name,
													uint16_t server_port,
													enum ESP8266_MDNS_SYSTEM_MODE mode);
//GET PARAMETERS FUNCTIONS


//CONTROL FUNCTIONS
void ICACHE_FLASH_ATTR ESP8266_MDNS_Stop(void);

//INTERNAL CALLBACK FUNCTIONS

//END FUNCTION PROTOTYPES/////////////////////////////////
#endif
