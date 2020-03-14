

# NAME

hexdump - hexdecimal dump

# SYNOPSIS

    hexdump [OPTION]... [FILE]...
    
# DESCRIPTION

hexdump is a filter to display the specified files in a hexadecimal dump. With no file dump standard input.

In the output each line starts with the offset from the start in hexadecimal, then eight bytes of hexadecimal data, then the same eight bytes as printable characters.

    **-l**    16 byte wide output 
    

# EXAMPLES

hexdump f g
    Output f's content, then g's content as hex dump
        
hexdump
    Dump standard input to standard output as hex dump

# AUTHOR

Written by André Fachat.

# REPORTING BUGS

Please report bugs at https://github.com/fachat/GeckOS-V2/issues

# COPYRIGHT

Copyright 2020 André Fachat. License GPL2 or later.
This is free software: you are free to change and redistribute it. There is no WARRANTY, to the extent permitted by law.

# SEE ALSO

