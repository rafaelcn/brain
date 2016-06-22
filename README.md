# Brain
[![Build Status](https://travis-ci.org/luizperes/brain.svg?branch=master)](https://travis-ci.org/luizperes/brain)

A computer language based on Brainfuck.

## Table of Contents

- [About](#about)
- [Current Status](#current-status)
- __How to build Brain__
  - [How to build LLVM (Required)](#how-to-build-llvm)
  - [How to install pre-commit(Optional)](#how-to-install-pre-commit)
  - [How to build Brain and compile/run files](#how-to-build-brain-and-run-files)
- [How it has been built](#how-it-has-been-built)
- [Technical Information](#technical-information)
- [Compiler Options](#compiler-options)
- [Applications for real life](#applications-on-real-life)
- [Help the Project](#help)
- [License](#license)

### About
__Brain__ wants to improve the performance of the Brainfuck programming language and extend it as well, as Brainfuck itself has a lack of data types and does not perform great control over variables, as well as when you want to make libraries and/or functions and when you want to use different models other than characters and small integers.

One of the main ideas of __Brain__ is saving some operations in machine language, creating an instruction optmizer due to the excess of instructions that Brainfuck would generate. Brain aims to implement it by using current technology __(LLVM)__.

In spite of implementing new commands and features, __Brain__ tries to be **completely compatible** with Brainfuck.

### Current Status
Brain is running just like __Brainfuck__ so far, so feel free to use its tag [version 0.5](https://github.com/luizperes/brain/blob/v0.5/README.md)

Obs.: To use __Project Status__ (the "Kanban" below), please visit:```https://github.com/luizperes/status-projects/blob/master/README.md``` and ```http://luizperes.github.io/status-projects/```

| Project Name                        | Status                                    | Technology  | Priority |  Deadline    |
| ----------------------------------- |:-----------------------------------------:| ----------- | :------: |  :--------:  |
| [Brain](#brain)         | ![Progress](http://progressed.io/bar/65)  | C/C++/LLVM  | Low      |              |

| To Do | In Progress | Done  |
| :---: | :---------: | :---: |
|![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%238&desc=Implement%20Brain%20Commands.)|![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%237&desc=Implement%20First%20Brain%20Commands%20({,%20},%20?,%20:,%20;,%20!).)|![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%233&desc=Make%20--debug%20and%20--help%20flags.%20Implement%20input%20files.) ![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%232&desc=Implement%20Brainfuck%20commands.)|
||| ![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%231&desc=Make%20Brainfuck%20compatible%20with%20LLVM.)![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%234&desc=Think%20about%20new%20commands.)
|||![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%235&desc=Optmize%20generated%20code.%20Include%20-O0%20and%20-O1%20options.)![PostIt](http://api.ideiadoluiz.com.br/postit/?title=%20%236&desc=Implement%20First%20Brain%20Commands%20(*,%20/%20%).)|

### TODO List
If you want to check the micro TODO list, please see the [TODO.md](TODO.md)

### How to build LLVM
__Brain__ runs on the top of __LLVM__, thus, you are required to install the lasted version of LLVM. You can do that with git and CMake:

```
$ git clone http://llvm.org/git/llvm.git
$ mkdir mybuilddir
$ cd mybuilddir
$ cmake ../llvm
$ cmake --build .
$ cmake --build . --target install
```

_You should be good to start. Although, having any problems with installing LLVM, please visit:http://llvm.org/docs/CMake.html_

### How to install pre-commit
This project uses __pre-commit__ to help us to check our commits in order to minimize bugs and other problems on the project, therefore is strongly recommended that you use it, if you are intending to contribute to the project. For that, you can install by:

if you have ```pip``` installed:

__Mac__
```
brew install pre-commit
```
__Linux__
```
sudo pip install pre-commit
```
After that, go to where Brain lives:
```
$ cd /path/to/brain
$ pre-commit install
```
More information about that [here](http://pre-commit.com/)

### How to build Brain and run files
To build it, after [installing LLVM](#how-to-build-llvm), execute:
```
$ cd /path/to/brain/src
$ make
```
You can also change the compiler (tested on ```g++``` and ```clang++```) on the ```Makefile``` inside the ```src``` directory.

After running ```make``` on it, you can execute:```./brain your_brain_file.b```. Please check the [current status](#current-status) of the project.

### How it has been built
Brain is based on previous work [https://github.com/luizperes/BrainfuckInterpreter](https://github.com/luizperes/BrainfuckInterpreter) and [https://github.com/Lisapple/BF-Compiler-Tutorial-with-LLVM](https://github.com/Lisapple/BF-Compiler-Tutorial-with-LLVM), now trying to make something more serious: __Turing Complete__, faster, more features/commands and different types.

### Technical Information
Brain is __not yet__ a Turing Complete language, once I'm limiting its ```memory``` to ```100 * 32 bytes``` for now (only for testing purposes). Later on I will think in a way to allocate memory as needed instead.

### Commands
__Implemented__
- ```>``` increment the data pointer (to point to the next cell to the right).
- ```<``` decrement the data pointer (to point to the next cell to the left).
- ```+``` increment (increase by one) the value at the data pointer.
- ```-``` decrement (decrease by one) the value at the data pointer.
- ```.``` output the value at the data pointer.
- ```,``` accept one value of input, storing its value in the value at the data pointer.
- ```[``` if the value at the data pointer is zero, then instead of moving the instruction pointer forward to the next command, jump it forward to the command after the matching ] command.
- ```]``` jump to its correspondent [ .
- ```*``` multiply ```*ptr``` with ```*(ptr-1)```. Store result in *ptr _// format: 2 3 *_
- ```/``` divide ```*ptr``` with ```*(ptr-1)```. Store the result in *ptr _// format: 2 3 /_
- ```%``` divide ```*ptr``` with ```*(ptr-1)```. Store the remainder in *ptr _// format: 2 3 %_
- ```#``` prints out the current debug information.
- ```{``` (__for__ loop) iterates ```'value-at-the-data-pointer' times``` and needs to be closed with a matching } command. It __does not decrease__ the ```value``` at the data pointer. 
- ```}``` jump to its correspondent { . 

__Not Implemented__
- ```!``` (__break__) jumps to the end of a loop (__[ ]__ or __{ }__)
- ```?``` if the value at the data pointer is ```0```, jumps to the block with ```:``` or ```;``` and executes the commands one by one up to its correlative ```;```, otherwise, it executes the code until it finds a ```:``` or ```;```.
- ```:``` it works as an ```otherwise``` (or ```else```) for ```?```.
- ```;``` ends a statement.

__Thinking About__
- ```$``` cast the value at the data pointer back and forth to ```float``` and ```int```.
- ```@``` include other __Brain__ files.

Example of the instructions above:
- ___if-else___: ```? +++ : --- ;``` _// if (*ptr) { *ptr += 3; } else { *ptr -= 3; }_
- __for__: ```++++ { commands }``` _// makes four iterations 4 through 0 (excluded)_

### Compiler Options

- ```--help``` or ```-help```: Lists all compiler options.
- ```-emit-llvm```: Dumps the LLVM IR code before executing the output.
- ```-emit-expr```: Dumps the Expressions generated before executing the output.
- ```-O0```: Generates output code with no optmizations.
- ```-O1```: Optimizes Brain generated output code (Default).

### Applications on real life

  - Artificial Intelligence/ Machine Learning
  - Send commands to Arduino
  - Easy support to primitive processors

### Help
Feel free to send your pull requests. :)

### LICENSE
This project extends [GNU GPL v. 3](http://www.gnu.org/licenses/gpl-3.0.en.html), so be aware of that, regarding copying, modifying and (re)destributing.

