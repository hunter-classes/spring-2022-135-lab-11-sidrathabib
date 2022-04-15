
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "profile.h"
#include "network.h"
#include <string>

    Profile p1("sidrat", "Sidrat");    
    Profile p2("abir", "Abir");    
    Profile p3("tarma1", "Tarma Roving");    
  
TEST_CASE("TASK A: Class Profile") {
    SUBCASE("getUsername()") { 
        CHECK(p1.getUsername() == "sidrat");
        CHECK(p2.getUsername() == "abir");
        CHECK(p3.getUsername() == "tarma1");
    }

    SUBCASE("getFullName()") { 
        CHECK(p1.getFullName() == "Marco(@marco)");
        CHECK(p2.getFullName() == "Polo(@polo)");
        CHECK(p3.getFullName() == "Tarma Roving(@tarma1)");
    }
}

TEST_CASE("TASK B: Class Network: Adding users") {
    Network nw; 
    SUBCASE("addUser()") { 
        CHECK(nw.addUser("mario", "Mario") == true); 
        CHECK(nw.addUser("mario", "Mario") == false); 
        CHECK(nw.addUser("mario-2", "Mario2") == false);
        CHECK(nw.addUser("yoshi1", "yoshi") == true); 
        CHECK(nw.addUser("yoshi", "Yoshi") == true);
    }
}

TEST_CASE("TASK C: Class Network: Following others") { 
    Network nw;

    SUBCASE("addUser(user1, user2)") { 
        CHECK(nw.addUser("mario", "Mario") == true);
        CHECK(nw.addUser("luigi", "Luigi") == true);

        nw.addUser("mario", "Mario");
        nw.addUser("luigi", "Luigi");
        for(int i = 2; i < 20; i++) {
            nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
        }

        CHECK(nw.addUser("user", "user") == false); 
    }

    SUBCASE("follow(user1, user2)") { 
        nw.addUser("mario", "Mario");
        nw.addUser("luigi", "Luigi");
        for(int i = 2; i < 20; i++) {
            nw.addUser("mario" + std::to_string(i), "Mario" + std::to_string(i));
        }

        CHECK(nw.follow("mario", "luigi") == true);
        CHECK(nw.follow("mario-", "mario") == false);
        CHECK(nw.follow("mario1", "mario2") == false);
        CHECK(nw.follow("mario2", "mario2") == true); 
        CHECK(nw.follow("mario-3", "mario3") == false); 
    }
}