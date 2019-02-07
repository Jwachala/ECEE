# Patrick's prelab

## a

It fails at line 98, as that is where it catches if the inizialization fails

## b

### Initialize

This function's job is to 'set things up' for the board. I essentially sets up addresses for things to happen, using nmap to keep things spaced right for the size of the gpio (see man mman)

### Finalize

It undoes initialise. It unmaps what mmap did, and also closes the file where this stuff was being written/read.

### RegisterRead

Reads value of a register. It takes in the base memory address and the actual register's offset from that, and returns the content of the register. This is essentially reading a signal or state.

### RegisterWrite

Functions like RegisterRead, but instead of returning a value it sets taht value to that register. Used to turn on a light, for instance.