# TODO

### GENERAL

* Finish supervise(1) program.
* Write runlevel-start(8) program.
* Write init script framework.
* Write example init scripts.
* Write program to interact with supervise(1).
* Write program to interact with init(8).

#### DONE
* Add more complex logging framework with support for syslog(3).  
  *Added 'logging' subsystem, with syslog(3) support and a special logfile for*
  *init and runlevel-start.*

### SPECIFIC

* Port init(8)'s userspace part to getopt.
* Add function to getopt for getting remaining command line arguments.

#### DONE
* Port eputs/eprintf calls to single unified logging framework.  
  *See GENERAL>DONE for more information.*
