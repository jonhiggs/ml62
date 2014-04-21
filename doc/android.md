# The Android Experiment

last updated 21/04/14

## Overview

I really like the native apps in Android. I figured that if I could get a good
ssh client to connect to an EC2 instance, it may make a suitable laptop
replacement.

Compared to my Macbook Pro, I get a much nicer keyboard and screen in a more
portable package.

This document describes the pros and cons of using such a system and whether
its worthy replacement for me.


## Hardware

- Nexus 7 tablet.
- ML62 keyboard via OTG cable. 
- Apple Magic Trackpad via Bluetooth.
- Amazon EC2 instance running Debian as a real Linux machine.


## Software

### Android OS

Pro:  

- Has some very nice apps. Often nicer than desktop versions. For instance
  Pocket and Press.
- Multitouch on Magic Touchpad works.

Con:

- Limited keyboard support
- I wish I could use a three-finger left swipe to simulate the back button.
- I wish I could use a four-finger up swipe to show open apps.
- The cursor when using a trackpad is distracting when swiping.
- Alt-Tab doesn't go to the next app. It will show you a list of running apps
  with your current app initially selected. To go to the last app you need to
  press Alt-Tab, Tab.


### Chrome Browser

Pro:

- It's a nice browser

Con:

- ctrl-w does not delete a word, it closes a tab.
- I loose my plugin support for navigating with the keyboard.


### JuiceSSH

Pro:

- Has good tmux support.
- Supports 256 colours.

Con:

- Does not support immersive fullscreen mode.
- I cannot find a way to use custom colors (although it may be possible). The
  dark blue is a bit dark and can be difficult to read.
- Cannot use the keyboard to paste from the system keyboard.

### Android Terminal

Pro:

- It works.

Con:

- Tmux is all messed up.


### DroidMPD

Pro:

- It will allow me to stream music from MPD server on EC2 instance.


### Xposed

Pro:

- Allows system-wide immersive-mode solving the problem with JuiceSSH

Con:

- Immersive mode is not nice everywhere. It makes it difficult to get to the
  home screen.


## Using an EC2 instance remotely.

### Software

- mutt
- irssi
- vim
- tmux
- tig


Pro:

- I have all my command line tools.


Con:

- Cannot use Vim as a server to send files to a remote tab. It requires X to be
  running.
- Syncronizing clipboards is nasty. You have a separate clipboard for tmux, vim
  and bash.


## Things I'd like but currently do not have.

- Console markdown viewer (something must exist or I could write one).
- An app that will pipe input into the Android clipboard (clipbrd will work).
- Notifications (wall might work)
- Command line password manager (1passwd-cli might work)
- Command line pinboard client (pinboard-cli might work)
- A more stable mount for the tablet so it could be used in places like on a
  train.
- Longer battery life (can be fixed by putting a battery in the keyboard
  chassis).
- Charging tablet while using OTG cable (can be fixed by hacking the cable).


## Summary

Pro

- Nice native apps.
- A very nice keyboard.
- A very nice screen, although it's a little small, that can be upgraded to a
  Nexus 10.
- A laptop that is smaller than my Macbook Pro.
- EC2 instance is always the same regardless of how or where you connect to it.
- I can stream my music via MPD wherever I am, including on my phone.
- I could use chromecast to send my display to an external monitor which could
  mean I don't even have to carry my tablet if I didn't want to. I could use my
  phone for the same job instead.
- Can use Touchscreen or Touchpad.

Con

- You have to also pay for an EC2 instance.
- Pretty bad keyboard control outside of terminal.
- A lot of wasted screen space, but that could be resolved with a bigger
  tablet or an external screen via chromecast.
- I loose access to desktop apps.

If I could get 90% of my daily apps running nice in tmux then this system could
be manageable.
