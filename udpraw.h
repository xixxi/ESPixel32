///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef __UDPRAW_H__
#define __UDPRAW_H__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <ESPAsyncUDP.h>

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define ESPS_UDP_RAW_DEFAULT_PORT 2801

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// Status structure
typedef struct {
    uint32_t    num_packets;
    uint32_t    long_packets;
    uint32_t    short_packets;
    uint32_t    packet_errors;
    IPAddress   last_clientIP;
    uint16_t    last_clientPort;
} udpraw_stats_t;


class UdpRaw
{
    AsyncUDP _udp;

public:
    udpraw_stats_t  stats;    // Statistics tracker
    bool zeropad = true;

    void begin(uint16_t port = ESPS_UDP_RAW_DEFAULT_PORT);

    void end()
    {
        _udp.close();
    }

private:
    void onPacket(AsyncUDPPacket packet);
    uint16_t port = ESPS_UDP_RAW_DEFAULT_PORT;
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif // #ifndef __UDPRAW_H__

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
