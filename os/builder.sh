#!/bin/sh

# if we don't have a file, start at zero
if [ ! -f "/tmp/value.dat" ] ; then
  version=0

# otherwise read the value from the file
else
  version=`cat /tmp/value.dat`
fi

# increment the value
version=`expr ${version} + 1`

# show it to the user
echo "value: ${version}"

# and save it for next time
echo "${version}" > /tmp/value.dat

cd build
nasm -f elf32 ../kernel.asm -o kasm.o
gcc -m32 -c ../kernel.c -o kc.o
ld -m elf_i386 -T link.ld -o ./versions/kernel$version.bin kasm.o kc.o
qemu-system-i386 -kernel ./versions/kernel$version.bin