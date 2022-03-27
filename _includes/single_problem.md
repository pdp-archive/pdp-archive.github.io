{% assign problem = include.problem_it[1] %}
{% assign codename = include.problem_it[0] %}
{% assign url_codename = codename | replace: "_", "-" %}
{% assign url_stage = problem.stage | replace: "_", "-" %}

**{{ problem.full_name }} (<span>{{ codename }}</span>):**
{% if problem.statement_md == true %}[εκφώνηση](/{{ contest_url }}/{{ url_stage }}-{{ url_codename }}-statement) {% else %} εκφώνηση {% endif %}
{% if problem.statement_pdf_url == "" %}(pdf){% else %}([pdf]({{ problem.statement_pdf_url}})) {% endif %} \|
{% if problem.testcases_url == '' %} testcases {% else %}[testcases]({{ problem.testcases_url }}) {% endif %}
{% if problem.solution == true %}\| [λύση](/{{ contest_url }}/{{ problem.stage }}-{{ url_codename }}-solution){% else %}{% unless problem.stage contains "camp_" %}\| λύση{% endunless %}{% endif %} \|
{% if problem.codes_in_git == true %}[κώδικες]({{ git_code_location | append: codename }}) {% else %} κώδικες {% endif %}
{% if include.include_tags == true %}
  <i>Tags: {{ problem.solution_tags | join: ", " }}</i>
{% endif %}
