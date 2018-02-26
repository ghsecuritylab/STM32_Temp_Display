7-Segment Display Supplemental Documentation
============================================

**Note:** When you give the address to the ST HAL, you want to shift
the address up by one.  So you'll end up passing `0xe0` instead of
`0x70`.

- [Adafruit documentation page](https://learn.adafruit.com/adafruit-7-segment-led-featherwings/overview)


Background
----------

7-Segment displays are essentially matrices of LEDs.  In order to show
a digit, you drop the cathode for that digit and turn on all of the
anodes that need turning on to display the chosen glyph.  You do this
for a short time, raise the cathode, then go to the next digit and do
the same thing.  If you go through all of the digits quickly enough
it'll give the illusion that the digits are on at the same time.

In this implementation, the HT16K33 component will take care of
pulsing the right LEDs at the right time.  The only thing you have to
do is tell it what you want to display.  You do this by mapping bits
to LEDs.

Segments
--------

The FeatherWing schematic labels each of the LEDs per common cathode
using the letters `A` through `G`, and `DP` for the decimal-point.
These letters correspond to the segments as in the following diagram:


         A
        ----
      |      |
    F |      | B
	  |  G   |
	    ----
      |      |
    E |      | C    __
	  |  D   |     |__| dp
	    ----


[Wikipedia][1] has a good treatment of 7-Segment displays, including a
handy table mapping some glyphs to hexadecimal values (you're going to
want the `gfedcba` column).

[1]: https://en.wikipedia.org/wiki/Seven-segment_display

In this implementation, ROW0 corresponds to A, ROW1 to B, ..., ROW6 to
G, and ROW7 to DP.

The documentation isn't very clear on how to write to the "display
memory".  You'll want to refer to the section titled _Display Memory
-- RAM Structure_ on page 13.  What this table is trying to show is
the address you write to in order to control certain output (`ROW`)
pins.  Since there are only 8 segments (7 + plus the decimal point)
ROWS 8-15 are not used.

Here's a different presentation of the relevant addresses for the digits:


    | Digit | COM  | Address |
    |-------|------|---------|
    | 0     | COM0 | 0x0     |
    | 1     | COM1 | 0x2     |
    | `:`   | COM2 | 0x4     |
    | 2     | COM3 | 0x6     |
    | 3     | COM4 | 0x8     |
    |       |      |         |

*Note* that the clock separator `:` is on `COM2`. It is turned on
using ROW1 (equivalent to `B` for the 7-segment digits).  You don't
need to use it for this project.

To write to the display memory, you need to perform an I2C write of
two bytes. The first byte is the command (`0x0X` where `X` is the
address from the table above) and the second byte is the bits that
correspond to the segments.  For example, in order to display the
character `E` on the third digit, you would write `0x06 0x79` over I2C
to the slave at address `0x70`.  The first byte `0x06` is the command
for writing data to the memory for COM3, and `0x79` is the data that
corresponds to turning on segments `A`, `D`, `E`, `F`, and `G`.


    0x79    =   1 1 1 1 0 0 1
	            G F E D     A
