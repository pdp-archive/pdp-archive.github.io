{% capture cap_content %}
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %}
  {% assign codename = problem_it[0] %}
  {% assign url_codename = problem_it[0] | replace: "_", "-" %}
  {% if problem.stage == include.stage %}

**{{ problem.full_name }} ({{ codename }}):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ contest_url }}/{{ include.stage }}-{{ url_codename }}-statement) {% else %} εκφώνηση {% endif %}
([pdf]({{ problem.statement_pdf_url}})) \|
{% if problem.testcases_url == '' %} testcases {% else %}[testcases]({{ problem.testcases_url }}) {% endif %} \|
{% if problem.solution == true %}[λύση](/{{ contest_url }}/{{ include.stage }}-{{ url_codename }}-solution) \|{% else %} λύση \| {% endif %}
{% if problem.codes_in_git == true %}[κώδικες]({{ git_code_location | append: codename }}) {% else %} κώδικες {% endif %}
  {% endif %}
{% endfor %}
{% endcapture %}
{% assign cap_content_no_new_lines = cap_content | strip_newlines | remove: " " %}
{% if cap_content_no_new_lines != "" %}
## {{include.stage_title}}
{{cap_content}}
{% endif %}