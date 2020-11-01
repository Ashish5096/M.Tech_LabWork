var displayBooksDiv = $(".displayBooks")
function displayBooks(books) 
{
	var bookDetails = $(".bookDetails");
	for(var i=0;i<books.length;i++)
	{
        var bookClone =  bookDetails.clone();
		bookClone.find("#isbn").html(books[i].isbn)
        bookClone.find("#title").html(books[i].title)

        bookClone.find("#subtitle").html(books[i].subtitle)
        bookClone.find("#author").html(books[i].author)
        bookClone.find("#published").html(books[i].published)
        bookClone.find("#publisher").html(books[i].publisher)
        bookClone.find("#pages").html(books[i].pages)
        bookClone.find("#description").html(books[i].description)
        bookClone.find("#website").html(books[i].website)
        bookClone.find("#website").attr("href", books[i].website)
		displayBooksDiv.append(bookClone)
	}
	bookDetails.remove()
    for(var i = 0; i <books.length; i++){
        $(".title").eq(i).click(function(){
            $(this).next().slideToggle('slow');
        });
    }
}

function loadDoc() {

	var booksObject
	var books
 	var responseText

	var xhttp = new XMLHttpRequest();
	xhttp.open("GET", "https://raw.githubusercontent.com/sranjan710/Books-in-json-format/master/books.json", true);
	xhttp.onload = function() 
	{
		if (this.status == 200) 
		{
			 displayBooksDiv.show();
			responseText = this.responseText
			booksObject = JSON.parse(responseText);
			books=booksObject.books
			console.log(books)
			displayBooks(books)			  
		}
		else
		{
			console.log("404 page not found")
		}
   };


	xhttp.send();
 	$("#retrieveJSON").remove()
}

$("#retrieveJSON").click(function(){
    loadDoc();
});
