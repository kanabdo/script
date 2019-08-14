/**
	input are two positive integers x,y and x > y 
	r = remainder
**/

function gcd(x,y){
	if(isNaN(x) || isNaN(y) ){
		alert("please make sure the two values are numbers");
		return false;
	}
	console.log( "gcd("+ x + "," + y +")") // helps to see initial values
	while(y) {
		var r = y;
		y = x % y;
		x = r;
		console.log( "= " + x + " + " + y) // helps to track the operations
	}			
	return x;
}

