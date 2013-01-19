/* 
max profit problem
Question: given a week's time series of a stock price

Goal: find maximum profit you could make in a week

Algorithm: profit is maximum when buy and hold during each up trend
           recursion, on the ith day, if we know max profit we can make start from (i+1)th day, if the price of (i+1)th day is larger than price of the ith day, add price[i-1]-price[i] to max profit


A more difficult version, if we need to pay commission fee
Algorithms: 
*/

#include <iostream>

using namespace std;

//for question 1
float max_profit(float* price, int i, int last) {
	if ( i<last ) {
		if ( price[i]<price[i+1])
			return price[i+1]-price[i]+max_profit(price,i+1,last);
		else
			return max_profit(price,i+1,last);
	}
	return 0;
}

//for question 2
const float tol = 0.0000001;
int end_up_trend(float* price, int start, int last) {
	for (int i=start+1; i<=last; i++) {
		if (price[i]-price[i-1]<tol) 
			return i-1;	
	}
	return last;
}

float max_profit2(float *price, float commission, int start, int last) {
	float maxp = 0;
	int end_up = end_up_trend(price, start, last);
	float sub_profit = price[end_up]-price[start]-commission;
	if (end_up != last) {
		if (sub_profit>tol) 
			return sub_profit + max_profit2(price, commission, end_up+1,last);
		else 
			return max_profit2(price, commission, end_up+1,last);

	
	} 

	if(sub_profit>tol)
		return sub_profit;
	else
		return 0;

}


int main() {
	float price[] = {1,4,5,2,3};
	int n = sizeof(price)/sizeof(float);
	float maxprofit = max_profit(price, 0, n);
	cout<<"max profit = "<<maxprofit<<endl;

	float maxprofit2 = max_profit2(price, 3, 0, n);
	cout<<"max profit with commission = "<<maxprofit2<<endl;

	maxprofit2 = max_profit2(price, 2, 0, n);
	cout<<"max profit with commission = "<<maxprofit2<<endl;

	maxprofit2 = max_profit2(price, 1, 0, n);
	cout<<"max profit with commission = "<<maxprofit2<<endl;

	maxprofit2 = max_profit2(price, 0.5, 0, n);
	cout<<"max profit with commission = "<<maxprofit2<<endl;

	return 0;
}

