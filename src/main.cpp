#include <ESPHue.h>
#include <RestClient.h>
#include "config.h"

RestClient client = RestClient(HUE_HOST);

int flash_button = 0;
int rest_delay = 1000;

String response = "";
String urlString = "";
int statusCode = 0;
int counter = 0;

int getGroupAnyOn()
{
	int groupState = -1;

	response = "";
	urlString = "/api/" + HUE_API_KEY + "/groups/1";

	int url_len = urlString.length() + 1;
	char url[url_len];
	urlString.toCharArray(url, url_len);

	//Serial.printf(url);

	statusCode = client.get(url, &response);
	delay(rest_delay);
	Serial.print(statusCode);
	Serial.print(response);
	//if(statusCode/100 == 2){
		if (response.indexOf("\"any_on\":true") > 0)
		{
			groupState = 1;
		}
		else
		{
			groupState = 0;
		}
		return groupState;
	//}

	//return -1;
}

void changeHueState()
{
	int groupState = counter;//getGroupAnyOn();
	if(counter == 0){
		counter = 1;
	}else{
		counter = 0;
	}
	response = "";
	urlString = "/api/" + HUE_API_KEY + "/groups/1/action";

	int str_len = urlString.length() + 1;
	char url[str_len];
	urlString.toCharArray(url, str_len);

	if (groupState == 0)
	{
		statusCode = client.put(url, "{\"on\":true}", &response);
		//Serial.printf("ON_NOW");

	}
	else if(groupState == 1)
	{
		statusCode = client.put(url, "{\"on\":false}", &response);
		//Serial.printf("OFF_NOW");
	}
	delay(rest_delay);
	if(groupState == -1 || statusCode/100 != 2){
		//Serial.printf("ERROR");
	}
	Serial.print(statusCode);
	Serial.print(response);
}

void setup()
{
	Serial.begin(9600);
	client.begin(SSID, PASSWORD);

	pinMode(flash_button, INPUT);
}

void loop()
{
	if (digitalRead(flash_button) == LOW)
	{
		while(digitalRead(flash_button) == LOW){
			delay(100);
		}
		Serial.printf("PRESSED");
		changeHueState();
	}
}