Hacking The Keyboard
====================

## 1. The Hardware

Before we begin, there are a few oddities and details that I should explain.

1. These instructions are for hacking a Filco Minila. The revision that I am
using is `Matrix Ver1.0 2012/10/17`. These instructions may be compatible with
other revisions, however I cannot promise anything as I don't have the hardware
to check. It should become apparent quite early if your revision is different.
If you notice no differences in the switch-to-circuit-board-relationship, then
you'll probably be pretty right.

1. I'm going to refer to the keys, not by the label that is written on them, but
by the position within the [keymap](../keymap_common.h) that they are placed.
To start with, what is important is to recognise that the key exists. Their
function is flexible and for the moment, irrelevant.

          K00, K01, K02, K03, K04, K05, K06, K07, K08, K09, K0A, K0B, K0C, K0D, K0E,  
          K10,  K11, K12, K13, K14, K15, K16, K17, K18, K19, K1A, K1B, K1C,   K1D,  
          K20,   K21, K22, K23, K24, K25, K26, K27, K28, K29, K2A, K2B,   K2C,  
          K30,    K31, K32, K33, K34, K35, K36, K37, K38, K39, K3A,        K3B,  
          K40, K41, K42, K43,       K44,             K45,             K4C, K4D, K4E

1. Inspite the pins on each of the keys being name Cn and Rn, that does not mean
that they are the rows and columns. In fact, it's actually the other way
around. I needed to reverse this behaviour due to incorrect polarity coming
from the Teensy which prevented the signal to pass the diode on the Minila
circuit board.

1. I have removed some keys from my keyboard. There are a total of 63 instead
of the standard 67 of the Filco Minila. The keys that have been removed are
`RIGHT_ALT`, `RIGHT_WIN`, `RIGHT_SHIFT` and `RIGHT_APP`.

### 1.1 Switch to circuit board relationship.

Here we are mapping where on the circuit board each of the switches connect.
I've broken each row (in the physical sense) of keys into their own tables to make it easier to
read later on.

| Key | Column | Row    |
|-----|--------|--------|
| K00 | R3     | C1     |
| K01 | R7     | C1     |
| K02 | R7     | C2     |
| K03 | R7     | C3     |
| K04 | R7     | C4     |
| K05 | R6     | C4     |
| K06 | R6     | C5     |
| K07 | R7     | C5     |
| K08 | R7     | C6     |
| K09 | R7     | C7     |
| K0A | R7     | C8     |
| K0B | R6     | C8     |
| K0C | R6     | C6     |
| K0D | R6     | C1     |
| K0E | R1     | C10    |
                        
| Key | Column | Row    |
|-----|--------|--------|
| K10 | R1     | C1     |
| K11 | R0     | C1     |
| K12 | R0     | C2     |
| K13 | R0     | C3     |
| K14 | R0     | C4     |
| K15 | R1     | C4     |
| K16 | R1     | C5     |
| K17 | R0     | C5     |
| K18 | R0     | C6     |
| K19 | R0     | C7     |
| K1A | R0     | C8     |
| K1B | R1     | C8     |
| K1C | R1     | C6     |
| K1D | R2     | C10    |
                        
| Key | Column | Row    |
|-----|--------|--------|
| K20 | R1     | C2     |
| K21 | R2     | C1     |
| K22 | R2     | C2     |
| K23 | R2     | C3     |
| K24 | R2     | C4     |
| K25 | R3     | C4     |
| K26 | R3     | C5     |
| K27 | R2     | C5     |
| K28 | R2     | C6     |
| K29 | R2     | C7     |
| K2A | R2     | C8     |
| K2B | R3     | C8     |
| K2C | R4     | C10    |
                        
| Key | Column | Row    |
|-----|--------|--------|
| K30 | R1     | C15    |
| K31 | R4     | C1     |
| K32 | R4     | C2     |
| K33 | R4     | C3     |
| K34 | R4     | C4     |
| K35 | R5     | C4     |
| K36 | R5     | C5     |
| K37 | R4     | C5     |
| K38 | R4     | C6     |
| K39 | R4     | C7     |
| K3A | R5     | C8     |
| K3B | R3     | C14    |
                        
| Key | Column | Row    |
|-----|--------|--------|
| K40 | R6     | C0     |
| K41 | R1     | OC13   |
| K42 | R3     | C9     |
| K43 | R2     | C9     |
| K44 | R3     | C11    |
| K45 | R0     | C9     |
| K4C | R5     | C14    |
| K4D | R5     | C11    |
| K4E | R5     | C12    |

### 1.1 Original row/column matrix

This is the original matrix. It is seven rows and fifteen columns. As it is, that's going to take 24 pins.

|      |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
|------|-----|-----|-----|-----|-----|-----|-----|-----|
|**0** |     |     |     |     |     |     | K40 |     |
|**1** | K11 | K10 | K21 | K00 | K31 |     | K0D | K01 |
|**2** | K12 | K20 | K22 |     | K32 |     |     | K02 |
|**3** | K13 |     | K23 |     | K33 |     |     | K03 |
|**4** | K14 | K15 | K24 | K25 | K34 | K35 | K05 | K04 |
|**5** | K17 | K16 | K27 | K26 | K37 | K36 | K06 | K07 |
|**6** | K18 | K1C | K28 |     | K38 |     | K0C | K08 |
|**7** | K19 |     | K29 |     | K39 |     |     | K09 |
|**8** | K1A | K1B | K2A | K2B |     | K3A | K0B | K0A |
|**9** | K45 |     | K43 | K42 |     |     |     |     |
|**10**|     | K0E | K1D |     | K2C |     |     |     |
|**11**|     |     |     | K44 |     | K4D |     |     |
|**12**|     |     |     |     |     | K4E |     |     |
|**13**|     | K41 |     |     |     |     |     |     |
|**14**|     |     |     | K3B |     | K4C |     |     |
|**15**|     | K30 |     |     |     |     |     |     |

### 1.2 Compressed row/column matrix

The Teensy 2 probably has enough pins for each of the rows and columns but
after I add the status LEDs it's going to be really close. I'd rather not
chance it so I'll compress the matrix down so they'll be some extra pins later
if I need them. There are plenty of holes in the matrix and there are some
pretty obvious things that can be done to reduce the number of needed pins so
it'll be a good thing to do that now.

The idea is that you can merge two rows together, so long as there are no
clashing switches. All of the C pins on the circuit board are connected. If you
put your multimeter two of the C1 pins for example, you will find zero
resistance. Unlink the R pins, there are no resistors or diodes going on in
there, so all you need to do is short the connections together.

This is what the compressed matrix looks like.

|            |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
|------------|-----|-----|-----|-----|-----|-----|-----|-----|
|**1/12**    | K11 | K10 | K21 | K00 | K31 | K4E | K0D | K01 |
|**0/2/11**  | K12 | K20 | K22 | K44 | K32 | K4D | K40 | K02 |
|**3/13/14** | K13 | K41 | K23 | K3B | K33 | K4C |     | K03 |
|**4**       | K14 | K15 | K24 | K25 | K34 | K35 | K05 | K04 |
|**5**       | K17 | K16 | K27 | K26 | K37 | K36 | K06 | K07 |
|**6**       | K18 | K1C | K28 |     | K38 |     | K0C | K08 |
|**7/15**    | K19 | K30 | K29 |     | K39 |     |     | K09 |
|**8**       | K1A | K1B | K2A | K2B |     | K3A | K0B | K0A |
|**9**       | K45 |     | K43 | K42 |     |     |     |     |
|**10**      |     | K0E | K1D |     | K2C |     |     |     |

Now it's time to get out the soldering iron and physically connect those rows
up. So start by finding a C1 and a C12 on the circuit board and short them out.
Then continue for the rest.

From now on, I'll refer to the rows like this.

|      |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |
|------|-----|-----|-----|-----|-----|-----|-----|-----|
|**0** | K11 | K10 | K21 | K00 | K31 | K4E | K0D | K01 |
|**1** | K12 | K20 | K22 | K44 | K32 | K4D | K40 | K02 |
|**2** | K13 | K41 | K23 | K3B | K33 | K4C |     | K03 |
|**3** | K14 | K15 | K24 | K25 | K34 | K35 | K05 | K04 |
|**4** | K17 | K16 | K27 | K26 | K37 | K36 | K06 | K07 |
|**5** | K18 | K1C | K28 |     | K38 |     | K0C | K08 |
|**6** | K19 | K30 | K29 |     | K39 |     |     | K09 |
|**7** | K1A | K1B | K2A | K2B |     | K3A | K0B | K0A |
|**8** | K45 |     | K43 | K42 |     |     |     |     |
|**9** |     | K0E | K1D |     | K2C |     |     |     |

### 1.3 Patching up to the original circuit board.

Finding the connection points for the rows is pretty easy. Find a convenient
point that is labeled with what you are looking for and solder a wire to it.
The columns on the other hand... Well, that's a bit harder.

For each of the switches there is a diode. You need to make sure that you take
your on the other side of it. I found testing with a multimeter to be a bit
difficult but managed by using the following process:

1. Find a switch.
1. Find the next component that the switch is connected to. Do this by checking
the surrounding unlabeled points for a zero resistance.
1. Finding the other leg of that component should be quite obvious. Just look
for another point at right angles to the first point that has zero resistance
back to one of the pins of the original header.
1. Your connection point can be the pin of the original header, or any point on
the board that is connected to that header, including the leg of the component
you just found.

To help, here is the pinout of the original header.

| 28/27 | 26/25 | 24/23 | 22/21 | 20/19 | 18/17 | 16/15 | 14/13 | 12/11 | 10/09 | 08/07 | 06/05 | 04/03 | 02/01 |
|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|-------|
| GND   | C12   | C11   | C10   | C9    | C8    | C7    | C6    | C5    | C4    | C3    | C2    | C1    | C0    |
| OC13  | LED1  | LED2  | +5v   | C15   | C14   | R7    | R6    | R5    | R4    | R3    | R2    | R1    | R0    |

Once that's all done, all that's left is soldering up some leads to each of
your connection points.

I've connected my board to some connectors which will plug straight into my
breadboard. The connectors got like this.

Pin | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
----|---|---|---|---|---|---|---|---|
Row | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |

Pin | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |
----|---|---|---|---|---|---|---|---|---|---|
Col | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 |

### 1.4 Connecting to the Teensy.

Now that all the prep work is done, this is easy...  The Teensy is in the
middle. The keyboard's columns and rows are on the edges.

| Col |     |     | |     |     | Row |
|-----|-----|-----|-|-----|-----|-----|
| 0   | PB0 |     | |     | PF0 | 0   |
| 1   | PB1 |     | |     | PF1 | 1   |
| 2   | PB2 |     | |     | PF4 | 2   |
| 3   | PB3 |     | |     | PF5 | 3   |
| 4   | PB7 |     | |     | PF6 | 4   |
| 5   | PD0 |     | |     | PF7 | 5   |
| 6   | PD1 |     | |     | PB6 | 6   |
| 7   | PD2 |     | |     | PB5 | 7   |
| 8   | PD3 |     | |     | PB4 | 8   |
|     | PC6 |     | |     | PD7 | 9   |
|     | PC7 | PD5 | | PD4 | PD6 | 10  |

As you can see, there are only four pins left. It's a good thing that we
compressed the matrix before.

## 2.0 The firmware.

TODO

### 2.1 Setting the Teensy Pins.

See [matrix.c](../matrix.c).

### 2.2 Assigning Teensy pins to the matrix.

See [keymap_common.h](../keymap_common.h).

### 2.2 Assigning keys to the buttons

There is a default set of key assignments in the repo. You can use those
assignments if you like, but I'm going to describe how it works so that you can
modify it to your own liking.

#### 2.2.1 The default keymap

The default keymap is the layer that is used when there is no layer switching
going on. 

See [keymap_plain.c](../keymap_plain.c).



### 2.3 Building the layers

#### 2.3.1 Function layer

#### 2.3.2 Mouse layer

#### 2.3.3 Conveniences

### 2.4 Configuring the LEDs
