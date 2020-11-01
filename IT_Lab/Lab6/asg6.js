var disp = document.getElementById("disp");
var flag=0;

function display(n){
	disp.innerHTML += n ;
}

function ans(){

    if(flag==0)
    {
        res=dec_ans(disp.innerHTML);
        disp.innerHTML=res;
    }
    else if(flag==1)
        binary_ans();
    else if(flag==2)
        octal_ans();
    
}

function dec_ans( expr)
{
    res=eval(expr);
	
	if(res==null)
        res=0;

	return res ;
}

function binary_ans()
{
    expr=disp.innerHTML;
	var n=0;
	var pow=0;
	var result="";
    var sum=0,rem=0;

	for (i = expr.length-1 ; i >=0 ; i--)
	{ 
		
		if(expr[i]== "+" || expr[i]== '-' || expr[i]=="/" || expr[i]== '*')
		{
             result=expr[i].concat(sum,result);
             sum=0,pow=0;
		}
		else
		{
			sum=sum+ (expr[i]*(2**pow)) ;
			pow=pow+1;
		}
	}
    
    result= sum+result;     // concatenate
    
    sum=dec_ans(result);
    result="";
    
        
    while(sum!=0)
    {
        rem=(sum % 2).toString();  
        result =rem+result;;      
        sum=Math.floor(sum/2);
    }
    disp.innerHTML=result;
}


function octal_ans()
{
    expr=disp.innerHTML;
	var n=0;
	var pow=0;
	var result="";
    var sum=0;

	for (i = expr.length-1 ; i >=0 ; i--)
	{ 
		
		if(expr[i]== "+" || expr[i]== '-' || expr[i]=="/" || expr[i]== '*')
		{
             result=expr[i].concat(sum,result);
             sum=0,pow=0;
		}
		else
		{
			sum=sum+ (expr[i]*(8**pow)) ;
			pow=pow+1;
		}
	}
    
     result= sum+result;     // concatenate
    
    sum=dec_ans(result);
    result="";
    
        
    while(sum!=0)
    {
        rem=(sum % 8).toString();  
        result =rem+result;;      
        sum=Math.floor(sum/8);
    }
    disp.innerHTML=result;
}

function clear(){
	disp.innerHTML='';
}

function binary(){

    clear();
    flag=1;
    $("#binary").css("background-color","#4285f4");
    $("#dec").css("background-color","e6e6e6");
    $("#octal").css("background-color","e6e6e6");
    $("#2").attr("disabled", true);
	$("#3").attr("disabled", true);
	$("#4").attr("disabled", true);
	$("#5").attr("disabled", true);
	$("#6").attr("disabled", true);
	$("#7").attr("disabled", true);
	$("#8").attr("disabled", true);
	$("#9").attr("disabled", true);
}

function octal(){

    clear();
    flag=2;
    $("#octal").css("background-color","#4285f4");
    $("#dec").css("background-color","e6e6e6");
    $("#binary").css("background-color","e6e6e6");

    $("#2").attr("disabled", false);
    $("#3").attr("disabled", false);
	$("#4").attr("disabled", false);
	$("#5").attr("disabled", false);
	$("#6").attr("disabled", false);
	$("#7").attr("disabled", false);
	$("#8").attr("disabled", true);
	$("#9").attr("disabled", true);

}

function dec(){

    clear();
    flag=0;
	$("#dec").css("background-color","#4285f4");
    $("#octal").css("background-color","e6e6e6");
    $("#binary").css("background-color","e6e6e6");

    $("#0").attr("disabled", false);
    $("#1").attr("disabled", false);
    $("#2").attr("disabled", false);
    $("#3").attr("disabled", false);
	$("#4").attr("disabled", false);
	$("#5").attr("disabled", false);
	$("#6").attr("disabled", false);
	$("#7").attr("disabled", false);
	$("#8").attr("disabled", false);
	$("#9").attr("disabled", false);

}



$("#1").click(function(){ display(1); });
$("#2").click(function(){ display(2); });
$("#3").click(function(){ display(3); });
$("#4").click(function(){ display(4); });
$("#5").click(function(){ display(5); });
$("#6").click(function(){ display(6); });
$("#7").click(function(){ display(7); });
$("#8").click(function(){ display(8); });
$("#9").click(function(){ display(9); });
$("#0").click(function(){ display(0); });
$("#dot").click(function(){ display('.'); });
$("#add").click(function(){ display('+'); });
$("#subtr").click(function(){ display('-'); });
$("#mult").click(function(){ display('*'); });
$("#division").click(function(){ display('/'); });
$("#clear").click(function(){clear(); });
$("#ans").click(function(){ ans(); });
$("#binary").click(function(){ binary(); });
$("#octal").click(function(){ octal();});
$("#dec").click(function(){ dec();});

