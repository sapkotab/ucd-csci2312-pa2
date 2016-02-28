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
//    double v[] ={1,0, 0, 0, 0};
//    double w[] ={0,1, 0, 0, 0};
//    double x[] ={0,0, 1, 0, 0};
//    double y[] ={0,0, 0, 1, 0};
//    double z[] ={0,0, 0, 0, 1};
//
//    Point   p1(5,v),
//            p2(5,w),
//            p3(5,x),
//            p4(5,y),
//            p5(5,z);
//
//
//    Cluster     c1,
//                c2,
//                c3;
//
//    c1+=p1; c1+=p2; c1+=p3;
//
//    c2+=p3; c2+=p4; c2+=p5;
//
//    c1 += c2;
//    c3+=p1;c3+=p2;c3+=p3;c3+=p4;c3+=p5;
//
//    cout << c1 << endl;
//    cout << c3 << endl;
//
//    if (c1 == c2)
//        cout << " they are" << endl;
//
//    return 0;
//}