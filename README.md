Get terminal
I use the old term lib curse and termcap.

I take term name with getenv TERM
tgetent term
take term size with iotcl
tcgetattr take and tcsetattr fix term param
Circular list
A simple 'ring buffer', with true value for curser and select. If I up or down more than the term can print head list change.

Print
Use tgetstr and he's various id to make clean, move curser, or video mode etc.
