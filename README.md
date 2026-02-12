linux-cpu-temp-module

A small Linux kernel module that reads the CPU temperature and prints system information to the kernel log together with an ASCII "fish".

# Run

1.Place the 2 files (Makefile, cputemp.c) on your device.

2.Now run `make` in the same folder where you placed the files.

If you get an error, you probably have to install the build essentials with `sudo apt install -y build-essential`.

3.After that, you should have a bunch of files in that folder, one of them called cputemp.ko (check with `ls`).

4.Now you can run `sudo insmod cputemp.ko`. The kernel module will be loaded into your kernel.

5.Check the output with `dmesg | tail`. You should see the "fish" and some other OS Info!

6.To remove the module from the kernel, run `sudo rmmod cputemp.ko`.

Have fun with the project!

# Help

If you get the error
"insmod: ERROR: could not insert module cputemp.ko: File exists"
then the reason is that you haven't removed the module from the kernel yet. See point 6.

# Future development

I wrote this program as training for my own system information command, similar to fastfetch or neofetch, which I want to develop in the future.

See you there!
