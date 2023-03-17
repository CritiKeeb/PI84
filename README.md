# PI84
PI84 ("pee aye eighty-four"), a Raspberry Pi Pico (RP2040) 30-key upgraded number pad, inspired by the key layout of the ubiquitous TI-8X line of graphing calculators!
This project is an excellent first handwiring project due to the small matrix size and ease of access into the bottom case
This firmware is based on that of the Minivan 40% keyboard because I am new to QMK and not quite ready to start from scratch yet.
    A huge thanks to them for that help!
    * The fourbytwelve framework is built on the Minivan QMK firmware

Example flash:
qmk flash -kb critikeeb/pieeightfour -km default

There is some explanation on how to assemble the case in the folder with the STLs, but it requires heat-set inserts and matching screws. The MCU I chose is the Raspberry Pi Pico because it is cheap ($4 from Seeed and free shipping!!!) and retains enough GPIO pins to be comfortable. It would be possible to add OLEDs, a rotary encoder, etc in the future.
There are also some notches in the top and bottom case for a snap-on cover, but I haven't designed that yet. The idea was to have a device that one could toss in a backpack without worrying, but it turned out taller than I had pictured and I'm not sure I want to carry around a brick in my bag. It should fit nicely in a soft keyboard case, though!
I'm not happy with the fimrware yet. I don't have all the keys assigned and tap dance doesn't work, but this is a very user-centric device ... I will be configuring mine for writing mathematical equations in Google Docs and writing code in MATLAB, but there is a lot one can do with this! I will also attempt to add an ARTSEYIO layer using combos but I'm not sure the Pico will have enough storage for that.


- Critikeeb
