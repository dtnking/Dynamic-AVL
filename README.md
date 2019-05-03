# Dynamic-AVL

This is a modified AVL algorithm to handle relative values rather than absolute values. It is useful for application where the values are dynamic, like the time of firing events. What gets stored is the relative period from the time of the immediate previous event.<br /><br />
Below shows the difference of conventional AVL and dynamic AVL<br /><br />
![conventional AVL](https://github.com/dtnking/Dynamic-AVL/blob/master/image/Line.svg)<br /><br /><br /><br />
![Dynamic AVL](https://github.com/dtnking/Dynamic-AVL/blob/master/image/Line2.svg)<br /><br />
As you can see, both of the figures shows the period timeline. What makes the difference is that conventional AVL stores the absolute value of the periods whereas dynamic AVL stores the relative value of the periods which is the different of current period with next period. It's actually recording when is the next period coming after current period expired. This is very important when we are using timer at microcontroller, when the timer ticked until 2 second, where a certain event need to be handle, it will reset to 0. Then the next event is at 3rd second of the real time but don't forget that 2 second is already expired, and the timer is now 0, so the value should the timer count is 1 second( 2 + 1 = 3 seconds) after first event is handled. In other word, after 2 seconds expired the next event is at 1 second later, not 3 seconds(if using conventional AVL). By using dynamic AVL, we can use only one timer to handle several event as we don't need to worry about the expiration of the period.<br /><br />
__________________________________________________________________________________________________________________________
Here are the scenarios of how the value is inserted into or removed from AVL-Tree,<br />
1. [AVL Relative Add](https://github.com/dtnking/Dynamic-AVL/wiki/AVL-Relative-Add)<br />
2. [AVL Relative Remove](https://github.com/dtnking/Dynamic-AVL/wiki/AVL-Relative-Remove)<br />
