birdFountain
=====================================================

### Overview

This was first written as part of an assignment for my undergrad graphics
course. The original project required, for example, creating spheres in
openGL according to an input file and applying one of a small set of
transformations to them.

But it was way too fun to leave it at that.

After finishing the requirements of the assignment, I was
having fun with the project and spent more time on it both before
turning it in and after. For example, I added:

- A woodpecker object that was a composite of other GL objects
- An include directive to allow code re-use in Scene files
- Custom object definitions to allow object re-use in Scenes
- code to parse and execute formulas as a function of time for use in...
- various custom transformations
- improved configure script and Makefile
- cross-platform compilation (has run under FreeBSD, debian, ubuntu, Windows) 

I recently updated the code to compile and run under ubuntu and made
the directory structure a bit more intuitive. A few tweaks to the
configure script and Makefile would likely be necessary to run
under other platforms again.

### Dependencies

This depends on Anonymous1's Linear Algebra Library.

This depends on libglut

### Install

(After Installing Dependencies)

```
./configure
make -j 2
```

### Running examples

From the project root directory:

`sh demo.sh`

