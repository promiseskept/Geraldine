#ifndef IOTHTTPCLIENT_H
#define IOTHTTPCLIENT_H

#include <arduino.h>
#include <LWiFi.h>
#include <LWiFiClient.h>

#include <string>

// ********************************************
// ****** START user defined definitions ******
// ********************************************
#define AZURE_SERVICE_BUS_NAME_SPACE    "janjan-ns"
#define AZURE_EVENT_HUB_NAME            "janjan"
#define AZURE_POLICY_NAME               "janjanpolicy"

//#define AZURE_KEY                       "AhBB/d6/tJj/awnV9MPgj1UzXjeboHNzszF5ShcD2FY="
#define AZURE_KEY                       "46NPFmsvv+oLP2E3aWMyBw/1qDQjjX9CAeL/SyBx47w="



// ******************************************
// ****** END user defined definitions ******
// ******************************************

#define AZURE_HOST                      AZURE_SERVICE_BUS_NAME_SPACE".servicebus.windows.net"
#define AZURE_URL                       "/"AZURE_EVENT_HUB_NAME"/messages"

// Set to year 2020 so that it will not expire.

#define AZURE_UTC_2020_01_01            "1577836800"

/* HttpClient implementation to be used on the Mtk device. */
class IotHttpClient
{
    LWiFiClient client;
    
public:
    IotHttpClient();
    /* Send http request and return the response. */
    char* send(const char *request, const char* serverUrl, int port);
    int SendAzureHttpsData(std::string);
    
protected:
    char* sendHTTP(const char *request, const char* serverUrl, int port);
    char* sendHTTPS(const char *request, const char* serverUrl, int port);
    
public:
    static boolean sendHTTPS_remotecall(void*);
    static void sendHTTPS_ssl_callback(VMINT handle, VMINT event);
};

#endif
