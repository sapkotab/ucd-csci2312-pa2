// main.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "ErrorContext.h"
#include "ClusteringTests.h"

using std::cout;
using std::endl;

using namespace Testing;

int main() {

    const int NumIters = 3;

    cout << endl << "Testing PA2!!" << endl << endl;

    cout << "NOTE:  If you see any memory errors, you MUST fix them!" << endl;
    cout << "       Tests intentionally invoke destructors after they complete,"
    << endl;
    cout << "       so if you see a seg-fault after a passed test, it is"
    << endl;
    cout << "       probably a bug in your destructor." << endl;

    cout << endl;

    ErrorContext ec(cout);

    // point tests
    test_point_smoketest(ec);
    test_point_id(ec, NumIters);
    test_point_getsetelem(ec, NumIters);
    test_point_copying(ec, NumIters);
    test_point_assignment(ec, NumIters);
    test_point_equality(ec, NumIters);
    test_point_comparison(ec, NumIters);
    test_point_CAO(ec, NumIters);
    test_point_SAO(ec, NumIters);
    test_point_distance(ec, NumIters);
    test_point_IO(ec, NumIters);

//     cluster tests
    test_cluster_smoketest(ec);
    test_cluster_subscript(ec, NumIters);
    test_cluster_equality(ec, NumIters);
    test_cluster_order(ec, NumIters);
    test_cluster_addremove(ec, NumIters);
    test_cluster_contain(ec, NumIters);
    test_cluster_copying(ec, NumIters);
    test_cluster_assignment(ec, NumIters);
    test_cluster_CAO(ec, NumIters);
    test_cluster_SAO(ec, NumIters);
    test_cluster_IO(ec, NumIters);

    return 0;
}
//#include <iostream>
//#include "Cluster.h"
//using namespace std;
//using namespace Clustering;
//int main ()
//{
//    double x[] = {2.2, 4.5, 0.11};
//    double y[] = {1.1, 2.4, 0.33};
//    double z[] = {3.4, 5.6, 1.9};
//    double xx[] = {4.4, 2.2, 5.6};
//
//    Point s(3,xx);
//    Point p(3, x);
//    Point q(3, y);
//    Point r(3, z);
//
//
//    Cluster a;
//    a += r;
//    a += q;
//    a += p;
//    a += s;
//
//    Cluster b = a;
//    if (a == b)
//        cout << "true" << endl;
//    else
//        cout << "false" << endl;
//
//
//    cout << a << endl;
//    cout << a.getSize() << endl;
//    cout << b << endl;
//    cout << b.getSize() << endl;
//    cout << p.getId() << endl;
//
//    bool pass = true;
//    for (int i = 0; i < 10; i ++) {
//
//        Cluster c1, c2(c1);
//
//        pass = (c1 == c2);
//        if (!pass)break;
//    }
//    cout << "result " << pass << endl;
//    return 0;
//}