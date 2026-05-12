# minimal_ch32v003_toolchain
just a REALLY barebones linker , startup assembly , register map and utils for ch32v003
i will update the register_map.h and utils.h with more registers and functions respectively 
don't expect something extraordinary from this , you will be SORELY disappointed :)
for uploading the code please use minichlink by cnlohr
https://github.com/cnlohr/ch32fun/tree/master/minichlink
for programming the chip use the command 
sudo ./minichlink -w firmware.bin 0x08000000
