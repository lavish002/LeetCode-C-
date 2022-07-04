<h2><a href="https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/">1190. Reverse Substrings Between Each Pair of Parentheses</a></h2><h3>Medium</h3><hr><div style="user-select: auto;"><p style="user-select: auto;">You are given a string <code style="user-select: auto;">s</code> that consists of lower case English letters and brackets.</p>

<p style="user-select: auto;">Reverse the strings in each pair of matching parentheses, starting from the innermost one.</p>

<p style="user-select: auto;">Your result should <strong style="user-select: auto;">not</strong> contain any brackets.</p>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Example 1:</strong></p>

<pre style="position: relative; user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "(abcd)"
<strong style="user-select: auto;">Output:</strong> "dcba"
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper" style="user-select: auto;"></div></pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 2:</strong></p>

<pre style="position: relative; user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "(u(love)i)"
<strong style="user-select: auto;">Output:</strong> "iloveu"
<strong style="user-select: auto;">Explanation:</strong> The substring "love" is reversed first, then the whole string is reversed.
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper" style="user-select: auto;"></div></pre>

<p style="user-select: auto;"><strong style="user-select: auto;">Example 3:</strong></p>

<pre style="position: relative; user-select: auto;"><strong style="user-select: auto;">Input:</strong> s = "(ed(et(oc))el)"
<strong style="user-select: auto;">Output:</strong> "leetcode"
<strong style="user-select: auto;">Explanation:</strong> First, we reverse the substring "oc", then "etco", and finally, the whole string.
<div class="open_grepper_editor" title="Edit &amp; Save To Grepper" style="user-select: auto;"></div></pre>

<p style="user-select: auto;">&nbsp;</p>
<p style="user-select: auto;"><strong style="user-select: auto;">Constraints:</strong></p>

<ul style="user-select: auto;">
	<li style="user-select: auto;"><code style="user-select: auto;">1 &lt;= s.length &lt;= 2000</code></li>
	<li style="user-select: auto;"><code style="user-select: auto;">s</code> only contains lower case English characters and parentheses.</li>
	<li style="user-select: auto;">It is guaranteed that all parentheses are balanced.</li>
</ul>
</div>