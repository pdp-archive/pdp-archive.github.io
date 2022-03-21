{% capture cap_content %}
{% for problem_it in contest %}

{% if problem_it[1].stage == include.stage %}
{% include single_problem.md problem_it=problem_it include_tags=true %}
{% endif %}

{% endfor %}
{% endcapture %}
{% assign cap_content_no_new_lines = cap_content | strip_newlines | remove: " " %}
{% if cap_content_no_new_lines != "" %}
## {{include.stage_title}}
{{cap_content}}
{% endif %}