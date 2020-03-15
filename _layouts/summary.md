---
layout: post
---
{% assign contest = site.data.contests[page.contest_url] %}
{% assign git_code_location = "https://github.com/pdp-archive/pdp-archive.github.io/tree/master/source_code/code/" | append: page.contest_url | append: "/" %}

{% capture md %}

## Α' Φάση
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "a" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ page.contest_url }}/a-{{problem_it[0] | replace: "_", "-" }}-statement) {% else %} εκφώνηση {% endif %}
([pdf]({{ problem.statement_pdf_url}})) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/a-{{problem_it[0]}}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({% if problem.codes_in_git == true %} {{ git_code_location | append: problem_it[0] }} {% else %} {{ problem.codes_url }} {% endif %} )
{% endif %}
{% endfor %}

## Β' Φάση γυμνασίου
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "bgym" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ page.contest_url }}/bgym-{{problem_it[0] | replace: "_", "-" }}-statement) {% else %} εκφώνηση {% endif %}
([pdf]({{ problem.statement_pdf_url}})) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/bgym-{{problem_it[0] | replace: "_", "-" }}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({% if problem.codes_in_git == true %} {{ git_code_location | append: problem_it[0] }} {% else %} {{ problem.codes_url }} {% endif %} )
{% endif %}
{% endfor %}

## Β' Φάση λυκείου
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "blyk" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ page.contest_url }}/blyk-{{problem_it[0] | replace: "_", "-" }}-statement) {% else %} εκφώνηση {% endif %}
([pdf]({{ problem.statement_pdf_url}})) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/blyk-{{problem_it[0] | replace: "_", "-" }}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({% if problem.codes_in_git == true %} {{ git_code_location | append: problem_it[0] }} {% else %} {{ problem.codes_url }} {% endif %} )
{% endif %}
{% endfor %}
## Γ' Φάση
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "c" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ page.contest_url }}/c-{{problem_it[0] | replace: "_", "-" }}-statement) {% else %} εκφώνηση {% endif %}
([pdf]({{ problem.statement_pdf_url}})) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/c-{{problem_it[0] | replace: "_", "-" }}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({% if problem.codes_in_git == true %} {{ git_code_location | append: problem_it[0] }} {% else %} {{ problem.codes_url }} {% endif %} )
{% endif %}
{% endfor %}

{% endcapture %}
{{ md | markdownify }}

<div id="footer_space"></div>
{% include contributors_footer.html %}
