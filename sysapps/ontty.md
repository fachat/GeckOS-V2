
# ontty

## NAME

ontty - run a program on a different terminal

## SYNOPSIS

    ontty [TERMDEVICE] [COMMAND]
    
## DESCRIPTION

*ontty* allows running programs on a different terminal device. 

For a program, a terminal device is what is behind its standard error and especially console input streams. The console input stream (which is different from the standard input), mimics the original unix's read operation from standard error. It allows the console to send e.g. key presses for the more command.

While a normal shell should only redirect standard input, output and error streams, the console input will stay connected. (In future incarnations this will also be used to send e.g. Ctrl-C signals to the running process).

*ontty* allows re-connecting a process to a new device, i.e. reconnect the standard input, output, error and consol input streams to a new device.

## INPUT / OUTPUT REDIRECTION AND PIPING

As *ontty* cannot distinguish whether its own standard input, output or error streams are already redirected, it cannot decide whether in such cases it should not overwrite them with the connections to the new device. Consequently, the new command is completely connected to the new device, no redirection of the *ontty* streams is carried over.

(Note this may change in a future version using command line options as hints)

## EXAMPLES

	ontty a:video2 c:lsh
Start a new shell "c:lsh" on device "a:video2"
        
## AUTHOR

Written by André Fachat.

## REPORTING BUGS

Please report bugs at https://github.com/fachat/GeckOS-V2/issues

## COPYRIGHT

Copyright 2020 André Fachat. License GPL2 or later.
This is free software: you are free to change and redistribute it. There is no WARRANTY, to the extent permitted by law.

## SEE ALSO

