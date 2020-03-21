{% assign contest_url = include.contest_url | replace: "/", "" | replace: "index", "" %}
{% assign contest = site.data.contests[contest_url] %}
{% assign git_code_location = "https://github.com/pdp-archive/pdp-archive.github.io/tree/master/source_code/code/" | append: contest_url | append: "/" %}

{% capture md %}

## Α' Φάση

{% include single_stage.md stage="a" %}

## Β' Φάση γυμνασίου

{% include single_stage.md stage="bgym" %}

## Β' Φάση λυκείου

{% include single_stage.md stage="blyk" %}

## Γ' Φάση

{% include single_stage.md stage="c" %}

{% endcapture %}
{{ md | markdownify }}