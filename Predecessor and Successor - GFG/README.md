# Predecessor and Successor
## Easy 
<div class="problem-statement" style="user-select: auto;">
                <p style="user-select: auto;"></p><p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;">There is BST given with root node with key part as an integer only.&nbsp;You need to find the in-order successor and predecessor of a given key.&nbsp;If either predecessor or successor is not found, then set it to NULL.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Input:</strong><br style="user-select: auto;">
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case contains n denoting the number of edges of the BST. The next line contains the edges of the BST. The last line contains the key.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Output:</strong><br style="user-select: auto;">
Find the&nbsp;predecessor and successor of the&nbsp;key in BST and&nbsp;sets pre and suc as predecessor and successor, respectively Otherwise, set to NULL.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Note:&nbsp;</strong>You don't need to print anything. You only need to set p.pre to the predecessor and s.succ to the&nbsp;successor. p and s have been passed in the function parameter.</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Constraints:</strong><br style="user-select: auto;">
1&lt;=T&lt;=100<br style="user-select: auto;">
1&lt;=n&lt;=100<br style="user-select: auto;">
1&lt;=data of node&lt;=100<br style="user-select: auto;">
1&lt;=key&lt;=100</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Example:<br style="user-select: auto;">
Input:</strong><br style="user-select: auto;">
2<br style="user-select: auto;">
6<br style="user-select: auto;">
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R<br style="user-select: auto;">
65<br style="user-select: auto;">
6<br style="user-select: auto;">
50 30 L 30 20 L 30 40 R 50 70 R 70 60 L 70 80 R<br style="user-select: auto;">
100</span></p>

<p style="user-select: auto;"><span style="font-size: 18px; user-select: auto;"><strong style="user-select: auto;">Output:</strong><br style="user-select: auto;">
60 70<br style="user-select: auto;">
80 -1</span><br style="user-select: auto;">
&nbsp;</p>
 <p style="user-select: auto;"></p>
            </div>