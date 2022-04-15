#include <iostream> 
#include "profile.h"
#include "network.h"
#include <string> 


int main() {

//--------------------------Task A--------------------------//
    std::cout << "Task A: Class Profile\n";
    Profile p1("marco", "Marco");
    std::cout << p1.getUsername() << std::endl;
    std::cout << p1.getFullName() << std::endl;

    p1.setDisplayName("Marco Rossi");
    std::cout << p1.getUsername() << std::endl;
    std::cout << p1.getFullName() << std::endl;

    Profile p2("tarma1", "Tarma Roving");
    std::cout << p2.getUsername() << std::endl;
    std::cout << p2.getFullName() << std::endl;

//--------------------------Task B--------------------------//

    std::cout << "Task B: Class Network: Adding users\n";
    Network nw;
    std::cout << nw.addUser("mario", "Mario") << std::endl;     // true (1)
    std::cout << nw.addUser("luigi", "Luigi") << std::endl;     // true (1)

    std::cout << nw.addUser("mario", "Mario2") << std::endl;    // false (0)
    std::cout << nw.addUser("mario 2", "Mario2") << std::endl;  // false (0)
    std::cout << nw.addUser("mario-2", "Mario2") << std::endl;  // false (0)

    for(int i = 2; i < 20; i++)
        std::cout << nw.addUser("mario" + std::to_string(i), 
                    "Mario" + std::to_string(i)) << " ";   // true (1)
    std::cout << std::endl; 
    std::cout << nw.addUser("yoshi", "Yoshi") << std::endl;     // false (0)

//--------------------------Task C--------------------------//

    std::cout << "Task C: Class Network: Following others\n"; 
    
    Network taskc;
    // add three users
    taskc.addUser("mario", "Mario");
    taskc.addUser("luigi", "Luigi");
    taskc.addUser("yoshi", "Yoshi");

    // make them follow each other
    taskc.follow("mario", "luigi");
    taskc.follow("mario", "yoshi");
    taskc.follow("luigi", "mario");
    taskc.follow("luigi", "yoshi");
    taskc.follow("yoshi", "mario");
    taskc.follow("yoshi", "luigi");

    // add a user who does not follow others
    taskc.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        std::string usrn = "mario" + std::to_string(i);
        std::string dspn = "Mario " + std::to_string(i);
        taskc.addUser(usrn, dspn);
        taskc.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    taskc.follow("mario2", "luigi");

    taskc.printDot();

    return 0;
}