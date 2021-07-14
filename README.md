Command Line Arguments for C code.
===

Source: 

[GNU GetOpt Function Usage](https://www.gnu.org/software/libc/manual/html_node/Using-Getopt.html)

[GNU GetOpt Example](https://www.gnu.org/software/libc/manual/html_node/Example-of-Getopt.html)



**Remember (from usage page):** The options argument is a string that specifies the option characters that are valid for this program. An option character in this string can be followed by a colon (‘:’) to indicate that it takes a required argument. If an option character is followed by two colons (‘::’), its argument is optional; this is a GNU extension.
* If these colons are not used correctly and args are used without following string when they expect one OR vice-versa, errors such as ```basic_string::_M_construct null not valid after constructing subvector of strings``` might appear for lines where ```getopt()``` is used.
