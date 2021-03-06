//
// Author: Maarten Westenberg
// Version: 1.0.1
// Date: 2016-07-25
//
// This file contains a number of compile-time settings that can be set on (=1) or off (=0)
// The disadvantage of compile time is minor compared to the memory gain of not having
// too much code compiled and loaded on your ESP8266.
//
// ----------------------------------------------------------------------------------------


#define STATISTICS 1			// Gather statistics on sensor and Wifi status
// Initial value of debug var. Can be changed using the admin webserver
// Debug level! 0 is no msgs, 1 normal, 2 is extensive
// For operational use, set initial DEBUG vaulue 0
#define DEBUG 1

#define CFG_sx1276_radio		// Define the correct radio type that you are using
//#define CFG_sx1272_radio		// sx1272 not supported yet
					
// Wifi definitions
// Array with SSID and password records. Set WPA size to number of entries in array
#define WPASIZE 2
static char *wpa[WPASIZE][2] = {
  { "nodeMCU", "Dd12345678"},
  { "nodeteste", "Dd12345678"}
};

// Set the Server Settings
#define _SPREADING SF7							// We receive and sent on this Spreading Factor (only)
#define _LOCUDPPORT 1700						// Often 1701 is used for upstream comms

#define _PULL_INTERVAL 31						// PULL_DATA messages to server to get downstream
#define _STAT_INTERVAL 61						// Send a 'stat' message to server
#define _NTP_INTERVAL 3600						// How often doe we want time NTP synchronization

// MQTT definitions
#define _TTNPORT 1700
//#define _TTNSERVER "router.eu.staging.thethings.network"
#define _TTNSERVER "router.eu.thethings.network" //DJL "router.eu.thethings.network"

// Port is UDP port in this program
#define _THINGPORT 1700							// dash.things4u.eu
//#define _THINGSERVER "yourserver.com"			// Server URL of the LoRa-udp.js program

// Gateway Ident definitions
#define _DESCRIPTION "ESP Gateway"
#define _EMAIL "youremail@gmail.com"
#define _PLATFORM "ESP8266"
#define _LAT 41.157944 
#define _LON -8.629105
#define _ALT 0

								
// Definitions for the admin webserver
#define A_SERVER 1				// Define local WebServer only if this define is set
#define SERVERPORT 8080			// local webserver port

#define A_MAXBUFSIZE 192		// Must be larger than 128, but small enough to work
#define _BAUDRATE 115200		// Works for debug messages to serial momitor (if attached).

// ntp
#define NTP_TIMESERVER "pt.pool.ntp.org"	// Country and region specific
#define NTP_TIMEZONES	-8		// How far is our Timezone from UTC (excl daylight saving/summer time)
#define SECS_PER_HOUR	3600

#if !defined(CFG_noassert)
#define ASSERT(cond) if(!(cond)) gway_failed(__FILE__, __LINE__)
#else
#define ASSERT(cond) /**/
#endif
