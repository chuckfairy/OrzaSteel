# Meta Synth [Jack](http://jackaudio.org/) App

![Main View](https://raw.githubusercontent.com/chuckfairy/OrzaSteel/master/screenshots/orzasteel_20200226.png)


# Install


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
