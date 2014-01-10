ML62 Portable Computer
======================

Taking a Filco Minila keyboard and turning it into a portable Linux
Keyboard/Computer.

The goals I have for this project are as follows:

- Real Unix Layout using Vi and Emacs shortcuts.
- Mouse Control from the keyboard.
- Use a layout that suits a Linux system nicely.
- Install a full powered computer within the keyboard chassis.
- Keyboard should be able to be used as a regular keyboard, disconnecting the
  interal computer.
- Small enough to fit into my small backpack (Eagle Industries - Yote).
- Support multiple displays.
- Support an SSD and a spinning disk.

Some things that are initially true, but may change in the future.

- No screen.
- No batteries.
- Only support Linux.

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

## 1. Overview

### Goals
## 2. Hardware
- Teensy 2.0
- Filco Minila
- Intel NUC motherboard

### 2.1 Keyboard Pins
The keyboard has 28 pins which it interfaces with the original controller. The
pinout goes like this.

| PIN | 28 | 26 | 24 | 22 | 20 | 18 | 16| 14| 12| 10 | 8 | 6 | 4 | 2 |
|-----|----|----|----|----|----|----|---|---|---|----|---|---|---|---|
| PIN | 27 | 25 | 23 | 21 | 19 | 17 | 15| 13| 11|  9 | 7 | 5 | 3 | 1 |
|     |GND | C12| C11| C10| C9 | C8 | C7| C6| C5| C4 | C3| C2| C1| C0|
|     |OC13| L1 | L2 | +5v| C15| C14| R7| R6| R5| R4 | R3| R2| R1| R0|

`GND` connects to USB Shield  
`L1` is Scroll Lock LED  
`L2` is Caps Lock LED

### 2.2 Key to Row/Column Relationship
#### 2.2.1 Ignored Keys
I've removed some keys from my keyboard so they have been also removed from
this table. The keys I've removed are:

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
|-----|------------|------------|-----------|----|----|----|---------------|-----|---------------|---------|-----------|-------------|--------------|------|--------------|-----------|
| R0  |            | Q          | W         | E  | R  | U  | I             | O   | P             |         |           |             |              |      |              |           |
| R1  |            | TAB        | CONTROL_L |    | T  | Y  | SLASH         |     | BRACKET_LEFT  |         | BACKQUOTE |             |              | ALT  |              | SHIFT_L   |
| R2  |            | A          | S         | D  | F  | J  | K             | L   | SEMICOLON     | FN      | DELETE    |             |              |      | CURSOR_UP    |           |
| R3  |            | ESCAPE     |           |    | G  | H  |               |     | QUOTE         | COMMAND |           | SPACE       |              |      |              |           |
| R4  |            | Z          | X         | C  | V  | M  | COMMA         | DOT |               |         | RETURN    |             |              |      |              |           |
| R5  |            |            |           |    | B  | N  |               |     | FORWARD_SLASH |         |           | CURSOR_DOWN | CURSOR_RIGHT |      | CURSOR_LEFT  |           |
| R6  | CAPSLOCK   |            |           |    | 5  | 6  | EQUAL         |     | MINUS         |         |           |             |              |      |              |           |
| R7  |            | 1          | 2         | 3  | 4  | 7  | 8             | 9   | 0             |         |           |             |              |      |              |           |

#### 2.2.3 New Layout

| New    | C0       | C1        | C2 | C3 | C4 | C5            | C6        | C7            | C8             | C9          |
| Old    | C0 + C1  | C2        | C3 | C4 | C5 | C6 + C14      | C7 + OC13 | C8            | C9 + C12 + C15 | C10 + C11   |
|--------|----------|-----------|----|----|----|---------------|-----------|---------------|----------------|-------------|
| **R0** | Q        | W         | E  | R  | U  | I             | O         | P             |                |             |
| **R1** | TAB      | CONTROL_L |    | T  | Y  | SLASH         | ALT       | BRACKET_LEFT  | SHIFT_L        | BACKQUOTE   |
| **R2** | A        | S         | D  | F  | J  | K             | L         | SEMICOLON     | FN             | DELETE      |
| **R3** | ESCAPE   |           |    | G  | H  |               |           | QUOTE         | COMMAND        | SPACE       |
| **R4** | Z        | X         | C  | V  | M  | COMMA         | DOT       |               |                | RETURN      |
| **R5** |          |           |    | B  | N  | CURSOR_LEFT   |           | FORWARD_SLASH | CURSOR_RIGHT   | CURSOR_DOWN |
| **R6** | CAPSLOCK |           |    | 5  | 6  | EQUAL         |           | MINUS         |                |             |
| **R7** | 1        | 2         | 3  | 4  | 7  | 8             | 9         | 0             |                |             |

      R0      R1      R2      R3      R4      R5      R6      R7
C0    Q       TAB     A       ESC     Z               CAPS    1
C1    W       CTRL    S               X                       2
C2    E               D               C       B               3
C3    R       T       F       G       V       N       5       4
C4    U       Y       J       H       M       LEFT    6       7
C5    I       \       K               ,               =       8
C6    O       ALT     L               .       /               9
C7    P       [       ;       '               RIGHT   -       0
C8            SHIFT   FN      CMD             DOWN
C9            `       DEL     SPACE   ENTER


### 2.3 The Teensy Controller
I'm using a Teensy 2.0 dev board.

| Matrix Pos | Teensy Pin | Teensy Pin | Matrix Pos | 
| ---------- | ---------- | ---------- | ---------- | 
|            | GND        | Vcc        |            | 
| R0         | PB0        | PF0        | C0         | 
| R1         | PB1        | PF1        | C1         | 
| R2         | PB2        | PF4        | C2         | 
| R3         | PB3        | PF5        | C3         | 
| R4         | PD0        | PF6        | C4         | 
| R5         | PD1        | PF7        | C5         | 
| R6         | PD2        | PB6        | C6         | 
| R7         | PD3        | PB5        | C7         | 
|            |            | PB4        | C8         | 
|            |            | PD7        | C9         | 

| Keyboard Pin | Matrix Row | Teensy PIN | Teensy PIN | Keyboard Pin |
| ------------ | ---------- | ---------- | ---------- | ------------ |
| 28           |            | GND        | Vin        | 21           |
| 1            | R0         |            |            |              |
| 3            |            |            |            |              |
| 5            |            |            |            |  2    4      |
| 7            |            |            |            |  6           |
| 9            |            |            |            |  8           |
| 11           |            |            |            |  10          |
| 13           |            |            |            |  12          |
| 15           |            |            |            |  14  17      |
|              |            |            |            |  16  27      |
|              |            |            |            |  18          |
|              |            |            |            |  19  20  26  |
| 23           |            |            |            |  22  24      |
| 25           |            |            |            |              |




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
