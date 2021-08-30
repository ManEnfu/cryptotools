#include "util.h"

void uppercase(std::string& str) {
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it >= 'a' && *it <= 'z') *it -= 32;
    }
    /* for (char c : str) { */
    /*     if (c >= 'a' && c <= 'z') c = c - 32; */
    /* } */

}

void filter_alphabet(std::string &str) {
    std::string::iterator j = str.begin();
    for (std::string::iterator it = str.begin(); it != str.end(); it++) {
        if (*it < 'A' || (*it > 'Z' && *it < 'a') || *it > 'z') {
            std::string::iterator ot = it--;
            str.erase(ot);
        }
        /* if ((*it >= 'A' && *it <= 'Z') || (*it >= 'a' && *it <= 'z')) { */

        /* } */
        /* if (j == it) */
        /*     *j = *it; */
    }
}
