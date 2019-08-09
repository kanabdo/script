
/**

	This JavaScript function return an array of length 2 with sum of negative numbers and count the number of positive numbers. 
	e.g: input [1,2,3,4,5,6,7,8,9,10, -11,-12,-13] 
	     response is [ number of positive numbers, sum of negative numbers] like this [10,-36]
		 and if the array result is [0,0] it return empty strings like this [,];
		 
		 this function can be test using test_array_operator.html. it can be found at:  https://github.com/kanabdo/azavea

**/

	function countPositiveNumbersSumNegativeNumbers(_input) {
		var _values = _input.replace(/\s|\[|\]/g,"");
		    _values = _values.split(",");
		var _results = new Array();
		var _positiveNumberCounter = 0 ;
		var _sumNegativeNumber = 0 ;
		
		_values.forEach(function(_value){
			if (isNaN(_value)){
				alert("Please make sure all elements in the array are number ! " + _value + " is not a number.");
			}
			else{
				if (_value > 0){
					_positiveNumberCounter = _positiveNumberCounter + 1 ;
				}
				else{
					_sumNegativeNumber = _sumNegativeNumber + Number(_value) ;
				}
			}				
		});
		
		if (_positiveNumberCounter==0 && _sumNegativeNumber==0){
			_results[0] = "";
			_results[1] = "";
		}
		else{
			_results[0] = _positiveNumberCounter;
			_results[1] = _sumNegativeNumber;
		}
		
		return _results;
	}