{% assign contest_no = page.contest | slice : 0,2 %} {% assign filename = "https://github.com/pdp-archive/pdp-archive.github.io/blob/master/_includes/source_code/code/" 
    | append: contest_no
    | append: "-PDP/" 
    | append: page.codename 
    | append: "/" 
    | append: include.solution_name %}{{filename}}