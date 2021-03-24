/* Filter out rows which do not have a tag of the given solution. */
function filterRelevantEntries() {
  var input, filter, table, tr, td, i;
  input = document.getElementById("relevant_filter_text");
  codename = input.value.toLowerCase();
  table = document.getElementById("categorised_table");
  tr = table.getElementsByTagName("tr");
  
  // Find the searched problem.
  codename_tags = Array();
  for (i = 0; i < tr.length; i++) {
    td = tr[i].getElementsByTagName("td")[0];
    span = td.getElementsByTagName("span")[0];
    tr[i].style.display = "";
    if (span) {
      console.log(span.innerText);
      txt = span.innerText;
      if (span.innerText == codename) {
         txt = td.textContent || td.innerText;
         normalisedTxt = txt.toLowerCase();
         tagsLocation = normalisedTxt.indexOf("tags:");
         codename_tags = normalisedTxt.substring(tagsLocation + 6, normalisedTxt.length - 2).split(",");
         break;
      }
    }       
  }
  
  console.log(codename_tags);
  if (codename_tags.length == 0 && codename == "") return;
  
  for (i = 0; i < tr.length; i++) {
    td = tr[i].getElementsByTagName("td")[0];
    if (td) {
      txt = td.textContent || td.innerText;
      normalisedTxt = txt.toLowerCase();
      tagsLocation = normalisedTxt.indexOf("tags:");
      // TODO: Make this more efficient.
      tr[i].style.display = "none";
      for (j = 0; j < codename_tags.length; ++j) {
         filter = codename_tags[j];
         if (normalisedTxt.lastIndexOf(filter) > tagsLocation || filter == "") {
           tr[i].style.display = "";
           break;
         }
      }
    }       
  }
}

function loadCodenameFromUrl() {
   var url_string = window.location.href;
   var url = new URL(url_string);
   var codename = url.searchParams.get("codename");
   input = document.getElementById("relevant_filter_text");
   input.value = codename.toLowerCase();
   filterRelevantEntries();
}