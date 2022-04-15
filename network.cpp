#include "network.h"
#include "profile.h"
#include <string>
#include <cctype>
#include <iostream>

Network::Network() { 
    numUsers = 0; 

    for(int i = 0; i < MAX_USERS; i++) { 
        for(int j = 0; j < MAX_USERS; j++) { 
            following[i][j] = false;
        }
    }
}

int Network::findID(std::string user) { 
    for(int i = 0; i < numUsers; i++) { 
        if(profiles[i].getUsername() == user) { 
            return i; 
        }
    }

    return -1; //user not found in the profiles array
}

// Attempts to sign up a new user with specified username and displayname
// return true if the operation was successful, otherwise return false
bool Network::addUser(std::string username, std::string display) { 
    if(numUsers == MAX_USERS) { 
        return false; 
    } else if(findID(username) != -1) { 
        return false; 
    }

    for(int i = 0; i < username.size(); i++) { 
        if(!isalnum(username.at(i))) { 
            return false; 
        }
    }

    profiles[numUsers] = { username, display };
    numUsers++;
    return true;
}

bool Network::follow(std::string user, std::string target) { 
    // Makes user follow target 
    if(findID(user) == -1 || findID(target) == -1) { 
        return false;
    }

    following[findID(user)][findID(target)] = true;
    return true; 
}

void Network::printDot() { 
    
    std::cout << "digraph {" << std::endl;
    for(int i = 0; i < numUsers; i++) { 
        std::cout << "  \"@" << profiles[i].getUsername() << "\"" << std::endl;
    }

    std::cout << std::endl;

    for(int i = 0; i < MAX_USERS; i++) { 
        for(int j = 0; j < MAX_USERS; j++) { 
            if(following[i][j] == true) { 
                std::cout << "  \"@" << profiles[i].getUsername() << "\" -> \"" << 
                             "@" << profiles[j].getUsername() << "\"" << std::endl;
            }
        }
    }

    std::cout << "}" << std::endl;
}