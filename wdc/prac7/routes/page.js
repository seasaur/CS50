var postList = [];
function makePost() {
    var title = document.getElementById("title").value;
   var content = document.getElementById("content").value;

   var xhttp = new XMLHttpRequest();
   xhttp.onreadystatechange = function() {
       if (this.readyState == 4 && this.status == 200) {
           console.log("done");
       }
   };
   xhttp.open("POST", "/addpost", true);
   xhttp.setRequestHeader("Content-type", "application/json");
   xhttp.send(JSON.stringify({ title: title, content: content }));
}


function showPosts() {

   var title = document.getElementById("title").value;
   var content = document.getElementById("content").value;

   var xhttp = new XMLHttpRequest();
   xhttp.onreadystatechange = function() {
       if (this.readyState == 4 && this.status == 200) {
           postList = JSON.parse(this.responseText);
           let append = '';
           for (var i=0;i<jsonArray.length;i++) {
               append +=
               `<div>
                   <h2>${posts.title}</h2>
                   <p>${posts.content}</p>
               </div>`;
           }
       }
   };
   xhttp.open("GET", "/getposts", true);
   xhttp.setRequestHeader("Content-type", "application/json");
   xhttp.send();