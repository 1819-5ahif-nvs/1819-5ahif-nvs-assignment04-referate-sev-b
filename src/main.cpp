#include <WiFiClient.h>
#include <ESPHue.h>
#include "credentials.h"

WiFiClient client;
ESPHue hueLamp = ESPHue(client, HUE_API_KEY, HUE_HOST, 80);

#define HUE_GROUP_ID 1

int flash_button = 0;

int getGroupAnyOn(byte groupNum)
{
	int groupState = 0;
	String response = hueLamp.getGroupInfo(groupNum);

	if (response.indexOf("\"any_on\":true") > 0)
	{
		groupState = 1;
	}
	else
	{
		groupState = 0;
	}

	return groupState;
}

void changeHueState()
{
	int groupState = getGroupAnyOn(HUE_GROUP_ID);

	if (groupState == 1)
	{
		hueLamp.setGroupPower(HUE_GROUP_ID, hueLamp.OFF);
	}
	else
	{
		hueLamp.setGroup(HUE_GROUP_ID, hueLamp.ON, 0, 254, 0);
	}
}

void setup()
{
	pinMode(flash_button, INPUT);
	attachInterrupt(digitalPinToInterrupt(flash_button), changeHueState, RISING);

	WiFi.begin(SSID, PASSWORD);

	while (WiFi.status() != WL_CONNECTED)
	{
		delay(500);
	}
}

void loop()
{
	if (WiFi.status() != WL_CONNECTED)
	{
		while (WiFi.begin(SSID, PASSWORD) != WL_CONNECTED)
		{
			delay(4000);
		}
	}
}