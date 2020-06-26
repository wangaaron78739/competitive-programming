#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGITS = 18;


long long upper_digit_dp[MAX_DIGITS+1][MAX_DIGITS*9+1][2];
long long lower_digit_dp[MAX_DIGITS+1][MAX_DIGITS*9+1][2];

static int digit_sum(long target, long long (&dp)[MAX_DIGITS+1][MAX_DIGITS*9+1][2]) {
	int dig = 0;
	for(; target; target /= 10, dig++) {
		if (dig == 0) {
			for(int i=0;i<=9;i++) {
				if (i <= target%10)
					dp[0][i][1] = 1;
				else
					dp[0][i][0] = 1;
			}
		} else {
			for(int i=0;i<=9;i++) {
				if (i < target%10)
					for(int j=0;j<=MAX_DIGITS*9;j++) {
						dp[dig][min(j+i,MAX_DIGITS*9)][1] += dp[dig-1][j][0] + dp[dig-1][j][1];
					}
				else if (i == target%10) {
					for(int j=0;j<=MAX_DIGITS*9;j++) {
						dp[dig][min(j+i,MAX_DIGITS*9)][1] += dp[dig-1][j][1];
						dp[dig][min(j+i,MAX_DIGITS*9)][0] += dp[dig-1][j][0];
					}
				}
				else 
					for(int j=0;j<=MAX_DIGITS*9;j++) {
						dp[dig][min(j+i,MAX_DIGITS*9)][0] += dp[dig-1][j][0] + dp[dig-1][j][1];
					}
			}
		}
	}
	return dig-1;
 }

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	long long upper, lower;
	cin >> lower >> upper;
	int upper_dig = digit_sum(upper, upper_digit_dp);
	int lower_dig = digit_sum(lower, lower_digit_dp);
	long max_ticket = -1;
	for(int i=0;i<=MAX_DIGITS*9;i++) {
		upper_digit_dp[upper_dig][i][1] -= lower_digit_dp[lower_dig][i][1];
		assert(upper_digit_dp[upper_dig][i][1]>=0);
		if (upper_digit_dp[upper_dig][i][1]>max_ticket ) {
			max_ticket = upper_digit_dp[upper_dig][i][1];
		}
	}
	long ticket_count = 0;
	for(int i=0;i<=MAX_DIGITS*9;i++) {
		if (upper_digit_dp[upper_dig][i][1] == max_ticket) ticket_count++;
	}
	cout << ticket_count << endl;
	cout << max_ticket << endl;
	return 0;
}