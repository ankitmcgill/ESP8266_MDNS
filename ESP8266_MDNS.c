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


#include "ESP8266_MDNS.h"

//LOCAL LIBRARY VARIABLES/////////////////////////////////////
//DEBUG RELATRED
static uint8_t _esp8266_mdns_debug;

//END LOCAL LIBRARY VARIABLES/////////////////////////////////

void ICACHE_FLASH_ATTR ESP8266_MDNS_SetDebug(uint8_t debug_on)
{
    //SET DEBUG PRINTF ON(1) OR OFF(0)

	_esp8266_mdns_debug = debug_on;
}

void ICACHE_FLASH_ATTR ESP8266_MDNS_Initialize(char* host_name,
													char* server_name,
													uint16_t server_port,
													ESP8266_MDNS_SYSTEM_MODE mode)
{
	//INTIALIZE AND START MDNS SERVICE WITH THE SPECIFIED PARAMETERS
	//THE DEVICE IS AVAILABLE AT THE ADDRESS <host_name>.local
	//NOTE SURE YET WHAT SERVER_NAME AND PORT DO

	struct ip_info ip;
	struct mdns_info* m_info;

	//FIRST OF ALL CHECK IF THE SYSTEM IS CONNECTED TO WIFI AND HAS IP
	//ADDRESS. REQUIRED BEFORE STARTING MDNS SERVICE

	if(wifi_get_ip_info(mode, &ip) == FALSE)
	{
		//ERROR GETTING SYSTEM IP ADDRESS
		//TERMINATE
		if(_esp8266_mdns_debug)
		{
			os_printf("ESP8266 : MDNS : Cannot find system IP. Terminating mdns init\n");
		}
		return;
	}

	//ALLOCATE STRUCTURE
	m_info = (struct mdns_info*)os_zalloc(sizeof(struct mdns_info));

	//SET PARAMETERS
	m_info->host_name = host_name;
	m_info->ipAddr = ip.ip.addr;
	m_info->server_name = server_name;
	m_info->server_port = server_port;

	//INIT MDNS
	espconn_mdns_init(m_info);

	if(_esp8266_mdns_debug)
	{
		os_printf("ESP8266 : MDNS : Started with parameters\n");
		os_printf("host_name = %s\n", m_info->host_name);
		os_printf("server_name = %s\n", m_info->server_name);
		os_printf("server_port = %u\n", m_info->server_port);
	}
}

void ICACHE_FLASH_ATTR ESP8266_MDNS_Stop(void)
{
	//STOP MDNS ON THE SYSTEM

	espconn_mdns_close();

	if(_esp8266_mdns_debug)
	{
		os_printf("ESP8266 : MDNS : Stopped\n");
	}
}
