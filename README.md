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

## 2. Hardware
- Teensy 2.0
- Filco Minila
- Intel NUC motherboard


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
