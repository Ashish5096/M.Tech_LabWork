var table= document.getElementsByTagName("table")[0];
var trList= table.getElementsByTagName("tr");
var button_GM=document.getElementsByClassName("generateMarks")[0];
var button_CGPA=document.getElementsByClassName("getCGPA")[0];
var CGPA_score=0 ;


function generate(tList)
{

	var count=0,j=0, sum=0,avg=0;
	
	for( j=0;j<tList.length-2;j++)
	{
		if(tList[j].innerHTML!="NA")
		{
			var value= (Math.random() * 5) + 5;
			sum = sum+value;
			count=count+1;
			tList[j].innerHTML =  value.toFixed(2);
		}
	}
	
	avg=sum/count;
    CGPA_score = +CGPA_score + +avg;

	tList[j].innerHTML =  avg.toFixed(2);
	
	if(avg >=9 && avg <=10)
		tList[j+1].innerHTML = "A+";
    
    if(avg >=8 && avg <=9)
		tList[j+1].innerHTML = "A";

	if(avg >=7 && avg <=8)
		tList[j+1].innerHTML = "B+";
	
	if(avg >=6 && avg <=7)
		tList[j+1].innerHTML = "B";
    
    if(avg >=5 && avg <=6)
		tList[j+1].innerHTML = "C";

    //tList[j+1].innerHTML = CGPA_score ;
}






function add()
{
	CGPA_score=0;

    for(var i=1;i<trList.length;i++)
	{
		tdList=trList[i].getElementsByTagName("td");  
		generate(tdList);
   	}

    CGPA_score= +CGPA_score / +4;  
}

button_CGPA.onclick = function()
{
        
    document.getElementById("cgpa").innerHTML = CGPA_score;

    if( CGPA_score >=9 && CGPA_score <=10)
        document.getElementById("grade").innerHTML = "A+";

    if( CGPA_score >=8 && CGPA_score <=9 )
		document.getElementById("grade").innerHTML = "A";
	
	if( CGPA_score >=7 && CGPA_score <=8)
		document.getElementById("grade").innerHTML = "B+";
    
    if( CGPA_score >=6 && CGPA_score <=7)
		document.getElementById("grade").innerHTML = "B";
    
    if( CGPA_score >=5 && CGPA_score <=6)
		document.getElementById("grade").innerHTML = "C";
}


button_GM.onclick = function()
{
  add();
}
