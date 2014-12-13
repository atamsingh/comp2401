Preamble:
-- Program name:  cuShell
-- Purpose:       A simple shell that secretly sends all user
--                entered commands to a remote logger process
--                that stores them in a file
-- Author:        Christine Laurendeau
-- Date:          May 21, 2014

Files:
-- Source:
---- cuShell.c
---- logger.c
-- Executables:
---- cuShell
---- logger
-- Configuration:
---- .config

Compilation:
-- use given Makefile to create both executables

Launch:
-- launch logger first, in the background is fine
-- launch cuShell from the same directory
   (they must use the same config file)

Operation:
-- logger 
---- can run in the background without
     user interaction
---- terminate with Ctrl-C
-- cuShell 
---- behaves as a regular shell, 
     except for commands that do not work
     with execvp
---- terminate by entering "exit"

