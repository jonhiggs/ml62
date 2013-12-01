ML62 keyboard firmware
======================
Taking a Filco Minila keyboard and turning it into a real 60% Unix keyboard.

This is still a work in progress, so I wouldn't recommend you use it yet. If
you want to anyway, then add this repo as a submodule of
https://github.com/tmk/tmk_keyboard.git by doing this:

```Shell
        git clone https://github.com/tmk/tmk_keyboard.git /path/to/repo
        cd /path/to/repo
        git submodule add https://github.com/jonhiggs/ml62.git keyboards/ml62
        git submodule init
        git submodule update
```

## Feature List
- Real Unix Layout using Vi and Emacs shortcuts.
- Mouse Control.
- OS X Special Keys.


## 2. Hardware

### 2.1 Keyboard Pins
The keyboard has 28 pins which it interfaces with the original controller. The
pinout goes like this.

| PIN | 28 | 26 | 24 | 22 | 20 | 18 | 16| 14| 12| 10 | 8 | 6 | 4 | 2 |
| PIN | 27 | 25 | 23 | 21 | 19 | 17 | 15| 13| 11|  9 | 7 | 5 | 3 | 1 |
|-----|----|----|----|----|----|----|---|---|---|----|---|---|---|---|
|     |GND | C12| C11| C10| C9 | C8 | C7| C6| C5| C4 | C3| C2| C1| C0|
|     |OC13| L1 | L2 | 5v | C15| C14| R7| R6| R5| R4 | R3| R2| R1| R0|

`GND` connects to USB Shield  
`L1` is Scroll Lock LED  
`L2` is Caps Lock LED

### 2.2 Key to Row/Column Relationship
#### 2.2.1 Ignored Keys
I've removed some keys from my keyboard so they have been also removed from
this table. The keys I've removed are:

- Right Function
- Right App
- Right Command
- Right Shift
- Forward Delete

#### 2.2.2 Renamed Keys
I'm building my keyboard initially for a Mac using a Unix layout. Key positions
have been modified to represent the actual labels written on *my* keyboard. The
changes are as follows:

| Original Key | My Key    |
|--------------|-----------|
| ALT_L        | COMMAND   |
| BACKQUOTE    | SLASH     |
| CAPSLOCK     | CONTROL_L |
| CONTROL_L    | FN2       |
| DELETE       | BACKQUOTE |
| SLASH        | DELETE    |
| WIN_L        | ALT_L     |

#### 2.2.3 Original Layout
| Row | C0         | C1         | C2        | C3 | C4 | C5 | C6            | C7  | C8            | C9      | C10       | C11         | C12          | 0C13 | C14          | C15       |
| --- | ---------- | ---------- | --------- | -- | -- | -- | ------------- | --- | ------------- | ------- | --------- | ----------- | ------------ | ---- | ------------ | --------- |
| R0  |            | Q          | W         | E  | R  | U  | I             | O   | P             |         |           |             |              |      |              |           |
| R1  |            | TAB        | CONTROL_L |    | T  | Y  | SLASH         |     | BRACKET_LEFT  |         | BACKQUOTE |             |              | ALT  |              | SHIFT_L   |
| R2  |            | A          | S         | D  | F  | J  | K             | L   | SEMICOLON     | FN      | DELETE    |             |              |      | CURSOR_UP    |           |
| R3  |            | ESCAPE     |           |    | G  | H  |               |     | QUOTE         | COMMAND |           | SPACE       |              |      |              |           |
| R4  |            | Z          | X         | C  | V  | M  | COMMA         | DOT |               |         | RETURN    |             |              |      |              |           |
| R5  |            |            |           |    | B  | N  |               |     | FORWARD_SLASH |         |           | CURSOR_DOWN | CURSOR_RIGHT |      | CURSOR_LEFT  |           |
| R6  | CAPSLOCK   |            |           |    | 5  | 6  | EQUAL         |     | MINUS         |         |           |             |              |      |              |           |
| R7  |            | 1          | 2         | 3  | 4  | 7  | 8             | 9   | 0             |         |           |             |              |      |              |           |

#### 2.2.3 New Layout
| Row    | C0 + C1  | C2        | C3 | C4 | C5 | C6 + C14      | C7 + OC13 | C8            | C9 + C12 + C15 | C10 + C11   |
| ------ | -------- | --------- | -- | -- | -- | ------------- | --------- | ------------- | -------------- | ----------- |
| **R0** | Q        | W         | E  | R  | U  | I             | O         | P             |                |             |
| **R1** | TAB      | CONTROL_L |    | T  | Y  | SLASH         | ALT       | BRACKET_LEFT  | SHIFT_L        | BACKQUOTE   |
| **R2** | A        | S         | D  | F  | J  | K             | L         | SEMICOLON     | FN             | DELETE      |
| **R3** | ESCAPE   |           |    | G  | H  |               |           | QUOTE         | COMMAND        | SPACE       |
| **R4** | Z        | X         | C  | V  | M  | COMMA         | DOT       |               |                | RETURN      |
| **R5** |          |           |    | B  | N  | CURSOR_LEFT   |           | FORWARD_SLASH | CURSOR_RIGHT   | CURSOR_DOWN |
| **R6** | CAPSLOCK |           |    | 5  | 6  | EQUAL         |           | MINUS         |                |             |
| **R7** | 1        | 2         | 3  | 4  | 7  | 8             | 9         | 0             |                |             |


### 2.3 The Teensy Controller
I'm using a Teensy 3.0 dev board.

| Keyboard Pin | Teensy PIN | Teensy PIN | Keyboard Pin |
| ------------ | ---------- | ---------- | ------------ |
| 28           | GND        | Vin        | 21           |
| 1            | 0          | AGND       |              |
| 3            | 1          | 3.3V       |              |
| 5            | 2          | A9         |  2    4      |
| 7            | 3          | A7         |  6           |
| 9            | 4          | A7         |  8           |
| 11           | 5          | A6         |  10          |
| 13           | 6          | A5         |  12          |
| 15           | 7          | A4         |  14  17      |
|              | 8          | A3         |  16  27      |
|              | 9          | A2         |  18          |
|              | 10         | A1         |  19  20  26  |
| 23           | 11         | A0         |  22  24      |
| 25           | 12         | 13         |              |




### 3.0.0


## 3. Software

## Layers
###  Layer 0: Plain Layer
      .-----------------------------------------------------------.
      |Esc|  1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \|  `|
      |-----------------------------------------------------------|
      | Tab |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|Backs|
      |-----------------------------------------------------------|
      | Ctrl |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|  Enter |
      |-----------------------------------------------------------|
      | Shift  |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|    | U|  |
      |-----------------------------------------------------------|
      |  Fn2 | Opt | Cmd | Fn1|    SPACE      |          | L| D| R|
      `-----------------------------------------------------------'

###  Layer 2: Shift - Feel-Good Layar1
      .-----------------------------------------------------------.
      | ~ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
      |-----------------------------------------------------------|
      |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
      |-----------------------------------------------------------|
      |      |   |   |   |   |   |   |   |   |   |   |   |        |
      |-----------------------------------------------------------|
      |        |   |   |   |   |   |   |   |   |   |   |    |  |  |
      |-----------------------------------------------------------|
      |      |     |     |    |               |          |  |  |  |
      `-----------------------------------------------------------'

###  Layer 3: Command - Feel-Good Layar2
      .-----------------------------------------------------------.
      | ⌘`|   |   |   |   |   |   |   |   |   |   |   |   |   |   |
      |-----------------------------------------------------------|
      |     |   |   |   |   |   |   |   |   |   |   |   |   |  ⌘| |
      |-----------------------------------------------------------|
      |      |   |   |   |   |   |   |   |   |   |   |   |        |
      |-----------------------------------------------------------|
      |        |   |   |   |   |   |   |   |   |   |   |    |  |  |
      |-----------------------------------------------------------|
      |      |     |     |    |               |          |  |  |  |
      `-----------------------------------------------------------'

###  Layer 4: Command-Shift - Feel-Good Layar3
      .-----------------------------------------------------------.
      |⌘⇧`|   |   |   |   |   |   |   |   |   |   |   |   |   |   |
      |-----------------------------------------------------------|
      |     |   |   |   |   |   |   |   |   |   |   |   |   |     |
      |-----------------------------------------------------------|
      |      |   |   |   |   |   |   |   |   |   |   |   |        |
      |-----------------------------------------------------------|
      |        |   |   |   |   |   |   |   |   |   |   |    |  |  |
      |-----------------------------------------------------------|
      |      |     |     |    |               |          |  |  |  |
      `-----------------------------------------------------------'

###  Layer 4: Function1 - Vim/Emacs Layer
      .-----------------------------------------------------------.
      |   | F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|F13|F14|
      |-----------------------------------------------------------|
      |     |   |   | En|   |   |   | pU|   |   |   |   |   |     |
      |-----------------------------------------------------------|
      |      |HOM|   | pD|   |   |  L|  D|  U|  R|   |   |        |
      |-----------------------------------------------------------|
      |        |   |   |   |   |   |   |   |   |   |   |    |pU|  |
      |-----------------------------------------------------------|
      |      |     |     |    |               |          |Ho|pD|En|
      `-----------------------------------------------------------'

###  Layer 5: Function2 - Specials Layer
      .-----------------------------------------------------------.
      |   | bd| bu| mc| db|   |   | pt| pp| nt| mt| vd| vu|   |   |
      |-----------------------------------------------------------|
      |     |   |   |   |   |   |   | lC| mC| rC|   |   |   |     |
      |-----------------------------------------------------------|
      |      |   |   |   |   |   | mL| mD| uU| mR|   |   |        |
      |-----------------------------------------------------------|
      |        |   |   |   |   |   |   |   |   |   |   |    |  |  |
      |-----------------------------------------------------------|
      |      |     |     |    |               |          |  |  |  |
      `-----------------------------------------------------------'

- bd: Brightness Down (F14)
- bu: Brightness Up (F15)
- db: Dashboard (F12)
- lC: Left Click
- mC: Middle Click
- mc: Mission Control (Ctrl + Up)
- mt: Mute
- nt: Next Track
- pD: Page Down
- pU: Page Up
- pp: Play/Pause
- pt: Previous Track
- rC: Right Click
- vd: Volume Down
- vu: Volume Up
