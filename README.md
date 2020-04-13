# Get Next Line Project For 42 Silicon Valley

<p>This program was created and tested on Mac os x darwin</p>

## Description
<p>The main focus on this project is static variables, buffering output and some of the basics of file descriptor's</p>
<p>While this function is very useful in it's own right I'm coming to find that it's the core concept that I end up using
more then the actual function. Being able to wait for a line of input from the user is a common task in programming.</p>
<p>get_next_line makes that easy by abstracting the task away, but there are some instances where it may not be as useful, mainly; What happens when I need to proccess input that does not contain a newline example (ctrl-C, arrow keys, etc..)? In those cases the core functionality here provides everything you need to be able to copy/paste and modify everything as needed.</p>
<p>The get_next_line function is buffered and uses a macro defined BUFF_SIZE in the get_next_line.h</p>
<p>To change the buffer size being used simply edit the integer value for BUFF_SIZE and recompile the program.</p>

## Using This Function
<p>This function along with a sample main can be downloaded and ran with a simple with the following commands inside a terminal.</p>
<pre>$> git clone https://github.com/fractalfox01/get_next_line.git get_next_line
$> cd get_next_line
$> make
$> ./get_next_line main.c
...
... output of main.c contents ...
...
</pre>
