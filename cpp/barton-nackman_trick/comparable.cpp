/*
 * Demo of Barton–Nackman trick to implement a comparable mixin.
 *
 * Reference:
 *   http://en.wikipedia.org/wiki/Barton%E2%80%93Nackman_trick
 */

#include <cassert>

template <typename T>
class comparable {
	friend bool operator!=(const T& lhs, const T& rhs) { return lhs.less_than(rhs) || rhs.less_than(lhs); }
	friend bool operator==(const T& lhs, const T& rhs) { return !(lhs != rhs); }
	friend bool operator<(const T& lhs, const T& rhs) { return lhs.less_than(rhs); }
	friend bool operator<=(const T& lhs, const T& rhs) { return lhs.less_than(rhs) || lhs == rhs; }
	friend bool operator>(const T& lhs, const T& rhs) { return rhs.less_than(lhs); }
	friend bool operator>=(const T& lhs, const T& rhs) { return rhs.less_than(lhs) || lhs == rhs; }
};

class MyInt : private comparable<MyInt> {
public:
	MyInt(int v) : data(v) {}
	bool less_than(const MyInt &x) const { return data < x.data; }
private:
	int data;
};

class MyAbsInt : private comparable<MyAbsInt> {
public:
	MyAbsInt(int v) : data(v) {}
	bool less_than(const MyAbsInt &x) const { return abs(data) < abs(x.data); }
private:
	int data;
};

int main(int argc, char const *argv[])
{
	MyInt zero(0), zer0(0), one(1);

	assert((zero == zer0) == true);
	assert((zero == one) == false);

	assert((zero < one) == true);
	assert((one > zero) == true);

	assert((zero <= zer0) == true);
	assert((zero >= zer0) == true);

	assert((one <= zero) == false);
	assert((one >= zero) == true);

	MyAbsInt neg_two(-2), pos_one(1);

	assert((neg_two > pos_one) == true);
	assert((neg_two >= pos_one) == true);

	return 0;
}