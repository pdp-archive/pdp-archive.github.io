---
layout: default
---

{% assign sortedCollections = site.collections %}
 {% for collection in site.collections reversed %} 
  {% if collection.label != "posts" %}
    {% for post in site[collection.label] %}
       {% if post.layout == "summary" %}

# {{ post.contest_no }}ος ΠΔΠ

     {% include single_year.md contest_url = post.url %}

     {% endif %}
    {% endfor %}
   {% endif %}
 {% endfor %}

<div id="footer_space"></div>
{% include contributors_footer.html %}
