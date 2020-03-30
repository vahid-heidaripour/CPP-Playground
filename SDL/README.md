# This is a toy program to learn how to work with SDL

First make sure that you have SDL installed on your machine.
Run this command to check if it's installed properly:
```
pkg-config --list-all | grep -i sdl
```
If it's not installed on your machine do like this:
```
sudo apt update
sudo apt full-upgrade
sudo apt autoremove
sudo apt install pkg-config
sudp apt install libsdl2-dev
pkg-config --list-all | grep -i sdl
```
To run the code:
```
make clean
make
./test
```


