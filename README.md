# Shell

Last Holbertonschool C programming language roject.

## Description

0x16. C Write a simple UNIX command interpreter.
The shell is the command interpretor in an operating system such as Unix or GNU/Linux. It provides a computer user an interface to the Unix/GNU Linux system so that the user can run different commands or utilities/tools with some input data.

## Procedure

1. Clone this repository

```
$ git clone https://github.com/motunrayo1993/simple_shell.git
```

2. Change directory to "simple_shell"

```
$ cd simple_shell
```

3. Make use of the **Makefile** file by typing "make".
This will compile and execute the shell.

```
$ make
```

If you're having problems with the **Makefile**, just copy and paste the following command, it will compile and execute the shell.

```
$ gcc shell.c -Wall -Werror -Wextra -pedantic _* -o shell && ./shell
```

## Examples

First of all, the shell has two possible forms:

**INTERACTIVE**

Where the shell stays on a loop prompting the user's input, then executes it, after executing the output is shown and finally the shell goes back to prompting.

```
$ pwd
/home/vagrant/simple_shell
$
```

**NON INTERACTIVE**

Where the shell doesn't loop, it just executes the written command on echo and closing when finished.

```
$ echo "pwd" | ./shell
/home/vagrant/simple_shell
```
---

**EXAMPLES**
(Interactive mode)

* Flags to commands

```
$
```

* Changing directory

```
$ cd -
/home/vagrant/
$ cd simple_shell
$ pwd
/home/vagrant/simple_shell
$
```

* Creating and deleting files

```
$ touch file1
$ ls
AUTHORS      _freegrid.c    pathfinderSave.c  shell.h       _strcpy.c
_builtins.c  _getline.c     README.md         _splitline.c  _strlen.c
_execute.c   Makefile       shell             _strcat.c     _strstr.c
file1        _pathfinder.c  shell.c           _strcmp.c
$ rm file1
$ ls
AUTHORS      _freegrid.c  _pathfinder.c     shell    _splitline.c  _strcpy.c
_builtins.c  _getline.c   pathfinderSave.c  shell.c  _strcat.c     _strlen.c
_execute.c   Makefile     README.md         shell.h  _strcmp.c     _strstr.c
$
```

## Files

This is a table with the files and their respective description used to create the shell.

| File | Description |
| --- | --- |
| pid.c | Main function, selects if interactive or non interactive, also calls the other functions |
| shell.h | Header file, contains prototypes of every function used |
| _getline.c | Gets the user's input and returns the typed command |
| _strtokline.c | Splits the command into arguments for processing |
| _which.c | Finds path of execution for first argument (command) if ir wasn't typed fully |
| _execute.c | Executes the the command and returns a status for continuing or stopping the main loop |
| _builtins.c | Special commands innate of thell, no need of pathfinding |
| _strcat.c | Concatenates one string into another **_strcat(hello, world => helloworld)** |
| _strcmp.c | Compares two strings and returns 0 if equals **_strcmp(hello, hello => 0)** |
| _strcpy.c | Copy one string into an empty pointer **_strcpy(newName(empty), name(Camilo) => newName(Camilo))** |
| _strlen.c | Returns the number of chars (without null) of a string **_strlen(name(Camilo) => 5)** |

## Authors

* Yetunde Egunjobi <omotunrayoegunjobi@gmail.com>
* Sani Abuh <saniabuh@gmail.com>
