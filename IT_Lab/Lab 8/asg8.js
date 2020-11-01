function marketprice(myObj, timestamp)
{
	marketprices = myObj.Stock_Market_Prices_At_Timestamp[timestamp]
	total = 0;
	for(var i=0;i<5;i++){
		stockmarketPriceSelector = $("[data-label='Market Price']").eq(i)
		stockmarketPriceSelector.text('$'+marketprices['Stock_'+(i+1)])
		var buyprice = $("[data-label='Buy Price']").eq(i).text().slice(1,3);
		var profitloss = marketprices['Stock_'+(i+1)] - buyprice;
		//alert(profitloss);
		$("[data-label='Profit/Loss']").eq(i).text('$'+profitloss.toFixed(2))
		var pnl = profitloss/buyprice;
		pnl = pnl*100;
		$("[data-label='PnL(%)']").eq(i).text(Math.abs(pnl.toFixed(2))+'%')
		var total;
		total = profitloss + total;
		$("[data-label='T_PnL']").eq(i).text(total.toFixed(2));
		if(profitloss<0)
		{
			$("[data-label='Profit/Loss']").eq(i).css("color","red");
			$("[data-label='PnL(%)']").eq(i).css("color","red");
		}
		else
		{
			$("[data-label='Profit/Loss']").eq(i).css("color","green");
			$("[data-label='PnL(%)']").eq(i).css("color","green");
		}
		if(total<0)
		{
			$("[data-label='T_PnL']").eq(i).css("color","red");
		}
		else
		{
			$("[data-label='T_PnL']").eq(i).css("color","green");
		}
	}
	return stockmarketPriceSelector;
}


function retrieveJSONandPopulateData(){
    
     var num2 = generateRandom(4,1);
     num2 = Math.floor(num2);
     var xmlhttp = new XMLHttpRequest();
     var timestamp = randomjson();
     xmlhttp.open("GET", "random_stock_price_"+num2+".json", true);
     xmlhttp.onload = function() 
     {
     	if (this.status == 200)
     		{
       		var myObj = JSON.parse(this.responseText);
       		market = marketprice(myObj,timestamp);
    		}
     };
    xmlhttp.send();
    
}


function randomjson()
{
	timestamp = "T";
	var num1 = generateRandom(6,1);
	num1 = Math.floor(num);
	timestamp = timestamp+num1;
	return timestamp;   	
}

//button click action
$("button").click(function() {
	retrieveJSONandPopulateData()
});
