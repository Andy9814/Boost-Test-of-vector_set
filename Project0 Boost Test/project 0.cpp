
#define BOOST_TEST_MODULE UNIT_TEST
#include <boost\test\unit_test.hpp>
#include<iostream>
#include<stack>
#include"vector_set.hpp"
#include<algorithm>

using namespace std;

// constructor A a
//destuctor ~A;
// copy constructor A b(a);
// Move constructor A c(move);
// 


// default constructor
#include<boost\mpl\list.hpp>
using test_types = boost::mpl::list<int, long, unsigned char, double>;
using string_test_types = boost::mpl::list<string>;
using bool_test_types = boost::mpl::list<bool>;
BOOST_AUTO_TEST_CASE_TEMPLATE(default_constructor_test, T,test_types) 
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



BOOST_AUTO_TEST_CASE_TEMPLATE(test,T, test_types)
{
	vector_set<T> v;
	//BOOST_CHECK(v.empty());
	//BOOST_CHECK(v.size() == 0);
	//BOOST_CHECK(v.capacity() == 0);
	//
	BOOST_CHECK(v.begin() == nullptr);

	for (size_t i = 1; i <= 10; ++i) {
		v.insert(i);
		BOOST_CHECK(v.size() == i );
		BOOST_CHECK(!v.empty());

	}
	BOOST_CHECK(v.size() == 10);

	
// check for the iterators

	for (size_t i= 0; i < 10; ++i) {
		BOOST_CHECK(*(v.begin()) == 1);
		BOOST_CHECK(*(v.end() - 1) == 10);
		BOOST_CHECK(*(v.begin() + i) == i+1);

	}



	for (size_t i = 0; i < 10; ++i) {
		BOOST_CHECK_EQUAL(*(v.cbegin()) , 1);
		BOOST_CHECK(*(v.cend() - 1) == 10);
		BOOST_CHECK_MESSAGE(*(v.cbegin() + i) == i + 1,"Error *(v.being() should be equal to i");

	}



	for ( size_t  i = 0; i < 10; ++i) {
		BOOST_CHECK_EQUAL( *(v.cbegin()),   1);
		BOOST_CHECK( *(v.cend() - 1) ==  10);
		BOOST_CHECK_MESSAGE(*(v.cbegin() + i) == i + 1, "Error *(v.being() should be equal to i");
	}
	

	for ( size_t i = 0; i < 10; ++i) {
		BOOST_CHECK_EQUAL(*(v.rbegin()), 10);
		BOOST_CHECK(*(v.rend() - 1) == 1);

	BOOST_CHECK_MESSAGE(*(v.rbegin() )-i == 10 - i , "Error *(v.being() should be equal to i");

	}



	for (size_t i = 0; i < 10; ++i) {
		BOOST_CHECK_EQUAL(*(v.crbegin()), 10);
		BOOST_CHECK(*(v.crend() - 1) == 1);

		BOOST_CHECK_MESSAGE(*(v.crbegin()) - i == 10 - i, "Error *(v.being() should be equal to i");

	}


	
	BOOST_CHECK(v.end() != nullptr);
BOOST_CHECK(v.cbegin() != nullptr);
	BOOST_CHECK(*v.cbegin() == 1);
	BOOST_CHECK(*(v.cend()-1) == 10);

}


 
/*
Method = copy constructor
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(c_constructor_test, T,test_types)
{
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);

	v = { 1,2,3,4,5,6,7,8,9,10 };
	
	// check the size
	BOOST_CHECK(!v.empty());
	BOOST_CHECK(v.size() != 0);
	BOOST_CHECK(v.capacity() != 0);
	
	vector_set<T>:: iterator it = v.begin();



	// check the pointers
	BOOST_CHECK(*(v.begin()) == 1);
	BOOST_CHECK(*(v.end() - 1) == 10);

	BOOST_CHECK(v.end() != nullptr);
	BOOST_CHECK(v.cbegin() != nullptr);
	BOOST_CHECK(*v.cbegin() == 1);
	BOOST_CHECK(*(v.cend()-1) == 10);
	


	// now the copied one.
	vector_set<T> v_copy(v);

	 
	BOOST_CHECK(!v_copy.empty());

	BOOST_CHECK(v_copy.size() != 0);

	BOOST_CHECK(*v.begin() == *v_copy.begin());
	BOOST_CHECK((v_copy.begin()) != nullptr);
	BOOST_CHECK((*v_copy.begin()) == 1); // check whether the copy's ifrst element is 1
	BOOST_CHECK(*(v.end()-1) == *(v_copy.end()-1));
	// check for address
	BOOST_CHECK(&(*v.begin()) != &(*v_copy.begin()));// check whether ther address is equall

	

	BOOST_CHECK(&(*v.end()) != &(*v_copy.end()));// check whether ther address is equall



	vector_set<T>::iterator itCopy = v_copy.begin();
	
	for (; itCopy != v_copy.end(); ++itCopy, ++it) {

	// check each element
		BOOST_CHECK(*it== *itCopy);
	
	}

	// check the size

	BOOST_CHECK_EQUAL(v_copy.size() , v.size());
	BOOST_CHECK_MESSAGE(v_copy.capacity() == 10,"Error the capacity should be equall to 10");


}

// copy constructor in using string


BOOST_AUTO_TEST_CASE(string_copy_constructor_test)
{
	vector_set<string> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	v = { "hello", "mini","sing" };
	vector_set<string>::iterator it = v.begin();
	// check the size
	BOOST_CHECK(!v.empty());
	BOOST_CHECK(v.size() != 0);
	BOOST_CHECK(v.capacity() != 0);

	// check the pointers
	BOOST_CHECK(*(v.begin()) == "hello");
	BOOST_CHECK(*(v.end() - 1) == "sing");

	BOOST_CHECK(v.end() != nullptr);
	BOOST_CHECK(v.cbegin() != nullptr);
	BOOST_CHECK(*v.cbegin() == "hello");
	BOOST_CHECK(*(v.cend() - 1) == "sing");

	//// now the copied one.
	vector_set<string> v_copy(v);

	BOOST_CHECK(!v_copy.empty());

	BOOST_CHECK(v_copy.size() != 0);

	BOOST_CHECK(*v.begin() == *v_copy.begin());
	BOOST_CHECK((v_copy.begin()) != nullptr);
	BOOST_CHECK((*v_copy.begin()) == "hello"); // check whether the copy's ifrst element is 1


	BOOST_CHECK(&(*v.end()) != &(*v_copy.end()));// check whether ther address is equall

	auto i = 0;
	vector_set<string> ::iterator itCopy = v_copy.begin();

	for (; i < 3; ++itCopy, ++i,++it) {
	//	//check before element does not move
		BOOST_CHECK(*(v_copy.begin() + i) == *itCopy);
		BOOST_CHECK(*it == *itCopy);

	}

}




/*
Method - Move Constructor
purpose - test move Constructor
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(move_const_test, T,test_types)
{
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);

	v = { 1,2,3,4,5,6,7,8,9,10 };


	// check the size
	BOOST_CHECK(!v.empty());
	BOOST_CHECK(v.size() != 0);
	BOOST_CHECK(v.capacity() != 0);

	// create the iterator
	vector_set<T>::iterator it = v.begin();



	// check the pointers
	BOOST_CHECK(*(v.begin()) == 1);
	BOOST_CHECK(*(v.end() - 1) == 10);
	
	BOOST_CHECK(v.end() != nullptr);
	BOOST_CHECK(v.cbegin() != nullptr);
	BOOST_CHECK(*v.cbegin() == 1);
	BOOST_CHECK(*(v.cend() - 1) == 10);



	
	// new vector with moving constructor

	vector_set<T>v_Move(move(v));

	
	BOOST_CHECK(v.empty());
	BOOST_CHECK_EQUAL(v.size(),0);
	BOOST_CHECK_EQUAL(v.capacity(),0);
	BOOST_CHECK_MESSAGE(v.begin() == nullptr,"now the v is nullptr");
	


	BOOST_CHECK_EQUAL(v_Move.size(), 10);
	BOOST_CHECK(!v_Move.empty());
	BOOST_CHECK(v_Move.size() != 0);

	BOOST_CHECK(v_Move.capacity() != 0);

	auto t = 1;
	vector_set<T> ::iterator itMove = v_Move.begin();
	for (; itMove != v_Move.end(); ++itMove, ++t) {


		//check before element does not move
		BOOST_CHECK_EQUAL(*itMove,t);
		


	}
	// the iterator  will be same
	BOOST_CHECK(it != itMove);
	BOOST_CHECK(v.begin() != v_Move.begin());

	
}







/*
Method = move  string construtor
purpose = test move constructor for string
*/

BOOST_AUTO_TEST_CASE(string_move_const) {


	vector_set<string> v = { "abc","cba" };


	
	BOOST_CHECK_MESSAGE(!v.empty(),"vector is not empty, so it is an error");
	
	BOOST_CHECK_EQUAL(!v.capacity(),0);
	BOOST_CHECK_EQUAL(!v.size(), 0);

	vector_set<string> vMove(move(v));
	// check the moved vector
	BOOST_CHECK(!vMove.empty());
	BOOST_CHECK(vMove.size() != 0);
	BOOST_CHECK(vMove.capacity() != 0);



	BOOST_CHECK(vMove.size() == 2);
	BOOST_CHECK_EQUAL(*vMove.begin() , "abc");
	BOOST_CHECK_EQUAL(*(vMove.begin()+1), "cba");

	// check the original vector should be empty
	

	BOOST_CHECK(v.empty());
	BOOST_CHECK_EQUAL(v.size(), 0);
	BOOST_CHECK_EQUAL(v.capacity(), 0);
	BOOST_CHECK_MESSAGE(v.begin() == nullptr, "now the v is nullptr");


}



BOOST_AUTO_TEST_CASE_TEMPLATE(bool_move_const,T,test_types) {


	vector_set<bool> v = { false,true };



	BOOST_CHECK_MESSAGE(!v.empty(), "vector is not empty, so it is an error");

	BOOST_CHECK_EQUAL(!v.capacity(), 0);
	BOOST_CHECK_EQUAL(!v.size(), 0);
	


	vector_set<bool> vMove(move(v));
	//// check the moved vector
	BOOST_CHECK(!vMove.empty());
	BOOST_CHECK(vMove.size() != 0);
	BOOST_CHECK(vMove.capacity() != 0);



	BOOST_CHECK(vMove.size() == 2);
	BOOST_CHECK_EQUAL(*vMove.begin(), false);
	BOOST_CHECK_EQUAL(*(vMove.begin() + 1), true);

	//// check the original vector should be empty


	BOOST_CHECK(v.empty());
	BOOST_CHECK_EQUAL(v.size(), 0);
	BOOST_CHECK_EQUAL(v.capacity(), 0);
	BOOST_CHECK_MESSAGE(v.begin() == nullptr, "now the v is nullptr");


}







// insert
BOOST_AUTO_TEST_CASE_TEMPLATE(insertt,T,test_types) {
	vector_set<int> v;
	BOOST_CHECK(v.empty());
		BOOST_CHECK(v.size() == 0);
		BOOST_CHECK(v.capacity() == 0);
		
		v.insert(1);
		v.insert(2);
		v.insert(3);
		v.insert(4); 
			v.insert(5);
			v.insert(6);
			v.insert(7);
			v.insert(8);
			v.insert(9);
		


//	v.lower_bound(v.begin());


	//	BOOST_CHECK(v.capacity() == ( v.end()-1*2));
	BOOST_CHECK(v.size() != 0);
	
	//auto insertLocation = lower_bound(v.begin(), v.end()), 1);

	//v.insert(1);


	//BOOST_CHECK(v.capacity() == *(v.end()-1));
	//BOOST_CHECK();
}



/*
Method = erase
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(erase_test,T,test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);



// insert some element in it
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



/*
Method = erase
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(erase_string_test, T, string_test_types ) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);

	//insert some element

	v.insert("kylie");
	v.insert("kendel");
	v.insert("khole");
		v.insert("chris");
		v.insert("jenner");
		v.insert("kim");
		v.insert("kimc");
		v.insert("kima");
		v.insert("kimab");

		// let check if it is sorted
		BOOST_CHECK(*(v.begin()) == "chris");
BOOST_CHECK(*(v.begin()+1 )== "jenner");
BOOST_CHECK(*(v.begin() + 2) == "kendel");
// check for kim

BOOST_CHECK(*(v.begin()+4) == "kim");

BOOST_CHECK(*(v.begin() + 5) == "kima");

BOOST_CHECK(*(v.begin() + 6) == "kimab");
BOOST_CHECK(*(v.begin() + 7) == "kimc");


	auto valueToDelete = "kim";
	auto pos = v.begin() ;

	BOOST_CHECK(*(v.begin()) == "chris");
	BOOST_CHECK(*(v.begin()+1) == "jenner");
	BOOST_CHECK(v.size() == 9);
	v.erase(pos);
	// check  the value after 5 the move forward;
	BOOST_CHECK(*(v.begin() ) != "kim");
	

	BOOST_CHECK(v.size() == 8);

	// after deleting the kim see the elements before does not move but element after move forward

	
	
	BOOST_CHECK(*(v.begin() + 4) != "kim");
	BOOST_CHECK(*(v.begin() + 4) == "kima");
	BOOST_CHECK(*(v.begin() + 5) != "kima");
	BOOST_CHECK(*(v.begin() + 5) == "kimab");



	
	//auto pos1 = v.begin() + 2;
	v.erase(v.begin() + 3);
	BOOST_CHECK(*(v.begin() + 3) != "khole");

	BOOST_CHECK(*(v.begin() + 3) == "kima");



}


/*
Method = erase
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(bool_string_test, T, bool_test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);

	//insert some element

	v.insert(true);
	

	auto valueToDelete = true;
	auto pos = v.begin();

	
	BOOST_CHECK(v.size() == 1);
	v.erase(pos);

	BOOST_CHECK_EQUAL(v.size() , 0);
}

 /*
 Method = erase range
 */

BOOST_AUTO_TEST_CASE_TEMPLATE(erase_test_range,T,test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);



	
	for (size_t i = 1; i <= 10; ++i) {
		v.insert(i);
		BOOST_CHECK(v.size() == i);
		BOOST_CHECK(!v.empty());
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






/*
Method = erase range
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(string_erase_test_range, T, string_test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	v= {"andy","tina","kevin","jared","julia"};
	auto first = v.begin();
	auto last = v.begin() + 2;

	BOOST_CHECK(v.size() == 5);

	v.erase(first, last);

	BOOST_CHECK(v.size() == 3);
	BOOST_CHECK(*v.begin() == "julia");
	// we can see that kevin and tina has not affected , there order was same as it was after sorting
		BOOST_CHECK(*(v.begin() + 1) == "kevin");
	BOOST_CHECK(*(v.begin() + 2) == "tina");	
}



// clear method
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


/*
Method  = clear using string
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(string_clear_test, T, string_test_types) {
	vector_set<T> v = { "andy","tina","kevin","jared","julia" };
	BOOST_CHECK(!v.empty());
	BOOST_CHECK_EQUAL(!v.size(), 0);
	BOOST_CHECK_EQUAL(!v.capacity(), 0);
	v.clear();
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	// check capacity it should not be 0;
	BOOST_CHECK_MESSAGE(v.capacity() != 0,"Error capacity should not be zero");

}




/*
Method = copy assign operator*/
BOOST_AUTO_TEST_CASE_TEMPLATE(copy_optor,T, test_types) {
	vector_set<T> v;


	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);



		vector_set<T>::iterator it1 = v.begin();
	for (size_t i = 1; i <= 10; ++i) {
		v.insert(i);
		//	cout << "*it  = " << *it1 << endl;
		BOOST_CHECK(v.size() == i);
		BOOST_CHECK(!v.empty());
		/*BOOST_CHECK(*it1 == i);
		cout << "*it1  " << *it1 << endl;*/
		;
	}

	//checking capacity
	BOOST_CHECK(v.capacity() >= v.size());

	auto i = 0;
	for (vector_set<T> ::iterator it = v.begin(); it <= v.begin()+9; ++it, ++i) {
		
		
		//check before element does not move
		BOOST_CHECK(*(v.begin() + i) == *it);
		//BOOST_CHECK(v.size() == i+1);

	}
	





	//copy 
	vector_set<T> v_Copy;
	BOOST_CHECK(v_Copy.capacity() <= v.size());
	BOOST_CHECK(v_Copy.capacity() == 0);
	// now assign the value to the copy make a new buffer
	v_Copy = v;
	BOOST_CHECK(v_Copy.capacity() >= v.size());
	BOOST_CHECK(v_Copy.capacity() != 0);


	BOOST_CHECK(v_Copy.begin() != v.begin());
	BOOST_CHECK(v_Copy.size() == v.size());


	auto f = 0;
	for (size_t i = 1; i <= 10; ++i,++f) {
	
		//	cout << "*it  = " << *it1 << endl;
		BOOST_CHECK(*v_Copy.begin() == *v.begin());
		BOOST_CHECK(*(v_Copy.begin() +f) == *(v.begin()+f));
		// the end pointer should have different address
		BOOST_CHECK(&(*v_Copy.end()) != &(*v.end()));
		

		BOOST_CHECK(!v.empty());
		
		
	}
//	vector_set<T> v_Copy2{ 11,12,13,1,41,51,6 };
//	vector_set<T> v_Copy3{ 11,12,13,1,41,51,6 };
//
//	// equal assignoperator
//BOOST_CHECK_MESSAGE(v_Copy2 == v_Copy3,"Error They shoudl be equall");
//	BOOST_CHECK(v== v_Copy);
//	BOOST_CHECK(v != v_Copy2);
//	BOOST_CHECK(v != v_Copy3);
//	BOOST_CHECK(v > v_Copy2);
//	BOOST_CHECK(v > v_Copy3);
//
}

/*
Method = copy string assign operator*/
BOOST_AUTO_TEST_CASE(copy_string_optor) {
	vector_set<string> v{"aaa","abc","Andy","kim","kylie"};

	vector_set<string>::iterator it1 = v.begin();
		BOOST_CHECK(v.size() == 5);
		BOOST_CHECK(!v.empty());

	//checking capacity
	BOOST_CHECK(v.capacity() >= v.size());

	//copy 
	vector_set<string> v_Copy;
	BOOST_CHECK(v_Copy.capacity() <= v.size());
	BOOST_CHECK(v_Copy.capacity() == 0);
	// now assign the value to the copy make a new buffer
	v_Copy = v;
	BOOST_CHECK(v_Copy.capacity() >= v.size());
	BOOST_CHECK(v_Copy.capacity() != 0);


	BOOST_CHECK(v_Copy.begin() != v.begin());
	BOOST_CHECK(v_Copy.size() == v.size());


	auto f = 0;
	for (size_t i = 1; i <= 5; ++i, ++f) {

		//	cout << "*it  = " << *it1 << endl;
		BOOST_CHECK(*v_Copy.begin() == *v.begin());
		BOOST_CHECK(*(v_Copy.begin() + f) == *(v.begin() + f));
		// the end pointer should have different address
		BOOST_CHECK(&(*v_Copy.end()) != &(*v.end()));


		BOOST_CHECK(!v.empty());


	}
	vector_set<string> v_Copy2{ "arz","AIP","lilly" };
	vector_set<string> v_Copy3{ "arz","AIP","lilly" };

	// equal assignoperator
	BOOST_CHECK_MESSAGE(v_Copy2 == v_Copy3, "Error They shoudl be equall");
	BOOST_CHECK(v == v_Copy);
	BOOST_CHECK(v != v_Copy2);
	BOOST_CHECK(v != v_Copy3);
	BOOST_CHECK(v > v_Copy2);
	BOOST_CHECK(v > v_Copy3);

}


// move assignment operator
BOOST_AUTO_TEST_CASE_TEMPLATE(move_optor, T, test_types) {
	vector_set<T> v;


	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);

	v ={ 1,2,3,4,5,6,7,8,9,10 };

	
	//for (size_t i = 1; i <= 10; ++i) {
	//	v.insert(i);
	//	//	cout << "*it  = " << *it1 << endl;
	//	BOOST_CHECK(v.size() == i);
	//	BOOST_CHECK(!v.empty());
	//	/*BOOST_CHECK(*it1 == i);
	//	cout << "*it1  " << *it1 << endl;*/
	//	;
	//}

	//checking capacity
	BOOST_CHECK(v.capacity() >= v.size());

	vector_set<T> ::iterator it = v.begin();
	cout << "*it ==== "<<*it << endl;

	auto i = 0;
	for (; it <= v.begin() + 9; ++it, ++i) {


		//check before element does not move
		BOOST_CHECK(*(v.begin() + i) == *it);
		//BOOST_CHECK(v.size() == i+1);

	}



	//move
	vector_set<T> v_Move = move(v);
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);

	BOOST_CHECK(v_Move.size() == 10);
	BOOST_CHECK(!v_Move.empty());
	BOOST_CHECK(v_Move.size() != 0);

	BOOST_CHECK(v_Move.capacity() != 0);

	cout << "*it ==== "<<*it << endl;


	//check all the values
	auto t = 0;
	vector_set<T> ::iterator itMove = v_Move.begin();
	for (; itMove != v_Move.end(); ++itMove, ++t) {


		//check before element does not move
		BOOST_CHECK(*(v_Move.begin() + t) == *itMove);
		//BOOST_CHECK(v.size() == i+1);

	}
	// the iterator  will be same
	BOOST_CHECK(it == itMove);
	BOOST_CHECK(v.begin() != v_Move.begin());
}

// operator initializer
using test_types = boost::mpl::list<int, long, unsigned char, double>;
BOOST_AUTO_TEST_CASE_TEMPLATE(intializerList_optor, T, test_types) {
	vector_set<T> v;
	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	BOOST_CHECK(v.begin() == nullptr);
	BOOST_CHECK(v.end() == nullptr);
	v = { 1,2,3,4,5,6,7,8,9,10 };

	BOOST_CHECK(!v.empty());
	BOOST_CHECK(v.size() != 0);
	BOOST_CHECK(v.capacity() != 0);
	BOOST_CHECK(v.begin() != nullptr);
	BOOST_CHECK(*v.begin() == 1);
	BOOST_CHECK(v.size() == 10);

}
/*
Method = equal operator == */
//
BOOST_AUTO_TEST_CASE_TEMPLATE(Equality_optor,T,test_types) {
	vector_set<T> v1 = { 1,2,3,4,5,6,7,8,9,10};
	vector_set<T> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v3= {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	vector_set<T> v4 = { 5, 6,7, 8, 9, 10 };
	vector_set<T> v5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	vector_set<T> v6;

	vector_set<T> v7;
	
	for (auto i = 1; i <= 10; ++i) {
		v7.insert(i);

	}
	for (auto i = 1; i <= 10; ++i) {
		v6.insert(i);

	}
	

	BOOST_CHECK(v1 == v2);
	BOOST_CHECK(v3 == v5);
	BOOST_CHECK(v2 != v4);
	BOOST_CHECK(v1 != v4);
	BOOST_CHECK(v3 != v4);
	BOOST_CHECK(v5 != v4);
	BOOST_CHECK(v6 == v7);
	BOOST_CHECK(v6 == v1);
	BOOST_CHECK(v6 != v4);

	
}


/*
Method =  equal_operator_bool*/
BOOST_AUTO_TEST_CASE(Equality_bool_optor) {
	vector_set<bool> v1 = {false};
	vector_set<bool> v2 = { false };
	vector_set<bool> v3;
	v3.insert(true);
	v3.insert(false);

	vector_set<bool> v4;
	v4.insert(true);
	v4.insert(false);
	

	vector_set<bool> v5;
	v5.insert(true);
	v5.insert(false);
	v5.insert(false);


	vector_set<bool> v6;
	v5.insert(true);
	v5.insert(false);
	v5.insert(true);



	BOOST_CHECK(v1 == v2);
	BOOST_CHECK(v3 == v4);
	BOOST_CHECK(v2 != v4);
	BOOST_CHECK(v1 != v4);
	BOOST_CHECK(v3 == v4);
	BOOST_CHECK(v5 == v4);
	BOOST_CHECK(v5 != v6);


}


/*
Method =  equal_operator_string*/
BOOST_AUTO_TEST_CASE(Equality_string_optor) {
	vector_set<string> v1 = { "abc","tro" };
	vector_set<string> v2 = { "cba" ,"ippo"};
	vector_set<string> v3;
	v3.insert("mini");
	v3.insert("sunny");

	vector_set<string> v4;
	v4.insert("mini");
	v4.insert("sunny");


	vector_set<string> v5;
	v5.insert("mini");
	v5.insert("sunny");
	v5.insert("cloudy");


	vector_set<string> v6;
	v5.insert("mini");
	v5.insert("sunny");
	v5.insert("citty");



	BOOST_CHECK(v1 != v2);
	BOOST_CHECK(v3 == v4);
	BOOST_CHECK(v2 != v4);
	BOOST_CHECK(v1 != v4);

	BOOST_CHECK(v5 != v4);
	BOOST_CHECK(v5 != v6);


}


/*
Method = equal operator !=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(operator_notEqual, T, test_types) {
	vector_set<T> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector_set<T> v4 = { 5, 6,7, 8, 9, 10 };
	vector_set<T> v5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	vector_set<T> v6;

	vector_set<T> v7;

	for (auto i = 1; i <= 100; ++i) {
		v7.insert(i);

	}
	for (auto i = 1; i <= 10; ++i) {
		v6.insert(i);

	}


	BOOST_CHECK(v3 != v1);
	BOOST_CHECK(v7 != v1);
	BOOST_CHECK(v7 != v6);
	BOOST_CHECK(v7 != v4);

	BOOST_CHECK(v2 != v4);
	BOOST_CHECK(v1 != v4);
	BOOST_CHECK(v3 != v4);
	BOOST_CHECK(v5 != v4);
	BOOST_CHECK(v6 != v4);
	BOOST_CHECK(v7 != v2);



}

/*
Method = equal operator != using string
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(string_operator_notEqual, T, string_test_types) {
	vector_set<T> v1 = {"abc","tro"};
	vector_set<T> v2 = {"cba","ippo"};
	vector_set<T> v3 = { "arz","AIP","lilly" };
	vector_set<T> v4 = { "arz","AIP","lillya" };
	vector_set<T> v5 = { "arz","AIP","lillyab" };
	BOOST_CHECK(v1 != v2);
	BOOST_CHECK(v2 != v3);
	BOOST_CHECK(v3 != v1);
	BOOST_CHECK(v2 != v4);
	BOOST_CHECK(v1 != v4);
	BOOST_CHECK(v3 != v4);
	BOOST_CHECK(v5 != v4);
}



/*
Method = equal operator != using bool
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(bool_operator_notEqual, T, bool_test_types) {
	vector_set<T> v1 = { true};
	vector_set<T> v2 = { false };
	
	BOOST_CHECK(v1 != v2);

}


/*
Method = equal operator <
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(operator_greaterThan,T, test_types) {
	vector_set<T> v1 = { 1,2,3,4,5,6,7,8,9,10 ,11};
	vector_set<T> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector_set<T> v4 = { 5, 6,7, 8, 9, 10 };
	vector_set<T> v5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	BOOST_CHECK(v2 < v1);
	BOOST_CHECK(v1 < v3);
	BOOST_CHECK(v2 < v4);
	BOOST_CHECK(v1 < v4);
	BOOST_CHECK(v3 < v4);
	BOOST_CHECK(v5 < v4);
}

/*
Method = equal string operator <
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(string_operator_greaterThan, T, string_test_types) {
	vector_set<T> v1 = { "abc","cde" };
	vector_set<T> v2 = { "abc" };
	vector_set<T> v3 = { "abc","cded"};
	vector_set<T> v4 = {"apple" };

	vector_set<T> v5 = { "mango"};
	vector_set<T> v6 = { "apples" };

	BOOST_CHECK(v2 < v1);
	BOOST_CHECK(v1 < v3);
	BOOST_CHECK(v4 < v5);
	BOOST_CHECK(v4 < v6);
	
}

/*
Method = equal bool operator <
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(bool_operator_greaterThan, T, bool_test_types) {
	vector_set<T> v1 = { true };
	vector_set<T> v2 = { false };



	BOOST_CHECK(v2 < v1);
	

}


/*
Method = equal operator >
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(operator_lessThan, T, test_types) {
	vector_set<T> v1 = { 1,2,3,4,5,6,7,8,9,10 ,11 };
	vector_set<T> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector_set<T> v4 = { 5, 6,7, 8, 9, 10 };
	vector_set<T> v5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	BOOST_CHECK(v1 > v2);
	BOOST_CHECK(v3 > v1);
	BOOST_CHECK(v4 > v2);
	BOOST_CHECK(v4 > v1);
	BOOST_CHECK(v4 > v3);
	BOOST_CHECK(v4 > v5);
}




/*
Method = equal string operator >
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(string_operator_lessThan, T, string_test_types) {
	vector_set<T> v1 = { "abc","cde" };
	vector_set<T> v2 = { "abc" };
	vector_set<T> v3 = { "abc","cded" };
	vector_set<T> v4 = { "apple" };

	vector_set<T> v5 = { "mango" };
	vector_set<T> v6 = { "apples" };

	BOOST_CHECK(v1 > v2);
	BOOST_CHECK(v3 > v1);
	BOOST_CHECK(v5 > v4);
	BOOST_CHECK(v6 > v4);

}



/*
Method = equal bool operator >
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(bool_operator_lessThan, T, bool_test_types) {
	vector_set<T> v1 = { true };
	vector_set<T> v2 = { false };
	BOOST_CHECK(v1 > v2);
}


/*
Method = equal operator >=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(operator_lessThanEquall, T, test_types) {
	vector_set<T> v1 = { 1,2,3,4,5,6,7,8,9,10  };
	vector_set<T> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector_set<T> v4 = { 5, 6,7, 8, 9, 10 };
	vector_set<T> v5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	BOOST_CHECK(v1 >= v2);
	BOOST_CHECK(v3 >= v1);
	BOOST_CHECK(v4 >= v2);
	BOOST_CHECK(v4 >= v1);
	BOOST_CHECK(v4 >= v3);
	BOOST_CHECK(v4 >= v5);
}




/*
Method = equal string operator >=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(string_operator_lessThanEquall, T, string_test_types) {
	vector_set<T> v1 = { "abc","cde" };
	vector_set<T> v2 = { "abc" };
	vector_set<T> v3 = { "abc","cded" };
	vector_set<T> v4 = { "apple" };

	vector_set<T> v5 = { "mango" };
	vector_set<T> v6 = { "apples" };
	vector_set<T> v7 = { "apples" };


	BOOST_CHECK(v1 >= v2);
	BOOST_CHECK(v3 >= v1);
	BOOST_CHECK(v5 >= v4);
	BOOST_CHECK(v6 >= v4);
	BOOST_CHECK(v6 >= v7);


}



/*
Method = equal bool operator >=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(bool_operator_lessThanEquall, T, bool_test_types) {
	vector_set<T> v1 = { true };
	vector_set<T> v2 = { false };
	vector_set<T> v3 = { false };

	BOOST_CHECK(v1 >= v2);
	BOOST_CHECK(v3 >= v2);

}



/*
Method = equal operator <=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(operator_greaterThanEquall, T, test_types) {
	vector_set<T> v1 = { 1,2,3,4,5,6,7,8,9,10  };
	vector_set<T> v2 = { 1,2,3,4,5,6,7,8,9,10 };
	vector_set<T> v3 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13 };
	vector_set<T> v4 = { 5, 6,7, 8, 9, 10 };
	vector_set<T> v5 = { 1,2,3,4,5,6,7,8,9,10,11,12,13 };
	BOOST_CHECK(v2 <= v1);
	BOOST_CHECK(v1 <= v3);
	BOOST_CHECK(v2 <= v4);
	BOOST_CHECK(v1 <= v4);
	BOOST_CHECK(v3 <= v4);
	BOOST_CHECK(v5 <= v4);
}

/*
Method = equal string operator <=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(string_operator_greaterThanEquall, T, string_test_types) {
	vector_set<T> v1 = { "abc","cde" };
	vector_set<T> v2 = { "abc" };
	vector_set<T> v3 = { "abc","cded" };
	vector_set<T> v4 = { "apple" };

	vector_set<T> v5 = { "mango" };
	vector_set<T> v6 = { "apples" };
	vector_set<T> v7 = { "apples" };


	BOOST_CHECK(v2 <= v1);
	BOOST_CHECK(v1 <= v3);
	BOOST_CHECK(v4 <= v5);
	BOOST_CHECK(v4 <= v6);
	BOOST_CHECK(v7 <= v6);


}

/*
Method = equal bool operator <=
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(bool_operator_greaterThanEquall, T, bool_test_types) {
	vector_set<T> v1 = { true };
	vector_set<T> v2 = { false };
	vector_set<T> v3 = { false };




	BOOST_CHECK(v2 <= v1);
	BOOST_CHECK(v2 <= v3);



}
/*
Method  = find
*/

BOOST_AUTO_TEST_CASE_TEMPLATE(find_test, T, test_types) {
	vector_set<T> v;
	for (auto i = 1; i <= 10; ++i) {
		v.insert(i);

	}
	for (auto i = 1; i <= 10; ++i) {
		BOOST_CHECK(*(v.find(i)) == i);

	}
	BOOST_CHECK(v.find(2) != v.end());
	BOOST_CHECK(v.find(5) == v.begin() + 4);
	BOOST_CHECK(*(v.find(6)) == 6);
	BOOST_CHECK(*(v.find(11)) != 11);

}

/*
find */
BOOST_AUTO_TEST_CASE_TEMPLATE(find_string_test, T, string_test_types) {
	vector_set<T> v = { "apple","mango","pineapple" };
	// check for apple if it is there untill it is stop
	BOOST_CHECK(v.find("apple") != v.end());
	BOOST_CHECK(v.find("pineapple") == v.begin() + 2);
	// find mango if it is in there
	BOOST_CHECK(*(v.find("mango")) == "mango");
	BOOST_CHECK(*(v.find("sam")) != "sam");

}

/*
Method = find  using bool value*/
BOOST_AUTO_TEST_CASE_TEMPLATE(find_bool_test, T, bool_test_types) {
	vector_set<T> v = { true};
	BOOST_CHECK(v.find(true) != v.end());
	BOOST_CHECK(v.find(true) == v.begin());
	BOOST_CHECK_EQUAL(*(v.find(true)),true);
	
}


/*
Method = capacity
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(capacity_test, T,test_types) {
	vector_set<T> v ;

	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	BOOST_CHECK(v.begin() == nullptr);
	BOOST_CHECK(v.end() == nullptr);

	for (auto i = 1; i <= 1000; ++i) {
		v.insert(i);
		

	}
	
	BOOST_CHECK_MESSAGE(v.capacity() >= v.size(),"Error since it cannot be equal because char is 256 not 1000");
}


/*
Method = capacity using string
 */
BOOST_AUTO_TEST_CASE_TEMPLATE(string_capacity_test, T, string_test_types) {
	vector_set<T> v;

	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	BOOST_CHECK(v.begin() == nullptr);
	BOOST_CHECK(v.end() == nullptr);

	for (auto i = 1; i <= 1000; ++i) {
		v.insert("Nripdeep singh");
	}

	// size == 1 since it is unique
	BOOST_CHECK_EQUAL(v.size(),1);

	BOOST_CHECK_MESSAGE(v.capacity() >= v.size(), "Error since it cannot be equal because char is 256 not 1000");
}


/*
Method = capacity using bool
*/
BOOST_AUTO_TEST_CASE_TEMPLATE(bool_capacity_test, T, bool_test_types) {
	vector_set<T> v;

	BOOST_CHECK(v.empty());
	BOOST_CHECK(v.size() == 0);
	BOOST_CHECK(v.capacity() == 0);
	BOOST_CHECK(v.begin() == nullptr);
	BOOST_CHECK(v.end() == nullptr);

	for (auto i = 1; i <= 1000; ++i) {
		v.insert(true);


	}
	BOOST_CHECK_EQUAL(v.size(), 1);

	BOOST_CHECK_MESSAGE(v.capacity() >= v.size(), "Error since it cannot be equal because char is 256 not 1000");
}


/*
Method = destructor*/
BOOST_AUTO_TEST_CASE_TEMPLATE(destructor_test, T, test_types) 
{
	
	vector_set<T> v ;

	// destructor is automatically called;

	
	
}

/*
Method = swap*/
BOOST_AUTO_TEST_CASE_TEMPLATE(swap_test, T, test_types)
{

	vector_set<T> v1= { 1 };
	vector_set<T> v2 = { 2 };
	swap(v1,v2);
	BOOST_CHECK(*(v2.begin())== 1);
	BOOST_CHECK(*(v1.begin()) == 2);

	


}


/*
Method = swap using string*/
BOOST_AUTO_TEST_CASE_TEMPLATE(swap_string_test, T, string_test_types)
{

	vector_set<T> v1 = { "Weekend" };
	vector_set<T> v2 = { "Eminem" };
	swap(v1, v2);
	BOOST_CHECK(*(v2.begin()) == "Weekend");
	BOOST_CHECK(*(v1.begin()) == "Eminem");

}



/*
Method = swap using bool*/
BOOST_AUTO_TEST_CASE_TEMPLATE(swap_bool_test, T, bool_test_types)
{

	vector_set<T> v1 = { true };
	vector_set<T> v2 = { false};
	swap(v1, v2);
	BOOST_CHECK(*(v2.begin()) == true);
	BOOST_CHECK(*(v1.begin()) == false);

}

// check for sorted vector_set
BOOST_AUTO_TEST_CASE_TEMPLATE(sort_Test, T, test_types) {
	vector_set<T> v1 = { 5,6,9,8,7,4,13,6,1,5,41,2 };

	BOOST_CHECK_MESSAGE(*(v1.begin()) == 1,"Error v1.begin should be 1 since it is sorted");
	BOOST_CHECK_EQUAL(*(v1.begin() + 1) , 2);
}

// check for sorted vector_set using string
BOOST_AUTO_TEST_CASE_TEMPLATE(sort_string_Test, T, string_test_types) {
	vector_set<T> v1 = {"z","d","u","p","a" };

	BOOST_CHECK_MESSAGE(*(v1.begin()) == "a", "Error v1.begin should be a since it is sorted");
	BOOST_CHECK_EQUAL(*(v1.begin() + 1), "d");
}



// check for UNIQUE vector_set
BOOST_AUTO_TEST_CASE_TEMPLATE(unique_Test, T, test_types) {
	vector_set<T> v1 = { 1,2,1,2,3,4,5,5,5,6,7,8,8,8,8,9,9,9 };

	BOOST_CHECK_MESSAGE(*(v1.begin()) == 1, "Error v1.begin should be 1 since it is sorted");
	BOOST_CHECK_EQUAL(*(v1.begin() + 2), 3);
	BOOST_CHECK_EQUAL(*(v1.end() - 1), 9);
	BOOST_CHECK_EQUAL(v1.size(), 9);


	BOOST_CHECK_EQUAL(*(v1.end() - 2), 8);

}

// check for sorted vector_set using string
BOOST_AUTO_TEST_CASE_TEMPLATE(unique_string_Test, T, string_test_types) {
	vector_set<T> v1 = { "z","d","u","p","a" };

	BOOST_CHECK_MESSAGE(*(v1.begin()) == "a", "Error v1.begin should be a since it is sorted");
	BOOST_CHECK_EQUAL(*(v1.begin() + 1), "d");
}