# drippleMini OS

A 32 bit operating system made from scratch, using Assembly & C-lang to create kernels and other stuff. 
**Current version:** `1.0.0-public`

# Running Guide
| :exclamation:  BOOT INFORMATION ALERT!   |
|------------------------------------------|

## THIS HAS NEVER BEEN TESTED ON A DUAL BOOT OR AN ACTUAL BOOT! THIS HAS ONLY BEEN TESTED ON QEMU SO RUNNING THIS IS YOUR RESPONSIBILITY
Moving on to run this, make sure you have installed **[qemu](https://www.qemu.org/)** to run this image file and **git** to download this repository. Once that has been installed, you can run the following file on Linux & if you are not on Linux or MacOS, you can install WSL on Windows. For other operating systems like FreeBSD, it has never been tried on.

```
$ git clone https://github.com/BaseProgrammer/drippleMini   # Download repo
$ cd drippleMini/                                           # Change directory to repo
$ cat bin/bootsect.bin bin/kernel.bin > drippleos.bin       # Merge into one file
$ qemu-system-i386 -fda drippleos.bin                       # Run it
```

Additionally if the `qemu-system-i386` command doesn't work, the presumably alternative way to solve this is by just running `qemu -fda drippleos.bin`

### What's New?

- Cleared out the boot-in logs
- Cleaner
- A bit slower to boot into the OS
- Updated drip-kernel
- Added VGA suport with ports/screen files

### What's coming next?
- Video scroll
- Shell
- Text output

### How can I create my own OS?
One of the main GitHub repositories that helped me quite a lot is the [os-tutorial](https://github.com/cfenollosa/os-tutorial/) one, made by [cfenollosa](https://github.com/cfenollosa). It quite briefly explains what each commands are, in Assembly and how to use them; I also recommend learning the basics of Assembly.