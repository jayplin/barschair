
# barschair

A wifi controlled bladess fan powered by quatrocopter blades.    


## Tech Stack

 **PCB Design:** [Kicad](https://www.kicad.org/)

 **Microcontroller:** [ESP8266](https://www.espressif.com/en/products/socs/esp8266)

 **Client:** [Blynk](https://blynk.io/)
 

## Components
```
   +-----------------------------------------------+
     |                                               |
     |                                               |
     |                                               |
+----+----+                                          |
|         +--------------------------+               |
|Power    |                 |LED     |               |
+-----+---+------+          |        |               |
      |          |          +---+----+               |
      |          |              |              +-----+---+     +-----------+
 +----+----+     |              |              |   ESC   |     | Motor     |
 |Sonoff   |     |              |       +------+         +-----+           |
 +---------+     |          +---+----+  |      +---------+     +-----------+
                 |          |  ESP   +--------------------+
                 |          |        +--+                 |
                 |          +---+---++      +--------+   ++-------+
                 |              |   |       |Prog    |   |Switch  |
                 |              |   +-------+        |   +--------+
                 |          +---+-----+     +--------+
                 +----------+  Servo  |
                            |         |
                            +---------+

```
