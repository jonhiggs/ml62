Keymap
======

## Modifier Keys

**Command:** 
Reserved for OS X shortcuts.

**Control:**
Almost untouchable. Needed for Unix shortcuts.

**Option / Alt:**
There are a few Unix shortcuts here. Mostly free.

**Shift:**
A good second modifier.

**Fn##:**
User-defined functions.


## Important System Shortcuts

| Combo                     | Function                          | Tool        |
| ------------------------- | --------------------------------- | ----------- |
| alt-b                     | Move back one word                | unix        |
| alt-f                     | Move forward one word             | unix        |
| ctrl-a                    | Default key binding               | screen      |
| ctrl-a                    | Move to start of line             | unix,osx    |
| ctrl-b                    | Move back one character           | unix        |
| ctrl-c                    | Break                             | unix        |
| ctrl-d                    | Forward delete                    | unix,osx    |
| ctrl-d                    | Page down                         | less,vim    |
| ctrl-d                    | Stop reading stdin                | unix        |
| ctrl-e                    | Move to end of line               | unix,osx    |
| ctrl-g                    | Show file info                    | less,vim    |
| ctrl-h                    | Delete                            | unix,osx    |
| ctrl-l                    | Redraw console                    | unix        |
| ctrl-m                    | Enter                             | unix        |
| ctrl-n                    | Next line                         | unix,osx,less,vim    |
| ctrl-p                    | Previous line                     | unix,osx,less,vim    |
| ctrl-q                    | Continue drawing console          | unix        |
| ctrl-r                    | Reverse search                    | unix        |
| ctrl-s                    | Stop drawing console              | unix        |
| ctrl-t                    | Swap this and the last character  | unix,osx    |
| ctrl-u                    | Delete line                       | unix        |
| ctrl-u                    | Page up                           | less,vim    |
| ctrl-w                    | Delete last word                  | unix        |
| ctrl-y                    | Paste yanked text                 | unix        |
| ctrl-z                    | Background process                | unix        |


* less == less
* osx  == OS X Mavericks GUI
* unix == Console (iTerm2)
* vim  == MacVim


## Default layer

| Combo                     | Now Sends        | Reason                       |
| ------------------------- | ---------------- | ---------------------------- |
| shift-esc                 | shift-grv        | maintaining position of ~    |

### Control Replacement Layer

**Function Key:** Fn0  
**Key Position:** Capslock

| Combo        | Function               | Sends        | Originates | Clashes With        | Fixes    | 
| ------------ | ---------------------- | ------------ | ---------- | ------------------- | -------- |   
| fn1-a        | Start of line          | home         | unix       | vim (increment),screen | chrome   |  
| fn1-b        | Move to previous letter| ctrl-b       | unix       |                     |          |
| fn1-c        | Break                  | ctrl-c       | unix       |                     |          |
| fn1-d        | Page down              | page-down    | less,vim   | unix (forward delete)|         |
| fn1-e        | Move to end of line    | end          | unix       |                     | chrome   |  
| fn1-f        | Move to next letter    | ctrl-f       | unix       |                     |          |
| fn1-g        | Show file info         | ctrl-g       | less,vim   |                     |          |
| fn1-h        | Delete                 | backspace    | unix       |                     | various  |   
| fn1-l        | Redraw console         | ctrl-l       | unix       |                     |          |
| fn1-n        | Next line              | ctrl-n       | unix       |                     |          |
| fn1-p        | Previous line          | ctrl-p       | unix       |                     |          |
| fn1-r        | Reverse search         | ctrl-r       | unix       |                     |          |
| fn1-t        | Swap this and last char| ctrl-r       | unix       |                     |          |
| fn1-u        | Page up                | page-up      | unix       | unix (paste)        |          |
| fn1-w        | Delete word            | ctrl-w       | unix       |                     |          |
| fn1-y        | Paste yanked line      | ctrl-y       | unix       |                     |          |
| ctrl-z       | Background process     | ctrl-z       | unix       |                     |          |
| fn1-bkspc    | Forward delete         | delete       | ????       |                     |          | 
| fn1-space    | Ctrl-Space does nothing| space        | n/a        |                     | osx      |


### Vim Movement Layer

**Function Key:** Fn2  
**Key Position:** Left of Space

| Combo        | Sends         | Originates |
| ------------ | ------------- | ---------- |
| fn2-h        | left          | vim        |
| fn2-j        | down          | vim        |
| fn2-k        | up            | vim        |
| fn2-l        | right         | vim        |
| fn2-space    | command-space | osx        |

- f## keys

### Special Functions Layer

**Function Key:** Fn2  
**Key Position:** Left of Space

- media keys
- capslock
- fn2 lock
