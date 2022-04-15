#include "profile.h"
#include <string> 

Profile::Profile() {
    username = "";
    displayname = "";
}

Profile::Profile(std::string user, std::string display) {
    username = user; 
    displayname = display; 
}

std::string Profile::getUsername() {
    return username; 
}
std::string Profile::getFullName() {
    std::string full_name = displayname + "(@" + username + ")";
    return full_name;
}

void Profile::setDisplayName(std::string dspn) {
    displayname = dspn;
}