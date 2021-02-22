{% assign contest_url = include.contest_url | replace: "/", "" | replace: "index", "" %}
{% assign contest = site.data.contests[contest_url] %}
{% assign git_code_location = "https://github.com/pdp-archive/pdp-archive.github.io/tree/master/_includes/source_code/code/" | append: contest_url | append: "/" %}

{% capture md %}

{% include single_stage.md stage="a" stage_title="Α' Φάση" %}

{% include single_stage.md stage="bgym" stage_title="Β' Φάση γυμνασίου" %}

{% include single_stage.md stage="blyk" stage_title="Β' Φάση λυκείου" %}

{% include single_stage.md stage="c" stage_title="Γ' Φάση" %}

{% endcapture %}
{{ md | markdownify }}