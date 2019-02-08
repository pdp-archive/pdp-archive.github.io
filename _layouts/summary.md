---
layout: post
---
{% assign contest = site.data.contests[page.contest_url] %}

{% capture md %}

## Α' Φάση γυμνασίου
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "a" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
[εκφώνηση]({{ problem.statement_pdf_url}}) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/a-{{problem_it[0]}}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({{ problem.codes_url }})
{% endif %}
{% endfor %}

## Β' Φάση γυμνασίου
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "bgym" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
[εκφώνηση]({{ problem.statement_pdf_url}}) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/bgym-{{problem_it[0]}}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({{ problem.codes_url }})
{% endif %}
{% endfor %}

## Β' Φάση λυκείου
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "blyk" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
[εκφώνηση]({{ problem.statement_pdf_url}}) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/blyk-{{problem_it[0]}}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({{ problem.codes_url }})
{% endif %}
{% endfor %}
## Γ' Φάση
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %} 
  {% if problem.stage == "c" %}
**{{ problem.full_name }} ({{ problem_it[0] }}):**
[εκφώνηση]({{ problem.statement_pdf_url}}) \|
[testcases]({{ problem.testcases_url }}) \|
{% if problem.solution == true %}[λύση](/{{ page.contest_url }}/c-{{problem_it[0]}}-solution) \|{% else %} λύση \| {% endif %}
[κώδικες]({{ problem.codes_url }})
{% endif %}
{% endfor %}

{% endcapture %}
{{ md | markdownify }}