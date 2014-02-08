/* 
 * Demo of a general object counter with CRTP idiom.
 *
 * Reference: 
 *   http://en.wikipedia.org/wiki/Curiously_recurring_template_pattern
 *   http://www.drdobbs.com/cpp/counting-objects-in-c
 */

#include <iostream>
#include <cassert>

using namespace std;

template<class T>
class Counter {
public:
	static int created()
	{
		return num_created;
	}

	static int alive()
	{
		return num_alive;
	}

protected:
	Counter()
	{
		++num_created;		
		++num_alive;
	}

	~Counter()
	{
		--num_alive;
	}

private:
	static int num_created;
	static int num_alive;
};

template<class T> int Counter<T>::num_created = 0;
template<class T> int Counter<T>::num_alive = 0;

class A : private Counter<A> {
	int dummy;
};
static_assert(sizeof(A) == sizeof(int), "No addtional space overhead");

class B : private Counter<B> {
};

class AA : private Counter<AA>, public A {
};

int main(int argc, char const *argv[])
{	
	/* Prevent create instance of Counter class */
	// Counter<A> p;                       -> error: calling a protected constructor of class 'Counter<A>'
	// Counter<A> *pca = new Counter<A>(); -> error: calling a protected constructor of class 'Counter<A>'
	// Counter<A> *pa = new A();           -> error: cannot cast 'A' to its private base class 'Counter<A>'

	/* Tests for base usage */
	assert(Counter<A>::created() == 0);
	assert(Counter<B>::created() == 0);

	A a0;
	B b0;
	{ A a1, a2; }
	
	assert(Counter<A>::created() == 3);
	assert(Counter<A>::alive() == 1);
	assert(Counter<B>::created() == 1);
	assert(Counter<B>::alive() == 1);

	/* Tests for new/delete */
	B* pb = new B();
	assert(Counter<B>::created() == 2);
	assert(Counter<B>::alive() == 2);

	delete pb;
	assert(Counter<B>::created() == 2);
	assert(Counter<B>::alive() == 1);

	/* Tests for inherited class */
	AA aa0;
	{ AA aa1; }
	assert(Counter<A>::created() == 5);
	assert(Counter<A>::alive() == 2);
	assert(Counter<AA>::created() == 2);
	assert(Counter<AA>::alive() == 1);

	/* Tests for inherited class with polymorphism */
	AA* paa = new AA();
	assert(Counter<A>::created() == 6);
	assert(Counter<A>::alive() == 3);
	assert(Counter<AA>::created() == 3);
	assert(Counter<AA>::alive() == 2);

	delete paa;
	assert(Counter<A>::created() == 6);
	assert(Counter<A>::alive() == 2);
	assert(Counter<AA>::created() == 3);
	assert(Counter<AA>::alive() == 1);

	return 0;
}