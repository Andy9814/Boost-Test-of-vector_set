
#define BOOST_TEST_MODULE UNIT_TEST
#include <boost\test\unit_test.hpp>
#include<iostream>
#include<stack>
#include"vector_set.hpp"

using namespace std;

// constructor A a
//destuctor ~A;
// copy constructor A b(a);
// Move constructor A c(move);
// 


// default constructor
#include<boost\mpl\list.hpp>
using default_constructor_test_types = boost::mpl::list<int, long, unsigned char, double>;
BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_test, T, default_constructor_test_types) 
	{	
	vector_set<T> v_Def;
	//vector is empty
	BOOST_CHECK(v_Def.empty());
	BOOST_CHECK(v_Def.size() == 0);
	BOOST_CHECK(v_Def.capacity() == 0);

	// check the pointers
	BOOST_CHECK(v_Def.begin() == nullptr);
	BOOST_CHECK(v_Def.end() == nullptr);
	BOOST_CHECK(v_Def.cbegin() == nullptr);
	BOOST_CHECK(v_Def.cend() == nullptr);
	

   // reverse iterator 
	BOOST_CHECK((v_Def.rbegin() == v_Def.rend()));
	BOOST_CHECK((v_Def.rend() == v_Def.rbegin ()));
	BOOST_CHECK((v_Def.crend() == v_Def.crbegin()));
	BOOST_CHECK((v_Def.crbegin()== v_Def.crend()));


	/*BOOST_CHECK(v_Def.cbegin() == nullptr);
*/
	

}

// Empty_copy construcotr

using copy_constructor_test_types = boost::mpl::list<int, long, unsigned char, double>;
BOOST_AUTO_TEST_CASE_TEMPLATE(copy_constructor_test, T, copy_constructor_test_types)
{
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	

	for (size_t i = 0; i < 10; ++i) {
		v.insert(i);
		BOOST_CHECK(v.size() == i + 1);
		BOOST_CHECK(!v.empty());
		BOOST_CHECK(*(v.begin()+i) == i );
	}


	

	/*for (int i = 0; i < 10; ++i) {
		
		BOOST_CHECK(*(v.begin()));
		v.erase(v.begin());


	
	
	}
*/

	

//
//	
//	// check the size
	BOOST_CHECK(!v.empty());
	BOOST_CHECK(!v.size() == 0);
	//BOOST_CHECK(v.capacity() == 0);
//
//
//
//
//	// check the pointers
	//BOOST_CHECK(*(v.begin()) == 1);
//   BOOST_CHECK(*(v.end()-1) == 10);
//	
	//BOOST_CHECK(v.end() != nullptr);
//BOOST_CHECK(v.cbegin() != nullptr);
//	BOOST_CHECK(*v.cbegin() == 1);
//	BOOST_CHECK(*(v.cend()-1) == 10);
//
//
////	
//
//// now the copied one.
	vector_set<T> v_copy(v);
	BOOST_CHECK(v_copy.capacity() == v_copy.size());
	
	BOOST_CHECK(!v_copy.empty());
	
	BOOST_CHECK(v_copy.size() != 0);

	BOOST_CHECK(*v.begin() == *v_copy.begin());
	BOOST_CHECK((v_copy.begin()) != nullptr);
//	BOOST_CHECK((*v_copy.begin()) == a); // check whether the copy's ifrst element is 1


	BOOST_CHECK(&(*v.end()) != &(*v_copy.end()));// check whether ther address is equall

	//check whether end ==  begin

}


// Empty_copy construcotr
//using c_constructor_test_types = boost::mpl::list<int, long, unsigned char, double>;
//BOOST_AUTO_TEST_CASE_TEMPLATE(c_constructor_test, T, c_constructor_test_types)
//{
//	vector_set<T> v;
//	BOOST_CHECK(v.empty());
//	BOOST_CHECK(v.size() == 0);
//	BOOST_CHECK(v.capacity() == 0);
//
//	//int a = 1, b = 2.0;
//	double a = 45.2, b = 55.3;
//	//string a = "hello", b = "mini";
//	v.insert(a);
//	v.insert(b);
//	// check the size
//	BOOST_CHECK(!v.empty());
//	BOOST_CHECK(v.size() != 0);
//	BOOST_CHECK(v.capacity() != 0);
//	//BOOST_CHECK(v.size() == v.size());
//
//
//
//
//	// check the pointers
//	BOOST_CHECK(*(v.begin()) == a);
//	BOOST_CHECK(*(v.end() - 1) == b);
//
//	BOOST_CHECK(v.end() != nullptr);
//	BOOST_CHECK(v.cbegin() != nullptr);
//	BOOST_CHECK(*v.cbegin() == a);
//	BOOST_CHECK(*(v.cend()-1) == b);
//	
//
//
//	//	
//	//
//	//// now the copied one.
//	vector_set<T> v_copy(v);
//
//	BOOST_CHECK(!v_copy.empty());
//
//	BOOST_CHECK(v_copy.size() != 0);
//
//	BOOST_CHECK(*v.begin() == *v_copy.begin());
//	BOOST_CHECK((v_copy.begin()) != nullptr);
//	BOOST_CHECK((*v_copy.begin()) == a); // check whether the copy's ifrst element is 1
//
//
//	BOOST_CHECK(&(*v.end()) != &(*v_copy.end()));// check whether ther address is equall
//
//
//}
//
//// copy constructor in using string
//

//using cString_constructor_test_types = boost::mpl::list<int, long, unsigned char, double>;
//BOOST_AUTO_TEST_CASE_TEMPLATE(cstring_constructor_test, T, cString_constructor_test_types)
//{
//	vector_set<string> v;
//	BOOST_CHECK(v.empty());
//	BOOST_CHECK(v.size() == 0);
//	BOOST_CHECK(v.capacity() == 0);
//
//	string a = "hello", b = "mini";
//	v.insert(a);
//	v.insert(b);
//	// check the size
//	BOOST_CHECK(!v.empty());
//	BOOST_CHECK(v.size() != 0);
//	BOOST_CHECK(v.capacity() != 0);
//	//BOOST_CHECK(v.size() == v.size());
//
//
//
//
//	// check the pointers
//	BOOST_CHECK(*(v.begin()) == a);
//	BOOST_CHECK(*(v.end() - 1) == b);
//
//	BOOST_CHECK(v.end() != nullptr);
//	BOOST_CHECK(v.cbegin() != nullptr);
//	BOOST_CHECK(*v.cbegin() == a);
//	BOOST_CHECK(*(v.cend() - 1) == b);
//
//
//
//	//	
//	//
//	//// now the copied one.
//	vector_set<string> v_copy(v);
//
//	BOOST_CHECK(!v_copy.empty());
//
//	BOOST_CHECK(v_copy.size() != 0);
//
//	BOOST_CHECK(*v.begin() == *v_copy.begin());
//	BOOST_CHECK((v_copy.begin()) != nullptr);
//	BOOST_CHECK((*v_copy.begin()) == a); // check whether the copy's ifrst element is 1
//
//
//	BOOST_CHECK(&(*v.end()) != &(*v_copy.end()));// check whether ther address is equall
//
//
//}


using test_types = boost::mpl::list<int, long, unsigned char, double>;

BOOST_AUTO_TEST_CASE_TEMPLATE(insertt,T,test_types) {
	vector_set<int> v;
	BOOST_CHECK(v.empty());
		BOOST_CHECK(v.size() == 0);
		BOOST_CHECK(v.capacity() == 0);
		cout << v.capacity() << endl;
		v.insert(1);
		v.insert(2);
		v.insert(3);
		v.insert(4); 
			v.insert(5);
			v.insert(6);
			v.insert(7);
			v.insert(8);
			v.insert(9);
		cout << v.capacity() << endl;


//	v.lower_bound(v.begin());


	//	BOOST_CHECK(v.capacity() == ( v.end()-1*2));
	BOOST_CHECK(v.size() != 0);
	
	//auto insertLocation = lower_bound(v.begin(), v.end()), 1);

	//v.insert(1);


	//BOOST_CHECK(v.capacity() == *(v.end()-1));
	//BOOST_CHECK();
}



// clear 
using test_types = boost::mpl::list<int, long, unsigned char, double>;

BOOST_AUTO_TEST_CASE_TEMPLATE(erase_test,T,test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);



//	vector_set<int>::iterator it1 = v.begin();
	for (size_t i = 1; i <= 10; ++i) {
		v.insert(i);
	
		BOOST_CHECK(v.size() == i );
		BOOST_CHECK(!v.empty());
		//BOOST_CHECK(*it1 == i);
	}

	auto valueToDelete = 5;
	auto pos = v.begin() + 4;

	BOOST_CHECK(*(v.begin() + 4) == valueToDelete);
	BOOST_CHECK(v.size() == 10);
	v.erase(pos);
	// check  the value after 5 the move forward;
	BOOST_CHECK(*(v.begin() + 4) == 6);
	BOOST_CHECK(v.size() == 9);



	auto i = 0; 
		for (vector_set<T> ::iterator it = v.begin(); it <= v.begin() + 3; ++it,++i) {

			//check before element does not move
		BOOST_CHECK(*(v.begin() + i) == *it);

	}

}

 //erase for range of element
using test_types = boost::mpl::list<int, long, unsigned char, double>;

BOOST_AUTO_TEST_CASE_TEMPLATE(erase_test_range,T,test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);



	//	vector_set<int>::iterator it1 = v.begin();
	for (size_t i = 1; i <= 10; ++i) {
		v.insert(i);
		//	cout << "*it  = " << *it1 << endl;
		BOOST_CHECK(v.size() == i);
		BOOST_CHECK(!v.empty());
		//BOOST_CHECK(*it1 == i);
	}

	//for (auto e : v) {
	//	cout << "in the vector = " << e << endl;
	//}

	auto first = v.begin();
	auto last = v.begin() + 5;

	v.erase(first, last);


	BOOST_CHECK(v.size() == 5);

	auto i = 0; 
	auto d = 6;
		for (vector_set<T> ::iterator it = v.begin(); it <= v.begin() + 4; ++it,++i,++d) {

			//check before element does not move
		BOOST_CHECK(*(v.begin() + i) == *it);
		BOOST_CHECK(*it == d);

	}
}


// clear method
using test_types = boost::mpl::list<int, long, unsigned char, double>;

BOOST_AUTO_TEST_CASE_TEMPLATE(clear_test, T, test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);



	//	vector_set<int>::iterator it1 = v.begin();
	for (size_t i = 1; i <= 10; ++i) {
		v.insert(i);
		//	cout << "*it  = " << *it1 << endl;
		BOOST_CHECK(v.size() == i);
		BOOST_CHECK(!v.empty());
		//BOOST_CHECK(*it1 == i);
	}

	

	

	v.clear();
	

	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.empty());





	auto i = 0;
	auto d = 6;
	for (vector_set<T> ::iterator it = v.begin(); it <= v.begin() + 9; ++it, ++i, ++d) {

		//check whether the element is zero
		BOOST_CHECK(*(v.begin() + i) == 0);
		BOOST_CHECK(*it == 0);

	}
}





