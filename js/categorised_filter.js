/* Filter out rows for which the given tag does not appear after
   "Tag:" */
function filterCategorisedEntries() {
  var input, filter, table, tr, td, i;
  input = document.getElementById("categorised_filter_text");
  filter = input.value.toLowerCase();
  table = document.getElementById("categorised_table");
  tr = table.getElementsByTagName("tr");
  for (i = 0; i < tr.length; i++) {
    td = tr[i].getElementsByTagName("td")[0];
    if (td) {
      txt = td.textContent || td.innerText;
      normalisedTxt = txt.toLowerCase();
      tagsLocation = normalisedTxt.indexOf("tags:");
      if (normalisedTxt.indexOf(filter) > tagsLocation || filter == "") {
        tr[i].style.display = "";
      } else {
        tr[i].style.display = "none";
      }
    }       
  }
}
