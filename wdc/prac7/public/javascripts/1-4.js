var postList = [];

function makePost() {
    var title = document.getElementById("title").value;
    var content = document.getElementById("content").value;

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function() {
        if (this.readyState == 4 && this.status == 200) {
            // console.log("done");
            //getPosts();
        }
    };
    xhttp.open("POST", "/users/addpost", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send(JSON.stringify({ title: title, content: content }));
}

function showPosts() {



    // for(let post of postList) {
    //     addPost(post.title,post.content);
    // }

    var x = document.getElementById("postListing");
    if (x.style.display === "none") {
      x.style.display = "block";
    } else {
      x.style.display = "none";
    }

   var xhttp = new XMLHttpRequest();
   xhttp.onreadystatechange = function() {
       if (this.readyState == 4 && this.status == 200) {
           postList = JSON.parse(this.responseText);
           
        var d = document.createElement("div");
        h.classList.add("postDiv");
        document.getElementById("postListing").appendChild(d);

        var h = document.createElement("h2");
        h.classList.add("h");
        h.innerHTML = postList.title;
        document.getElementById("postDiv").appendChild(h);

        var p = document.createElement("p");
        p.classList.add("p");
        p.innerHTML = postList.content;
        document.getElementById("postDiv").appendChild(p);
       }
   };
   xhttp.open("GET", "/getposts", true);
   xhttp.setRequestHeader("Content-type", "application/json");
   xhttp.send();

}