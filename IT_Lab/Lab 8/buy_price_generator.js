qty = [2,4,1,5,3]
var Equity = 0

function populateBuyPriceColumn(stocksBuyPriceDict) {
	for(var i=0;i<5;i++){
		stockBuyPriceSelector = $("[data-label='Buy Price']").eq(i)
		stockBuyPriceSelector.text('$'+stockBuyPrices['Stock_'+(i+1)])
	}
}

function updatePortfolio(stockPrices) {
	Equity = 0
	for(var i=1;i<=5;i++) {
		Equity += stockPrices['Stock_'+i] * qty[i-1] 
	}
	$("[data-label='Equity']").text('$'+Equity.toFixed(2))
	$("[data-label='Equity']").css('color','purple')
}

function generateRandom(max, min) {
	num = (Math.random() * (max-min)) + min;
	return num
}

function priceGenerator() {
  max = 40
  min = 20
  price = generateRandom(max, min)
  return price.toFixed(2)
}

// *************** //

stockBuyPrices = {}
totalProfitnLoss = 0

//create dictionary of {stocks : prices}
for(var i=1;i<=5;i++) {
	stockBuyPrices['Stock_'+i] = priceGenerator()
}

populateBuyPriceColumn(stockBuyPrices); 
updatePortfolio(stockBuyPrices)


// **************** //
