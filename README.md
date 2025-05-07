# Star Citizen Eject Lever
Eject lever for Star Citizen and other space/flight sims. It's designed to go under a DX Racer Sentinel gaming chair, to see if the bracket fits to your chair check "bracket_dimensions" in the picture folder. I included the .step file for the parts in the 3D_Files folder so you can adjust it when needed.

## Parts links
[TinyPico](https://www.tinypico.com/buy)

[M3 Threaded Inserts](https://cnckitchen.store/products/heat-set-insert-m3-x-5-7-100-pieces)

[Microswitches](https://www.aliexpress.com/item/1926553469.html) 1x Without Lever NO-NC, 1x 16mm Lever

[Remove before flight flags](https://www.aliexpress.com/item/32944985653.html)

Other parts: Generic split pin with aprox. 3.75mm diameter, 1S LiPo battery **with** protection circuit (2000mAh in my case), 10mm diameter bungee cord, 2x M3x8mm countersunk screws, 10x M3x10mm screws with any head (screws can be slightly longer), 4x M3 Nut, 30x12x"Z"mm Neodymium magnets (The "Z" height of the magnet depends on what you can get, I'm using 4mm high magnets rated at 6.8kg strength, but I had to use two magnets per "slot" for it to hold. There are 8 slots that have to be populated.)

## Printing and Assembly
I adjusted the parts based on my experience after printing them, they should be fairly easy to print now. The only part that needs a small amount of support at the bottom is the "Actuator main.stl". "Bracket.stl" uses the whole width of a 250mm print bed, you might have to disable skirt for it to work.

After printing you first have to glue the magnets to the bracket and the bridge, there are indentations on both parts for them. I used two component epoxy which works quite well. Make sure you orient the magnets properly so the two parts stick together. The bracket is mounted to your chair with the screws that hold the seat and the mechanical/wheel part together. To keep the chair level you have to print 2x Washer.stl and install them to the screws on the back.

 Next is inserting the threaded inserts into the 4mm holes on the actuator main and the plunger. To do so you heat your soldering iron to the printing temperature of the used filament +10°C and push the inserts slowly into the hole. [Video](https://www.youtube.com/watch?v=QTeAx-ykhhw)
 
The bungee cord is inserted into the 10mm holes in the plunger, this is a tight fit so I recommend to try without glue first. After gluing in the first end test how long the cord needs to be to stay upright but still allow you to grab it easily. Don't forget to give it an extra 4cm that go into the hole. I used two component epoxy to glue it in.

After that insert the plunger into the hole of the actuator main part from the top and screw on the plunger counter plate with two countersunk M3 screws. Make sure the part that stands out on the counter plate faces outwards.

Now you can glue the microswitches in place, I used double sided tape for that. The switch without lever is used for the plunger (see picture), the switch with the lever (power) is glued onto the lid so that it gets activated when the pin is inserted. You can also wait with this step until after soldering.

The electric circuit is relatively simple. The plunger switch is connected to pin 33 and GND of the TinyPico, use the normally open (NO) and common (C) pins on the switch. The battery *plus* is connected to the common (C) pin of the power switch and the **normally closed (NC)** pin is then connected to the BAT pin on the Pico. The *minus* of the battery is connected to GND. I also soldered in a connector for the battery so I don't have to cut the wires. Use double sided tape to attach the TinyPico and the battery, make sure you can still insert a USB cable for programming and charging the battery. On the updated design the box has no bottom, so you should have easy access.

To upload the code you will have to install the TinyPico helper library which is available in the library manager of the Arduino IDE as well as the BLE Keyboard library which you have to [download from github](https://github.com/T-vK/ESP32-BLE-Keyboard/releases) and add as a zip file. If you never used an ESP32 before you also have to [install the board](https://docs.espressif.com/projects/arduino-esp32/en/latest/installing.html) in the Arduino IDE. The code I included presses "right Alt"+"y" (Alt Gr+Z on QWERTZ keyboards), you can change it by following these [guidelines](https://www.arduino.cc/reference/en/language/functions/usb/keyboard/keyboardmodifiers/) (make sure you use bleKeyboard instead of Keyboard).

Last but not least screw the actuator box to the bridge and the lid to the box. If you now remove the pin the board gets powered and is ready for pairing with your PC. If your PC doesn't come with Bluetooth you will have to buy a USB-Bluetooth adapter for it to work.


I included the .step file for the printed parts so you can adjust them if you want.



[![CC BY-NC-SA 4.0][cc-by-nc-sa-shield]][cc-by-nc-sa]

[cc-by-nc-sa]: http://creativecommons.org/licenses/by-nc-sa/4.0/
[cc-by-nc-sa-shield]: https://img.shields.io/badge/License-CC%20BY--NC--SA%204.0-lightgrey.svg
