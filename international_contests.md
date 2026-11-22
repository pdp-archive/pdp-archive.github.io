---
layout: default
---

<div style="text-align:right">
  <div>
    <a href="/"> Αρχική </a>
  </div>
</div>

# Διεθνείς διαγωνιμοί πληροφορικής

Παρακάτω θα βρείτε διάφορες μαζεμένες εκφωνήσεις, λύσεις, testcases και κώδικες από τους διεθνείς διαγωνισμούς πληροφορικής στους οποίους συμμετέχει συχνά η Ελλάδα. Αρκετοί από αυτούς είναι ελλειπείς. Αν έχετε περεττέρω υλικό, ενημερώστε μας [εδώ](https://github.com/pdp-archive/pdp-archive.github.io/issues).

## Διεθνείς Ολυμπιάδα Πληροφορικής (IOI)

{% assign sortedCollections = site.data.international_contests.IOI %}
{% for contest in sortedCollections reversed %} [{{contest[0]}}]({{contest[1].drive_url}}) {% endfor %}

## Βαλκανική Ολυμπιάδα Πληροφορικής (BOI)

{% assign sortedCollections = site.data.international_contests.BOI %}
{% for contest in sortedCollections reversed  %} [{{contest[0]}}]({{contest[1].drive_url}}) {% endfor %}

## Βαλκανική Ολυμπιάδα Πληροφορικής Νέων (jBOI)

{% assign sortedCollections = site.data.international_contests.JBOI %}
{% for contest in sortedCollections reversed  %} [{{contest[0]}}]({{contest[1].drive_url}}) {% endfor %}

## Ευρωπαϊκή Ολυμπιάδα Πληροφορικής Νέων (EJOI)

{% assign sortedCollections = site.data.international_contests.EJOI %}
{% for contest in sortedCollections reversed  %} [{{contest[0]}}]({{contest[1].drive_url}}) {% endfor %}

## Ευρωπαϊκή Ολυμπιάδα Πληροφορικής για Κορίτσια (EGOI)

{% assign sortedCollections = site.data.international_contests.EGOI %}
{% for contest in sortedCollections reversed  %} [{{contest[0]}}]({{contest[1].drive_url}}) {% endfor %}

<div id="footer_space"></div>
{% include contributors_footer.html %}
