#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'waysToChooseSum' function below.
 *
 * The function is expected to return a LONG_INTEGER_ARRAY.
 * The function accepts following parameters:
 *  1. LONG_INTEGER lowLimit
 *  2. LONG_INTEGER highLimit
 */

// This routine is extremely sensitive to integer overflows
// make sure you have ints and longs working

#include <math.h>
constexpr int DEBUG = 100;
constexpr long MAX_RANGE = 1'000'000'000'000'000'000l; //1e18

// Count for digits sum from n+1 digits of 00... to 9999.
// Result must be long to avoid overflow
typedef unordered_map<int, long> integer_map_t;

static auto initialize_precount(int max_digits) ->
    vector< integer_map_t > {
        vector<integer_map_t> r = { { { 0, 1 } } };

    for (int i = 1; i <= max_digits; i++) {
        integer_map_t map;
        for(int j=0; j<=9; j++) {
            for(const auto &k: r[i-1]) {
                map[j+k.first] += k.second;
            }
        }
        r.push_back(map);
    }
    return r;
}

// zero indexed digit from right
static auto nth_digit_from_right(long x, int d) -> int {
    long y = x;
    for (int i=0; i < d; i++) {
        y = y / 10;
    }
    if (y==0) {
        return 0;
    } else {
        return y % 10;
    }
}

ostream &operator << ( ostream &output, const integer_map_t &m) {
    for (const auto &j : m) {
        output << j.first << " " << j.second << endl;
    }
    return output;
}

ostream &operator << ( ostream &output, const vector<integer_map_t> &m) {
    for (const auto &i: m) {
        output << i << endl;
    }
    return output;
}

static int num_digits(long x) {
  return 1+ (long) log10(x);
}

static auto get_winners(const integer_map_t& m) ->
    vector<long> {
        long nways = 0;
        long nwinners = 0;
        vector<long> r;
        for (const auto &i: m) {
            if (i.second > nwinners) {
                nwinners = i.second;
                nways = 1;
            } else if (i.second == nwinners) {
                nways ++;
            }
        }
        if (DEBUG) {
            cout << "nways=" << nways << " nwinners=" << nwinners
                << endl;
        }
        r.push_back(nways);
        r.push_back(nwinners);
        return r;
    }

auto remove_matching_digits(long lowLimit, long highLimit) ->
    tuple<int, int> {
    int ndigits = num_digits(highLimit);
    int sum = 0;
    for (int i=ndigits-1; i >= 0; i--) {
        int low_digit = nth_digit_from_right(lowLimit, i);
        int high_digit = nth_digit_from_right(highLimit, i);
        if (low_digit == high_digit) {
            sum += low_digit;
            ndigits--;
        } else {
            break;
        }
    }
    return std::make_tuple(ndigits, sum);
}

void merge_precount(integer_map_t &count, 
    const vector<integer_map_t> &precount,
    int sum_to_add,
    int digits_to_merge) {
        for(const auto &j : precount[digits_to_merge]) {
            count[sum_to_add+j.first] += j.second;
        }
    }


// This algorithm first precomputes the totals for
// blocks of ndigits

// The algorithm splits the range into three parts.
// The first part consists of the numbers from lowLimit
// to a complete set of blocks.  The middle part consists
// of the numbers whose totals are precomputed from the
// range of blocks.  The high part consists of the
// numbers from the range of blocks to highLimit.


auto waysToChooseSum(long lowLimit, long highLimit) -> vector<long> {
    if (DEBUG) {
      cout << lowLimit << " " << highLimit << endl;
    }
    if (lowLimit < 1 || highLimit < lowLimit || highLimit >  MAX_RANGE) {
        throw std::invalid_argument("limits out of bounds");
    }
    auto precount = initialize_precount(num_digits(highLimit));
    if (DEBUG) {
      cout << "initial precounts" << endl
        << precount << endl;
    }
    int ndigits, sum;
    tie(ndigits, sum) = remove_matching_digits(lowLimit, highLimit);

    integer_map_t r;
    int low_digit = nth_digit_from_right(lowLimit, ndigits-1);
    int high_digit = nth_digit_from_right(highLimit, ndigits-1);

    if (DEBUG) {
      cout << "ndigits=" << ndigits << " sum=" << sum << endl;
        cout << "initial digits" << endl
            << low_digit << " " << high_digit << endl;
    }

    for (int i=low_digit+1; i<high_digit; i++) {
        merge_precount(r, precount,
            sum + i, ndigits - 1);
    }

    int low_sum = sum + low_digit;
    int high_sum = sum + high_digit;
  
    for (int i=ndigits-2; i >= 0; i--) {
        low_digit = nth_digit_from_right(lowLimit, i);
        high_digit = nth_digit_from_right(highLimit, i);
        for (int j = low_digit + 1; j <= 9; j++) {
            merge_precount(r, precount, j+low_sum, i);
        }
        low_sum += low_digit;
        for (int j = 0; j <= high_digit-1; j++) {
            merge_precount(r, precount, j+high_sum, i);
        }
        high_sum += high_digit;
    }
    r[low_sum]++;
    r[high_sum]++;

    long sum_counts = 0;
    for(const auto&i : r) {
        sum_counts += i.second;
    }

    if (sum_counts != (highLimit - lowLimit + 1)) {
        cout << "Internal error.  Results inconsistent" << endl;
        cout << "counts" << endl << r << endl;
 
        cout << "sum" << sum_counts << " "
            << highLimit - lowLimit + 1 << endl;
        throw std::runtime_error("internal error");
    }
    if (DEBUG) {
        cout << "counts" << endl << r << endl;
 
        cout << "sum" << sum_counts << " "
            << highLimit - lowLimit + 1 << endl;
    }
    return get_winners(r);
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    // ofstream fout(getenv("OUTPUT_PATH"));

    string lowLimit_temp;
    getline(cin, lowLimit_temp);

    long lowLimit = stol(ltrim(rtrim(lowLimit_temp)));

    string highLimit_temp;
    getline(cin, highLimit_temp);

    long highLimit = stol(ltrim(rtrim(highLimit_temp)));

    vector<long> result = waysToChooseSum(lowLimit, highLimit);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i];

        if (i != result.size() - 1) {
            cout << "\n";
        }
    }

    cout << "\n";


    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
