**Was ist IoT?**

„die Vernetzung von Gegenständen mit dem Internet, damit diese Gegenstände selbstständig über das Internet kommunizieren und so verschiedene Aufgaben für den Besitzer erledigen können.&quot;

Die Anfänge des IoT gehen auf RFID (radio-frequency identification) zurück. Bereits im Jahr 1999 wurde der Begriff von Kevin Ashton in Verbindung damit aufgebracht.

**Einsatzbereiche**

Der Einsatzbereich für IoT ist fast uneingeschränkt. Beispiele sind etwa:

- Beleuchtung (Philips Hue)
- Verkehrsmittel (Im Auto)
- Ampeln
- Medizinische Geräte (Herzschrittmacher)
- Türsteuerungsanlagen

**Technologiestack**

**Amazon Alexa**

**Node-RED**

Visuelles Tool zur Verbindung von IOT-Geräten, APIs und anderen Online Services.

**Bluetooth Low Energy**

Vergleichbar mit normalem Bluetooth hat allerdings geringere Reichweite und Stromverbrauch.

**XIAOMI**

Hersteller von Smart-Home Produkten (z.B. Lampen)

**FS20**

Funkschaltungssystem

**Sensor**

Werten Messgrößen aus und schicken je nach Ergebnis verschiedene Signale. (Temperatur, Helligkeit, Druck, Bewegung, …)

**Aktor**

Das Gegenstück zum Sensor, reagiert auf Signale und bewegt etwas oder verändert z.B. Druck. (Elektromotor, …).

**ESP2866**

NodeMCU V2 Amica

Ist ein Low-Power 32-Bit Microcontroller von Espressif.

- Clockspeed: 60-160 MHz
- Flashspeicher: 4MB
- Digital I/O: 11
- Analog In: 1
- Integriertes Wifi-Modul

ESP32

ESP32 DevKitC V4

Ultra-Low-Power 32-Bit Microcontroller ebenfalls von Espressif.

- Zwei Kerne
- Ein low-power co-processor
- Clockspeed: 160-240 MHz
- Flashspeicher: 4MB
- Digital I/O: 11
- Analog In: 12 Channels
- Analog Out: Pulsweitenmodulation, 2 Channels direkt
- Intergriertes Wifi-Modul und BLE

**MQTT**

Steht für Message Queing Telemetry Transport und ist ein Nachrichtenprotokoll für M2M Kommunikation. Es ermöglicht den Transport von Daten auch bei schlechter Verbindung. Wir haben an unserer Schule einen eigenen, von Professor Köck und Professor Stützt betreuten, MQTT-Server.

**OPEN-HAB**

Ein unabhängiges Softwaretool für die Verbindung von IoT-Geräten. Es handelt sich dabei um in OpenSource-Projekt in Java. Ähnlich dem bereits erwähnten Node-RED.

**PlatformIO**

PlatformIO ist eine Cross-Platform IDE für das Programmieren von IoT-Geräten. Es ist für Atom als Package und VSCode als Extension erhältlicht.

**Beispiel**

**Philips Hue**

Ein Philibs Hue System besteht aus einer Bridge/Hub und mehreren Hue-Lampen, es gibt auch noch weitere Komponenten wie einen eigenen Dimmer etc. Das Ganze wird im Normalfall über eine App am Smartphone gesteuert kann allerdings auch über eine eigene Rest-API angesprochen werden.

Die Kommunikation zwischen den Lampen und der Bridge erfolgt über das ZigBee-Prookoll insbesondere mithilfe eines ZigBee Light Link mit eigenen security keys, weshalb das Verwenden von Hue-Lampen ohne Bridge nicht/kaum möglich ist.

**ZigBee**

Die ZigBee-Spezifikation baut auf den Standard IEEE 802.15.4 ( Übertragungsprotokoll für Wireless Personal Area Networks) auf und beschreibt drei Geräterollen:

- Endgeräte (ZED – ZigBee End Devices)
  - Melden sich bei einem Router an und können ausschließlich mit diesem kommunizieren. Es kann in einen Schlafmodus gehen und Daten die ihm dann geschickt werden werden so lange von Router gespeichert, bis das Endgerät sie abruft.
- Router (ZR – ZigBee Router)
  - Sind für das Routing von Paketen innerhalb des ZigBee Netzes verantwortlich. Tritt ein neues Gerät dem Netzwerk bei wird diesem eine 16-Bit Andresse zugewiesen.
- Koordinatoren (ZC – ZigBee Coordinator)
  - Ist für das Starten des Netzwerks verantwortlich und übernimmt nach dem Start die selben Aufgaben wie der Router.

**ZigBee Light-Link**

Enthält Funktionen für das Steuern von Farbe, Helligkeit und dem An- und Ausschalten von Lampen. Der Einfachheit halber wird im Normalfall auf Koordinator verzichtet.

Da jedes Gerät durch einen einzigen „Masterkey&quot; verschlüsselt wird, welcher bei manchen Herstellern bereits bekannt ist, ist Sicherheit hierbei ein großes Risiko.

Der wohl nervigste Nachteil dieser Methode ist der, dass keine, nicht mit dem Masterkey zertifizierten, Endgeräte ins Netzwerk eintreten können. Dies verhindert zum Beispiel, dass man Hue-Lampen ganz ohne die Bridge ansprechen kann.

**Alternativen**

**diyHue**

Emuliert eine PhilipsHue Bridge und ermöglicht es auch eigene ZigBee Lampen zu seinem Netzwerk hinzuzufügen. Hue-Lampen können allerdings auch nur über die physikalische Bridge angesprochen werden.

**zigbee2mqtt**

Ermöglicht es beim Verwenden von Hue Produkte komplett auf die Bridge zu verzichten. Hierfür ist allerdings ein Hue Dimmer (zum Reseten der Lampen) und weitere externe Software z.B. eins CC2531 USB Sniffer und ein CC debugger notwendig.