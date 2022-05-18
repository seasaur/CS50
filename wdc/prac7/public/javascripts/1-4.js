var postList = [];

function makePost() {
    var title = document.getElementById("title").value;
   var content = document.getElementById("content").value;

   addPost(title,content);


    //showPosts();
}

function addPost(title, content) {
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

function updatePosts() {



    // for(let post of postList) {
    //     addPost(post.title,post.content);
    // }

   var xhttp = new XMLHttpRequest();
   xhttp.onreadystatechange = function() {
       if (this.readyState == 4 && this.status == 200) {
           postList = JSON.parse(this.responseText);
        //    let append = '';
        //    for (let i=0;i<postList.length;i++) {
        //        append +=
        //        `<div>
        //            <h2>${posts.title}</h2>
        //            <p>${posts.content}</p>
        //        </div>`;
        //    }

    //     var d = document.createElement("div");
    //     h.classList.add("postDiv");
    //     document.getElementById("postListing").appendChild(d);

    //     var h = document.createElement("h2");
    //     h.classList.add("h");
    //     h.innerHTML = postList.title;
    //     document.getElementById("postListing").appendChild(h);

    //     var p = document.createElement("p");
    //     p.classList.add("p");
    //     p.innerHTML = postList.content;
    //     document.getElementById("postListing").appendChild(p);
       }
   };
   xhttp.open("GET", "/getposts", true);
   xhttp.setRequestHeader("Content-type", "application/json");
   xhttp.send();

}

function showPosts() {
    var x = document.getElementById("postListing");
    if (x.style.display === "none") {
      x.style.display = "block";
    } else {
      x.style.display = "none";
    }
  }