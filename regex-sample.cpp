#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

void regexMatchFilenames() {
    // Simple regular expression matching
    std::string fnames[] = { "foo.txt", "bar.txt", "baz.dat", "zoidberg" };
    std::regex txt_regex("[a-z]+\\.txt");

    for (const auto &fname : fnames) {
        std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
    }

    // Extraction of a sub-match
    std::regex base_regex("([a-z]+)\\.txt");
    std::smatch base_match;

    for (const auto &fname : fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // The first sub_match is the whole string; the next
            // sub_match is the first parenthesized expression.
            if (base_match.size() == 2) {
                std::ssub_match base_sub_match = base_match[1];
                std::string base = base_sub_match.str();
                std::cout << fname << " has a base of " << base << '\n';
            }
        }
    }

    // Extraction of several sub-matches
    std::regex pieces_regex("([a-z]+)\\.([a-z]+)");
    std::smatch pieces_match;

    for (const auto &fname : fnames) {
        if (std::regex_match(fname, pieces_match, pieces_regex)) {
            std::cout << fname << '\n';
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                std::ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << "  submatch " << i << ": " << piece << '\n';
            }
        }
    }
}

void regexParseObj() {
    vector<string> candidates{
        "f 5449//5449 5279//5279 5450//5450",
        "f 5450//5450 5279//5279 5278//5278",
        "f 5451//5451 5280//5280 5452//5452",
        "f 5280//5280 5451//5451 5265//5265",
        "f 5449 5279 5450",
        "f 5280 5451 5265",
    };
    std::regex simple_face_regex("f\\s+(\\d+)\\s+(\\d+)\\s+(\\d+)");
    std::regex multi_face_regex("f\\s+(\\d+)//\\d+\\s+(\\d+)//\\d+\\s+(\\d+)//\\d+");
    std::smatch base_match, multi_match;
    for (const auto& line : candidates) {
        if (regex_match(line, base_match, simple_face_regex)) {
            cout << base_match[1].str() << " " << base_match[2].str() << " " << base_match[3].str() << endl;
        }
        else if (regex_match(line, multi_match, multi_face_regex)) {
            cout << multi_match[1].str() << " " << multi_match[2].str() << " " << multi_match[3].str() << endl;
        }
    }
}

int main()
{
    regexMatchFilenames();
    regexParseObj();

    system("PAUSE");
}