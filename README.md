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


# Pi

```shell
sudo apt-get install x11vncserver wiringPi
```


# Jack

Starting the app will start jack. I recommnend starting it elsewhere, `./bin/jack_startup.sh` is a sample startup. Midi will need to be enabled.
