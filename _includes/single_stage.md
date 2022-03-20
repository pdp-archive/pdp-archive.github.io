{% capture cap_content %}
{% for problem_it in contest %}
  {% assign problem = problem_it[1] %}
  {% assign codename = problem_it[0] %}
  {% assign url_codename = problem_it[0] | replace: "_", "-" %}
  {% assign url_stage = include.stage | replace: "_", "-" %}
  {% if problem.stage == include.stage %}
  {% assign startsWith = 'camp_' %}
  {% assign isNotCamp = problem.stage | split:startsWith %}

**{{ problem.full_name }} ({{ codename }}):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ contest_url }}/{{ url_stage }}-{{ url_codename }}-statement) {% else %} εκφώνηση {% endif %}
{% if problem.statement_pdf_url == "" %}(pdf){% else %}([pdf]({{ problem.statement_pdf_url}})) {% endif %} \|
{% if problem.testcases_url == '' %} testcases {% else %}[testcases]({{ problem.testcases_url }}) {% endif %}
{% if problem.solution == true %}\| [λύση](/{{ contest_url }}/{{ include.stage }}-{{ url_codename }}-solution){% else %}{% unless problem.stage contains "camp_" %}\| λύση{% endunless %}{% endif %} \|
{% if problem.codes_in_git == true %}[κώδικες]({{ git_code_location | append: codename }}) {% else %} κώδικες {% endif %}
  {% endif %}
{% endfor %}
{% endcapture %}
{% assign cap_content_no_new_lines = cap_content | strip_newlines | remove: " " %}
{% if cap_content_no_new_lines != "" %}
## {{include.stage_title}}
{{cap_content}}
{% endif %}