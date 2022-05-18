var postList = [];

function makePost() {
    var title = document.getElementById("title").value;
    var content = document.getElementById("content").value;

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
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
    }

    var xhttp = new XMLHttpRequest();
    xhttp.onreadystatechange = function () {
        if (this.readyState == 4 && this.status == 200) {
            x.innerHTML = ""; //delete everything in the div
            postList = JSON.parse(this.responseText);
            postList.forEach(element => {

                var d = document.createElement("div");
                div.classList.add("postDiv");

                var h = document.createElement("h2");
                h.classList.add("h");
                h.innerHTML = postList.title; //change to element
                d.appendChild(h);

                var p = document.createElement("p");
                p.classList.add("p");
                p.innerHTML = postList.content;
                d.appendChild(p);

                x.appendChild(d);
            });

        }
    };
    xhttp.open("GET", "/getposts", true);
    xhttp.setRequestHeader("Content-type", "application/json");
    xhttp.send();

}