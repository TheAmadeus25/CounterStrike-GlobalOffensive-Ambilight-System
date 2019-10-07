



#ifndef A_Variable_h
#define A_Variable_h


const char* ssid = "******";                                      // WiFi Name
const char* password = "******";                                  // WiFi Password
String IP = "192.168.178.23";                                     // IP of Node.js Scriptfile
String PORT = "65001";                                            // Port of Node.js Scriptfile

WiFiUDP Udp;

unsigned int localUdpPort = 65001;                                // local port to listen on
char incomingPacket[255];                                         // buffer for incoming packets
int packetSize, len;

String payload = "";                                              // Input Buffer

bool canBtnPress = true;                                          // Button available
bool ShowOverlay = true;                                          // 

short ColorMover = 0;                                             // Important for HSV Colorspace

short Light_Mode = 0;                                             // Which Light Mode is active now
bool  FX_Changed = false;

struct {
  short A_LOW, A_HIGH = 0;
  short B_LOW, B_HIGH = 0;
  short C_LOW, C_HIGH = 0;
  short D_LOW, D_HIGH = 0;
  short E_LOW, E_HIGH = 0;
} Zone;



struct {
  short        health        = 0;                                 // Optimized for 100 -> 0
  short        armor         = 0;                                 // Value between 100 -> 0
  unsigned int flashed       = 0;                                 // Value between 255 -> 0
  unsigned int burning       = 0;                                 // Value between 255 -> 0
  unsigned int round_killshs = 0;                                 // Optimized for 0 -> 5
  String       helmet        = "";                                // Value is true or false
  bool         smoked        = false;                             // Value is true or false
  bool         defusekit     = false;                             // Value is true or undefined (wtf?)
} Player, Player_Last;

struct {
  String win_team;                                                // CT or T
  String bomb;                                                    // Planted, Defused, Exploded
} Round, Round_Last;

short Value_Parts = 0;

struct {
  const long    refresh_delay = 100;                              // How often checking for new Information
  unsigned long last_refresh  = 0;                                // Last time checking for new Information
} Websocket;





#endif
