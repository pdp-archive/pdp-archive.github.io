{% assign contest_url = include.contest_url | replace: "/", "" | replace: "index", "" %}
{% assign contest = site.data.contests[contest_url] %}
{% assign git_code_location = "https://github.com/pdp-archive/pdp-archive.github.io/tree/master/_includes/source_code/code/" | append: contest_url | append: "/" %}
{% assign contest_year = contest_url | slice: 0,2 %}
{% assign judge_location = "https://pdp-archive.com/pdp-judge/submit.php?year=" | append: contest_year %}

{% capture md %}

{% include single_stage.md stage="a" stage_title="Α' Φάση" %}

{% include single_stage.md stage="bgym" stage_title="Β' Φάση γυμνασίου" %}

{% include single_stage.md stage="blyk" stage_title="Β' Φάση λυκείου" %}

{% include single_stage.md stage="c" stage_title="Γ' Φάση" %}

{% include single_stage.md stage="camp_j" stage_title="Καμπ (juniors)" %}

{% include single_stage.md stage="camp_s" stage_title="Καμπ (seniors)" %}

{% include single_stage.md stage="camp_c" stage_title="Καμπ (κοινά)" %}

{% endcapture %}
{{ md | markdownify }}