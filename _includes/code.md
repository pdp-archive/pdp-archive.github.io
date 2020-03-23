{% comment %}{% raw %}<!--
Add lines of code corresponding to a solution.

Usage:
  {% include code solution_name='my_solution.cc' (start=INT end=INT) %}

  solution_name: name of the file containing the code for this solution. This file should be in '_includes/source_code/XX-PDP/CODENAME/my_solution.cc'
  start: number of first line to include (starts at 1)
  end: number of last line to include (inclusive).

Example:

To include the entire solution 'my_solution.cc', write

  {% include code solution_name='my_solution.cc' %}

To include lines 5-7 of 'my_solution.cc', write

  {% include code solution_name='my_solution.cc' start=5 end=7 %}

Implementation inspired from https://hblok.net/blog/posts/2016/10/23/jekyll-include-partial-snippets-of-code/

-->{% endraw %}{% endcomment %}

{% assign contest_no = page.contest | slice : 0,2 %}
{% assign filename = "source_code/code/" 
    | append: contest_no
    | append: "-PDP/" 
    | append: page.codename 
    | append: "/" 
    | append: include.solution_name %}
{% capture filecontent %}{% include {{filename}} %}{% endcapture %}

{% if include.start and include.end %}

{% comment %}Πρέπει να ξανα-αφαιρέσουμε τις νέες γραμμμές γιατί η newline_to_br, δεν αφαιρεί τις \\r\\n{% endcomment %}
{% assign lines = filecontent | newline_to_br | split: '<br />' %}
{% assign lim = include.end |minus: include.start %}
{% comment %}Η τελευταία γραμμή πρέπει να είναι εκτός for για να αποφύγουμε την έξτρα γραμμή στο τέλος.{% endcomment %}
```c++
{% for line in lines limit:{{lim}} offset:{{include.start}} %}{{ line | strip_newlines }}
{% endfor %}{{ lines[include.end] | strip_newlines }}
```

{% else %}
{% comment %}Διαγράφουμε τον τελευταίο χαρακτήρα που αντιστοιχεί στην τελευταία νέα γραμμή.{% endcomment %}
{% assign end = filecontent.size | minus: 1 %}
```c++
{{ filecontent | slice: 0, end }}
```
{% endif %}
