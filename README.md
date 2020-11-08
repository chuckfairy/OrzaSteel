# Pedal Steel Guitar Synthesizer

This is a sound application to mimic playing a [pedal steel guitar](https://en.wikipedia.org/wiki/Pedal_steel_guitar). It uses my sound library [liborza](https://github.com/chuckfairy/liborza) and currently supports [JACK](https://jackaudio.org/) as an audio server.

![Main View](https://raw.githubusercontent.com/chuckfairy/OrzaSteel/master/screenshots/orzasteel_20200226.png)

# Features

- Change string notes and number of strings
- Change semitones
- Change pedals and what they modify
- Change number of octaves
- Effects rack supporting [LV2](https://lv2plug.in/) audio plugins.
- Basic square, saw, and sine wave outputs.


# What's to come?

- Manipulation of any audio signal as a note on the guitar
- Custom tonebar image
- Custom colors or image for frets
- Midi input integration to allow to control from another controller


# Usage

- 1-9 string notes
- mouse to move tonebar / raise or lower pitch
- Set characters in pedal editor, but the default is a,b,c and various others for the knee levers modeled after this website https://www.steelguitar.com/tunings.html


# Install


```shell
./tools/install.sh # will load needed packages
```

## Mac specific

```shell
# Install Qt from https://qt.io

# Following installs

# building
brew install cmake

# brew install jack # From http://www.jackosx.com
brew install boost lv2

# lv2 plugins
# brew install mda-lv2
# brew tap david0/homebrew-audio
# brew install --HEAD calf
```


## Building / Cmake Install

```shell
# Make sure to have latest lv2 core

./tools/install.sh; # for git repos and extras

# Also in ./bin/build_*
cd build;
../bin/build_linux.sh; # Or mac
make -j8

#gui, only qt rn
./src/qt/orzabal.qt
```


# Midi

You can connect to the app via midi and play from an outside program or external device. OrzaSteel will connect to **all** midi devices on startup. Controlling it works as follows.

Eventually I plan on being able to configure these, but they hardcoded for now.


## Notes
- *24(C1) - 47(B2)* = String on/off
- *48(C3) - 61(B4)* = Pedal on/off

## Control
- *14* Pitch or tonebar position
- *15* Volume control


# Jack

Starting the app will start jack. I recommnend starting it elsewhere, `./bin/jack_startup.sh` is a sample startup. Midi will need to be enabled.
