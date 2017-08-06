include <SPI.h>
include <Ethernet.h>
byte mac[] = { 0x90, 0xA2, 0xDA, 0x00, 0xE4, 0xA0 };
IPAddress ip(10, 0, 0, 223);
IPAddress gateway(10, 0, 0, 1);
IPAddress subnet(255, 0, 0, 0);
EthernetServer server(80);

void setup() {
  Ethernet.begin(mac, ip, gateway, subnet);
  server.begin();
}

void loop() {
  EthernetClient client = server.available();
  if (client) {
    while (client.connected()) {
      if (client.available()) {
        client.println("HTTP/1.1 200 OK");
        client.println("Content-Type: text/html");
        client.println("Connection: close");
        // client.println("Refresh:10");
        client.println();
        client.println("<!DOCTYPE HTML>
        client.println("<html lang='en'>");
        client.println(F("<head><title>Arduino Web Server Hello</title><meta charset='utf-8'><meta name='author' content='Don Falstein'><meta name='description' content='Arduino Web Server Hello'></head>"));
        client.println("<body>");
        client.println(F("<nav><span><a href='#'>Home</a></span><ul><li>Nav list one, item one</li><Nav list one, item two</li></ul><ul><li>Nav list two, item one</li><li>Nav list two, item two</li></ul></nav>"));
        client.println("<main>");
        client.println(F("<header><h2>Hello</h2></header>"));
        client.println("<article>");
        client.println(F("<section><p>Hello, I am an Arduino web server designed to introduce myself to the world.</p></section>"));
        client.println("</article>");
        client.println("</main>");
        client.println(F("<footer><p>Aruino Web Server Hello is openly available and distributable with the BSD-3 copyright license included in this GitHub repository made available by Don Falstein - August 2017.</p><p>If you have any questions, please create an issue or a pull request.</p></footer>"));
        client.println("</body>");
        client.println("</html>");
        break;
      }
    }
    delay(1);
    client.stop();
  }
}
